

default:
	@g++ -std=c++11 src/play.cpp -o bin/play.exe

verbose:
	@g++ -std=c++11 -v src/play.cpp -o bin/play.exe

run:
	@./bin/play.exe

clean:
	@rm **/*.exe