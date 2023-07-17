CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -std=c11 -pedantic -g #-fsanitize=address
GCOV_FLAGS		= -fprofile-arcs -ftest-coverage -fPIC
VALGRIND_FLAGS	= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
CHECK_FLAGS 	= $(shell pkg-config --cflags --libs check)

LIBRARY			= calculator.a
APP_NAME		= ../SmartCalculator
SRC_PROJECT		= $(wildcard logic/*.c stack/*.c)
SRC_TEST		= $(wildcard tests/*.c)
OBJ_PROJECT		= polish.o stack.o calc.o
OBJ_TEST		= test_core.o test_stack.o test_smart_calc.o test_credit_calc.o test_deposit_calc.o

all: install launch_app gcov_report uninstall

install: $(LIBRARY)
	mv $(LIBRARY) ../GUI/Calculator_GUI/lib$(LIBRARY)
	cmake -S ../GUI/Calculator_GUI -B build
	make -C build
	cp build/Calculator_GUI ../SmartCalculator

uninstall: clean
	rm -rf build
	rm -rf ../GUI/Calculator_GUI/lib$(LIBRARY)
	rm -rf ../SmartCalculator
	rm -rf ../SmartCalculator.tar.gz

dvi:
	open ../README.md

dist: install
	tar -czf SmartCalculator.tar.gz --directory=build/ .
	mv SmartCalculator.tar.gz ../SmartCalculator.tar.gz

launch_app:
	./$(APP_NAME)

$(LIBRARY): $(SRC_PROJECT)
	$(CC) $(CFLAGS) -c $(SRC_PROJECT)
	ar rc $(LIBRARY) $(OBJ_PROJECT)
	ranlib $(LIBRARY)

test: $(LIBRARY) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(OBJ_TEST) -o test $(LIBRARY) $(CHECK_FLAGS)
	./test

gcov_report: clean $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(CHECK_FLAGS)
	./test
	lcov -t "test" -o gcov.info -c -d .
	genhtml -o report gcov.info
	rm -rf ./*.gc*
	make open

$(OBJ_TEST):
	$(CC) $(CFLAGS) -c $(SRC_TEST)

clean:
	rm -rf test
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda
	rm -rf report
	rm -rf *.gcno
	rm -rf *.info
	rm -rf valgrind.txt

rebuild: clean test

open: 
	open report/index.html

.PHONY: all clean rebuild open clang valgrind docker

valgrind: rebuild
	valgrind $(VALGRIND_FLAGS) ./test
	grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"

clang:
	clang-format --style=google -i logic/*
	clang-format --style=google -i stack/*
	clang-format --style=google -i tests/*
	clang-format --style=google -i ../GUI/Calculator_GUI/*.cpp
	clang-format --style=google -i ../GUI/Calculator_GUI/*.h

docker:
	cd ../materials/build; sudo sh run.sh; cd ../../src
