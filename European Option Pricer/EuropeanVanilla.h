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
    //const double mStrikePrice; // strike price of the option
protected:
    double CDF(double x) const; // return cdf of standard normal distribution
    double PDF(double x) const; // pdf of x
    double DPlus() const; // d+ = (log(S0/K) + (r + sigmaˆ2) * T) / (sigma * sqrt(T))
    double DMinus() const; // d- = d+ - sigma * sqrt(T)
    
public:
    double CallPrice() const; // call price using BSM model
    double PutPrice() const; // put price using BSM model
    double OptionDelta() const; // delta of option using BS
    double OptionGamma() const; // gamme using BS
    double OptionTheta() const; // theta using BS
};
