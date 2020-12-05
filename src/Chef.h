//
// Created by elGrando on 04.12.2020.
//

#ifndef IMS_2020_CHEF_H
#define IMS_2020_CHEF_H

#include <simlib.h>
#include "input_data/input_data.h"

class Chef : public Process {

public:
    explicit Chef(input_data data);

    void Behavior() override;

private:
    input_data data;
};


#endif //IMS_2020_CHEF_H
