/* Menú Principal, Control de Flujo y Salida (Líder / Integrador)
Tarea: Crear la estructura del main(), el bucle do-while y el switch-case del menú.

Responsabilidad clave: Asegurarse de que el programa no se rompa si el usuario mete un número inválido en el menú (Opción 4 para salir de forma limpia). Es quien une las partes de todos al final.
*/

#include <stdio.h>
int main() {
    int opcion;

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
