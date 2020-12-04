#include <iostream>
#include <string>
#include "input_data.h"

using namespace std;

input_data::input_data(vector<string> args) {
	for (int i = 1; i < args.size(); i += 2) {
		if (args[i] == "-car-type") {
			if (args[i + 1] == "diesel") {
				this->car_type = DIESEL;
			} else if (args[i + 1] == "gasoline") {
				this->car_type = GASOLINE;
			} else {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-car-num") {
			try {
				this->car_num = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-chew-num") {
			try {
				this->chew_num = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-chew-center") {
			try {
				this->chew_center = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-chew-sigma") {
			try {
				this->chew_sigma = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-order-center") {
			try {
				this->order_center = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-order-sigma") {
			try {
				this->order_sigma = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-order-wait") {
			try {
				this->order_wait = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-car-delivery-center") {
			try {
				this->car_delivery_center = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-car-delivery-sigma") {
			try {
				this->car_delivery_sigma = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-car-refuel-center") {
			try {
				this->car_refuel_center = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-car-refuel-sigma") {
			try {
				this->car_refuel_sigma = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else if (args[i] == "-stop-time") {
			try {
				this->stop_time = stoi(args[i + 1]);
			} catch (const exception& e) {
				cerr << "Invalid parameter";
				exit(1);
			}
		} else {
			; // todo print help
		}
	}
}

int input_data::get_car_type() {
	return this->car_type;
}

int input_data::get_car_num() {
	return this->car_num;
}

int input_data::get_chef_num() {
	return this->chew_num;
}

int input_data::get_order_center() {
	return this->order_center;
}

int input_data::get_chew_center() {
	return this->order_sigma;
}

int input_data::get_chew_sigma() {
	return this->chew_sigma;
}

int input_data::get_order_wait_time() {
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
