
#ifndef IMS_2020_ORDER_H
#define IMS_2020_ORDER_H

#include <simlib.h>
#include "input_data/input_data.h"
#include "Refuel.h"
#include "Pause.h"

#define DIESEL_TANK 60
#define GASOLINE_TANK 22
#define DIESEL_CONSUMPTION 6.7
#define GASOLINE_CONSUMPTION 9.7
#define REFERENCE_DISTANCE 100
#define CITY_SPEED 50
#define FORCE_ATTEMPS 20

class Order : public Process {

public:
	/**
	 * Constructor of Order process
	 * @param data data from terminal
	 */
    explicit Order(input_data data);

    /**
     * Behavior of process
     */
    void Behavior() override;

    double static chef_work_time; /// counts time to pause
	double static fuel; /// count fuel to refuel
	bool static fuel_init;
	bool static time_init;
private:
    input_data data;
    double income;
};

#endif //IMS_2020_ORDER_H
