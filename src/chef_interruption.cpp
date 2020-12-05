#include "chef_interruption.h"
#include "intern_time/intern_time.h"
#include "Pause.h"


chef_interruption::chef_interruption(input_data data) : data(data) {
    this->data = data;
}

void chef_interruption::Behavior() {
		(new Pause(data))->Activate();
}
