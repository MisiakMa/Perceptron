all : bin/app

bin/app : src/*.cpp src/*.hpp
	g++ -W -Wall -pedantic -o $@ src/*.cpp -g

clean :
	rm -f bin/app
