#ifndef _GAMMAPRIOR_H
#define _GAMMAPRIOR_H

#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]

double GammaPrior(IntegerVector gamma, int p, int q) {
	IntegerVector ind(p);
	ind[gamma[Range(0,p-1)]>0]=1;
	int pvar = sum(ind);
	double pr;
	if(q > 0.5){
  	pr = Rf_lbeta(pvar+sum(gamma[Range(p,p+q-1)]==1)+1,p+q-pvar-sum(gamma[Range(p,p+q-1)]==1)+1)-pvar*log(2);
	}else{
	  pr = Rf_lbeta(pvar+1,p+pvar+1)-pvar*log(2);
	}
	return pr;
}

#else
#endif
