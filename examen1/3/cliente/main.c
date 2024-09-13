#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE] = {0};
    int port;

    // Verificar que se hayan pasado dos argumentos: servidor y puerto
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <nombre_servidor_o_IP> <puerto>\n", argv[0]);
        return -1;
    }

    // Convertir el argumento del puerto a un número entero
    port = atoi(argv[2]);

    // Verificar que el puerto esté en el rango válido (1024 - 65535)
    if (port < 1024 || port > 65535) {
        fprintf(stderr, "El puerto debe estar entre 1024 y 65535\n");
        return -1;
    }

    // Resolver el nombre del servidor o la dirección IP
    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: No se pudo resolver el nombre del servidor %s\n", argv[1]);
        return -1;
    }

    // Crear el socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error al crear el socket\n");
        return -1;
    }

    // Configurar la dirección del servidor
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Conectarse al servidor
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error al conectarse al servidor\n");
        return -1;
    }

    // Leer el mensaje del servidor
    valread = read(sock, buffer, BUFFER_SIZE);
    printf("Mensaje del servidor: %s\n", buffer);

    // Cerrar el socket
    close(sock);

    return 0;
}
