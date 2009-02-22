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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_TRSM_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_TRSM_HPP

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
    inline void trsm( char const side, char const uplo, char const transa,
            char const diag, integer_t const m, integer_t const n,
            float const alpha, float* a, integer_t const lda, float* b,
            integer_t const ldb ) {
        BLAS_STRSM( &side, &uplo, &transa, &diag, &m, &n, &alpha, a, &lda, b,
                &ldb );
    }
    inline void trsm( char const side, char const uplo, char const transa,
            char const diag, integer_t const m, integer_t const n,
            double const alpha, double* a, integer_t const lda, double* b,
            integer_t const ldb ) {
        BLAS_DTRSM( &side, &uplo, &transa, &diag, &m, &n, &alpha, a, &lda, b,
                &ldb );
    }
    inline void trsm( char const side, char const uplo, char const transa,
            char const diag, integer_t const m, integer_t const n,
            traits::complex_f const alpha, traits::complex_f* a,
            integer_t const lda, traits::complex_f* b, integer_t const ldb ) {
        BLAS_CTRSM( &side, &uplo, &transa, &diag, &m, &n,
                traits::complex_ptr(&alpha), traits::complex_ptr(a), &lda,
                traits::complex_ptr(b), &ldb );
    }
    inline void trsm( char const side, char const uplo, char const transa,
            char const diag, integer_t const m, integer_t const n,
            traits::complex_d const alpha, traits::complex_d* a,
            integer_t const lda, traits::complex_d* b, integer_t const ldb ) {
        BLAS_ZTRSM( &side, &uplo, &transa, &diag, &m, &n,
                traits::complex_ptr(&alpha), traits::complex_ptr(a), &lda,
                traits::complex_ptr(b), &ldb );
    }
}

// value-type based template
template< typename ValueType >
struct trsm_impl {

    typedef ValueType value_type;
    typedef void return_type;

    // templated specialization
    template< typename MatrixA, typename MatrixB >
    static return_type compute( char const side, char const transa,
            char const diag, traits::complex_d const alpha, MatrixA& a,
            MatrixB& b ) {
        detail::trsm( side, traits::matrix_uplo_tag(a), transa, diag,
                traits::matrix_size1(b), traits::matrix_size2(b), alpha,
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b) );
    }
};

// template function to call trsm
template< typename MatrixA, typename MatrixB >
inline integer_t trsm( char const side, char const transa,
        char const diag, traits::complex_d const alpha, MatrixA& a,
        MatrixB& b ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    trsm_impl< value_type >::compute( side, transa, diag, alpha, a, b );
}


}}}} // namespace boost::numeric::bindings::blas

#endif
