bin/scheck.exe : main.o parser.o CSVreporter.o XMLreporter.o
	g++ main.o parser.o CSVreporter.o XMLreporter.o -o bin/scheck.exe

parser.o : src/parser.cpp inc/parser.h inc/error.h
	g++ -I inc -c src/parser.cpp

main.o : src/main.cpp inc/parser.h inc/error.h inc/dictionary.h inc/reporter.h inc/CSVreporter.h inc/XMLreporter.h
	g++ -I inc -c src/main.cpp

CSVreporter.o : src/CSVreporter.cpp inc/CSVreporter.h inc/reporter.h
	g++ -I inc -c src/CSVreporter.cpp

XMLreporter.o : src/XMLreporter.cpp inc/XMLreporter.h inc/reporter.h
	g++ -I inc -c src/XMLreporter.cpp
