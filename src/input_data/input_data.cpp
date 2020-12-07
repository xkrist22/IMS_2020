#include <iostream>
#include <string>
#include "input_data.h"

using namespace std;

input_data::input_data(vector<string> args) {
    //DEFAULT VALUES



    car_type = DIESEL;
    car_num = 1;
    chef_num = 2;
    chef_center = 15;
    chef_pause = 5;
    pause_interval = 60;
    chef_sigma = 2;
    order_center = 10;
    order_wait = 30;
    car_delivery_center = 10;
    car_delivery_sigma = 3;
    car_refuel_center = 8;
    car_refuel_sigma = 1;
    car_capacity = 1;
    stop_time = 9;
    start_time = 21;
    earnings_center = 90;
    earnings_sigma = 5;
    day_num = 0;
    deliverer_salary = 250;
    chefs_salary = 300;
    monthly_car_expenses = 2000;

    for (int i = 1; i < args.size(); i += 2) {
        if (args[i] == "-car-type") {
            if (args[i + 1] == "diesel") {
                this->car_type = DIESEL;
            } else if (args[i + 1] == "gasoline") {
                this->car_type = GASOLINE;
            } else {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-car-num") {
            try {
                this->car_num = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-chef-num") {
            try {
                this->chef_num = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-chef-pause") {
            try {
                this->chef_pause = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-chef-center") {
            try {
                this->chef_center = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-chef-sigma") {
            try {
                this->chef_sigma = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-order-center") {
            try {
                this->order_center = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-order-wait") {
            try {
                this->order_wait = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-car-delivery-center") {
            try {
                this->car_delivery_center = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-car-delivery-sigma") {
            try {
                this->car_delivery_sigma = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-car-refuel-center") {
            try {
                this->car_refuel_center = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-car-refuel-sigma") {
            try {
                this->car_refuel_sigma = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-car-capacity") {
            try {
                this->car_capacity = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-pause-interval") {
            try {
                this->pause_interval = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-start-time") {
            try {
                this->start_time = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-day-num") {
            try {
                this->day_num = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-stop-time") {
            try {
                this->stop_time = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-earnings-center") {
            try {
                this->earnings_center = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-earnings-sigma") {
            try {
                this->earnings_sigma = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-monthy-car-expenses") {
            try {
                this->monthly_car_expenses = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-chefs-salary") {
            try {
                this->chefs_salary = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else if (args[i] == "-deliverers-salary") {
            try {
                this->deliverer_salary = stoi(args[i + 1]);
            } catch (const exception &e) {
                cerr << "Invalid value of parameter " << args[i];
                exit(1);
            }
        } else {
            cerr << "Invalid parameter " << args[i] << "\n";
            cerr << "FOOD DELIVERY MODEL\n";
            cerr << "Params:\n";
            cerr << "\t-car-type: define type of delivery car, can be \"diesel\" or \"gasoline\"\n";
            cerr << "\t-car-num: number of delivering car\n";
            cerr << "\t-car-capacity: number of orders car can take\n";
            cerr << "\t-chef-num: number of chefs\n";
            cerr << "\t-chef-pause: constant time of chefs pauses [min]\n";
            cerr << "\t-pause-interval: interval between two pauses [min]\n";
            cerr << "\t-chef-center: center of normal divide for cooking time [min]\n";
            cerr << "\t-chef-sigma: disperse of normal divide for cooking time [min]\n";
            cerr << "\t-order-center: center of exponential divide for order generating time [min]\n";
            cerr << "\t-order-wait: after this time food will be passed to external delivery service [min]\n";
            cerr << "\t-car-delivery-center: center of normal divide for delivery time [min]\n";
            cerr << "\t-car-delivery-sigma: disperse of normal divide for delivery time [min]\n";
            cerr << "\t-car-refuel-center: center of normal divide for break time [min]\n";
            cerr << "\t-car-refuel-sigma: disperse of normal divide for break time [min]\n";
            cerr << "\t-stop-time: restaurant closing hour (should be in interval 0-24) [hour]\n";
            cerr << "\t-start-time: restaurant opening hour (should be in interval 0-24) [hour]\n";
            cerr << "\t-day-num: numbers of simulation days\n";
            cerr << "\t-earnings-center: center of normal divide for earnings [any currency]\n";
            cerr << "\t-earnings-sigma: sigma of normal divide for earnings [any currency]\n";
            cerr << "\t-monthly-car-expenses: cost of car maintenance for one month\n";
            cerr << "\t-chefs-salary: supergross wage of chefs per hour [any currency]\n";
            cerr << "\t-earnings-sigma: supergross wage of deliverers per hour [any currency]\n";
        }
    }
    this->chefs = new Store("chefs", this->get_chef_num());
    this->cars = new Store("cars", this->get_car_num());
}

int input_data::get_car_type() {
    return this->car_type;
}

int input_data::get_car_num() {
    return this->car_num;
}

int input_data::get_car_capacity() {
    return this->car_num;
}

int input_data::get_chef_num() {
    return this->chef_num;
}

int input_data::get_chef_pause() {
    return this->chef_pause;
}

int input_data::get_order_center() {
    return this->order_center;
}

int input_data::get_chef_center() {
    return this->chef_center;
}

int input_data::get_chef_sigma() {
    return this->chef_sigma;
}

int input_data::get_order_wait() {
    return this->order_wait;
}

int input_data::get_car_delivery_center() {
    return this->car_delivery_center;
}

int input_data::get_car_delivery_sigma() {
    return this->car_delivery_sigma;
}

int input_data::get_car_refuel_center() {
    return this->car_refuel_center;
}

int input_data::get_car_refuel_sigma() {
    return this->car_refuel_sigma;
}

int input_data::get_stop_time() {
    return this->stop_time;
}

int input_data::get_start_time() {
    return this->start_time;
}

int input_data::get_day_num() {
    return this->day_num;
}

int input_data::get_pause_interval() {
    return this->pause_interval;
}

int input_data::get_earnings_center() {
    return this->earnings_center;
}

int input_data::get_earnings_sigma() {
    return this->earnings_sigma;
}


Store *input_data::get_chefs_store() {
    return this->chefs;
}

Store *input_data::get_cars_store() {
    return this->cars;
}

int input_data::get_chefs_salary() {
    return this->chefs_salary;
}

int input_data::get_deliverers_salary() {
    return this->deliverer_salary;
}

int input_data::get_monthly_car_expenses() {
    return this->monthly_car_expenses;
}