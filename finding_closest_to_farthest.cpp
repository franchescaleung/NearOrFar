//  FINDING_CLOSEST_AND_FARTHEST.cpp
#include <iostream>
#include <string>
#include <cmath>
#include "finding_closest_to_farthest.hpp"
#include "calc_distance.hpp"

float str_to_float(std::string s) // private, only used here
{
	
	

	if (s.find("S") == std::string::npos && s.find("W") == std::string::npos)
	{

		return std::stod(s); 	// if not found, return normal
	}
	else
	{
		return std::stod(s) * -1; // return negative if s or w found
	}


}

void closest_and_farthest(std::string num_of_locations, std::string starting_location, std::string lat1, std::string lon1) //public, used in main.cpp
{
	float closest_dis = 0;
	float farthest_dis = 0;
	std::string closest_location_string;
	std::string farthest_location_string;
	float d;
	double nol = std::stod(num_of_locations);
	for (double i = 0; i < nol; i++) // test if each input is greater or smaller than the distances now
	{
		std::string location;
		std::string lat2;
		std::string lon2;
		getline(std::cin, lat2, ' '); 
		getline(std::cin, lon2, ' ');
		getline(std::cin, location);

		d = distance(str_to_float(lat1), str_to_float(lon1), str_to_float(lat2), str_to_float(lon2)); // calc disntance apart
	
		if (closest_dis == 0 && farthest_dis == 0) // make sure that if there is only one other location, it is both farthest and closest
		{
			closest_dis = d;
			closest_location_string = lat2 + " " + lon2 + " (" + location + ")";
			farthest_dis = d;
			farthest_location_string = lat2 + " " + lon2 + " (" + location + ")";

		}
		else if (d < closest_dis)
		{
			closest_dis = d;
			closest_location_string = lat2 + " " + lon2 + " (" + location + ")";
		}
		else if (d > farthest_dis)
		{
			farthest_dis = d;
			farthest_location_string = lat2 + " " + lon2 + " (" + location + ")";
		}


	}
	std::cout << "Start Location: " << lat1 << " " << lon1 << " (" << starting_location << ")" << std::endl;
	std::cout << "Closest Location: " << closest_location_string << " (" << closest_dis <<" miles)" << std::endl;
	std::cout << "Farthest Location: " << farthest_location_string << " (" << farthest_dis <<" miles)" << std::endl;
}