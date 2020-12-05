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
	input_data(vector<string> args);

	int get_car_type();

	int get_car_num();

	int get_workplaces();

	int get_chef_num();

	int get_order_center();

	int get_chef_center();

	int get_chef_sigma();

	int get_order_wait_time();

	int get_car_delivery_center();

	int get_car_delivery_sigma();

	int get_car_refuel_center();

	int get_car_refuel_sigma();

	int get_stop_time();

    int get_chef_pause();

	int get_pause_interval();

	int get_car_refuel_after();

	string get_output_file();

	Store* get_chefs_store();

	Store* get_cars_store();

private:
	int car_type;
	int car_num;
	int workplaces;
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
	int car_refuel_after;
	string output_file;
	Store* chefs;
	Store* cars;
};

#endif // input_data_H
