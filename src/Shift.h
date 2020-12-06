
#ifndef IMS_2020_SHIFT_H
#define IMS_2020_SHIFT_H

#include "input_data/input_data.h"
#include <simlib.h>
#include "Order.h"

class Shift : public Event {

public:
	/**
	 * Generator of Order processes
	 * @param data data from terminal
	 */
    explicit Shift(input_data data);

    /**
     * Behavior of generator
     */
    void Behavior() override;

    void print_stats();

    void print_head();

private:
    input_data data;
};


#endif //IMS_2020_SHIFT_H
