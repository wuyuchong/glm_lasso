#include <Rcpp.h>
using namespace Rcpp;

  
NumericMatrix mmult(NumericMatrix m, NumericMatrix v)
{
  Environment base("package:base");
  Function mat_Mult = base["%*%"];
  return(mat_Mult(m, v));
}

NumericMatrix C(NumericMatrix A, NumericMatrix B)
{
  NumericMatrix C = mmult(A, B);
  return(C);
}


// [[Rcpp::export]]
NumericVector Rcppresp(NumericMatrix x, NumericVector beta, String family) {
  if(family == "logit")
  {
    Environment base("package:base");
    Function mat_Mult = base["%*%"];
    NumericVector eta = mat_Mult(x, beta);
    NumericVector expeta = Rcpp::exp(eta);
    NumericVector mu = expeta / (1 + expeta);
    int n = mu.size();
    Environment stats("package:stats");
    Function rcppbinom = stats["rbinom"];
    return (rcppbinom(n, 1, mu));
  }
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

