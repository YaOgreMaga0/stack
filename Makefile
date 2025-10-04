Stack.exe: obj/Stack.o obj/StackVerify.o obj/main.o
	g++ obj/Stack.o obj/StackVerify.o obj/main.o -o Stack.exe

obj/main.o: src/main.cpp
	g++ -c src/main.cpp -o obj/main.o

obj/Stack.o: src/Stack.cpp
	g++ -c src/Stack.cpp -o obj/Stack.o

obj/StackVerify.o: src/StackVerify.cpp
	g++ -c src/StackVerify.cpp -o obj/StackVerify.o
