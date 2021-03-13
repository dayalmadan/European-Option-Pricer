//
//  EuropeanCall.h
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#pragma once

#include "EuropeanVanilla.h"
#include <cmath>

class EuropeanCall:public EuropeanVanilla
{
    const double m_K; // strike price
public:
    EuropeanCall(double K, double T): m_K(K), EuropeanVanilla(T) {};
    
    double Payoff(const double S) const; // payoff of call option
};
