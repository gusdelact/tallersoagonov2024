#define MAX_SIZE  1024
struct miestructura {
  int campo1;  /* 4 bytes */
  char buffer[MAX_SIZE]; /*1024 bytes*/
  float campo2; /* 4 bytes */
};
/* inicializa una estructura de tipo mi estructura*/
void iniciar(struct miestructura *) ;
float calcular(struct miestructura *);