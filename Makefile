# Author: Jiří Křištof <xkrist22@stud.fit.vutbr.cz>
# Author: Petr Češka <xceska05@stud.fit.vutbr.cz>

.PHONY: model debug simulate

CC = gcc

SRC_FILES = src/main.cpp src/input_data/input_data.cpp src/intern_time/intern_time.cpp src/Shift.cpp src/Order.cpp src/Pause.cpp src/Refuel.cpp

CC_FLAGS = -lsimlib -lstdc++ -o

PARAMS = -car-type diesel -car-num 1 -chef-num 2 -chef-pause 5 -chef-center 15 -chef-sigma 3 -order-center 20 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 2 -car-refuel-center 12 -car-refuel-sigma 2 -start-time 11 -stop-time 21 -car-capacity 10 -pause-interval 60 -day-num 7 -earnings-center 170 -earnings-sigma 30 -monthly-car-expenses 1900 -chefs-salary 300 -deliverers-salary 150

#TESTING DATA
#changing chefs and deliverers counts
PARAMS1 = -car-type diesel -car-num 0 -chef-num 2 -chef-pause 5 -chef-center 15 -chef-sigma 3 -order-center 10 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 2 -car-refuel-center 12 -car-refuel-sigma 2 -start-time 11 -stop-time 21 -car-capacity 10 -pause-interval 60 -day-num 7 -earnings-center 170 -earnings-sigma 30 -monthly-car-expenses 1900 -chefs-salary 300 -deliverers-salary 150
PARAMS2 = -car-type diesel -car-num 1 -chef-num 3 -chef-pause 5 -chef-center 15 -chef-sigma 3 -order-center 10 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 2 -car-refuel-center 12 -car-refuel-sigma 2 -start-time 11 -stop-time 21 -car-capacity 10 -pause-interval 60 -day-num 7 -earnings-center 170 -earnings-sigma 30 -monthly-car-expenses 1900 -chefs-salary 300 -deliverers-salary 150
PARAMS3 = -car-type diesel -car-num 2 -chef-num 3 -chef-pause 5 -chef-center 15 -chef-sigma 3 -order-center 10 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 2 -car-refuel-center 12 -car-refuel-sigma 2 -start-time 11 -stop-time 21 -car-capacity 10 -pause-interval 60 -day-num 7 -earnings-center 170 -earnings-sigma 30 -monthly-car-expenses 1900 -chefs-salary 300 -deliverers-salary 150
PARAMS4 = -car-type diesel -car-num 3 -chef-num 3 -chef-pause 5 -chef-center 15 -chef-sigma 3 -order-center 10 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 2 -car-refuel-center 12 -car-refuel-sigma 2 -start-time 11 -stop-time 21 -car-capacity 10 -pause-interval 60 -day-num 7 -earnings-center 170 -earnings-sigma 30 -monthly-car-expenses 1900 -chefs-salary 300 -deliverers-salary 150

#faster, more expensive workers
PARAMS5 = -car-type diesel -car-num 1 -chef-num 2 -chef-pause 5 -chef-center 15 -chef-sigma 3 -order-center 15 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 2 -car-refuel-center 12 -car-refuel-sigma 2 -start-time 11 -stop-time 21 -car-capacity 10 -pause-interval 60 -day-num 7 -earnings-center 170 -earnings-sigma 30 -monthly-car-expenses 1900 -chefs-salary 300 -deliverers-salary 150
PARAMS6 = -car-type diesel -car-num 2 -chef-num 2 -chef-pause 5 -chef-center 10 -chef-sigma 2 -order-center 15 -order-wait 30 -car-delivery-center 10 -car-delivery-sigma 2 -car-refuel-center 12 -car-refuel-sigma 2 -start-time 11 -stop-time 21 -car-capacity 10 -pause-interval 60 -day-num 7 -earnings-center 170 -earnings-sigma 30 -monthly-car-expenses 1900 -chefs-salary 400 -deliverers-salary 150
PARAMS7 = -car-type diesel -car-num 2 -chef-num 2 -chef-pause 5 -chef-center 15 -chef-sigma 3 -order-center 15 -order-wait 30 -car-delivery-center 6 -car-delivery-sigma 2 -car-refuel-center 12 -car-refuel-sigma 2 -start-time 11 -stop-time 21 -car-capacity 10 -pause-interval 60 -day-num 7 -earnings-center 170 -earnings-sigma 30 -monthly-car-expenses 1900 -chefs-salary 300 -deliverers-salary 250


MODEL_NAME = model

# compile code
model:
	$(CC) $(SRC_FILES) $(CC_FLAGS) $(MODEL_NAME)

# run simulation with selected values
simulate:
	./$(MODEL_NAME) $(PARAMS)

simulate1:
	./$(MODEL_NAME) $(PARAMS1)

simulate2:
	./$(MODEL_NAME) $(PARAMS2)

simulate3:
	./$(MODEL_NAME) $(PARAMS3)

simulate4:
	./$(MODEL_NAME) $(PARAMS4)

simulate5:
	./$(MODEL_NAME) $(PARAMS5)

simulate6:
	./$(MODEL_NAME) $(PARAMS6)

simulate7:
	./$(MODEL_NAME) $(PARAMS7)

