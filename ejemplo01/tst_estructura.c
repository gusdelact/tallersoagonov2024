#include "comun.h"
#include "estructura.h"
#include <stdio.h>
int main(int argc, char *argv[]) {
  struct miestructura mio;
  union comun espacio;
  float resultado = 0;
  printf("%lu\n", sizeof(struct miestructura));
  printf("%lu\n", sizeof(mio));
  iniciar(&mio);
  printf("%d\n", mio.campo1);
  mio.campo1 = 0x10;
  mio.campo2 = 3.14F;
  mio.buffer[0] = 0xFF;
  resultado = calcular(&mio);
  printf("%f\n", resultado);
  iniciar2(&espacio);
  iniciar3(&espacio,3.14159F);
  printf("%f\n", espacio.opcion1);
  printf("%lu\n",sizeof(float));
  for (int i=0;i<sizeof(float);i++)
    printf("%d:",espacio.buffer[i]);
  printf("\n");
}