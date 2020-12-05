#include "car_interruption.h"
#include "intern_time/intern_time.h"
#include "Refuel.h"


car_interruption::car_interruption(input_data data) : data(data) {
    this->data = data;
}

void car_interruption::Behavior() {
	(new Refuel(data))->Activate();
}

