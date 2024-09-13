### Ejercicio: Manipulación de archivos con comandos UNIX

En este ejercicio, trabajarás con un archivo llamado `nomina.txt` que contiene cuatro columnas separadas por un carácter delimitador. Utilizarás comandos de UNIX para contar las líneas en el archivo, dividir el archivo en tres partes, y extraer ciertas columnas para generar nuevos archivos.

#### Pasos a seguir:

1. **Contar el número de líneas del archivo `nomina.txt`**:
   
   Usa el comando  __ para contar el número de líneas que tiene el archivo:


   Esto te dará el número total de líneas en el archivo.

2. **Dividir el archivo en tres partes**:
   
   Utiliza los comandos __ y __` para dividir el archivo en tres partes iguales. El prefijo de cada archivo es nomina y el sufijo de cada archivo resultante será `1`, `2`, o `3` respectivamente. Cada nuevo archivo tendrá la extensión `.txt`.

   Primero, divide el número total de líneas entre 3 (suponiendo que el archivo tiene un número divisible por 3). 
   

   Esto debe crear tres archivos con los nombres `nomina1.txt`, `nomina2.txt`, `nomina3.txt`. 
   

3. **Extraer las columnas 2 y 3 de los nuevos archivos**:
   
   Utiliza el comando __  para extraer solo las columnas 2 (salario) y 3 (puesto) de los archivos recién creados. Asegúrate de que los campos están separados por el carácter `:`. Por ejemplo:

   
   Los archivos resultantes deben llamarse nomina4.txt, nomina5.txt, y nomina6.txt.
   

###Resultado:

Al finalizar, deberías tener tres archivos nuevos (`nomina4.txt`, `nomina5.txt`, y `nomina6.txt`) que contienen únicamente las columnas 2 y 3 (salario y puesto) de cada parte del archivo original `nomina.txt`.

Estos archivos debene estar en el servidor Linux del cliente
