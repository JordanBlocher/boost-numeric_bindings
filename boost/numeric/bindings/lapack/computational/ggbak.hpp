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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_GGBAK_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_GGBAK_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
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
    inline void ggbak( const char job, const char side, const integer_t n,
            const integer_t ilo, const integer_t ihi, const float* lscale,
            const float* rscale, const integer_t m, float* v,
            const integer_t ldv, integer_t& info ) {
        LAPACK_SGGBAK( &job, &side, &n, &ilo, &ihi, lscale, rscale, &m, v,
                &ldv, &info );
    }
    inline void ggbak( const char job, const char side, const integer_t n,
            const integer_t ilo, const integer_t ihi, const double* lscale,
            const double* rscale, const integer_t m, double* v,
            const integer_t ldv, integer_t& info ) {
        LAPACK_DGGBAK( &job, &side, &n, &ilo, &ihi, lscale, rscale, &m, v,
                &ldv, &info );
    }
    inline void ggbak( const char job, const char side, const integer_t n,
            const integer_t ilo, const integer_t ihi, const float* lscale,
            const float* rscale, const integer_t m, traits::complex_f* v,
            const integer_t ldv, integer_t& info ) {
        LAPACK_CGGBAK( &job, &side, &n, &ilo, &ihi, lscale, rscale, &m,
                traits::complex_ptr(v), &ldv, &info );
    }
    inline void ggbak( const char job, const char side, const integer_t n,
            const integer_t ilo, const integer_t ihi, const double* lscale,
            const double* rscale, const integer_t m, traits::complex_d* v,
            const integer_t ldv, integer_t& info ) {
        LAPACK_ZGGBAK( &job, &side, &n, &ilo, &ihi, lscale, rscale, &m,
                traits::complex_ptr(v), &ldv, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct ggbak_impl{};

// real specialization
template< typename ValueType >
struct ggbak_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // templated specialization
    template< typename VectorLSCALE, typename VectorRSCALE, typename MatrixV >
    static void invoke( const char job, const char side, const integer_t ilo,
            const integer_t ihi, const VectorLSCALE& lscale,
            const VectorRSCALE& rscale, MatrixV& v, integer_t& info ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorLSCALE >::value_type, typename traits::vector_traits<
                VectorRSCALE >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorLSCALE >::value_type, typename traits::matrix_traits<
                MatrixV >::value_type >::value) );
        BOOST_ASSERT( job == 'N' || job == 'P' || job == 'S' || job == 'B' );
        BOOST_ASSERT( side == 'R' || side == 'L' );
        BOOST_ASSERT( traits::matrix_num_rows(v) >= 0 );
        BOOST_ASSERT( traits::vector_size(lscale) >=
                traits::matrix_num_rows(v) );
        BOOST_ASSERT( traits::vector_size(rscale) >=
                traits::matrix_num_rows(v) );
        BOOST_ASSERT( traits::matrix_num_columns(v) >= 0 );
        BOOST_ASSERT( traits::leading_dimension(v) >= std::max(1,
                traits::matrix_num_rows(v)) );
        detail::ggbak( job, side, traits::matrix_num_rows(v), ilo, ihi,
                traits::vector_storage(lscale),
                traits::vector_storage(rscale), traits::matrix_num_columns(v),
                traits::matrix_storage(v), traits::leading_dimension(v),
                info );
    }
};

// complex specialization
template< typename ValueType >
struct ggbak_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // templated specialization
    template< typename VectorLSCALE, typename VectorRSCALE, typename MatrixV >
    static void invoke( const char job, const char side, const integer_t ilo,
            const integer_t ihi, const VectorLSCALE& lscale,
            const VectorRSCALE& rscale, MatrixV& v, integer_t& info ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorLSCALE >::value_type, typename traits::vector_traits<
                VectorRSCALE >::value_type >::value) );
        BOOST_ASSERT( job == 'N' || job == 'P' || job == 'S' || job == 'B' );
        BOOST_ASSERT( side == 'R' || side == 'L' );
        BOOST_ASSERT( traits::matrix_num_rows(v) >= 0 );
        BOOST_ASSERT( traits::vector_size(lscale) >=
                traits::matrix_num_rows(v) );
        BOOST_ASSERT( traits::vector_size(rscale) >=
                traits::matrix_num_rows(v) );
        BOOST_ASSERT( traits::matrix_num_columns(v) >= 0 );
        BOOST_ASSERT( traits::leading_dimension(v) >= std::max(1,
                traits::matrix_num_rows(v)) );
        detail::ggbak( job, side, traits::matrix_num_rows(v), ilo, ihi,
                traits::vector_storage(lscale),
                traits::vector_storage(rscale), traits::matrix_num_columns(v),
                traits::matrix_storage(v), traits::leading_dimension(v),
                info );
    }
};


// template function to call ggbak
template< typename VectorLSCALE, typename VectorRSCALE, typename MatrixV >
inline integer_t ggbak( const char job, const char side,
        const integer_t ilo, const integer_t ihi, const VectorLSCALE& lscale,
        const VectorRSCALE& rscale, MatrixV& v ) {
    typedef typename traits::matrix_traits< MatrixV >::value_type value_type;
    integer_t info(0);
    ggbak_impl< value_type >::invoke( job, side, ilo, ihi, lscale,
            rscale, v, info );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
