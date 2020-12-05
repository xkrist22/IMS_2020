
#ifndef IMS_2020_SHIFT_H
#define IMS_2020_SHIFT_H

#include <src/input_data/input_data.h>
#include "simlib.h"
#include "Chef.h"
#include "Car.h"
#include "Order.h"

class Shift : public Event {

public:
    explicit Shift( input_data data);

    void Behavior() override;

private:
    input_data data;
    vector<Chef*> chefs;
    vector<Car*> cars;
};


#endif //IMS_2020_SHIFT_H
