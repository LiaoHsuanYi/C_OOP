.PHONY: directories clean stat

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/test_util.h test/ut_sample.h src/Product.h src/ShoppingCart.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all_gcovr -lgtest -lpthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread
directories:
	mkdir -p bin

clean:
	rm -rf bin *.gcov *.gcda *.gcno *.html *.css

stat:
	wc src/* test/*