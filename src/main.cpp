//#include <simlib.h>
#include "simlib.h"
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
	try {
		input_data data(args);
//		SetOutput(data.get_output_file().c_str());
		Init(intern_time::in_hours(data.get_start_time()), intern_time::in_hours(data.get_stop_time()) + intern_time::in_days(data.get_day_num()));
		auto *shift = new Shift(data);
		shift->print_head();
		shift->Activate();
		Run();
		shift->print_stats();

        SIMLIB_statistics.Output();
        data.get_cars_store()->Output();
        data.get_chefs_store()->Output();

    } catch (const char* err_msg) {
		cerr << err_msg << "\n";
		exit(1);
	}
	return 0;
}
