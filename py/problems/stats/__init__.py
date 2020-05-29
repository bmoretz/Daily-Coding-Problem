import pandas as pd
import numpy as np
import scipy.stats as st

def distribution_fitting(distribution_code, investments):

    """
    :param distribution_code (string): 'norm', 'cauchy', or 'expon'.
    :param investments: (list) The size of each investment received.
    :returns: (float) Akaike information criterion of the distribution for the dataset.
    """

    def AIC(theoretical, pdf, K):
        # this could probably be vectorized for performance,
        # but this is more readable than a 1 liner
        logLik = 0
        for v in theoretical:
            logLik += np.log( pdf(v) )
        
        return 2*K - 2*(logLik)
    
    def get_parameters(distribution, data):
        # completely generic dist fitting
        params = distribution.fit(data)

        arg = params[:-2]
        loc = params[-2]
        scale = params[-1]
        
        return (loc, scale, arg)

    def get_central_moment_dist_fit(distribution, data):
        
        # extract the parameters from the theoretical fit,
        # scale and center area always index 0 and 1 respectively
        # since they're central moment is 1
        params = get_parameters(distribution, data)
        
        # just make this nicer to read honestly
        mu, sigma = params[0], params[1]

        # generate N theoreticals from using the fitted parameters
        y_hat = distribution.rvs( loc = mu, scale = sigma, \
            size=len(data), random_state=None)
        
        # basically just alias the pdf for the passed in distribution
        pdf = distribution(mu, sigma).pdf

        # AIC will be the calculated with k=2 for all the distributions
        aic = AIC(y_hat, pdf, K=len(params))

        return aic

    distribution = None
    
    try:
        # get the distribution object from the literal code
        distribution = getattr(st, distribution_code)
    except:
        pass
    
    fit_criterion = None

    # any dist that has order of central moment 1
    if distribution is not None and distribution.moment_type == 1:
        fit_criterion = get_central_moment_dist_fit(distribution, investments)

    return fit_criterion