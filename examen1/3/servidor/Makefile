# Makefile para el servidor

CC = gcc
CFLAGS = -I.  # Aquí puedes agregar otros flags de compilación si es necesario

# Nombre del ejecutable
EXECUTABLE = servidor

# Archivos fuente
SOURCES = main.c

# Archivos objeto
OBJECTS = $(SOURCES:.c=.o)

# Regla para compilar el ejecutable
$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS)

# Regla para compilar los archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Regla de limpieza
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
