
#ifndef IMS_2020_PAUSE_H
#define IMS_2020_PAUSE_H

#include <simlib.h>
#include "input_data/input_data.h"

class Pause : public Process {

public:
    explicit Pause(input_data data);

    void Behavior() override;
private:
    input_data data;
    double income;
};

#endif //IMS_2020_PAUSE_H
