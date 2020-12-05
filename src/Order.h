
#ifndef IMS_2020_ORDER_H
#define IMS_2020_ORDER_H

#include <simlib.h>
#include "input_data/input_data.h"

class Order : public Process {

public:
    explicit Order(input_data data);

    void Behavior() override;
private:
    input_data data;
    double income;
};

#endif //IMS_2020_ORDER_H
