#include <simlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "intern_time/intern_time.h"
#include "input_data/input_data.h"
#include "Shift.h"

using namespace std;

/**
 *
 * @param argc
 * @param argv arg1 = num of chefs, arg2 = num of delivery cars
 * @return
 */
int main(int argc, char *argv[]) {
	vector<string> args(argv, argv + argc);
	input_data data(args);
	SetOutput(data.get_output_file().c_str());
	Init(0, intern_time::in_hours(data.get_stop_time()));
	(new Shift(data))->Activate();
    Run();
	data.get_cars_store()->Output();
	data.get_chefs_store()->Output();
	return 0;
}
