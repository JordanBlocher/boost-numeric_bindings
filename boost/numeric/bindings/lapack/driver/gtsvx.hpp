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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_GTSVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_GTSVX_HPP

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
    inline void gtsvx( const char fact, const char trans, const integer_t n,
            const integer_t nrhs, const float* dl, const float* d,
            const float* du, float* dlf, float* df, float* duf, float* du2,
            integer_t* ipiv, const float* b, const integer_t ldb, float* x,
            const integer_t ldx, float& rcond, float* ferr, float* berr,
            float* work, integer_t* iwork, integer_t& info ) {
        LAPACK_SGTSVX( &fact, &trans, &n, &nrhs, dl, d, du, dlf, df, duf, du2,
                ipiv, b, &ldb, x, &ldx, &rcond, ferr, berr, work, iwork,
                &info );
    }
    inline void gtsvx( const char fact, const char trans, const integer_t n,
            const integer_t nrhs, const double* dl, const double* d,
            const double* du, double* dlf, double* df, double* duf,
            double* du2, integer_t* ipiv, const double* b,
            const integer_t ldb, double* x, const integer_t ldx,
            double& rcond, double* ferr, double* berr, double* work,
            integer_t* iwork, integer_t& info ) {
        LAPACK_DGTSVX( &fact, &trans, &n, &nrhs, dl, d, du, dlf, df, duf, du2,
                ipiv, b, &ldb, x, &ldx, &rcond, ferr, berr, work, iwork,
                &info );
    }
    inline void gtsvx( const char fact, const char trans, const integer_t n,
            const integer_t nrhs, const traits::complex_f* dl,
            const traits::complex_f* d, const traits::complex_f* du,
            traits::complex_f* dlf, traits::complex_f* df,
            traits::complex_f* duf, traits::complex_f* du2, integer_t* ipiv,
            const traits::complex_f* b, const integer_t ldb,
            traits::complex_f* x, const integer_t ldx, float& rcond,
            float* ferr, float* berr, traits::complex_f* work, float* rwork,
            integer_t& info ) {
        LAPACK_CGTSVX( &fact, &trans, &n, &nrhs, traits::complex_ptr(dl),
                traits::complex_ptr(d), traits::complex_ptr(du),
                traits::complex_ptr(dlf), traits::complex_ptr(df),
                traits::complex_ptr(duf), traits::complex_ptr(du2), ipiv,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(x), &ldx,
                &rcond, ferr, berr, traits::complex_ptr(work), rwork, &info );
    }
    inline void gtsvx( const char fact, const char trans, const integer_t n,
            const integer_t nrhs, const traits::complex_d* dl,
            const traits::complex_d* d, const traits::complex_d* du,
            traits::complex_d* dlf, traits::complex_d* df,
            traits::complex_d* duf, traits::complex_d* du2, integer_t* ipiv,
            const traits::complex_d* b, const integer_t ldb,
            traits::complex_d* x, const integer_t ldx, double& rcond,
            double* ferr, double* berr, traits::complex_d* work,
            double* rwork, integer_t& info ) {
        LAPACK_ZGTSVX( &fact, &trans, &n, &nrhs, traits::complex_ptr(dl),
                traits::complex_ptr(d), traits::complex_ptr(du),
                traits::complex_ptr(dlf), traits::complex_ptr(df),
                traits::complex_ptr(duf), traits::complex_ptr(du2), ipiv,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(x), &ldx,
                &rcond, ferr, berr, traits::complex_ptr(work), rwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct gtsvx_impl{};

// real specialization
template< typename ValueType >
struct gtsvx_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorDL, typename VectorD, typename VectorDU,
            typename VectorDLF, typename VectorDF, typename VectorDUF,
            typename VectorDU2, typename VectorIPIV, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR,
            typename WORK, typename IWORK >
    static void invoke( const char fact, const char trans, const integer_t n,
            const VectorDL& dl, const VectorD& d, const VectorDU& du,
            VectorDLF& dlf, VectorDF& df, VectorDUF& duf, VectorDU2& du2,
            VectorIPIV& ipiv, const MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorD >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDU >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDLF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDUF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDU2 >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorFERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
        BOOST_ASSERT( fact == 'F' || fact == 'N' );
        BOOST_ASSERT( trans == 'N' || trans == 'T' || trans == 'C' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(b) >= 0 );
        BOOST_ASSERT( traits::vector_size(dl) >= n-1 );
        BOOST_ASSERT( traits::vector_size(d) >= n );
        BOOST_ASSERT( traits::vector_size(du) >= n-1 );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(x) >= std::max(1,n) );
        BOOST_ASSERT( traits::vector_size(berr) >=
                traits::matrix_num_columns(b) );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( n ));
        detail::gtsvx( fact, trans, n, traits::matrix_num_columns(b),
                traits::vector_storage(dl), traits::vector_storage(d),
                traits::vector_storage(du), traits::vector_storage(dlf),
                traits::vector_storage(df), traits::vector_storage(duf),
                traits::vector_storage(du2), traits::vector_storage(ipiv),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                rcond, traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())), info );
    }

    // minimal workspace specialization
    template< typename VectorDL, typename VectorD, typename VectorDU,
            typename VectorDLF, typename VectorDF, typename VectorDUF,
            typename VectorDU2, typename VectorIPIV, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void invoke( const char fact, const char trans, const integer_t n,
            const VectorDL& dl, const VectorD& d, const VectorDU& du,
            VectorDLF& dlf, VectorDF& df, VectorDUF& duf, VectorDU2& du2,
            VectorIPIV& ipiv, const MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        invoke( fact, trans, n, dl, d, du, dlf, df, duf, du2, ipiv, b, x,
                rcond, ferr, berr, info, workspace( tmp_work, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename VectorDL, typename VectorD, typename VectorDU,
            typename VectorDLF, typename VectorDF, typename VectorDUF,
            typename VectorDU2, typename VectorIPIV, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void invoke( const char fact, const char trans, const integer_t n,
            const VectorDL& dl, const VectorD& d, const VectorDU& du,
            VectorDLF& dlf, VectorDF& df, VectorDUF& duf, VectorDU2& du2,
            VectorIPIV& ipiv, const MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        invoke( fact, trans, n, dl, d, du, dlf, df, duf, du2, ipiv, b, x,
                rcond, ferr, berr, info, minimal_workspace() );
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
struct gtsvx_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorDL, typename VectorD, typename VectorDU,
            typename VectorDLF, typename VectorDF, typename VectorDUF,
            typename VectorDU2, typename VectorIPIV, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR,
            typename WORK, typename RWORK >
    static void invoke( const char fact, const char trans, const integer_t n,
            const VectorDL& dl, const VectorD& d, const VectorDU& du,
            VectorDLF& dlf, VectorDF& df, VectorDUF& duf, VectorDU2& du2,
            VectorIPIV& ipiv, const MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            detail::workspace2< WORK, RWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorFERR >::value_type, typename traits::vector_traits<
                VectorBERR >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorD >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDU >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDLF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDUF >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::vector_traits<
                VectorDU2 >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorDL >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_ASSERT( fact == 'F' || fact == 'N' );
        BOOST_ASSERT( trans == 'N' || trans == 'T' || trans == 'C' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(b) >= 0 );
        BOOST_ASSERT( traits::vector_size(dl) >= n-1 );
        BOOST_ASSERT( traits::vector_size(d) >= n );
        BOOST_ASSERT( traits::vector_size(du) >= n-1 );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(x) >= std::max(1,n) );
        BOOST_ASSERT( traits::vector_size(berr) >=
                traits::matrix_num_columns(b) );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( n ));
        detail::gtsvx( fact, trans, n, traits::matrix_num_columns(b),
                traits::vector_storage(dl), traits::vector_storage(d),
                traits::vector_storage(du), traits::vector_storage(dlf),
                traits::vector_storage(df), traits::vector_storage(duf),
                traits::vector_storage(du2), traits::vector_storage(ipiv),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::matrix_storage(x), traits::leading_dimension(x),
                rcond, traits::vector_storage(ferr),
                traits::vector_storage(berr),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename VectorDL, typename VectorD, typename VectorDU,
            typename VectorDLF, typename VectorDF, typename VectorDUF,
            typename VectorDU2, typename VectorIPIV, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void invoke( const char fact, const char trans, const integer_t n,
            const VectorDL& dl, const VectorD& d, const VectorDU& du,
            VectorDLF& dlf, VectorDF& df, VectorDUF& duf, VectorDU2& du2,
            VectorIPIV& ipiv, const MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        invoke( fact, trans, n, dl, d, du, dlf, df, duf, du2, ipiv, b, x,
                rcond, ferr, berr, info, workspace( tmp_work, tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename VectorDL, typename VectorD, typename VectorDU,
            typename VectorDLF, typename VectorDF, typename VectorDUF,
            typename VectorDU2, typename VectorIPIV, typename MatrixB,
            typename MatrixX, typename VectorFERR, typename VectorBERR >
    static void invoke( const char fact, const char trans, const integer_t n,
            const VectorDL& dl, const VectorD& d, const VectorDU& du,
            VectorDLF& dlf, VectorDF& df, VectorDUF& duf, VectorDU2& du2,
            VectorIPIV& ipiv, const MatrixB& b, MatrixX& x, real_type& rcond,
            VectorFERR& ferr, VectorBERR& berr, integer_t& info,
            optimal_workspace work ) {
        invoke( fact, trans, n, dl, d, du, dlf, df, duf, du2, ipiv, b, x,
                rcond, ferr, berr, info, minimal_workspace() );
    }

    static integer_t min_size_work( const integer_t n ) {
        return 2*n;
    }

    static integer_t min_size_rwork( const integer_t n ) {
        return n;
    }
};


// template function to call gtsvx
template< typename VectorDL, typename VectorD, typename VectorDU,
        typename VectorDLF, typename VectorDF, typename VectorDUF,
        typename VectorDU2, typename VectorIPIV, typename MatrixB,
        typename MatrixX, typename VectorFERR, typename VectorBERR,
        typename Workspace >
inline integer_t gtsvx( const char fact, const char trans,
        const integer_t n, const VectorDL& dl, const VectorD& d,
        const VectorDU& du, VectorDLF& dlf, VectorDF& df, VectorDUF& duf,
        VectorDU2& du2, VectorIPIV& ipiv, const MatrixB& b, MatrixX& x,
        typename traits::type_traits< typename traits::vector_traits<
        VectorDL >::value_type >::real_type& rcond, VectorFERR& ferr,
        VectorBERR& berr, Workspace work ) {
    typedef typename traits::vector_traits< VectorDL >::value_type value_type;
    integer_t info(0);
    gtsvx_impl< value_type >::invoke( fact, trans, n, dl, d, du, dlf, df,
            duf, du2, ipiv, b, x, rcond, ferr, berr, info, work );
    return info;
}

// template function to call gtsvx, default workspace type
template< typename VectorDL, typename VectorD, typename VectorDU,
        typename VectorDLF, typename VectorDF, typename VectorDUF,
        typename VectorDU2, typename VectorIPIV, typename MatrixB,
        typename MatrixX, typename VectorFERR, typename VectorBERR >
inline integer_t gtsvx( const char fact, const char trans,
        const integer_t n, const VectorDL& dl, const VectorD& d,
        const VectorDU& du, VectorDLF& dlf, VectorDF& df, VectorDUF& duf,
        VectorDU2& du2, VectorIPIV& ipiv, const MatrixB& b, MatrixX& x,
        typename traits::type_traits< typename traits::vector_traits<
        VectorDL >::value_type >::real_type& rcond, VectorFERR& ferr,
        VectorBERR& berr ) {
    typedef typename traits::vector_traits< VectorDL >::value_type value_type;
    integer_t info(0);
    gtsvx_impl< value_type >::invoke( fact, trans, n, dl, d, du, dlf, df,
            duf, du2, ipiv, b, x, rcond, ferr, berr, info,
            optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
