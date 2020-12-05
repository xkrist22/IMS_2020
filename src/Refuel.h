
#ifndef IMS_2020_REFUEL_H
#define IMS_2020_REFUEL_H

#include <simlib.h>
#include "input_data/input_data.h"

class Refuel : public Process {

public:
    explicit Refuel(input_data data);

    void Behavior() override;
private:
    input_data data;
    double income;
};

#endif //IMS_2020_REFUEL_H
