#include "chew_interruption.h"
#include "intern_time/intern_time.h"
#include "Pause.h"


chew_interruption::chew_interruption(input_data data) : data(data) {
    this->data = data;
}

void chew_interruption::Behavior() {
	(new Pause(data))->Activate();
    Activate(Time + intern_time::in_minutes(data.get_pause_interval()));
}