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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_UNGQL_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_UNGQL_HPP

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
    inline void ungql( const integer_t m, const integer_t n,
            const integer_t k, traits::complex_f* a, const integer_t lda,
            const traits::complex_f* tau, traits::complex_f* work,
            const integer_t lwork, integer_t& info ) {
        LAPACK_CUNGQL( &m, &n, &k, traits::complex_ptr(a), &lda,
                traits::complex_ptr(tau), traits::complex_ptr(work), &lwork,
                &info );
    }
    inline void ungql( const integer_t m, const integer_t n,
            const integer_t k, traits::complex_d* a, const integer_t lda,
            const traits::complex_d* tau, traits::complex_d* work,
            const integer_t lwork, integer_t& info ) {
        LAPACK_ZUNGQL( &m, &n, &k, traits::complex_ptr(a), &lda,
                traits::complex_ptr(tau), traits::complex_ptr(work), &lwork,
                &info );
    }
}

// value-type based template
template< typename ValueType >
struct ungql_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorTAU, typename WORK >
    static void invoke( const integer_t m, const integer_t n,
            const integer_t k, MatrixA& a, const VectorTAU& tau,
            integer_t& info, detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorTAU >::value_type >::value) );
        BOOST_ASSERT( m >= 0 );
        BOOST_ASSERT( n >= n );
        BOOST_ASSERT( k >= k );
        BOOST_ASSERT( traits::leading_dimension(a) >= std::max(1,m) );
        BOOST_ASSERT( traits::vector_size(tau) >= k );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n ));
        detail::ungql( m, n, k, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(tau),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorTAU >
    static void invoke( const integer_t m, const integer_t n,
            const integer_t k, MatrixA& a, const VectorTAU& tau,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        invoke( m, n, k, a, tau, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorTAU >
    static void invoke( const integer_t m, const integer_t n,
            const integer_t k, MatrixA& a, const VectorTAU& tau,
            integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        detail::ungql( m, n, k, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(tau),
                &opt_size_work, -1, info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        invoke( m, n, k, a, tau, info, workspace( tmp_work ) );
    }

    static integer_t min_size_work( const integer_t n ) {
        return std::max( 1, n );
    }
};


// template function to call ungql
template< typename MatrixA, typename VectorTAU, typename Workspace >
inline integer_t ungql( const integer_t m, const integer_t n,
        const integer_t k, MatrixA& a, const VectorTAU& tau, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    ungql_impl< value_type >::invoke( m, n, k, a, tau, info, work );
    return info;
}

// template function to call ungql, default workspace type
template< typename MatrixA, typename VectorTAU >
inline integer_t ungql( const integer_t m, const integer_t n,
        const integer_t k, MatrixA& a, const VectorTAU& tau ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    ungql_impl< value_type >::invoke( m, n, k, a, tau, info,
            optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
