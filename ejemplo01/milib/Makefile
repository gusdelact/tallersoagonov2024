
estructura.o: estructura.h estructura.c
	gcc -c estructura.c
comun.o: comun.h comun.c
	gcc -c comun.c
libgus.a : estructura.o comun.o
	ar -rcs libgus.a estructura.o comun.o
build: libgus.a
clean:
	rm *.o *.a
