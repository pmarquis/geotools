#include <iostream>
#include <math.h>
#include "haversine_distance.h"

const double earth = 6378.135;  // in km
const double PI    = 4.0 * atan(1.0);

double HaversineDistance::computeDistance(double lat1, double long1, double lat2, double long2)
{
    double radLat1  = lat1 * (PI / 180);
    double radlong1 = long1 * (PI / 180);
    double radLat2  = lat2 * (PI / 180);
    double radlong2 = long2 * (PI / 180);

    double dLong = radlong1 - radlong2;
    double dLat  = radLat1 - radLat2;

    double aHarv = pow(sin(dLat / 2.0), 2.0) + cos(radLat1) * cos(radLat2) * pow(sin(dLong / 2), 2);
    double cHarv = 2 * atan2(sqrt(aHarv), sqrt(1.0 - aHarv));
    double distance = earth * cHarv;
    return distance;
}

double HaversineDistance::computeDistance(std::pair<double, double>& location1, std::pair<double, double>& location2)
{
    return computeDistance(location1.first, location1.second, location2.first, location2.second);
}

