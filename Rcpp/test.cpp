#include <Rcpp.h>
using namespace Rcpp;


NumericMatrix mmult(NumericMatrix m, NumericMatrix v)
{
  Environment base("package:base");
  Function mat_Mult = base["%*%"];
  return(mat_Mult(m, v));
}

// [[Rcpp::export]]
NumericMatrix m(NumericMatrix A, NumericMatrix B){
  NumericMatrix C = mmult(A, B);
  
  return C;
}

// [[Rcpp::export]]
NumericVector expRcpp(NumericVector X)
{
  NumericVector Y = exp(X);
  return Y;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//


