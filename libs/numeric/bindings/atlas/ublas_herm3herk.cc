
// BLAS level 3
// hermitian matrices, herk 

#include <stddef.h>
#include <iostream>
#include <boost/numeric/bindings/blas/level3.hpp>
#include <boost/numeric/bindings/ublas/hermitian.hpp>
#include <boost/numeric/bindings/upper.hpp>
#include <boost/numeric/bindings/lower.hpp>
#include <boost/numeric/bindings/conj.hpp>
#include "utils.h"

namespace ublas = boost::numeric::ublas;
namespace blas = boost::numeric::bindings::blas;
namespace bindings = boost::numeric::bindings;

using std::cout;
using std::cin;
using std::endl; 

typedef double real_t; 
typedef std::complex<real_t> cmplx_t; 

typedef ublas::matrix<cmplx_t, ublas::column_major> cm_t;
typedef ublas::matrix<cmplx_t, ublas::row_major> rm_t;
typedef ublas::hermitian_adaptor<cm_t, ublas::upper> ucha_t; 
typedef ublas::hermitian_adaptor<cm_t, ublas::lower> lcha_t; 
typedef ublas::hermitian_adaptor<rm_t, ublas::upper> urha_t; 
typedef ublas::hermitian_adaptor<rm_t, ublas::lower> lrha_t; 

#define N 3
#define K 4

int main() {

  cm_t ac (N, K); 
  rm_t ar (N, K); 

  ac(0,0) = ar(0,0) = cmplx_t (1., 1.);
  ac(1,0) = ar(1,0) = cmplx_t (2., 1.);
  ac(2,0) = ar(2,0) = cmplx_t (3., 1.);
#if (K > 1)
  ac(0,1) = ar(0,1) = cmplx_t (1., 1.);
  ac(1,1) = ar(1,1) = cmplx_t (2., 1.);
  ac(2,1) = ar(2,1) = cmplx_t (3., 1.);
#if (K > 2)
  ac(0,2) = ar(0,2) = cmplx_t (1., 1.);
  ac(1,2) = ar(1,2) = cmplx_t (2., 1.);
  ac(2,2) = ar(2,2) = cmplx_t (3., 1.);
#if (K > 3)
  ac(0,3) = ar(0,3) = cmplx_t (1., 1.);
  ac(1,3) = ar(1,3) = cmplx_t (2., 1.);
  ac(2,3) = ar(2,3) = cmplx_t (3., 1.);
#endif
#endif
#endif

  print_m (ac, "ac"); 
  cout << endl; 
  print_m (ar, "ar"); 
  cout << endl << endl;

  cm_t cmu (N, N); 
  cm_t cml (N, N); 
  rm_t rmu (N, N); 
  rm_t rml (N, N); 
  ucha_t ucha (cmu); 
  lcha_t lcha (cml); 
  urha_t urha (rmu); 
  lrha_t lrha (rml); 

  blas::herk (1.0, ac, 0.0, ucha); 
  blas::herk (1.0, ac, 0.0, lcha); 
  blas::herk (1.0, ar, 0.0, urha); 
  blas::herk (1.0, ar, 0.0, lrha); 

  print_m (ucha, "ucha");
  cout << endl; 
  print_m (lcha, "lcha");
  cout << endl; 
  print_m (urha, "urha");
  cout << endl; 
  print_m (lrha, "lrha");
  cout << endl << endl; 

  // part 2

  cm_t act (ublas::herm (ac)); 
  rm_t art (ublas::herm (ar)); 
  print_m (act, "act"); 
  cout << endl; 
  print_m (art, "art"); 
  cout << endl << endl;

  init_m (cmu, const_val<cmplx_t> (cmplx_t (0, 0)));
  init_m (cml, const_val<cmplx_t> (cmplx_t (0, 0)));
  init_m (rmu, const_val<cmplx_t> (cmplx_t (0, 0)));
  init_m (rml, const_val<cmplx_t> (cmplx_t (0, 0)));

  blas::herk ( 1.0, bindings::conj(act), 0.0, bindings::upper(cmu)); 
  blas::herk ( 1.0, bindings::conj(act), 0.0, bindings::lower(cml)); 
  blas::herk ( 1.0, bindings::conj(art), 0.0, bindings::upper(rmu)); 
  blas::herk ( 1.0, bindings::conj(art), 0.0, bindings::lower(rml)); 

  print_m (cmu, "cmu");
  cout << endl; 
  print_m (cml, "cml");
  cout << endl; 
  print_m (rmu, "rmu");
  cout << endl; 
  print_m (rml, "rml");
  cout << endl; 
}

