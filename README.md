# Sistema de Gestión de Inventario (CRUD) - Zapatería

Este es un programa desarrollado en **lenguaje C** diseñado para gestionar el inventario de una zapatería. Utiliza archivos binarios para la persistencia de datos y manejo de memoria dinámica para el registro de productos.

## Funciones (CRUD)

El sistema permite realizar las cuatro operaciones fundamentales:

1.  **Registrar Producto (Create)**: Captura datos como ID, modelo, precio y stock, guardándolos en un archivo binario.
2.  **Ver Inventario (Read)**: Muestra en consola todos los registros almacenados en el archivo.
3.  **Actualizar Stock (Update)**: Permite buscar un producto por su ID y modificar su cantidad disponible.
4.  **Eliminar Producto (Delete)**: Borra un registro específico utilizando un archivo auxiliar para reestructurar la base de datos.

## Estructura del Código

El proyecto se divide en tres archivos principales para mantener la modularidad:

* **`inventario.h`**: Define la estructura `Producto` y los prototipos de las funciones.
* **`inventario.c`**: Contiene la implementación lógica de cada operación del sistema.
* **`main.c`**: Gestiona el menú interactivo y el flujo principal del programa.

## Instrucciones de Compilación

Para compilar el proyecto utilizando `gcc`, ejecuta el siguiente comando en la terminal:

```bash
gcc main.c inventario.c -o zapateria
```

Una vez compilado, inicia el programa con:

```Bash
./zapateria
```

## Detalles de Implementación
1. **`Base de Datos:`** Se genera un archivo llamado **`zapateria.dat`** donde se almacenan los datos de forma binaria.
2. **`Memoria:`** Se emplea **`malloc`** para la creación de nuevos registros y **`free`** para liberar la memoria una vez guardados en el disco.
3. **`Seguridad:`** El proceso de eliminación utiliza un archivo temporal para asegurar que no se pierdan datos en caso de una interrupción durante la escritura.
