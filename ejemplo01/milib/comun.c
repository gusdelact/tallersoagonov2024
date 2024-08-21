#include "comun.h"
#include <memory.h>

void iniciar2(union comun * p) {
  memset(p,0,sizeof(union comun));
  return;
}

void iniciar3(union comun * p,float valor) {
  p->opcion1 = valor;
  return;
}