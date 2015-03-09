#include <iostream>
#include "haversine_distance.h"

using namespace std;

int main()
{
	HaversineDistance hav;
	pair<double, double> parisLocation = make_pair(48.856578, 2.351828); // lat, lon
	pair<double, double> sfLocation = make_pair(37.779276, 122.419232);
	// double distanceParisSF = hav.computeDistance(48.856578, 2.351828, 
	// 											 37.779276, 122.419232);
	double distanceParisSF = hav.computeDistance(parisLocation.first,
												 parisLocation.second,
												 sfLocation.first,
												 sfLocation.second);
	cout 	<< "The distance between Paris and San Francisco is " 
			<< distanceParisSF 
			<< "km." 
			<< endl;
	return 0;
}