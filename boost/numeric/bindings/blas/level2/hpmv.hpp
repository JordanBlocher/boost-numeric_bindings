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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_HPMV_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_HPMV_HPP

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
    inline void hpmv( char const uplo, integer_t const n,
            traits::complex_f const alpha, traits::complex_f* ap,
            traits::complex_f* x, integer_t const incx,
            traits::complex_f const beta, traits::complex_f* y,
            integer_t const incy ) {
        BLAS_CHPMV( &uplo, &n, traits::complex_ptr(&alpha),
                traits::complex_ptr(ap), traits::complex_ptr(x), &incx,
                traits::complex_ptr(&beta), traits::complex_ptr(y), &incy );
    }
    inline void hpmv( char const uplo, integer_t const n,
            traits::complex_d const alpha, traits::complex_d* ap,
            traits::complex_d* x, integer_t const incx,
            traits::complex_d const beta, traits::complex_d* y,
            integer_t const incy ) {
        BLAS_ZHPMV( &uplo, &n, traits::complex_ptr(&alpha),
                traits::complex_ptr(ap), traits::complex_ptr(x), &incx,
                traits::complex_ptr(&beta), traits::complex_ptr(y), &incy );
    }
}

// value-type based template
template< typename ValueType >
struct hpmv_impl {

    typedef ValueType value_type;
    typedef void return_type;

    // templated specialization
    template< typename MatrixAP, typename VectorX, typename VectorY >
    static return_type compute( traits::complex_d const alpha, MatrixAP& ap,
            VectorX& x, traits::complex_d const beta, VectorY& y ) {
        detail::hpmv( traits::matrix_uplo_tag(ap),
                traits::matrix_size2(ap), alpha, traits::matrix_storage(ap),
                traits::vector_storage(x), traits::vector_stride(x), beta,
                traits::vector_storage(y), traits::vector_stride(y) );
    }
};

// template function to call hpmv
template< typename MatrixAP, typename VectorX, typename VectorY >
inline integer_t hpmv( traits::complex_d const alpha, MatrixAP& ap,
        VectorX& x, traits::complex_d const beta, VectorY& y ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    hpmv_impl< value_type >::compute( alpha, ap, x, beta, y );
}


}}}} // namespace boost::numeric::bindings::blas

#endif
