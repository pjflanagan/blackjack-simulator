

default:
	@g++ -std=c++11 play.cpp -o play.exe

run:
	@./play.exe

clean:
	@rm *.exe