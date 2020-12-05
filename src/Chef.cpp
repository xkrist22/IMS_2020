//
// Created by elGrando on 04.12.2020.
//

#include <iostream>
#include "Chef.h"
#include "Order.h"

Chef::Chef(input_data data) : data(data) {
    this->data = data;
}

/**
 * pokud není objednávka, jde si dát pauzu
 * jinak vezme obsadí místo v kuchyni odebere obědnávku z fronty, čeká, vloží objednávku do hotových a aktivuje daší cyklus
 */
void Chef::Behavior() {
    if (data.new_orders->Empty()){
        std::cout << "pausing";
        Activate(Time + data.get_chef_pause());
    }else{
        Enter(*data.kitchen, 1);
        auto *order = dynamic_cast<Order *>(data.new_orders->GetFirst());
        Wait(Normal(data.get_chef_center(), data.get_chef_sigma()));
        Leave(*data.kitchen, 1);
        order->wait_for_delivery();
        std::cout << "order DONE go for another";
        Activate();
    }
}