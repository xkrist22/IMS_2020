# Author: Jiří Křištof <xkrist22@stud.fit.vutbr.cz>
# Author: Petr Češka <xceska05@stud.fit.vutbr.cz>

.PHONY: model debug simulate

CC = gcc
SRC_FILES = src/main.cpp src/input_data/input_data.cpp src/intern_time/intern_time.cpp src/Shift.cpp src/Order.cpp src/Pause.cpp src/Refuel.cpp
CC_FLAGS = -lsimlib -lstdc++ -o
DEBUG_PARAMS = -car-type diesel -car-num 1 -chef-num 2 -chef-pause 5 -chef-center 15 -chef-sigma 0 -order-center 20 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 0 -car-refuel-center 12 -car-refuel-sigma 0 -stop-time 48 -car-capacity 10 -output-file stats.out -pause-interval 60
MODEL_NAME = model



# compile code
model:
	$(CC) $(SRC_FILES) $(CC_FLAGS) $(MODEL_NAME)

# run program with not valid data
debug:
	./$(MODEL_NAME) $(DEBUG_PARAMS)

# run simulation with selected values
simulate:
	./$(MODEL_NAME)

# g++ -o ball ball.cc -lsimlib
