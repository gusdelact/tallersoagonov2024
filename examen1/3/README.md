### Ejercicio: Creación de Makefile y ejecución de programas servidor y cliente de sockets

En este ejercicio, deberás crear un archivo `Makefile` para compilar dos programas en C: un **servidor de sockets** y un **cliente de sockets**. También aprenderás a ejecutar el servidor de manera que quede corriendo en segundo plano y a ejecutar el cliente desde una plataforma externa como Replit.

#### Descripción del Problema:

1. **Creación del archivo Makefile**:
   - Debes crear un archivo llamado `Makefile` que te permita compilar en cada subdirecotio, los programas del **servidor** y del **cliente** de sockets en C.
   - El `Makefile` debe generar los ejecutables llamados `servidor` y `cliente`.

2. **Ejecución del programa servidor**:
   - Una vez compilado, debes arrancar el **servidor** con dos argumentos: el puerto (debe estar entre 1024 y 65535) y el mensaje que va a enviar a los clientes.
   - El servidor debe ejecutarse en **segundo plano** (`background`) y continuar ejecutándose incluso si cierras la sesión en el sistema. Asegúrate de que el servidor permanezca corriendo utilizando herramientas como `nohup` o `screen`.

3. **Ejecución del programa cliente desde Replit**:
   - El programa cliente debe ejecutarse desde la plataforma **Replit**. Debes ejecutar el cliente con los argumentos correspondientes: la dirección IP o nombre del servidor y el puerto en el que el servidor está escuchando.
   - El cliente debe conectarse al servidor, recibir el mensaje y mostrarlo en pantalla.

#### Requisitos:
- Cada archivo `Makefile` debe estar bien estructurado y permitir la compilación, tanto del servidor como del cliente.
- El servidor debe ejecutarse en la máquina del cliente y en segundo plano de manera que siga corriendo tras cerrar la sesión.
- El cliente debe ser capaz de conectarse desde una plataforma externa como Replit, consumiendo el servicio proporcionado por el servidor y mostrando el mensaje que recibe.

#### Resultado esperado:

Al finalizar, debes tener:
1. El **servidor** corriendo en segundo plano en tu sistema, enviando el mensaje especificado a los clientes que se conecten.
2. El **cliente** ejecutado desde Replit, que se conecta al servidor, recibe el mensaje y lo muestra en la salida del programa.

Documenta todos los pasos que realizaste para compilar, ejecutar y probar ambos programas, tanto en tu entorno local como desde Replit.