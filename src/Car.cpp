
#include "Car.h"
#include "Order.h"

Car::Car(input_data data) : data(data) {
    this->data = data;
    this->delivered = 0;
}

void Car::Behavior() {
    if (data.waiting_delivery->Empty()){
        take_a_break();
    } else{
        list<Order*> orders;
        while(!data.waiting_delivery->Empty()){
           orders.push_back((Order*) data.waiting_delivery->GetFirst());
        }

        while(!orders.empty()){
            Wait(Normal(data.get_car_delivery_center(), data.get_car_delivery_sigma()));
            delete orders.front();
            orders.pop_front();
            delivered ++;
        }

        if (delivered >= data.get_car_refuel_after()){
            take_a_break();
        } else{
            Activate();
        }
    }
}

void Car::take_a_break(){
    Wait(Normal(data.get_car_refuel_center(), data.get_car_refuel_sigma()));
    Activate();
}