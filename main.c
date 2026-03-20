#include <stdio.h>
#include "inventario.h"

int main() {
    int opcion, id_busqueda;
    const char *DB_NAME = "zapateria.dat";

    do {
        printf("\n--- MENU ZAPATERIA ---\n");
        printf("1. Registrar producto\n");
        printf("2. Ver inventario\n");
        printf("3. Actualizar stock\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            limpiar_buffer();
            opcion = 0;
        } else {
            limpiar_buffer();
        }

        switch(opcion) {
            case 1: 
                agregar_producto(DB_NAME); 
                break;
            case 2: 
                listar_productos(DB_NAME); 
                break;
            case 3:
                printf("Ingrese ID a buscar: "); 
                if (scanf("%d", &id_busqueda) == 1) {
                    limpiar_buffer();
                    actualizar_producto(DB_NAME, id_busqueda);
                } else {
                    limpiar_buffer();
                    printf("ID invalido.\n");
                }
                break;
            case 4:
                printf("Ingrese ID a eliminar: "); 
                if (scanf("%d", &id_busqueda) == 1) {
                    limpiar_buffer();
                    eliminar_producto(DB_NAME, id_busqueda);
                } else {
                    limpiar_buffer();
                    printf("ID invalido.\n");
                }
                break;
            case 5:
                printf("Cerrando sistema...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while(opcion != 5);

    return 0;
}