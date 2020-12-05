#include "Order.h"
#include "intern_time/intern_time.h"
#include <iostream>
using namespace std;

Order::Order(input_data data) : data(data) {
    this->data = data;
}

void Order::Behavior() {
	// save income time
    this->income = Time;

    // waiting for chew
    Enter(*this->data.get_chefs_store(), 1);
    // cooking
    Wait(Normal(intern_time::in_minutes(this->data.get_chef_center()), intern_time::in_minutes(this->data.get_chef_sigma())));
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
	double delivery_time = Normal(intern_time::in_minutes(this->data.get_car_delivery_center()), intern_time::in_minutes(this->data.get_car_delivery_sigma()));
	Wait(delivery_time);
	// car returns to restaurant
	Leave(*this->data.get_cars_store(), 1);
}
