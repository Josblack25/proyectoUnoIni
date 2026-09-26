#include <stdio.h>

int main()
{

    // 1. CATALOGO DE PRODUCTOS
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
    int codigo_producto;
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

    do
    {
        // Imprimir el menu de la tienda
        printf("\n=====================================\n");
        printf("  CAJARAPIDA - TIENDA ESCOLAR  \n");
        printf("======================================\n");

        printf("  1. Registrar venta de un cliente\n");
        printf("  2. Ver reporte del dia\n");
        printf("  3. Ver producto mas vendido\n");
        printf("  4. Salir\n");
        printf("======================================\n");
        printf("Elija una opcion: ");

        // Leer la opcion que presiona el usuario3

        scanf("%d", &opcion);

        // Evaluar la opcion elegida
        switch (opcion)
        {
        case 1:
            // Incrementamos el numero de cliente
            total_clientes++;

            // Reiniciamos los calculos para este nuevo cliente
            subtotal_cliente = 0.0;
            total_unidades_cliente = 0;
            descuento_cliente = 0.0;
            total_a_pagar = 0.0;

            printf("\n==================================================\n");
            printf("    >>> CLIENTE #%d\n", total_clientes);
            printf("=====================================================\n");

            printf("¿Es estudiante? (1=Si, 0=No): ");
            scanf("%d", &es_estudiante);

            /*Mostrar el catalogo de productos*/
            printf("\n=====================================\n");
            printf("        CATALOGO DE PRODUCTOS\n");
            printf("=====================================\n");
            printf("| Codigo | Nombre    | Precio | Categoria\n");
            printf("| 1      | Jugo      | $1.50  | Bebida (B001)\n");
            printf("| 2      | Agua      | $0.80  | Bebida (B002)\n");
            printf("| 3      | Papas     | $1.20  | Snack  (S001)\n");
            printf("| 4      | Cuaderno  | $2.50  | Papeleria (P001)\n");
            printf("| 5      | Lapiz     | $0.60  | Papeleria (P002)\n");
            printf("=====================================\n");

            printf("¿Cuantos productos distintos desea comprar?: ");
            scanf("%d", &cant_prod_distintos);

            // Bucle para procesar cada producto
            for (int i = 1; i <= cant_prod_distintos; i++)
            {
                int producto_valido = 0;

                while (!producto_valido)
                {
                    printf("\n--- Producto %d de %d ---\n", i, cant_prod_distintos);
                    printf("Ingrese el numero de codigo (1 al 5): ");
                    scanf("%d", &codigo_producto);

                    printf("Ingrese la cantidad que desea comprar: ");
                    scanf("%d", &cantidad_comprada);

                    // REGLA DE NEGACION (!): Validar cantidad
                    if (!(cantidad_comprada > 0))
                    {
                        printf("[ERROR] Cantidad invalida. Debe ser mayor a cero. Reintente.\n");
                        continue;
                    }

                    // Determinar el precio, la categoria y actualizar el producto individual
                    precio_actual = 0.0;
                    int categoria = 0; // 1=Bebida, 2=Snack, 3=Papeleria

                    if (codigo_producto == 1)
                    {
                        precio_actual = precio_B001;
                        categoria = 1;
                        cant_B001 += cantidad_comprada;
                    }
                    else if (codigo_producto == 2)
                    {
                        precio_actual = precio_B002;
                        categoria = 1;
                        cant_B002 += cantidad_comprada;
                    }
                    else if (codigo_producto == 3)
                    {
                        precio_actual = precio_S001;
                        categoria = 2;
                        cant_S001 += cantidad_comprada;
                    }
                    else if (codigo_producto == 4)
                    {
                        precio_actual = precio_P001;
                        categoria = 3;
                        cant_P001 += cantidad_comprada;
                    }
                    else if (codigo_producto == 5)
                    {
                        precio_actual = precio_P002;
                        categoria = 3;
                        cant_P002 += cantidad_comprada;
                    }
                    else
                    {
                        // REGLA DE NEGACION (!): Codigo invalido
                        printf("[ERROR] Codigo no existe. Elija una opcion del 1 al 5.\n");
                        continue;
                    }

                    // Si llego hasta aqui, los datos ingresados son correctos
                    producto_valido = 1;

                    // Acumular unidades por categoria para el reporte del dia
                    switch (categoria)
                    {
                    case 1:
                        unidades_bebidas += cantidad_comprada;
                        break;
                    case 2:
                        unidades_snacks += cantidad_comprada;
                        break;
                    case 3:
                        unidades_papeleria += cantidad_comprada;
                        break;
                    }

                    // Calcular subtotal del producto
                    subtotal_producto = precio_actual * cantidad_comprada;

                    // Acumular totales para este cliente y para el dia
                    subtotal_cliente += subtotal_producto;
                    total_unidades_cliente += cantidad_comprada;
                    unidades_totales += cantidad_comprada;

                    printf("-> Producto agregado exitosamente. Subtotal: $%.2f\n", subtotal_producto);
                }
            } // Fin del bucle for de productos

            // ==================================================
            //   APLICACIÓN DE REGLAS DE NEGOCIO Y LOGICA
            // ==================================================

            // 1. CONJUNCION (&&): Descuento del 10% si gasta mas de 50 y es estudiante
            if (subtotal_cliente > 50.0 && es_estudiante == 1)
            {
                descuento_cliente = subtotal_cliente * 0.10;
                aplica_descuento = 1;
            }
            else
            {
                descuento_cliente = 0.0;
                aplica_descuento = 0;
            }

            total_a_pagar = subtotal_cliente - descuento_cliente;

            // 2. DISYUNCION (||): Regalo de lapiz si subtotal > 100 O compra mas de 15 unidades
            if (subtotal_cliente > 100.0 || total_unidades_cliente > 15)
            {
                recibe_lapiz = 1;
            }
            else
            {
                recibe_lapiz = 0;
            }

            // 3. BICONDICIONAL (==): Cliente VIP
            if (((subtotal_cliente >= 80.0) == (cant_prod_distintos == 5)) && (subtotal_cliente >= 80.0))
            {
                es_vip = 1;
            }
            else
            {
                es_vip = 0;
            }

            // BICONDICIONAL (==): Envio gratis
            if (total_a_pagar > 50.0)
            {
                envio_gratis = 1;
            }
            else
            {
                envio_gratis = 0;
            }

            // --- MOSTRAR TICKET/RESUMEN AL CLIENTE ---
            printf("\n----------------------------------\n");
            printf("  RESUMEN DE COBRO - CLIENTE #%d\n", total_clientes);
            printf("----------------------------------\n");
            printf("Subtotal      : $%.2f\n", subtotal_cliente);
            printf("Descuento     : $%.2f\n", descuento_cliente);
            printf("TOTAL A PAGAR : $%.2f\n", total_a_pagar);
            printf("----------------------------------\n");

            if (recibe_lapiz)
                printf(">> Beneficio: ¡Gana un LAPIZ DE REGALO!\n");
            if (es_vip)
                printf(">> Estado   : ¡CLIENTE VIP RECONOCIDO!\n");
            if (envio_gratis)
                printf(">> Beneficio: ¡Aplica ENVIO GRATIS!\n");
            printf("----------------------------------\n");

            // --- ACTUALIZAR ACUMULADORES GLOBALES DEL DIA ---
            monto_bruto_total += subtotal_cliente;
            total_descuentos += descuento_cliente;
            monto_neto_total += total_a_pagar;

            // Determinar venta maxima y minima del dia
            if (total_clientes == 1)
            {
                venta_maxima = total_a_pagar;
                cliente_maximo = 1;
                venta_minima = total_a_pagar;
                cliente_minimo = 1;
            }
            else
            {
                if (total_a_pagar > venta_maxima)
                {
                    venta_maxima = total_a_pagar;
                    cliente_maximo = total_clientes;
                }
                if (total_a_pagar < venta_minima)
                {
                    venta_minima = total_a_pagar;
                    cliente_minimo = total_clientes;
                }
            }

            break;
        case 2:
            printf("\n--- Aqui se muestra el reporte del dia ---\n");
            //  codigo del reporte
            break;

        case 3:
            printf("\n--- Aqui se muestra el producto mas vendido ---\n");
            // Aqui codigo del producto mas vendido
            break;

        case 4:
            printf("\nSaliendo del programa... ¡Hasta luego!\n");
            break;

        default:
            printf("\nOpcion invalida. Intente de nuevo con un numero del 1 al 4.\n");
            break;
        }

    } while (opcion != 4); // Se repite hasta que elija la opcion 4 para salir

    return 0;
}
