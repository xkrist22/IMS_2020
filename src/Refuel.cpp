#include "Refuel.h"
#include "intern_time/intern_time.h"
#include "input_data/input_data.h"
#include <iostream>
using namespace std;

Refuel::Refuel(input_data data) : data(data) {
    this->data = data;
}

void Refuel::Behavior() {
	// save income time
    this->income = Time;

    // refuel has priority
    Priority = 1;
    // enter store of cars
    Enter(*this->data.get_cars_store(), 1);
    // car has refuel stop
    Wait(Normal(intern_time::in_minutes(this->data.get_car_refuel_center()), intern_time::in_minutes(this->data.get_car_refuel_sigma())));
    // end of refuel
    Leave(*this->data.get_cars_store(), 1);
    Priority = 0;
}
