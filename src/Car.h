//
// Created by elGrando on 04.12.2020.
//

#ifndef IMS_2020_CAR_H
#define IMS_2020_CAR_H

#include <simlib.h>
#include <src/input_data/input_data.h>

class Car : public Process{

public:
    explicit Car(input_data data);

    void Behavior() override;

private:
    input_data data;
};


#endif //IMS_2020_CAR_H