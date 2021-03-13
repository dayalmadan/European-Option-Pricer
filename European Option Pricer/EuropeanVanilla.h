//
//  EuropeanVanilla.h
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#pragma once
#include <cmath>

class EuropeanVanilla
{
    const double mStrikePrice; // strike price of the option
protected:
    double CDF(double x) const; // return cdf of standard normal distribution
    double PDF(double x) const; // pdf of x
    double DPlus() const; // d+ = (log(S0/K) + (r + sigmaˆ2) * T) / (sigma * sqrt(T))
    double DMinus() const; // d- = d+ - sigma * sqrt(T)
    
public:
    virtual double OptionPrice() const = 0; // black scholes option pricing calculation
    virtual double OptionDelta() const = 0; // delta of option using BS
    virtual double OptionGamma() const = 0; // gamme using BS
    virtual double OptionTheta() const = 0; // theta using BS
};
