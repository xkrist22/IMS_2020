/**
 * @file input_data.h
 * @author Jiri Kristof (xkrist22@stud.fit.vutbr.cz)
 * @author Petr Ceska (xceska05@stud.fit.vutbr.cz)
 * FIT VUT IMS project – food delivery model
 *
 * File contains class function
 */

#ifndef input_data_H
#define input_data_H

#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <simlib.h>
//#include "simlib/src/simlib.h"

/* ***************
 * INPUT DATA CONSTANTS
 * ***************/
#define DIESEL 0
#define GASOLINE 1

using namespace std;

/**
 * Class input_data
 *
 * class contains methods for getting data from user input, ...
 */
class input_data {
public:
	/**
	 * Method for parsing data from terminal into object
	 * @param args data from terminal
	 */
	input_data(vector<string> args);

	/**
	 * getter of car type
	 * @return type of car (Diesel or gasoline)
	 */
	int get_car_type();

	/**
	 * Getter of car count
	 * @return number of cars to generate
	 */
	int get_car_num();

    /**
     * Getter of car count
     * @return number of cars to generate
     */
    int get_car_capacity();

	/**
	 * Getter of chef count
	 * @return number of chefs to generate
	 */
	int get_chef_num();

	/**
	 * Getter of center of order divide
	 * @return center of order divide (Exponential)
	 */
	int get_order_center();

	/**
	 * Getter of center of chef divide
	 * @return center of chef divide (Normal)
	 */
	int get_chef_center();

	/**
	 * Getter of dispersion of chef divide
	 * @return dispersion of chef divide (Normal)
	 */
	int get_chef_sigma();

	/**
	 * Getter of time order waits for delivery
	 * @return constant time which order waits for delivery
	 */
	int get_order_wait();

	/**
	 * Getter of center of car delivery divide
	 * @return center of car delivery divide (Normal)
	 */
	int get_car_delivery_center();

	/**
	 * Getter of disperse of car delivery divide
	 * @return disperse of car delivery divide (Normal)
	 */
	int get_car_delivery_sigma();

	/**
	 * Getter of center of car refuel divide
	 * @return center of car refuel divide (Normal)
	 */
	int get_car_refuel_center();

	/**
	 * Getter of disperse of car refuel divide
	 * @return disperse of car refuel divide (Normal)
	 */
	int get_car_refuel_sigma();

    /**
     * Getter of simulation end time
     * @return end time of simulation
     */
    int get_stop_time();

    /**
     * Getter of simulation start time
     * @return start time of simulation
     */
    int get_start_time();

    /**
     * Getter of day numbers
     * @return number of days in simulation
     */
    int get_day_num();

	/**
	 * Getter of chef pause time
	 * @return constant time representing pause for chef
	 */
    int get_chef_pause();

    /**
     * Getter of interval between pauses
     * @return constant time representing interval between pauses
     */
	int get_pause_interval();

	/**
	 * Getter of center of earnings divide
	 * @return center of earnings divide (Normal)
	 */
	int get_earnings_center();

	/**
	 * Getter of center of earnings disperse
	 * @return disperse of earnings divide (Normal)
	 */
	int get_earnings_sigma();

	/**
	 * Getter of chefs store
	 * @return store containing chefs
	 */
	Store* get_chefs_store();

	/**
	 * Getter of cars store
	 * @return store containing cars
	 */
	Store* get_cars_store();

private:
	int car_type;
	int car_num;
	int chef_num;
	int chef_center;
	int chef_pause;
	int pause_interval;
	int chef_sigma;
	int order_center;
	int order_wait;
	int car_delivery_center;
	int car_delivery_sigma;
	int car_refuel_center;
	int car_refuel_sigma;
	int car_capacity;
	int stop_time;
	int start_time;
	int earnings_center;
	int earnings_sigma;
	int day_num;
	Store* chefs;
	Store* cars;
};

#endif // input_data_H
