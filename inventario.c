#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void agregar_producto(const char *nombre_fichero) {
    FILE *archivo = fopen(nombre_fichero, "ab");
    if (archivo == NULL) return;

    Producto *nuevo = (Producto *)malloc(sizeof(Producto));
    if (nuevo == NULL) {
        fclose(archivo);
        return;
    }

    do {
        printf("ID: ");
        if (scanf("%d", &nuevo->id) != 1) {
            limpiar_buffer();
            nuevo->id = -1;
        } else {
            limpiar_buffer();
        }
    } while (nuevo->id <= 0);

    printf("Modelo: ");
    if (fgets(nuevo->modelo, sizeof(nuevo->modelo), stdin)) {
        nuevo->modelo[strcspn(nuevo->modelo, "\n")] = 0;
    }

    do {
        printf("Precio: ");
        if (scanf("%f", &nuevo->precio) != 1) {
            limpiar_buffer();
            nuevo->precio = -1.0;
        } else {
            limpiar_buffer();
        }
    } while (nuevo->precio <= 0);

    do {
        printf("Stock: ");
        if (scanf("%d", &nuevo->stock) != 1) {
            limpiar_buffer();
            nuevo->stock = -1;
        } else {
            limpiar_buffer();
        }
    } while (nuevo->stock < 0);

    fwrite(nuevo, sizeof(Producto), 1, archivo);
    
    free(nuevo);
    fclose(archivo);
}

void listar_productos(const char *nombre_fichero) {
    FILE *archivo = fopen(nombre_fichero, "rb");
    if (archivo == NULL) return;

    Producto temp;
    while (fread(&temp, sizeof(Producto), 1, archivo) == 1) {
        printf("ID: %-4d | Modelo: %-15s | Precio: $%-7.2f | Stock: %d\n", 
               temp.id, temp.modelo, temp.precio, temp.stock);
    }
    fclose(archivo);
}

void actualizar_producto(const char *nombre_fichero, int id_buscar) {
    FILE *archivo = fopen(nombre_fichero, "r+b");
    if (archivo == NULL) return;

    Producto temp;
    while (fread(&temp, sizeof(Producto), 1, archivo) == 1) {
        if (temp.id == id_buscar) {
            int n_stock;
            do {
                printf("Nuevo stock: ");
                if (scanf("%d", &n_stock) != 1) {
                    limpiar_buffer();
                    n_stock = -1;
                } else {
                    limpiar_buffer();
                }
            } while (n_stock < 0);

            temp.stock = n_stock;
            fseek(archivo, (long)-sizeof(Producto), SEEK_CUR);
            fwrite(&temp, sizeof(Producto), 1, archivo);
            break;
        }
    }
    fclose(archivo);
}

void eliminar_producto(const char *nombre_fichero, int id_eliminar) {
    FILE *archivo = fopen(nombre_fichero, "rb");
    if (!archivo) return;

    FILE *temporal = fopen("temp.dat", "wb");
    if (!temporal) {
        fclose(archivo);
        return;
    }

    Producto temp;
    while (fread(&temp, sizeof(Producto), 1, archivo) == 1) {
        if (temp.id != id_eliminar) {
            fwrite(&temp, sizeof(Producto), 1, temporal);
        }
    }
    fclose(archivo);
    fclose(temporal);

    remove(nombre_fichero);
    rename("temp.dat", nombre_fichero);
}