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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_HPR_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_HPR_HPP

#include <boost/numeric/bindings/blas/blas.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {

//$DESCRIPTION

// overloaded functions to call blas
namespace detail {
    inline void hpr( char const uplo, integer_t const n, float const alpha,
            traits::complex_f* x, integer_t const incx,
            traits::complex_f* ap ) {
        BLAS_CHPR( &uplo, &n, &alpha, traits::complex_ptr(x), &incx,
                traits::complex_ptr(ap) );
    }
    inline void hpr( char const uplo, integer_t const n, double const alpha,
            traits::complex_d* x, integer_t const incx,
            traits::complex_d* ap ) {
        BLAS_ZHPR( &uplo, &n, &alpha, traits::complex_ptr(x), &incx,
                traits::complex_ptr(ap) );
    }
}

// value-type based template
template< typename ValueType >
struct hpr_impl {

    typedef ValueType value_type;
    typedef void return_type;

    // templated specialization
    template< typename VectorX, typename MatrixAP >
    static return_type compute( real_type const alpha, VectorX& x,
            MatrixAP& ap ) {
        detail::hpr( traits::matrix_uplo_tag(ap),
                traits::matrix_size2(ap), alpha, traits::vector_storage(x),
                traits::vector_stride(x), traits::matrix_storage(ap) );
    }
};

// template function to call hpr
template< typename VectorX, typename MatrixAP >

        inline integer_t hpr( typename traits::vector_traits< VectorX >::value_type const alpha,
        VectorX& x, MatrixAP& ap ) {
    typedef typename traits::vector_traits< VectorX >::value_type value_type;
    hpr_impl< value_type >::compute( alpha, x, ap );
}


}}}} // namespace boost::numeric::bindings::blas

#endif
