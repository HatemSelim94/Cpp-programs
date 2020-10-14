#ifndef FILTER_FUNCTIONS_INCLUDED
#define FILTER_FUNCTIONS_INCLUDED
// functions
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>
#include "filter_functions.hpp"

using namespace std; 
vector <double> sense(vector <double> p ,string Z, vector <string> world, const float pHit, const float pMiss );
vector <double> move(vector <double> p, const int U, const float pExact, const float pOvershoot,const float pUndershoot);
#endif // FILTER_FUNCTIONS_INCLUDED