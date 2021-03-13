//
//  EuropeanCall.cpp
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#include "EuropeanCall.h"

double EuropeanCall::Payoff(const double S) const // payoff of call option
{
    return fmax(S - m_K, 0); // (S - K)+
}
