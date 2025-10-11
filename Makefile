SPU: obj/SPU.o obj/ByteCode.o obj/LanguageCode.o obj/translator.o
	g++ obj/SPU.o obj/ByteCode.o obj/LanguageCode.o obj/translator.o -o SPU

obj/SPU.o: SPU.cpp
	g++ -c SPU.cpp -o obj/SPU.o

obj/ByteCode.o: ByteCode.cpp
	g++ -c ByteCode.cpp -o obj/ByteCode.o

obj/LanguageCode.o: LanguageCode.cpp
	g++ -c LanguageCode.cpp -o obj/LanguageCode.o

obj/translator.o: translator.cpp
	g++ -c translator.cpp -o obj/translator.o
