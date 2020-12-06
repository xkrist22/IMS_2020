# Author: Jiří Křištof <xkrist22@stud.fit.vutbr.cz>
# Author: Petr Češka <xceska05@stud.fit.vutbr.cz>

.PHONY: model debug simulate

CC = gcc

SRC_FILES = src/main.cpp src/input_data/input_data.cpp src/intern_time/intern_time.cpp src/Shift.cpp src/Order.cpp src/Pause.cpp src/Refuel.cpp

CC_FLAGS = -lsimlib -lstdc++ -o

PARAMS = -car-type diesel -car-num 1 -chef-num 2 -chef-pause 5 -chef-center 15 -chef-sigma 3 -order-center 20 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 2 -car-refuel-center 12 -car-refuel-sigma 2 -start-time 11 -stop-time 21 -car-capacity 10 -pause-interval 60 -day-num 14 -earnings-center 150 -earnings-sigma 30

MODEL_NAME = model



# compile code
model:
	$(CC) $(SRC_FILES) $(CC_FLAGS) $(MODEL_NAME)

# run simulation with selected values
simulate:
	./$(MODEL_NAME) $(PARAMS)

