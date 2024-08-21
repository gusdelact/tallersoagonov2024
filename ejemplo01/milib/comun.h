union comun {
  float opcion1;
  char buffer[sizeof(float)];
};

void iniciar2(union comun *);
void iniciar3(union comun *,float);

