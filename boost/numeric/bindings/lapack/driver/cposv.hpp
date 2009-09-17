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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_CPOSV_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_CPOSV_HPP

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
    inline void cposv( const char uplo, const integer_t n,
            const integer_t nrhs, traits::complex_d* a, const integer_t lda,
            const traits::complex_d* b, const integer_t ldb,
            traits::complex_d* x, const integer_t ldx,
            traits::complex_d* work, traits::complex_f* swork, double* rwork,
            integer_t& iter, integer_t& info ) {
        LAPACK_ZCPOSV( &uplo, &n, &nrhs, traits::complex_ptr(a), &lda,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(x), &ldx,
                traits::complex_ptr(work), traits::complex_ptr(swork), rwork,
                &iter, &info );
    }
}

// value-type based template
template< typename ValueType >
struct cposv_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixB, typename MatrixX,
            typename WORK, typename SWORK, typename RWORK >
    static void invoke( MatrixA& a, const MatrixB& b, MatrixX& x,
            integer_t& iter, integer_t& info, detail::workspace3< WORK, SWORK,
            RWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_ASSERT( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        BOOST_ASSERT( traits::matrix_num_columns(a) >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(b) >= 0 );
        BOOST_ASSERT( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_num_columns(a)) );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,
                traits::matrix_num_columns(a)) );
        BOOST_ASSERT( traits::leading_dimension(x) >= std::max(1,
                traits::matrix_num_columns(a)) );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( $CALL_MIN_SIZE ));
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_swork( traits::matrix_num_columns(a),
                traits::matrix_num_columns(b) ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( traits::matrix_num_columns(a) ));
        detail::cposv( traits::matrix_uplo_tag(a),
                traits::matrix_num_columns(a), traits::matrix_num_columns(b),
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                traits::matrix_storage(work),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), iter, info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename MatrixX >
    static void invoke( MatrixA& a, const MatrixB& b, MatrixX& x,
            integer_t& iter, integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(
                $CALL_MIN_SIZE ) );
        traits::detail::array< value_type > tmp_swork( min_size_swork(
                traits::matrix_num_columns(a),
                traits::matrix_num_columns(b) ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_num_columns(a) ) );
        invoke( a, b, x, iter, info, workspace( tmp_work, tmp_swork,
                tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename MatrixX >
    static void invoke( MatrixA& a, const MatrixB& b, MatrixX& x,
            integer_t& iter, integer_t& info, optimal_workspace work ) {
        invoke( a, b, x, iter, info, minimal_workspace() );
    }

    static integer_t min_size_work( $ARGUMENTS ) {
        $MIN_SIZE
    }

    static integer_t min_size_swork( const integer_t n,
            const integer_t nrhs ) {
        return n*(n+nrhs);
    }

    static integer_t min_size_rwork( const integer_t n ) {
        return n;
    }
};


// template function to call cposv
template< typename MatrixA, typename MatrixB, typename MatrixX,
        typename Workspace >
inline integer_t cposv( MatrixA& a, const MatrixB& b, MatrixX& x,
        integer_t& iter, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    cposv_impl< value_type >::invoke( a, b, x, iter, info, work );
    return info;
}

// template function to call cposv, default workspace type
template< typename MatrixA, typename MatrixB, typename MatrixX >
inline integer_t cposv( MatrixA& a, const MatrixB& b, MatrixX& x,
        integer_t& iter ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    cposv_impl< value_type >::invoke( a, b, x, iter, info,
            optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
