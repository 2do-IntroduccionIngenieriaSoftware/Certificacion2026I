#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"

// CREATE: Agregar un producto al archivo binario
void agregar_producto(const char *nombre_fichero) {
    FILE *archivo = fopen(nombre_fichero, "ab");
    if (archivo == NULL) {
        perror("Error al abrir el archivo"); [cite: 28]
        return;
    }

    // Uso de memoria dinámica
    Producto *nuevo = (Producto *)malloc(sizeof(Producto));
    if (nuevo == NULL) {
        fprintf(stderr, "Error de asignacion de memoria.\n"); [cite: 28]
        fclose(archivo);
        return;
    }

    printf("ID: "); scanf("%d", &nuevo->id);
    printf("Modelo: "); scanf("%s", nuevo->modelo);
    printf("Precio: "); scanf("%f", &nuevo->precio);
    printf("Stock: "); scanf("%d", &nuevo->stock);

    fwrite(nuevo, sizeof(Producto), 1, archivo);
    
    free(nuevo); // Liberación de memoria
    fclose(archivo);
    printf("Producto guardado con exito.\n");
}

// READ: Leer todos los registros del archivo
void listar_productos(const char *nombre_fichero) {
    FILE *archivo = fopen(nombre_fichero, "rb");
    if (archivo == NULL) {
        printf("El inventario esta vacio o no existe.\n");
        return;
    }

    Producto temp;
    printf("\n--- INVENTARIO ACTUAL ---\n");
    while (fread(&temp, sizeof(Producto), 1, archivo)) {
        printf("ID: %d | Modelo: %-15s | Precio: $%-8.2f | Stock: %d\n", 
               temp.id, temp.modelo, temp.precio, temp.stock);
    }
    fclose(archivo);
}

// UPDATE: Modificar stock por ID
void actualizar_producto(const char *nombre_fichero, int id_buscar) {
    FILE *archivo = fopen(nombre_fichero, "r+b");
    if (archivo == NULL) return;

    Producto temp;
    int encontrado = 0;
    while (fread(&temp, sizeof(Producto), 1, archivo)) {
        if (temp.id == id_buscar) {
            encontrado = 1;
            printf("Nuevo stock para %s: ", temp.modelo);
            scanf("%d", &temp.stock);
            
            fseek(archivo, -sizeof(Producto), SEEK_CUR);
            fwrite(&temp, sizeof(Producto), 1, archivo);
            printf("Registro actualizado.\n");
            break;
        }
    }
    if (!encontrado) printf("ID %d no encontrado.\n", id_buscar);
    fclose(archivo);
}

// DELETE: Eliminar registro usando un archivo temporal
void eliminar_producto(const char *nombre_fichero, int id_eliminar) {
    FILE *archivo = fopen(nombre_fichero, "rb");
    FILE *temporal = fopen("temp.dat", "wb");
    if (!archivo || !temporal) return;

    Producto temp;
    int borrado = 0;
    while (fread(&temp, sizeof(Producto), 1, archivo)) {
        if (temp.id != id_eliminar) {
            fwrite(&temp, sizeof(Producto), 1, temporal);
        } else {
            borrado = 1;
        }
    }
    fclose(archivo);
    fclose(temporal);

    remove(nombre_fichero);
    rename("temp.dat", nombre_fichero);
    if (borrado) printf("Producto eliminado.\n");
}