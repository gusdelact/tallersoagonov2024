#include "estructura.h"
#include <memory.h>
/* inicializa una estructura de tipo mi estructura*/
void iniciar(struct miestructura * pest) {
  memset(pest,0x0,sizeof(struct miestructura));
  return ;
}

float calcular(struct miestructura * pest) {
  return pest->campo2*pest->campo1;
}