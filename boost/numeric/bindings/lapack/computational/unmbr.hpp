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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_UNMBR_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_UNMBR_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
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
    inline void unmbr( const char vect, const char side, const char trans,
            const integer_t m, const integer_t n, const integer_t k,
            const traits::complex_f* a, const integer_t lda,
            const traits::complex_f* tau, traits::complex_f* c,
            const integer_t ldc, traits::complex_f* work,
            const integer_t lwork, integer_t& info ) {
        LAPACK_CUNMBR( &vect, &side, &trans, &m, &n, &k,
                traits::complex_ptr(a), &lda, traits::complex_ptr(tau),
                traits::complex_ptr(c), &ldc, traits::complex_ptr(work),
                &lwork, &info );
    }
    inline void unmbr( const char vect, const char side, const char trans,
            const integer_t m, const integer_t n, const integer_t k,
            const traits::complex_d* a, const integer_t lda,
            const traits::complex_d* tau, traits::complex_d* c,
            const integer_t ldc, traits::complex_d* work,
            const integer_t lwork, integer_t& info ) {
        LAPACK_ZUNMBR( &vect, &side, &trans, &m, &n, &k,
                traits::complex_ptr(a), &lda, traits::complex_ptr(tau),
                traits::complex_ptr(c), &ldc, traits::complex_ptr(work),
                &lwork, &info );
    }
}

// value-type based template
template< typename ValueType >
struct unmbr_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorTAU, typename MatrixC,
            typename WORK >
    static void invoke( const char vect, const char side, const char trans,
            const integer_t k, const MatrixA& a, const VectorTAU& tau,
            MatrixC& c, integer_t& info, detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorTAU >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixC >::value_type >::value) );
        BOOST_ASSERT( vect == 'Q' || vect == 'P' );
        BOOST_ASSERT( side == 'L' || side == 'R' );
        BOOST_ASSERT( trans == 'N' || trans == 'C' );
        BOOST_ASSERT( traits::matrix_num_rows(c) >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(c) >= 0 );
        BOOST_ASSERT( k >= 0 );
        BOOST_ASSERT( traits::vector_size(tau) >= std::min(?NQ,k) );
        BOOST_ASSERT( traits::leading_dimension(c) >= std::max(1,
                traits::matrix_num_rows(c)) );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( side, traits::matrix_num_rows(c),
                traits::matrix_num_columns(c) ));
        detail::unmbr( vect, side, trans, traits::matrix_num_rows(c),
                traits::matrix_num_columns(c), k, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(tau),
                traits::matrix_storage(c), traits::leading_dimension(c),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorTAU, typename MatrixC >
    static void invoke( const char vect, const char side, const char trans,
            const integer_t k, const MatrixA& a, const VectorTAU& tau,
            MatrixC& c, integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( side,
                traits::matrix_num_rows(c), traits::matrix_num_columns(c) ) );
        invoke( vect, side, trans, k, a, tau, c, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorTAU, typename MatrixC >
    static void invoke( const char vect, const char side, const char trans,
            const integer_t k, const MatrixA& a, const VectorTAU& tau,
            MatrixC& c, integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        detail::unmbr( vect, side, trans, traits::matrix_num_rows(c),
                traits::matrix_num_columns(c), k, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(tau),
                traits::matrix_storage(c), traits::leading_dimension(c),
                &opt_size_work, -1, info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        invoke( vect, side, trans, k, a, tau, c, info, workspace( tmp_work ) );
    }

    static integer_t min_size_work( const char side, const integer_t m,
            const integer_t n ) {
        if ( side == 'L' )
            return std::max( 1, n );
        else
            return std::max( 1, m );
    }
};


// template function to call unmbr
template< typename MatrixA, typename VectorTAU, typename MatrixC,
        typename Workspace >
inline integer_t unmbr( const char vect, const char side,
        const char trans, const integer_t k, const MatrixA& a,
        const VectorTAU& tau, MatrixC& c, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    unmbr_impl< value_type >::invoke( vect, side, trans, k, a, tau, c,
            info, work );
    return info;
}

// template function to call unmbr, default workspace type
template< typename MatrixA, typename VectorTAU, typename MatrixC >
inline integer_t unmbr( const char vect, const char side,
        const char trans, const integer_t k, const MatrixA& a,
        const VectorTAU& tau, MatrixC& c ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    unmbr_impl< value_type >::invoke( vect, side, trans, k, a, tau, c,
            info, optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
