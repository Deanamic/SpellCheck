bin/scheck.exe : main.o parser.o
	g++ main.o parser.o -o bin/scheck.exe
