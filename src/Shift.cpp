#include <iostream>
#include "Shift.h"
#include "intern_time/intern_time.h"
#include "Order.h"

using namespace std;

Shift::Shift(input_data data) : data(data) {
    this->data = data;
}

void Shift::Behavior() {
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

}

void Shift::print_stats() {

//        cout << << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "-----------------------------------------------" << endl;

    int orders_extern = Order::external_delivery_times.size();
    int orders_intern = Order::internal_delivery_times.size();
    cout << "Směna trvala " << (this->data.get_stop_time() - this->data.get_start_time()) << "hodin [od: "
         << intern_time::print_time(intern_time::in_hours(this->data.get_start_time())) << " do: "
         << intern_time::print_time(intern_time::in_hours(this->data.get_stop_time())) <<  "]" << endl;
    cout << "-----------------------------------------------" << endl;

    cout << "Celkový počet objednávek: " + to_string(orders_extern + orders_intern) << endl;
    cout << "-----------------------------------------------" << endl;

    cout << "Doručeno vlastní dopravou: " + to_string(orders_intern) << endl;
//    cout << "Minimální čas: " + to_string(Order::internal_delivery_times) << endl;
//    cout << "Maximální čas: " + to_string(orders_intern) << endl;
//    cout << "Průměrný čas: " + to_string(orders_intern) << endl;


    cout << "-----------------------------------------------" << endl; //TODO min, max, avg

    cout << "Doručeno externí dopravou: " + to_string(orders_extern) << endl;

    cout << "-----------------------------------------------" << endl;

    cout << "Kuchaři měli celkem " + to_string(Refuel::refuel_times.size()) + " přestávek" << endl << "V časech:" << endl;
    for (int i = 0; i < Pause::pause_times.size(); ++i) {
        cout << intern_time::print_time(Pause::pause_times[i]) << "  ||  ";
    }
    cout << endl << "-----------------------------------------------" << endl;

    cout << "Řidiči jeli celkem " + to_string(Pause::pause_times.size()) + "x natankovat" << endl << "V časech:" << endl;
    for (int i = 0; i < Refuel::refuel_times.size(); ++i) {
        cout << intern_time::print_time(Refuel::refuel_times[i]) << "  ||  ";
    }
    cout << endl << "-----------------------------------------------" << endl;

}