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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_HPR2_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_HPR2_HPP

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
    inline void hpr2( char const uplo, integer_t const n,
            traits::complex_f const alpha, traits::complex_f* x,
            integer_t const incx, traits::complex_f* y, integer_t const incy,
            traits::complex_f* ap ) {
        BLAS_CHPR2( &uplo, &n, traits::complex_ptr(&alpha),
                traits::complex_ptr(x), &incx, traits::complex_ptr(y), &incy,
                traits::complex_ptr(ap) );
    }
    inline void hpr2( char const uplo, integer_t const n,
            traits::complex_d const alpha, traits::complex_d* x,
            integer_t const incx, traits::complex_d* y, integer_t const incy,
            traits::complex_d* ap ) {
        BLAS_ZHPR2( &uplo, &n, traits::complex_ptr(&alpha),
                traits::complex_ptr(x), &incx, traits::complex_ptr(y), &incy,
                traits::complex_ptr(ap) );
    }
}

// value-type based template
template< typename ValueType >
struct hpr2_impl {

    typedef ValueType value_type;
    typedef void return_type;

    // templated specialization
    template< typename VectorX, typename VectorY, typename MatrixAP >
    static return_type compute( traits::complex_d const alpha, VectorX& x,
            VectorY& y, MatrixAP& ap ) {
        detail::hpr2( traits::matrix_uplo_tag(ap),
                traits::matrix_size2(ap), alpha, traits::vector_storage(x),
                traits::vector_stride(x), traits::vector_storage(y),
                traits::vector_stride(y), traits::matrix_storage(ap) );
    }
};

// template function to call hpr2
template< typename VectorX, typename VectorY, typename MatrixAP >
inline integer_t hpr2( traits::complex_d const alpha, VectorX& x,
        VectorY& y, MatrixAP& ap ) {
    typedef typename traits::vector_traits< VectorX >::value_type value_type;
    hpr2_impl< value_type >::compute( alpha, x, y, ap );
}


}}}} // namespace boost::numeric::bindings::blas

#endif
