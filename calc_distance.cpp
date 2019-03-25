// calc_distance.cpp
#include <iostream>
#include <cmath>
#include <string>
#include "calc_distance.hpp"


// let lat1 be the latitude of the first location
// let lat2 be the latitude of the second location
// let lon1 be the longitude of the first location
// let lon2 be the longitude of the second location
// let dlat be the difference in latitudes between the locations
// let dlon be the difference in longitudes between the locations
float distance(float lat1, float lon1, float lat2, float lon2) // used in finding_closest_to_farthest
{
	float dlat;
	float dlon;
	float a;
	float c;
	float d;


	double n = M_PI/180; // convert to radians
	dlat = (lat1 * n - lat2 * n);
	dlon = (lon1 * n - lon2 * n);

	a = pow(sin(dlat/2), 2) + cos(n * lat1) * cos(n * lat2) * pow(sin(dlon/2), 2);
	c = 2 * atan2(sqrt(a), sqrt(1 - a));
	d = 3959.9 * c;        // 3959.0, in this part of the formula, is the radius of the Earth
	return d;
}
