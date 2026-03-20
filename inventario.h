#ifndef INVENTARIO_H
#define INVENTARIO_H

typedef struct {
    int id;
    char modelo[50];
    float precio;
    int stock;
} Producto;

void agregar_producto(const char *archivo);
void listar_productos(const char *archivo);
void actualizar_producto(const char *archivo, int id_buscar);
void eliminar_producto(const char *archivo, int id_eliminar);
void limpiar_buffer();

#endif