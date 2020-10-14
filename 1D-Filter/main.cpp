#include "filter_functions.hpp"


int main(int argc, char const *argv[])
{
    vector <double> p(5,0.2);
    vector <string> world = {"green", "red", "red", "green", "green"};
    vector <string> measurements = {"red", "green"};
    vector <int> motions = {1,1};
    const float pHit = 0.6;
    const float pMiss = 0.2;
    const float pExact = 0.8;
    const float pOvershoot = 0.1;
    const float pUndershoot = 0.1;
    for(int i=0;i <measurements.size();i++)
    {
      p = sense(p, measurements[i],world,pHit, pMiss);
      p = move(p, motions[i], pExact, pOvershoot, pUndershoot);
    }
    for(int i=0; i<p.size();i++)
    {
        cout<<"landmark "<<i+1<<", probability:"<<p[i]<<endl;
    }
    double max_prob = *max_element(p.begin(),p.end());

    auto it = find(p.begin(), p.end(), max_prob); 

    int index = distance(p.begin(), it);

    cout<<"current location:"<<index+1<<", landmark color:"<<world[index]<<endl;
    // print p-color

    return 0;
}
