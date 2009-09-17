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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_HBTRD_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_HBTRD_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
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
    inline void hbtrd( const char vect, const char uplo, const integer_t n,
            const integer_t kd, traits::complex_f* ab, const integer_t ldab,
            float* d, float* e, traits::complex_f* q, const integer_t ldq,
            traits::complex_f* work, integer_t& info ) {
        LAPACK_CHBTRD( &vect, &uplo, &n, &kd, traits::complex_ptr(ab), &ldab,
                d, e, traits::complex_ptr(q), &ldq, traits::complex_ptr(work),
                &info );
    }
    inline void hbtrd( const char vect, const char uplo, const integer_t n,
            const integer_t kd, traits::complex_d* ab, const integer_t ldab,
            double* d, double* e, traits::complex_d* q, const integer_t ldq,
            traits::complex_d* work, integer_t& info ) {
        LAPACK_ZHBTRD( &vect, &uplo, &n, &kd, traits::complex_ptr(ab), &ldab,
                d, e, traits::complex_ptr(q), &ldq, traits::complex_ptr(work),
                &info );
    }
}

// value-type based template
template< typename ValueType >
struct hbtrd_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAB, typename VectorD, typename VectorE,
            typename MatrixQ, typename WORK >
    static void invoke( const char vect, const integer_t n,
            const integer_t kd, MatrixAB& ab, VectorD& d, VectorE& e,
            MatrixQ& q, integer_t& info, detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorE >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixQ >::value_type >::value) );
        BOOST_ASSERT( vect == 'N' || vect == 'V' || vect == 'U' );
        BOOST_ASSERT( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( kd >= 0 );
        BOOST_ASSERT( traits::leading_dimension(ab) >= kd+1 );
        BOOST_ASSERT( traits::vector_size(d) >= n );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n ));
        detail::hbtrd( vect, traits::matrix_uplo_tag(a), n, kd,
                traits::matrix_storage(ab), traits::leading_dimension(ab),
                traits::vector_storage(d), traits::vector_storage(e),
                traits::matrix_storage(q), traits::leading_dimension(q),
                traits::vector_storage(work.select(value_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAB, typename VectorD, typename VectorE,
            typename MatrixQ >
    static void invoke( const char vect, const integer_t n,
            const integer_t kd, MatrixAB& ab, VectorD& d, VectorE& e,
            MatrixQ& q, integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        invoke( vect, n, kd, ab, d, e, q, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixAB, typename VectorD, typename VectorE,
            typename MatrixQ >
    static void invoke( const char vect, const integer_t n,
            const integer_t kd, MatrixAB& ab, VectorD& d, VectorE& e,
            MatrixQ& q, integer_t& info, optimal_workspace work ) {
        invoke( vect, n, kd, ab, d, e, q, info, minimal_workspace() );
    }

    static integer_t min_size_work( const integer_t n ) {
        return n;
    }
};


// template function to call hbtrd
template< typename MatrixAB, typename VectorD, typename VectorE,
        typename MatrixQ, typename Workspace >
inline integer_t hbtrd( const char vect, const integer_t n,
        const integer_t kd, MatrixAB& ab, VectorD& d, VectorE& e, MatrixQ& q,
        Workspace work ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    hbtrd_impl< value_type >::invoke( vect, n, kd, ab, d, e, q, info,
            work );
    return info;
}

// template function to call hbtrd, default workspace type
template< typename MatrixAB, typename VectorD, typename VectorE,
        typename MatrixQ >
inline integer_t hbtrd( const char vect, const integer_t n,
        const integer_t kd, MatrixAB& ab, VectorD& d, VectorE& e,
        MatrixQ& q ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    hbtrd_impl< value_type >::invoke( vect, n, kd, ab, d, e, q, info,
            optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
