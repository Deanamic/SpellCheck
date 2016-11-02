bin/scheck.exe : main.o parser.o CSVreporter.o XMLreporter.o cmdline.o settings.o
	g++ main.o parser.o CSVreporter.o XMLreporter.o cmdline.o settings.o -o bin/scheck.exe

parser.o : src/parser.cpp inc/parser.h inc/error.h
	g++ -I inc -c src/parser.cpp

CSVreporter.o : src/CSVreporter.cpp inc/CSVreporter.h inc/reporter.h
	g++ -I inc -c src/CSVreporter.cpp

XMLreporter.o : src/XMLreporter.cpp inc/XMLreporter.h inc/reporter.h
	g++ -I inc -c src/XMLreporter.cpp

settings.o : src/settings.cpp inc/settings.h inc/error.h 
	g++ -I inc -c src/settings.cpp

cmdline.o : src/cmdline.cpp inc/cmdline.h
	g++ -I inc -c src/cmdline.cpp

main.o : src/main.cpp inc/parser.h inc/error.h inc/dictionary.h inc/cmdline.h inc/settings.h
	g++ -I inc -c src/main.cpp
