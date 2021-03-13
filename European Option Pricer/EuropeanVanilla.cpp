//
//  EuropeanVanilla.cpp
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#include "EuropeanVanilla.h"

double EuropeanVanilla::PDF(double x) const // probability density function
{
    const double PI = atan(1.0) * 4;
    return (1.0/sqrt(2.0 * PI)) * exp(-0.5 * x * x);
}

double EuropeanVanilla::CDF(double x) const // return cdf of standard normal distribution
{
    return erfc(-x / sqrt(2.0)) * 0.5;
}

double EuropeanVanilla::DPlus() const
{
    return (log(StockPrice / StrikePrice) + (AnnualInterestRate + 0.5 * pow(Volatility,2.0)) * YearsToExpiry) /(Volatility * sqrt(YearsToExpiry));
}

double EuropeanVanilla::DMinus() const
{
    return DPlus() - Volatility * sqrt(YearsToExpiry);
}
