#include <iostream>
#include <math.h>

using namespace std;

enum eDistance_Type{
    EUCLIDEAN = 0,
    MANHATTAN = 1,
    DELTA_MAX = 2,
    NB_TYPES  = 3
};

class IDistance {
public:
    virtual double computeDistance(double x1, double y1, double x2, double y2) = 0;
};

class EuclideanDistance: public IDistance
{
public:
    double computeDistance(double x1, double y1, double x2, double y2)
    {
        double square_distance = pow((x2-x1), 2) + pow((y2-y1), 2);
        double distance = sqrt(square_distance);
        return distance;
    }
};

class ManhattanDistance: public IDistance
{
public:
    double computeDistance(double x1, double y1, double x2, double y2)
    {
        double distance = abs(x2-x1) + abs(y2-y1);
        return distance;
    }
};

class DeltaMaxDistance: public IDistance
{
public:
    double computeDistance(double x1, double y1, double x2, double y2)
    {
        double dX = abs(x2 - x1);
        double dY = abs(y2 - y1);
        double distance = 0.0;
        if(dX > dY)
        {
            distance = sqrt(dY * dY) + dX - dY;
        }
        else
        {            
            distance = sqrt(dX * dX) + dY - dX;
        }1);
        return distance;
    }
};

class DistanceFactory
{
public:
    shared_ptr<IDistance> createInstance(eDistance_Type type)
    {
        IDistance *distance = nullptr;
        switch(type)
        {
            case EUCLIDEAN:
                distance = new EuclideanDistance();
                break;
            case MANHATTAN:
                distance = new ManhattanDistance();
                break;
            case DELTA_MAX:
                distance = new DeltaMaxDistance();
                break;
            default:
                   distance = nullptr;
                   break;
        }
        
        if(instance != nullptr)
            return shared_ptr<IDistance>(instance);
        else
            return nullptr;
    }
};
