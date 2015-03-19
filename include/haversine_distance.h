#ifndef __HAVERSINE_DISTANCE_H_INCLUDED__
#define __HAVERSINE_DISTANCE_H_INCLUDED__

class HaversineDistance
{
public:
	// double computeDistance(double lat1, double long1, double lat2, double long2);
	double computeDistance(double, double, double, double);
	double computeDistance(std::pair<double, double>& location1, std::pair<double, double>& location2);
};

#endif // __HAVERSINE_DISTANCE_H_INCLUDED__