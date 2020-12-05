#include "Shift.h"
#include "intern_time/intern_time.h"
#include "Order.h"


Shift::Shift(input_data data) : data(data) {
    this->data = data;
}

void Shift::Behavior() {
	(new Order(data))->Activate();
    Activate(Time + Exponential(intern_time::in_minutes(data.get_order_center())));
}