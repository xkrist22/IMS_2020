
#include "Shift.h"
#include "Car.h"


Shift::Shift(input_data data) : data(data) {
    this->data = data;

    for (int i = 0; i < this->data.get_chef_num(); i++) { //initialize all chefs
        this->chefs.push_back(new Chef(data));
    }

    for (int i = 0; i < this->data.get_car_num(); i++) {  //initialize all cars
        this->cars.push_back(new Car(data));
    }
}

/**
 * Vygeneruje objednávku a zahájí exponenciální čekání
 */
void Shift::Behavior() {
    {
        (new Order(data))->Activate();
        Activate(Time + Exponential(data.get_order_center()));
    }
}