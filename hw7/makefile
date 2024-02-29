.PHONY: directories clean stat

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp src/cake_showcase.h src/cake.h src/chocolate_cake.h src/geode_cake.h src/honey_cake.h test/ut_ChocolateCake.h test/ut_HoneyCake.h test/ut_GeodeCake.h test/ut_cake.h test/ut_cake_showcase.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all_gcovr -lgtest -lpthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread
directories:
	mkdir -p bin

clean:
	rm -rf bin *.gcov *.gcda *.gcno *.html *.css

stat:
	wc src/* test/*