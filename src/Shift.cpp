#include <iostream>
#include "Shift.h"
#include "intern_time/intern_time.h"
#include "Order.h"

using namespace std;

Shift::Shift(input_data data) : data(data) {
    this->data = data;
}

void Shift::Behavior() {
	// get time of generating in interal 0-24
	double check_time = Time;
	while (intern_time::to_seconds(check_time) > intern_time::in_days(1)) {
		check_time -= intern_time::in_days(1);
	}

	// if time is after stop time, suppress generating of order
	if (intern_time::to_seconds(check_time) < intern_time::in_hours(this->data.get_start_time())) {
		// try to generate new orders when restaurant opens
		Activate(Time + intern_time::in_hours(data.get_start_time()) - intern_time::to_seconds(check_time));
		return;
	}

    (new Order(data))->Activate();
    Activate(Time + Exponential(intern_time::in_minutes(data.get_order_center())));
}

void Shift::print_head() {
    cout << "FOOD DELIVERY MODEL\n";
    cout << "Simulation params:\n";
    cout << "car type: " << data.get_car_type() << endl;
    cout << "car num: " << data.get_car_num() << endl;
    cout << "car delivery center: " << data.get_car_delivery_center() << endl;
    cout << "car delivery sigma: " << data.get_car_delivery_sigma() << endl;
    cout << "car refuel center: " << data.get_car_refuel_center() << endl;
    cout << "car refuel sigma: " << data.get_car_refuel_sigma() << endl;
    cout << "car capacity: " << data.get_car_capacity() << endl;
    cout << "chef num: " << data.get_chef_num() << endl;
    cout << "chef center: " << data.get_chef_center() << endl;
    cout << "chef sigma: " << data.get_chef_sigma() << endl;
    cout << "chef pause: " << data.get_chef_pause() << endl;
    cout << "chef pause interval: " << data.get_pause_interval() << endl;
    cout << "order center: " << data.get_order_center() << endl;
    cout << "order wait: " << data.get_order_wait() << endl;
    cout << "stop time: " << data.get_stop_time() << endl;
    cout << "start time: " << data.get_start_time() << endl;
	cout << "day num: " << data.get_day_num() << endl;
	cout << "earnings center: " << data.get_earnings_center() <<endl;
	cout << "earnings sigma: " << data.get_earnings_sigma() <<endl;
}

void Shift::print_stats() {

//        cout << << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "-----------------------------------------------" << endl;

    int orders_extern = Order::external_delivery_times.size();
    int orders_intern = Order::internal_delivery_times.size();
    cout << "Shifts duration: " << ((this->data.get_stop_time() - this->data.get_start_time()) * this->data.get_day_num())
    	 << " hours [from: " << intern_time::print_time(intern_time::in_hours(this->data.get_start_time())) << " to: "
         << intern_time::print_time(intern_time::in_hours(this->data.get_stop_time())) <<  "; "
         << this->data.get_day_num() << " days]" << endl;
    cout << "-----------------------------------------------" << endl;

    cout << "Total number of orders: " + to_string(orders_extern + orders_intern) << endl;
    cout << "-----------------------------------------------" << endl;

    cout << "Delivered by restaurant: " + to_string(orders_intern) << endl;
//    cout << "Minimální čas: " + to_string(Order::internal_delivery_times) << endl;
//    cout << "Maximální čas: " + to_string(orders_intern) << endl;
//    cout << "Průměrný čas: " + to_string(orders_intern) << endl;


    cout << "-----------------------------------------------" << endl; //TODO min, max, avg

    cout << "Delivered by external service: " + to_string(orders_extern) << endl;

    cout << "-----------------------------------------------" << endl;

    cout << "Chefs had " + to_string(Pause::pause_times.size()) + " pauses" << endl << "In times:" << endl;
    for (int i = 0; i < Pause::pause_times.size(); ++i) {
        cout << intern_time::print_time(Pause::pause_times[i]) << "  ||  ";
    }
    cout << endl << "-----------------------------------------------" << endl;

    cout << "Drivers went " + to_string(Refuel::refuel_times.size()) + "x for fuel" << endl << "In times:" << endl;
    for (int i = 0; i < Refuel::refuel_times.size(); ++i) {
        cout << intern_time::print_time(Refuel::refuel_times[i]) << "  ||  ";
    }
    cout << endl << "-----------------------------------------------" << endl;

    cout << "Restaurant earns " << Order::earnings << " (gross earnings)" << endl;
	cout << "Restaurant paid " << Order::fee << " to external delivery service" << endl;
	cout << "Restaurant paid " << Order::fuel_price << " for fuel" << endl;
	cout << "Restaurant earns " << Order::earnings - Order::fee - Order::fuel_price << " (net earnings)" << endl;

	cout << "-----------------------------------------------" << endl;

}