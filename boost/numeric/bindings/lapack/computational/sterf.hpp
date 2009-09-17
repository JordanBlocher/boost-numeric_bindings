//
// Copyright (c) 2003--2009
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_STERF_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_STERF_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void sterf( const integer_t n, float* d, float* e,
            integer_t& info ) {
        LAPACK_SSTERF( &n, d, e, &info );
    }
    inline void sterf( const integer_t n, double* d, double* e,
            integer_t& info ) {
        LAPACK_DSTERF( &n, d, e, &info );
    }
}

// value-type based template
template< typename ValueType >
struct sterf_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // templated specialization
    template< typename VectorD, typename VectorE >
    static void invoke( const integer_t n, VectorD& d, VectorE& e,
            integer_t& info ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorE >::value_type >::value) );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::vector_size(e) >= n-1 );
        detail::sterf( n, traits::vector_storage(d),
                traits::vector_storage(e), info );
    }
};


// template function to call sterf
template< typename VectorD, typename VectorE >
inline integer_t sterf( const integer_t n, VectorD& d, VectorE& e ) {
    typedef typename traits::vector_traits< VectorD >::value_type value_type;
    integer_t info(0);
    sterf_impl< value_type >::invoke( n, d, e, info );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
