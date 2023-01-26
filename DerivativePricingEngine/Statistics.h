//
//  Statistics.h
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/26/23.
//

#ifndef Statistics_h
#define Statistics_h

#include <cmath>
#include <vector>

using namespace std;


class StatisticalDistribution
{
public :
    StatisticalDistribution();
    virtual ~StatisticalDistribution();
    
    // Distribution Functions
    virtual double pdf(const double&) const = 0;
    virtual double cdf(const double&) const = 0;
    
    // Inverse CDF (Quantile Function)
    virtual double inv_cdf(const double&) const = 0;
    
    // Descriptive Statistics
    virtual double mean() const = 0;
    virtual double var() const = 0;
    virtual double std() const = 0;
    
    // Obtain a sequence of random draws from this distribution
    virtual void random_draws(const vector<double> &uniform_draws, vector<double> dist_draws) = 0;
 
    
};

class StandardNormalDistribution : public StatisticalDistribution
{
    StandardNormalDistribution();
    virtual ~StandardNormalDistribution();
    
    // Distribution Functions
    virtual double pdf(const double&) const ;
    virtual double cdf(const double&) const ;
    
    // Inverse CDF (Probit Function)
    virtual double inv_cdf(const double& quantile) const;
    
    // Descriptive Statistics
    virtual double mean() const ; // equal to 0
    virtual double var() const ; // equal to 1
    virtual double std() const ; // equal to 1
    
    // Obtain a sequence of random draws from the standard normal distribution distribution
    virtual void random_draws(const vector<double> &uniform_draws, vector<double> dist_draws) = 0;
    
    
};

#endif /* Statistics_h */


