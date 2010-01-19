//
// Copyright (c) 2002--2010
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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_HBGST_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_HBGST_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/bandwidth.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/uplo_tag.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for hbgst is the netlib-compatible backend.
//
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end LAPACK-routine.
//
namespace detail {

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
template< typename UpLo >
inline std::ptrdiff_t hbgst( const char vect, const UpLo uplo,
        const fortran_int_t n, const fortran_int_t ka, const fortran_int_t kb,
        std::complex<float>* ab, const fortran_int_t ldab,
        const std::complex<float>* bb, const fortran_int_t ldbb,
        std::complex<float>* x, const fortran_int_t ldx,
        std::complex<float>* work, float* rwork ) {
    fortran_int_t info(0);
    LAPACK_CHBGST( &vect, &lapack_option< UpLo >::value, &n, &ka, &kb, ab,
            &ldab, bb, &ldbb, x, &ldx, work, rwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
template< typename UpLo >
inline std::ptrdiff_t hbgst( const char vect, const UpLo uplo,
        const fortran_int_t n, const fortran_int_t ka, const fortran_int_t kb,
        std::complex<double>* ab, const fortran_int_t ldab,
        const std::complex<double>* bb, const fortran_int_t ldbb,
        std::complex<double>* x, const fortran_int_t ldx,
        std::complex<double>* work, double* rwork ) {
    fortran_int_t info(0);
    LAPACK_ZHBGST( &vect, &lapack_option< UpLo >::value, &n, &ka, &kb, ab,
            &ldab, bb, &ldbb, x, &ldx, work, rwork, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to hbgst.
//
template< typename Value >
struct hbgst_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixAB, typename MatrixBB, typename MatrixX,
            typename WORK, typename RWORK >
    static std::ptrdiff_t invoke( const char vect, MatrixAB& ab,
            const MatrixBB& bb, MatrixX& x, detail::workspace2< WORK,
            RWORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::uplo_tag< MatrixAB >::type uplo;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixAB >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixBB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename bindings::value_type< MatrixAB >::type >::type,
                typename remove_const< typename bindings::value_type<
                MatrixX >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixAB >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixX >::value) );
        BOOST_ASSERT( bindings::bandwidth(ab, uplo()) >= 0 );
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_rwork( bindings::size_column(ab) ));
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( bindings::size_column(ab) ));
        BOOST_ASSERT( bindings::size_column(ab) >= 0 );
        BOOST_ASSERT( bindings::size_minor(ab) == 1 ||
                bindings::stride_minor(ab) == 1 );
        BOOST_ASSERT( bindings::size_minor(bb) == 1 ||
                bindings::stride_minor(bb) == 1 );
        BOOST_ASSERT( bindings::size_minor(x) == 1 ||
                bindings::stride_minor(x) == 1 );
        BOOST_ASSERT( bindings::stride_major(ab) >= bindings::bandwidth(ab,
                uplo())+1 );
        BOOST_ASSERT( bindings::stride_major(bb) >= bindings::bandwidth(bb,
                uplo())+1 );
        BOOST_ASSERT( vect == 'N' || vect == 'V' );
        return detail::hbgst( vect, uplo(), bindings::size_column(ab),
                bindings::bandwidth(ab, uplo()), bindings::bandwidth(bb,
                uplo()), bindings::begin_value(ab),
                bindings::stride_major(ab), bindings::begin_value(bb),
                bindings::stride_major(bb), bindings::begin_value(x),
                bindings::stride_major(x),
                bindings::begin_value(work.select(value_type())),
                bindings::begin_value(work.select(real_type())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixAB, typename MatrixBB, typename MatrixX >
    static std::ptrdiff_t invoke( const char vect, MatrixAB& ab,
            const MatrixBB& bb, MatrixX& x, minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::uplo_tag< MatrixAB >::type uplo;
        bindings::detail::array< value_type > tmp_work( min_size_work(
                bindings::size_column(ab) ) );
        bindings::detail::array< real_type > tmp_rwork( min_size_rwork(
                bindings::size_column(ab) ) );
        return invoke( vect, ab, bb, x, workspace( tmp_work, tmp_rwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixAB, typename MatrixBB, typename MatrixX >
    static std::ptrdiff_t invoke( const char vect, MatrixAB& ab,
            const MatrixBB& bb, MatrixX& x, optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::uplo_tag< MatrixAB >::type uplo;
        return invoke( vect, ab, bb, x, minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n ) {
        return n;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array rwork.
    //
    static std::ptrdiff_t min_size_rwork( const std::ptrdiff_t n ) {
        return n;
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the hbgst_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for hbgst. Its overload differs for
// * MatrixAB&
// * MatrixX&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixBB, typename MatrixX,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbgst( const char vect, MatrixAB& ab, const MatrixBB& bb, MatrixX& x,
        Workspace work ) {
    return hbgst_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( vect, ab, bb, x, work );
}

//
// Overloaded function for hbgst. Its overload differs for
// * MatrixAB&
// * MatrixX&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixBB, typename MatrixX >
inline typename boost::disable_if< detail::is_workspace< MatrixX >,
        std::ptrdiff_t >::type
hbgst( const char vect, MatrixAB& ab, const MatrixBB& bb, MatrixX& x ) {
    return hbgst_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( vect, ab, bb, x, optimal_workspace() );
}

//
// Overloaded function for hbgst. Its overload differs for
// * const MatrixAB&
// * MatrixX&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixBB, typename MatrixX,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbgst( const char vect, const MatrixAB& ab, const MatrixBB& bb,
        MatrixX& x, Workspace work ) {
    return hbgst_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( vect, ab, bb, x, work );
}

//
// Overloaded function for hbgst. Its overload differs for
// * const MatrixAB&
// * MatrixX&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixBB, typename MatrixX >
inline typename boost::disable_if< detail::is_workspace< MatrixX >,
        std::ptrdiff_t >::type
hbgst( const char vect, const MatrixAB& ab, const MatrixBB& bb,
        MatrixX& x ) {
    return hbgst_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( vect, ab, bb, x, optimal_workspace() );
}

//
// Overloaded function for hbgst. Its overload differs for
// * MatrixAB&
// * const MatrixX&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixBB, typename MatrixX,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbgst( const char vect, MatrixAB& ab, const MatrixBB& bb,
        const MatrixX& x, Workspace work ) {
    return hbgst_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( vect, ab, bb, x, work );
}

//
// Overloaded function for hbgst. Its overload differs for
// * MatrixAB&
// * const MatrixX&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixBB, typename MatrixX >
inline typename boost::disable_if< detail::is_workspace< MatrixX >,
        std::ptrdiff_t >::type
hbgst( const char vect, MatrixAB& ab, const MatrixBB& bb,
        const MatrixX& x ) {
    return hbgst_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( vect, ab, bb, x, optimal_workspace() );
}

//
// Overloaded function for hbgst. Its overload differs for
// * const MatrixAB&
// * const MatrixX&
// * User-defined workspace
//
template< typename MatrixAB, typename MatrixBB, typename MatrixX,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
hbgst( const char vect, const MatrixAB& ab, const MatrixBB& bb,
        const MatrixX& x, Workspace work ) {
    return hbgst_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( vect, ab, bb, x, work );
}

//
// Overloaded function for hbgst. Its overload differs for
// * const MatrixAB&
// * const MatrixX&
// * Default workspace-type (optimal)
//
template< typename MatrixAB, typename MatrixBB, typename MatrixX >
inline typename boost::disable_if< detail::is_workspace< MatrixX >,
        std::ptrdiff_t >::type
hbgst( const char vect, const MatrixAB& ab, const MatrixBB& bb,
        const MatrixX& x ) {
    return hbgst_impl< typename bindings::value_type<
            MatrixAB >::type >::invoke( vect, ab, bb, x, optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
