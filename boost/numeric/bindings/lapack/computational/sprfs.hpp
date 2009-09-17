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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_SPRFS_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_SPRFS_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void sprfs( const char uplo, const integer_t n,
            const integer_t nrhs, const float* ap, const float* afp,
            const integer_t* ipiv, const float* b, const integer_t ldb,
            float* x, const integer_t ldx, float* ferr, float* berr,
            float* work, integer_t* iwork, integer_t& info ) {
        LAPACK_SSPRFS( &uplo, &n, &nrhs, ap, afp, ipiv, b, &ldb, x, &ldx,
                ferr, berr, work, iwork, &info );
    }
    inline void sprfs( const char uplo, const integer_t n,
            const integer_t nrhs, const double* ap, const double* afp,
            const integer_t* ipiv, const double* b, const integer_t ldb,
            double* x, const integer_t ldx, double* ferr, double* berr,
            double* work, integer_t* iwork, integer_t& info ) {
        LAPACK_DSPRFS( &uplo, &n, &nrhs, ap, afp, ipiv, b, &ldb, x, &ldx,
                ferr, berr, work, iwork, &info );
    }
    inline void sprfs( const char uplo, const integer_t n,
            const integer_t nrhs, const traits::complex_f* ap,
            const traits::complex_f* afp, const integer_t* ipiv,
            const traits::complex_f* b, const integer_t ldb,
            traits::complex_f* x, const integer_t ldx, float* ferr,
            float* berr, traits::complex_f* work, float* rwork,
            integer_t& info ) {
        LAPACK_CSPRFS( &uplo, &n, &nrhs, traits::complex_ptr(ap),
                traits::complex_ptr(afp), ipiv, traits::complex_ptr(b), &ldb,
                traits::complex_ptr(x), &ldx, ferr, berr,
                traits::complex_ptr(work), rwork, &info );
    }
    inline void sprfs( const char uplo, const integer_t n,
            const integer_t nrhs, const traits::complex_d* ap,
            const traits::complex_d* afp, const integer_t* ipiv,
            const traits::complex_d* b, const integer_t ldb,
            traits::complex_d* x, const integer_t ldx, double* ferr,
            double* berr, traits::complex_d* work, double* rwork,
            integer_t& info ) {
        LAPACK_ZSPRFS( &uplo, &n, &nrhs, traits::complex_ptr(ap),
                traits::complex_ptr(afp), ipiv, traits::complex_ptr(b), &ldb,
                traits::complex_ptr(x), &ldx, ferr, berr,
                traits::complex_ptr(work), rwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct sprfs_impl{};

// real specialization
template< typename ValueType >
struct sprfs_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAP, typename MatrixAFP, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR, typename WORK, typename IWORK >
    static void invoke( const integer_t n, const MatrixAP& ap,
            const MatrixAFP& afp, const VectorIPIV& ipiv, const MatrixB& b,
            MatrixX& x, VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixAFP >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::vector_traits<
                VectorFERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
        BOOST_ASSERT( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(x) >= 0 );
        BOOST_ASSERT( traits::vector_size(afp) >= n*(n+1)/2 );
        BOOST_ASSERT( traits::vector_size(ipiv) >= n );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(x) >= std::max(1,n) );
        BOOST_ASSERT( traits::vector_size(berr) >=
                traits::matrix_num_columns(x) );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( n ));
        detail::sprfs( traits::matrix_uplo_tag(a), n,
                traits::matrix_num_columns(x), traits::matrix_storage(ap),
                traits::matrix_storage(afp), traits::vector_storage(ipiv),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                traits::vector_storage(ferr), traits::vector_storage(berr),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAP, typename MatrixAFP, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void invoke( const integer_t n, const MatrixAP& ap,
            const MatrixAFP& afp, const VectorIPIV& ipiv, const MatrixB& b,
            MatrixX& x, VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        invoke( n, ap, afp, ipiv, b, x, ferr, berr, info, workspace( tmp_work,
                tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAP, typename MatrixAFP, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void invoke( const integer_t n, const MatrixAP& ap,
            const MatrixAFP& afp, const VectorIPIV& ipiv, const MatrixB& b,
            MatrixX& x, VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        invoke( n, ap, afp, ipiv, b, x, ferr, berr, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( const integer_t n ) {
        return 3*n;
    }

    static integer_t min_size_iwork( const integer_t n ) {
        return n;
    }
};

// complex specialization
template< typename ValueType >
struct sprfs_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAP, typename MatrixAFP, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR, typename WORK, typename RWORK >
    static void invoke( const integer_t n, const MatrixAP& ap,
            const MatrixAFP& afp, const VectorIPIV& ipiv, const MatrixB& b,
            MatrixX& x, VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, RWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorFERR >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixAFP >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_ASSERT( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(x) >= 0 );
        BOOST_ASSERT( traits::vector_size(afp) >= n*(n+1)/2 );
        BOOST_ASSERT( traits::vector_size(ipiv) >= n );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(x) >= std::max(1,n) );
        BOOST_ASSERT( traits::vector_size(berr) >=
                traits::matrix_num_columns(x) );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( n ));
        detail::sprfs( traits::matrix_uplo_tag(a), n,
                traits::matrix_num_columns(x), traits::matrix_storage(ap),
                traits::matrix_storage(afp), traits::vector_storage(ipiv),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                traits::vector_storage(ferr), traits::vector_storage(berr),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAP, typename MatrixAFP, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void invoke( const integer_t n, const MatrixAP& ap,
            const MatrixAFP& afp, const VectorIPIV& ipiv, const MatrixB& b,
            MatrixX& x, VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        invoke( n, ap, afp, ipiv, b, x, ferr, berr, info, workspace( tmp_work,
                tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAP, typename MatrixAFP, typename VectorIPIV,
            typename MatrixB, typename MatrixX, typename VectorFERR,
            typename VectorBERR >
    static void invoke( const integer_t n, const MatrixAP& ap,
            const MatrixAFP& afp, const VectorIPIV& ipiv, const MatrixB& b,
            MatrixX& x, VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        invoke( n, ap, afp, ipiv, b, x, ferr, berr, info,
                minimal_workspace() );
    }

    static integer_t min_size_work( const integer_t n ) {
        return 2*n;
    }

    static integer_t min_size_rwork( const integer_t n ) {
        return n;
    }
};


// template function to call sprfs
template< typename MatrixAP, typename MatrixAFP, typename VectorIPIV,
        typename MatrixB, typename MatrixX, typename VectorFERR,
        typename VectorBERR, typename Workspace >
inline integer_t sprfs( const integer_t n, const MatrixAP& ap,
        const MatrixAFP& afp, const VectorIPIV& ipiv, const MatrixB& b,
        MatrixX& x, VectorFERR& ferr, VectorBERR& berr, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    sprfs_impl< value_type >::invoke( n, ap, afp, ipiv, b, x, ferr, berr,
            info, work );
    return info;
}

// template function to call sprfs, default workspace type
template< typename MatrixAP, typename MatrixAFP, typename VectorIPIV,
        typename MatrixB, typename MatrixX, typename VectorFERR,
        typename VectorBERR >
inline integer_t sprfs( const integer_t n, const MatrixAP& ap,
        const MatrixAFP& afp, const VectorIPIV& ipiv, const MatrixB& b,
        MatrixX& x, VectorFERR& ferr, VectorBERR& berr ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    sprfs_impl< value_type >::invoke( n, ap, afp, ipiv, b, x, ferr, berr,
            info, optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
