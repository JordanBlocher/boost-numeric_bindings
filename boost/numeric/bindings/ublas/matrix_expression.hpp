//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_UBLAS_MATRIX_EXPRESSION_HPP
#define BOOST_NUMERIC_BINDINGS_UBLAS_MATRIX_EXPRESSION_HPP

#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <boost/numeric/bindings/detail/property_map.hpp>
#include <boost/numeric/bindings/end.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Id, typename Enable >
struct adaptor< boost::numeric::ublas::matrix_reference< T >, Id, Enable > {

    typedef typename copy_const< Id, typename value<T>::type >::type value_type;
    typedef typename property_insert<
        T,
        mpl::pair< tag::value_type, value_type >
    >::type property_map;

    static std::ptrdiff_t size1( const Id& id ) {
        return bindings::size1( id.expression() );
    }

    static std::ptrdiff_t size2( const Id& id ) {
        return bindings::size2( id.expression() );
    }

    static value_type* begin_value( Id& id ) {
        return bindings::begin_value( id.expression() );
    }

    static value_type* end_value( Id& id ) {
        return bindings::end_value( id.expression() );
    }

    static std::ptrdiff_t stride1( const Id& id ) {
        return bindings::stride1( id.expression() );
    }

    static std::ptrdiff_t stride2( const Id& id ) {
        return bindings::stride2( id.expression() );
    }

};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
