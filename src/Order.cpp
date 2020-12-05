
#include "Order.h"

Order::Order(input_data data) : data(data) {
    this->data = data;
}

/**
 * Vloží se nová objednávka do fronty a passivuje se
 */
void Order::Behavior() {
    delete(this);
}

void Order::wait_for_making() {
    data.new_orders->Insert(this);
    Passivate();
}
void Order::wait_for_delivery() {
//TODO activate wolt messanger
    data.waiting_delivery->Insert(this);
    Passivate();
}