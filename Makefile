target = main
#dependancy = main
build:
	clear
	#@g++ $(dependancy).cpp -c
	@g++ $(target).cpp -lm -o out -Wall

test: build
	./out data/test

clean:
	rm out *.o
