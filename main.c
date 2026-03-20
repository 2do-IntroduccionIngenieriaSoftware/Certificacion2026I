#include <stdio.h>
#include "inventario.h"

int main() {
    int opcion, id_busqueda;
    const char *DB_NAME = "zapateria.dat";

    do {
        printf("\n=== SISTEMA CRUD ZAPATERIA ===\n"); [cite: 5]
        printf("1. Registrar Producto (C)\n");
        printf("2. Ver Inventario (R)\n");
        printf("3. Actualizar Stock (U)\n");
        printf("4. Eliminar Producto (D)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: agregar_producto(DB_NAME); break;
            case 2: listar_productos(DB_NAME); break;
            case 3:
                printf("ID a actualizar: "); scanf("%d", &id_busqueda);
                actualizar_producto(DB_NAME, id_busqueda);
                break;
            case 4:
                printf("ID a eliminar: "); scanf("%d", &id_busqueda);
                eliminar_producto(DB_NAME, id_busqueda);
                break;
            case 5: printf("Finalizando programa...\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while(opcion != 5);

    return 0;
}