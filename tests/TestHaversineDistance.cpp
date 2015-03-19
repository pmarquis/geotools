#include "TestHaversineDistance.h"
#include <iostream>
#include <cassert>
#include "haversine_distance.h"
    
using namespace std;

const double DISTANCE_PARIS_SF = 8729.25;

/**
*    Test HaversineDistance::computeDistance
**/
void TestHaversineDistance::Test_Distance_SF_Paris()
{
    HaversineDistance hav;
    pair<double, double> parisLocation = make_pair(48.856578, 2.351828);
    pair<double, double> sfLocation = make_pair(37.779276, 122.419232);
    double distanceParisSF = hav.computeDistance(parisLocation, sfLocation); 
    assert((int)distanceParisSF*100 == (int)DISTANCE_PARIS_SF*100);

    distanceParisSF = hav.computeDistance(parisLocation.first, parisLocation.second,
                                          sfLocation.first, sfLocation.second);
    assert((int)distanceParisSF*100 == (int)DISTANCE_PARIS_SF*100);
}
    
    

void TestHaversineDistance::TestAll()
{
    Test_Distance_SF_Paris();
    cout << "OK" 
         << endl;
}