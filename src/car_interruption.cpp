#include "car_interruption.h"
#include "intern_time/intern_time.h"
#include "Refuel.h"


car_interruption::car_interruption(input_data data) : data(data) {
    this->data = data;
}

void car_interruption::Behavior() {
	(new Refuel(data))->Activate();
    Activate(Time + Normal(intern_time::in_minutes(this->data.get_car_refuel_center()), intern_time::in_minutes(this->data.get_car_refuel_sigma())));
}