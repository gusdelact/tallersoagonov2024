INCLUDE=libgus
clean:
	rm tst_estructura.o tst_estructura
tst_estructura.o : tst_estructura.c
	gcc -c tst_estructura.c -Ilibgus
tst_estructura: tst_estructura.o
	gcc -o tst_estructura  tst_estructura.o libgus/libgus.a
run: tst_estructura
	./tst_estructura
