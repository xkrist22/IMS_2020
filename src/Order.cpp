#include <iostream>

#include "Order.h"
#include "intern_time/intern_time.h"

using namespace std;

double Order::fuel = 0;
double Order::chef_work_time = 0;
bool Order::fuel_init = false;
bool Order::time_init = false;

Order::Order(input_data data) : data(data) {
	this->data = data;
	if (data.get_car_type() == DIESEL && !Order::fuel_init) {
		Order::fuel = DIESEL_TANK;
		Order::fuel_init = true;
	} else if (data.get_car_type() == GASOLINE && !Order::fuel_init) {
		Order::fuel = GASOLINE_TANK;
		Order::fuel_init = true;
	}
	if (!Order::time_init) {
		Order::chef_work_time = intern_time::in_minutes(data.get_pause_interval());
		Order::time_init = true;
	}
}

void Order::Behavior() {
	// save income time
    this->income = Time;

    // waiting for chef
    Enter(*this->data.get_chefs_store(), 1);
    // cooking

    double cooking_time = -1;
    // force Normal to generate positive number
	int i = 0;
	while (cooking_time <= 0) {
    	cooking_time = Normal(intern_time::in_minutes(this->data.get_chef_center()), intern_time::in_minutes(this->data.get_chef_sigma()));
		i++;
		if (i > FORCE_ATTEMPS) {
			cerr << "Unable to generate positive number using Normal divide\n";
			exit(1);
		}
	}
    Wait(cooking_time);
	Order::chef_work_time -= cooking_time;
	if (Order::chef_work_time <= 0) {
		(new Pause(data))->Activate();
		Order::chef_work_time = intern_time::in_minutes(this->data.get_pause_interval());
	}
    // cooked
    Leave(*this->data.get_chefs_store(), 1);

    // if there is no car, order is waiting
	if (this->data.get_cars_store()->Used() == this->data.get_car_num()) {
		int i = 0;
		while (i < intern_time::in_seconds(this->data.get_order_wait_time())) {
			// every second check car store
			Wait(intern_time::in_seconds(1));
			if (! this->data.get_cars_store()->Used() == this->data.get_car_num()) {
				// order will be delivered be restaurant
				break;
			}
			i++;
		}
		// order is delivered by external service
		if (this->data.get_cars_store()->Used() == this->data.get_car_num()) {
			return;
		}
	}

	// order is loaded into car
	Enter(*this->data.get_cars_store(), 1);
	// food is delivered
	double delivery_time = -1;
	// force Normal to generate positive number
	i = 0;
	while (delivery_time <= 0) {
		delivery_time =	Normal(intern_time::in_minutes(this->data.get_car_delivery_center()), intern_time::in_minutes(this->data.get_car_delivery_sigma()));
		i++;
		if (i > FORCE_ATTEMPS) {
			cerr << "Unable to generate positive number using Normal divide\n";
			exit(1);
		}
	}
	Wait(delivery_time);

	// count consumption of fuel due to car type
	double consumption;
	if (this->data.get_car_type() == DIESEL) {
		consumption = (DIESEL_CONSUMPTION * (CITY_SPEED * intern_time::to_hours(delivery_time))) / REFERENCE_DISTANCE;
	} else {
		consumption = (GASOLINE_CONSUMPTION * (CITY_SPEED * intern_time::to_hours(delivery_time))) / REFERENCE_DISTANCE;
	}

	// simulate consumption
	Order::fuel -= consumption;
	if (Order::fuel <= 0) {
		// go for fuel
		(new Refuel(data))->Activate();
		if (data.get_car_type() == DIESEL) {
			Order::fuel = DIESEL_TANK;
		} else {
			Order::fuel = GASOLINE_TANK;
		}
	}
	// car returns to restaurant
	Leave(*this->data.get_cars_store(), 1);
}

