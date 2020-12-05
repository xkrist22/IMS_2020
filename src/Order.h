
#ifndef IMS_2020_ORDER_H
#define IMS_2020_ORDER_H

#include <simlib.h>
#include <src/input_data/input_data.h>

class Order : public Process {

public:
    explicit Order(input_data data);

    void Behavior() override;

    void wait_for_delivery();

    void wait_for_making();

private:
    input_data data;
};

#endif //IMS_2020_ORDER_H
