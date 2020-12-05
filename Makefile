# Author: Jiří Křištof <xkrist22@stud.fit.vutbr.cz>
# Author: Petr Češka <xceska05@stud.fit.vutbr.cz>

.PHONY: model debug simulate

CC = gcc
SRC_FILES = src/input_data/input_data.cpp src/intern_time/intern_time.cpp src/main.cpp#src/Shift.cpp src/Order.cpp src/Chef.cpp src/Car.cpp src/main.cpp
CC_FLAGS = -lstdc++ -o

# compile code
model:
	$(CC) $(SRC_FILES) $(CC_FLAGS) model

# run program with not valid data
debug:
	./model -car-type diesel -car-num 2 -chef-num 2 -chef-pause 5 -chef-center 30 -chef-sigma 10 -order-center 5 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 7 -car-refuel-center 12 -car-refuel-sigma 8 -stop-time 1200

# run simulation with selected values
simulate:
	./model # TODO

