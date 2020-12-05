
#ifndef IMS_2020_SHIFT_H
#define IMS_2020_SHIFT_H

#include "input_data/input_data.h"
#include "simlib.h"
#include "Order.h"

class Shift : public Event {

public:
    explicit Shift(input_data data);

    void Behavior() override;

private:
    input_data data;
};


#endif //IMS_2020_SHIFT_H
