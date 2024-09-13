#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>

#define BUFFER_SIZE 1024

int server_fd; // Variable global para el socket del servidor

// Función de manejo de la señal SIGTERM
void handle_sigterm(int sig) {
    printf("\nRecibida señal %d, cerrando el servidor...\n", sig);
    close(server_fd);
    exit(0);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int new_socket;
    char buffer[BUFFER_SIZE] = {0};
    int opt = 1;
    int port;

    // Verificar que se haya pasado el número de puerto como argumento
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <puerto> <mensaje>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convertir el argumento a número
    port = atoi(argv[1]);

    // Verificar que el puerto esté en el rango válido (1024 - 65535)
    if (port < 1024 || port > 65535) {
        fprintf(stderr, "El puerto debe estar entre 1024 y 65535\n");
        exit(EXIT_FAILURE);
    }

    // Asignar la función de manejo de la señal SIGTERM
    signal(SIGTERM, handle_sigterm);

    // Crear el socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error al crear el socket");
        exit(EXIT_FAILURE);
    }

    // Configurar el socket para reutilizar el puerto
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error en setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Configurar la dirección y el puerto del servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Asociar el socket al puerto
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error en bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Escuchar conexiones entrantes
    if (listen(server_fd, 3) < 0) {
        perror("Error en listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Servidor escuchando en el puerto %d...\n", port);

    // Bucle infinito para aceptar conexiones
    while (1) {
        printf("Esperando conexión...\n");

        // Aceptar una conexión entrante
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Error en accept");
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        // Enviar el mensaje pasado como argumento al cliente
        send(new_socket, argv[2], strlen(argv[2]), 0);
        printf("Mensaje enviado al cliente: %s\n", argv[2]);

        // Cerrar la conexión con el cliente
        close(new_socket);
    }

    // Cerrar el socket del servidor (aunque no se llegará aquí debido al ciclo infinito)
    close(server_fd);

    return 0;
}
