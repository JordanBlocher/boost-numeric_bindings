//
// Copyright (c) 2009 Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_TNT_FORTRAN_ARRAY1D_HPP
#define BOOST_NUMERIC_BINDINGS_TNT_FORTRAN_ARRAY1D_HPP

#include <boost/numeric/bindings/detail/adaptor.hpp>
#include <tnt_fortran_array1d.h>

namespace boost {
namespace numeric {
namespace bindings {
namespace detail {

template< typename T, typename Id, typename Enable >
struct adaptor< TNT::Fortran_Array1D< T >, Id, Enable > {

    typedef typename copy_const< Id, T >::type value_type;
    typedef mpl::map<
        mpl::pair< tag::value_type, value_type >,
        mpl::pair< tag::entity, tag::vector >,
        mpl::pair< tag::size_type<1>, std::ptrdiff_t >,
        mpl::pair< tag::data_structure, tag::linear_array >,
        mpl::pair< tag::stride_type<1>, tag::contiguous >
    > property_map;

    static std::ptrdiff_t size1( Id const& t ) {
        return t.dim();
    }

    static value_type* data( Id& t ) {
        return &t(1);
    }

};

} // namespace detail
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
