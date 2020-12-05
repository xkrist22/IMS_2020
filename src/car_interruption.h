
#ifndef IMS_2020_CAR_INTERRUPTION_H
#define IMS_2020_CAR_INTERRUPTION_H

#include "input_data/input_data.h"
#include "simlib.h"
#include "Order.h"



class car_interruption : public Event {

public:
    explicit car_interruption(input_data data);

    void Behavior() override;

private:
    input_data data;
};


#endif //IMS_2020_CAR_INTERRUPTION_H
