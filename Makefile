# Author: Jiří Křištof <xkrist22@stud.fit.vutbr.cz>
# Author: Petr Češka <xceska05@stud.fit.vutbr.cz>

.PHONY: model simulate

CC = gcc
SRC_FILES = src/*.cpp
CC_FLAGS = -lstdc++ -o

# compile code
model:
	$(CC) $(SRC_FILES) $(FLAGS) model

run:
	./model # TODO

# run simulation with selected values
simulate:
	./model # TODO

