//
//  EuropeanPut.cpp
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//


#include "EuropeanPut.h"

double EuropeanPut::Payoff(const double S) const // payoff of call option
{
    return fmax(m_K - S, 0); // (K - S)+
}
