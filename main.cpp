#include <iostream>
#include <string>
#include <cmath>
#include "calc_distance.hpp"
#include "finding_closest_to_farthest.hpp"

//  NOTE TO SELF, FINISHED TURNING THE EWNS into positive/negative.
// work on loop that calculates distance the amount of times there are locations


int main()
{


	std::string starting_location;
	std::string lat1;
	std::string lon1;
	
	// get information about starting location
	getline(std::cin, lat1, ' '); 
	getline(std::cin, lon1, ' ');
	getline(std::cin, starting_location);

	// determine number of locations
	std::string num_of_locations;
	getline(std::cin, num_of_locations);
	
	// prints all output needed
	closest_and_farthest(num_of_locations, starting_location, lat1, lon1);




    return 0;
}

