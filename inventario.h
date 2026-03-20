#ifndef INVENTARIO_H
#define INVENTARIO_H

/**
 * Estructura que representa un producto del negocio (Zapatería).
 */
typedef struct {
    int id;
    char modelo[50];
    float precio;
    int stock;
} Producto;

// Prototipos de funciones para el CRUD
void agregar_producto(const char *archivo);
void listar_productos(const char *archivo);
void actualizar_producto(const char *archivo, int id_buscar);
void eliminar_producto(const char *archivo, int id_eliminar);

#endif