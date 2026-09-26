/* Menú Principal, Control de Flujo y Salida (Líder / Integrador)
Tarea: Crear la estructura del main(), el bucle do-while y el switch-case del menú.

Responsabilidad clave: Asegurarse de que el programa no se rompa si el usuario mete un número inválido en el menú (Opción 4 para salir de forma limpia). Es quien une las partes de todos al final.
*/
#include <stdio.h>

int main() {

    
    // 1. CATALOGO DE PRODUCTOS (Valores fijos)
    float precio_B001 = 1.50; // Jugo
    float precio_B002 = 0.80; // Agua
    float precio_S001 = 1.20; // Papas
    float precio_P001 = 2.50; // Cuaderno
    float precio_P002 = 0.60; // Lapiz

    
    // 2. ACUMULADORES GLOBALES DEL DIA (Para los reportes)

    int total_clientes = 0;
    float monto_bruto_total = 0.0;
    float total_descuentos = 0.0;
    float monto_neto_total = 0.0;

    float venta_maxima = 0.0;
    int cliente_maximo = 0;
    float venta_minima = 0.0;
    int cliente_minimo = 0;

    int cant_B001 = 0;
    int cant_B002 = 0;
    int cant_S001 = 0;
    int cant_P001 = 0;
    int cant_P002 = 0;

    int unidades_bebidas = 0;
    int unidades_snacks = 0;
    int unidades_papeleria = 0;
    int unidades_totales = 0;

    
    // 3. VARIABLES DEL MENU PRINCIPAL
    
    int opcion;

    
    // 4. VARIABLES INDIVIDUALES PARA CADA VENTA (Opcion 1)
    
    int es_estudiante;
    int cant_prod_distintos;
    int cantidad_comprada;
    float precio_actual;
    float subtotal_producto;
    float subtotal_cliente;
    int total_unidades_cliente;
    float descuento_cliente;
    float total_a_pagar;

    // Variables de reglas de negocio
    int aplica_descuento;
    int recibe_lapiz;
    int es_vip;
    int envio_gratis;

    // Ciclo del Menu Principal

    do {
        // Imprimir el menu de la tienda
        printf("   CAJARAPIDA - TIENDA ESCOLAR\n");
    
        printf("1. Registrar venta de un cliente\n");
        printf("2. Ver reporte del dia\n");
        printf("3. Ver producto mas vendido\n");
        printf("4. Salir\n");
        printf("Elija una opcion: ");
        
        // Leer la opcion que presiona el usuario3
        
        scanf("%d", &opcion);

        // Evaluar la opcion elegida
        switch(opcion) {
            case 1:
                printf("\n--- Aqui se registra la venta ---\n");
                // Aqui mi companero pegara su codigo para registrar ventas
                break;

            case 2:
                printf("\n--- Aqui se muestra el reporte del dia ---\n");
                // Aqui mi companero pegara su codigo del reporte
                break;

            case 3:
                printf("\n--- Aqui se muestra el producto mas vendido ---\n");
                // Aqui mi companero pegara su codigo del producto mas vendido
                break;

            case 4:
                printf("\nSaliendo del programa... ¡Hasta luego!\n");
                break;

            default:
                printf("\nOpcion invalida. Intente de nuevo con un numero del 1 al 4.\n");
                break;
        }

    } while(opcion != 4); // Se repite hasta que elija la opcion 4 para salir

    return 0;
}	
