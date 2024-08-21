tst_estructura.o : tst_estructura.c
	gcc -c tst_estructura.c -Imilib
tst_estructura: tst_estructura.o
	gcc -o tst_estructura  tst_estructura.o milib/libgus.a
build: tst_estructura
test: build
	./tst_estructura
clean:
	rm *.o tst_estructura
