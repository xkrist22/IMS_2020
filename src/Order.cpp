
#include "Order.h"

Order::Order(input_data data) : data(data) {
    this->data = data;
}

/**
 * Vloží se nová objednávka do fronty a passivuje se
 */
void Order::Behavior() {
    data.new_orders->Insert(this);
    Passivate();
}