

default:
	@g++ -std=c++11 Dealer.cpp Player.cpp play.cpp -o play.exe

run:
	@./play.exe

clean:
	@rm *.exe