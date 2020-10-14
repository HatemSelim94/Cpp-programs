#include "filter_functions.hpp"

vector <double> sense(const vector <double> p ,const string Z, vector <string> world, const float pHit, const float pMiss )
{
    vector <double> q(p.size(),0);
    bool hit;
    double vec_sum=0;
    for(int i=0;i<p.size();i++)
    {
        hit = (Z==world[i]);
        q[i] = p[i]*(hit*pHit+(1-hit)*pMiss);
        vec_sum += q[i];
    }
    // vec_sum = accumulate(q.begin(),q.end(),0.0);

    for(int i=0;i<q.size();i++)
    {
        q[i] = q[i]/vec_sum;
    }
    return q;
}
// U motion
vector <double> move(vector <double> p, const int U, const float pExact, const float pOvershoot,const float pUndershoot)
{
    vector <double> q(p.size());
    double s = 0; // holds probability values calculated below

    // Calculate new probabilities
    for (int i = 0; i < p.size(); i++) {
        if (i-U < 0) {
            s = pExact * p[(i-U) + p.size()];
        }
        else {
            s = pExact * p[(i-U) % p.size()];
        }
        if (i-U-1 < 0) {
            s = s + pOvershoot * p[(i-U-1) + p.size()];
        }
        else {
            s = s + pOvershoot * p[(i-U-1) % p.size()];
        }
        if (i-U+1 < 0) {
            s = s + pUndershoot * p[(i-U+1) + p.size()];
        }
        else {
            s = s + pUndershoot * p[(i-U+1) % p.size()];
        }

        q[i] = s;
    }
    return q;
}
