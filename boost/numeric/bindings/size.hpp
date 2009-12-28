//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_SIZE_HPP
#define BOOST_NUMERIC_BINDINGS_SIZE_HPP

#include <boost/numeric/bindings/detail/generate_functions.hpp>
#include <boost/numeric/bindings/detail/get.hpp>
#include <boost/numeric/bindings/rank.hpp>
#include <boost/numeric/bindings/index_major.hpp>
#include <boost/numeric/bindings/index_minor.hpp>
#include <boost/numeric/bindings/index_trans.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/min.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/less_equal.hpp>
#include <boost/static_assert.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Index, typename Enable = void >
struct size_impl {

    typedef typename tag::size_type< Index::value > key_type;
    typedef typename result_of_get< T, key_type >::type result_type;

    static result_type invoke( const T& t ) {
        return get< key_type >( t );
    }

};

template< typename T, typename Index >
struct size_impl< T, Index,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Index, rank<T> >,
            is_same_at< T, tag::size_type<1>, std::ptrdiff_t >
        >::type >::type > {

    typedef std::ptrdiff_t result_type;

    static result_type invoke( const T& t ) {
        return std::min< std::ptrdiff_t >( size_impl<T, tag::index<1> >::invoke(t), 1 );
    }

};

template< typename T, typename Index >
struct size_impl< T, Index,
        typename boost::enable_if< typename mpl::and_<
            mpl::greater< Index, rank<T> >,
            mpl::not_< is_same_at< T, tag::size_type<1>, std::ptrdiff_t > >
        >::type >::type > {

    typedef typename mpl::min<
        typename detail::property_at< T, tag::size_type<1> >::type,
        mpl::int_<1>
    >::type result_type;

    static result_type invoke( const T& t ) {
        return result_type();
    }

};

} // namespace detail


namespace result_of {

template< typename T, typename Tag = tag::index<1> >
struct size {
    BOOST_STATIC_ASSERT( (is_tag<Tag>::value) );
    typedef typename detail::size_impl< T, Tag >::result_type type;
};

} // namespace result_of

//
// Overloads for free template functions size( x, tag ), 
//
template< typename T, typename Tag >
inline typename result_of::size< const T, Tag >::type
size( const T& t, Tag ) {
    return detail::size_impl< const T, Tag >::invoke( t );
}

// Overloads for free template function size( x )
// Valid for types with rank <= 1 (scalars, vectors)
// In theory, we could provide overloads for matrices here, too, 
// if their minimal_rank is at most 1.

template< typename T >
typename boost::enable_if< mpl::less< rank<T>, mpl::int_<2> >,
    typename result_of::size< const T >::type >::type
size( const T& t ) {
    return detail::size_impl< const T, tag::index<1> >::invoke( t );
}

#define GENERATE_SIZE_INDEX( z, which, unused ) \
GENERATE_FUNCTIONS( size, which, tag::index<which> )

BOOST_PP_REPEAT_FROM_TO(1,3,GENERATE_SIZE_INDEX,~)

GENERATE_FUNCTIONS( size, _row, tag::index<1> )
GENERATE_FUNCTIONS( size, _column, tag::index<2> )
GENERATE_FUNCTIONS( size, _major, typename index_major<T>::type )
GENERATE_FUNCTIONS( size, _minor, typename index_minor<T>::type )

//
// Overloads for free template functions size_row( x, tag ), 
// Here, tag is assumed to be either one of
// tag::transpose, tag::no_transpose, or tag::conjugate
//
namespace result_of {

template< typename T, typename TransTag >
struct size_row_op {
    typedef typename size<
        T,
        typename index_trans< tag::index<1>, TransTag >::type
    >::type type;
};

template< typename T, typename TransTag >
struct size_column_op {
    typedef typename size< T, 
        typename index_trans< tag::index<2>, TransTag >::type >::type type;
};

} // namespace result_of

template< typename T, typename Tag >
inline typename result_of::size_row_op< const T, Tag >::type
size_row_op( const T& t, Tag ) {
    return result_of::size_row_op< const T, Tag >::type( t );
}

template< typename T, typename Tag >
inline typename result_of::size_row_op< const T, Tag >::type
size_column_op( const T& t, Tag ) {
    return result_of::size_column_op< const T, Tag >::type( t );
}

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
