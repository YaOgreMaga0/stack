SPU: obj/LanguageCode.o obj/CommandFunc.o obj/StackFunc.o obj/StackVerify.o
	g++ obj/LanguageCode.o obj/StackFunc.o obj/StackVerify.o obj/CommandFunc.o -o Stack

obj/StackFunc.o: StackFunc.cpp
	g++ -c StackFunc.cpp -o obj/StackFunc.o

obj/StackVerify.o: StackVerify.cpp
	g++ -c StackVerify.cpp -o obj/StackVerify.o

obj/CommandFunc.o: CommandFunc.cpp
	g++ -c CommandFunc.cpp -o obj/CommandFunc.o

obj/LanguageCode.o: LanguageCode.cpp
	g++ -c LanguageCode.cpp -o obj/LanguageCode.o
