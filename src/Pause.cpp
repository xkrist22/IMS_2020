#include "Pause.h"
#include "intern_time/intern_time.h"
#include "input_data/input_data.h"
#include <iostream>

using namespace std;

vector<double> Pause::pause_times;


Pause::Pause(input_data data) : data(data) {
    this->data = data;
    this->income = 0;
}

void Pause::Behavior() {
    // save income time
    this->income = Time;

    // pause has priority
    Priority = 1;
    // enter store of chefs
    Enter(*this->data.get_chefs_store(), 1);
    Pause::pause_times.push_back(Time);
    // chef has a pause
    Wait(intern_time::in_minutes(this->data.get_chef_pause()));
    // end of pause
    Leave(*this->data.get_chefs_store(), 1);
    Priority = 0;
}
