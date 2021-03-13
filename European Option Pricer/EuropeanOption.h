//
//  EuropeanOption.h
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#pragma once

#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "EuropeanVanilla.h"

class EuropeanOption
{
public:
    EuropeanOption(const double UnderlyingPrice, const double StrikePrice, const double InterestRate,  const double DaysToExpiry, const double Volatility, const char CallPut);
};
