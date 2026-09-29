/*
    ============================================================
    PROYECTO 1 - CAJARAPIDA (TIENDA ESCOLAR)
    ============================================================

    Programa en C, ejecutado en consola, que permite registrar las ventas
    de cada cliente de una tienda escolar y mostrar un reporte con las
    estadisticas del dia.

    Como esta armado el programa:
      1. Se declaran las variables (los "espacios de memoria" donde se
         guardan los datos).
      2. Hay un menu principal con un do-while y un switch.
      3. Cada opcion del menu hace su parte y despues se vuelve al menu.
      4. Las cuatro reglas de negocio usan los cuatro operadores logicos:
         conjuncion (&&), disyuncion (||), negacion (!) y bicondicional (==).

    Ideas de C que se usan en este programa:
      - Tipos de datos: int (enteros), double (decimales), char (una letra).
      - Entrada y salida: printf (mostrar) y scanf (leer del teclado).
      - Estructuras de control: if / else, for, while, do-while, switch.
      - Operadores logicos: &&, ||, ! y el operador de igualdad ==.
*/

#include <stdio.h> /* stdio.h es la libreria estandar de entrada y salida.
                      Ahi estan printf (escribir en pantalla) y
                      scanf (leer lo que el usuario escribe). */

int main() /* main es la funcion principal: el programa SIEMPRE empieza aqui.
              Se escribe int porque al terminar devuelve un entero (return 0). */
{
    /* ================================================================
       1. VARIABLES DE LOS ACUMULADORES DEL DIA
       ---------------------------------------------------------------
       Son los "contadores" que guardan el total de la jornada. Cada vez que
       se registra una venta se le suma lo nuevo, y al final se muestran en
       el reporte. Todas arrancan en 0 para que no sumen valores sueltos.
       ================================================================ */

    int total_clientes = 0;         /* cantidad de clientes atendidos */
    double monto_bruto_total = 0.0; /* suma de todos los subtotales */
    double total_descuentos = 0.0;  /* suma de todos los descuentos */
    double monto_neto_total = 0.0;  /* suma de todos los totales a pagar */

    double venta_maxima = 0.0; /* el total mas alto del dia */
    int cliente_maximo = 0;    /* numero del cliente que mas gasto */
    double venta_minima = 0.0; /* el total mas bajo del dia */
    int cliente_minimo = 0;    /* numero del cliente que menos gasto */

    /* Unidades vendidas de cada producto del catalogo.
       Son 5 porque el catalogo tiene 5 productos. */
    int cant_jugo = 0;
    int cant_agua = 0;
    int cant_papas = 0;
    int cant_cuaderno = 0;
    int cant_lapiz = 0;

    /* Unidades vendidas por categoria (para el reporte del dia) */
    int unidades_bebidas = 0;
    int unidades_snacks = 0;
    int unidades_papeleria = 0;

    /* ================================================================
       2. VARIABLES DEL MENU PRINCIPAL
       ================================================================ */

    int opcion = 0; /* guarda la opcion que escribe el usuario */

    /* ================================================================
       3. VARIABLE DE LECTURA
       ---------------------------------------------------------------
       Se usa para "limpiar" lo que quedo escrito en la linea cuando el
       usuario escribe algo que no es un numero (por ejemplo "abc").
       Sin esta limpieza el programa volveria a leer lo mismo una y otra
       vez y se quedaria trabado en un bucle infinito.
       ================================================================ */

    char caracter = ' '; /* char = una sola letra. Al final guardara el
                            caracter leido con getchar (el Enter u otro). */

    /* ================================================================
       4. VARIABLES DE LA VENTA QUE SE ESTA REGISTRANDO
       ================================================================ */

    int es_estudiante = 0;      /* 1 = Si es estudiante, 0 = No */
    int cant_prod_distintos = 0; /* cuantos productos distintos va a comprar */
    int i = 0;                  /* contador del for (cual producto va) */
    int producto_valido = 0;    /* 0 = todavia no, 1 = ya esta correcto */

    char letra_codigo = ' ';   /* letra del codigo: 'B', 'S' o 'P' */
    int numero_codigo = 0;     /* numero del codigo: 1 o 2 */
    int cantidad_comprada = 0;  /* cuantas unidades lleva de ese producto */
    int categoria = 0;         /* 1 = Bebida, 2 = Snack, 3 = Papeleria */

    /* const char * = un texto fijo. El * indica que es un puntero a texto.
       Se usa para guardar el nombre del producto: "Jugo", "Agua", etc. */
    const char *nombre_producto = "";

    double precio_actual = 0.0;     /* precio del producto segun el catalogo */
    double subtotal_producto = 0.0; /* precio x cantidad de UN producto */
    double subtotal_cliente = 0.0;  /* suma de los subtotales del cliente */
    int unidades_cliente = 0;       /* unidades totales que lleva el cliente */
    double descuento_cliente = 0.0; /* descuento que se le aplica */
    double total_a_pagar = 0.0;     /* subtotal menos el descuento */

    /* ================================================================
       5. VARIABLES DE LAS REGLAS DE NEGOCIO
       ---------------------------------------------------------------
       Cada regla guarda 1 si se cumple y 0 si no. Sirven tanto para
       calcular como para mostrar el mensaje en el ticket.
       ================================================================ */

    int aplica_descuento = 0; /* 1 = le corresponde el 10% de descuento */
    int recibe_lapiz = 0;     /* 1 = se lleva lapiz de regalo */
    int es_vip = 0;           /* 1 = es cliente VIP */
    int envio_gratis = 0;     /* 1 = el envio le sale gratis */

    /* ================================================================
       6. VARIABLES DE LOS REPORTES (se llenan en la opcion 2 y 3)
       ================================================================ */

    int unidades_totales = 0;        /* suma de las unidades de las 3 categorias */
    double promedio_cliente = 0.0;   /* monto neto / cantidad de clientes */
    double porcentaje_descuento = 0.0; /* descuentos / monto bruto * 100 */
    double porcentaje_bebidas = 0.0;   /* % de unidades que son bebidas */
    double porcentaje_snacks = 0.0;    /* % de unidades que son snacks */
    double porcentaje_papeleria = 0.0; /* % de unidades que son papeleria */
    int max_cantidad = 0;             /* unidades del producto mas vendido */
    const char *nombre_max = "Jugo";  /* nombre del producto mas vendido */
    const char *codigo_max = "B001";  /* codigo del producto mas vendido */

    /* ================================================================
       7. CICLO PRINCIPAL DEL MENU
       ---------------------------------------------------------------
       Es un do-while: primero hace (do) y despues revisa (while).
       Sirve para que el menu aparezca, el usuario elija, y luego vuelva
       a aparecer. El programa termina cuando la opcion es 4.
       La condicion tambien revisa feof(stdin): esa funcion avisa si el
       usuario ya no escribio nada (cerro la entrada con Ctrl+D), para que
       el programa no se quede esperando datos que nunca van a llegar.
       ================================================================ */

    do
    {
        /* ---------- MENU PRINCIPAL ---------- */
        printf("\n========================================\n");
        printf("CAJARAPIDA - TIENDA ESCOLAR\n");
        printf("========================================\n");
        printf("1. Registrar venta de un cliente\n");
        printf("2. Ver reporte del dia\n");
        printf("3. Ver producto mas vendido\n");
        printf("4. Salir\n");
        printf("========================================\n");
        printf("Elija una opcion: ");

        /* scanf("%d", &opcion) lee un numero entero y lo guarda en opcion.
           El & significa "la direccion de": scanf necesita saber DONDE
           dejar el dato. Si la lectura no se pudo hacer, scanf devuelve
           otra cosa y el programa avisa en vez de seguir con basura. */
        if (scanf("%d", &opcion) != 1)
        {
            /* Se lee y se descarta el resto de la linea mal escrita */
            caracter = getchar();
            while ((caracter != '\n') && (caracter != EOF))
            {
                caracter = getchar();
            }

            printf("Opcion invalida. Ingrese un numero del 1 al 4.\n");

            /* continue vuelve al inicio del do-while, o sea, al menu */
            continue;
        }

        /* ---------- SWITCH DEL MENU ----------
           Cada case es una opcion. El break corta el switch para que no
           se sigan revisando los demas case. El default se usa cuando la
           opcion no es ninguna de las cuatro. */
        switch (opcion)
        {
        /* ============================================================
           CASO 1: REGISTRAR VENTA DE UN CLIENTE
           ============================================================ */
        case 1:
            /* Se incrementa el numero de cliente para saber cuantos van */
            total_clientes++;

            /* Se reinician los calculos del cliente para empezar de cero */
            subtotal_cliente = 0.0;
            unidades_cliente = 0;
            descuento_cliente = 0.0;
            total_a_pagar = 0.0;

            printf("\n==================================================\n");
            printf(">>> CLIENTE #%d\n", total_clientes);
            printf("==================================================\n");

            /* --- Pregunta 1: es estudiante (solo se admite 1 o 0) ---
               El do-while repite la pregunta mientras la respuesta no sea
               valida. En el scanf se coloca -1 como valor trampa: si la
               lectura falla, es_estudiante queda en -1 (un valor que de
               entrada no es valido) y por eso vuelve a preguntar. */
            do
            {
                printf("Es estudiante? (1=Si / 0=No): ");

                if (scanf("%d", &es_estudiante) != 1)
                {
                    /* Se descarta el resto de la linea mal escrita */
                    caracter = getchar();
                    while ((caracter != '\n') && (caracter != EOF))
                    {
                        caracter = getchar();
                    }

                    es_estudiante = -1;
                }

                if ((es_estudiante != 0) && (es_estudiante != 1))
                {
                    printf("[ERROR] Ingrese 1 (Si) o 0 (No).\n");
                }
            } while ((es_estudiante != 0) && (es_estudiante != 1) && (feof(stdin) == 0));

            /* --- Pregunta 2: cuantos productos distintos compra ---
               Misma idea que la pregunta anterior, pero aqui el valor
               trampa es -1 porque debe comprar al menos 1 producto. */
            do
            {
                printf("Cuantos productos distintos compra?: ");

                if (scanf("%d", &cant_prod_distintos) != 1)
                {
                    caracter = getchar();
                    while ((caracter != '\n') && (caracter != EOF))
                    {
                        caracter = getchar();
                    }

                    cant_prod_distintos = -1;
                }

                if (cant_prod_distintos < 1)
                {
                    printf("[ERROR] Debe comprar al menos 1 producto.\n");
                }
            } while ((cant_prod_distintos < 1) && (feof(stdin) == 0));

            /* Se muestra el catalogo para que el cajero sepa los codigos */
            printf("\nCatalogo: B001 Jugo $1.50 | B002 Agua $0.80 | S001 Papas $1.20\n");
            printf("          P001 Cuaderno $2.50 | P002 Lapiz $0.60\n");

            /* ---------- FOR: un producto por cada vez ----------
               i va desde 1 hasta la cantidad de productos pedidos. */
            for (i = 1; (i <= cant_prod_distintos) && (feof(stdin) == 0); i++)
            {
                producto_valido = 0;

                /* ---------- WHILE: repetir hasta que el dato sea correcto ----------
                   Se usa porque hace falta preguntar otra vez cuando el cajero
                   escribe un codigo o una cantidad que no sirve. */
                while ((producto_valido == 0) && (feof(stdin) == 0))
                {
                    printf("\n--- Producto %d ---\n", i);
                    printf("Codigo: ");

                    /* Valores trampa: si la lectura falla, el codigo queda
                       como '?' y el switch de abajo lo toma como inexistente. */
                    letra_codigo = '?';
                    numero_codigo = 0;

                    /* %c lee UNA letra y %d lee el numero del codigo.
                       El espacio antes de %c ignora el Enter que quedo
                       de la pregunta anterior. Se espera leer 2 datos, por eso
                       se compara con != 2 (si el codigo es "B001", el %c
                       lee la 'B' y el %d lee el 001, que es 1). */
                    if (scanf(" %c%d", &letra_codigo, &numero_codigo) != 2)
                    {
                        caracter = getchar();
                        while ((caracter != '\n') && (caracter != EOF))
                        {
                            caracter = getchar();
                        }
                    }

                    printf("Cantidad: ");
                    cantidad_comprada = 0; /* valor trampa si la lectura falla */

                    if (scanf("%d", &cantidad_comprada) != 1)
                    {
                        caracter = getchar();
                        while ((caracter != '\n') && (caracter != EOF))
                        {
                            caracter = getchar();
                        }
                    }

                    /* --- REGLA DE NEGACION (!) ---
                       Si la cantidad NO es mayor que cero, el producto se
                       cancela y se vuelve a preguntar. El operador ! niega
                       la condicion: !(cantidad > 0) es verdadero cuando la
                       cantidad es 0 o negativa. */
                    if (!(cantidad_comprada > 0))
                    {
                        printf("[ERROR] Cantidad invalida. Debe ser mayor a cero. Reintente.\n");
                        continue;
                    }

                    /* ---------- CATALOGO DE PRODUCTOS ----------
                       Aqui se busca el precio, el nombre y la categoria del
                       producto que escribio el cajero. Cada codigo tiene una
                       letra (B, S o P) y un numero (1 o 2), asi que basta con
                       comparar los dos: por ejemplo, si la letra es 'B' y el
                       numero es 1, el producto es el Jugo.

                       El += es una forma corta de escribir:
                       cant_jugo = cant_jugo + cantidad_comprada; */
                    if ((letra_codigo == 'B') && (numero_codigo == 1))
                    {
                        /* Jugo - Bebida */
                        precio_actual = 1.50;
                        nombre_producto = "Jugo";
                        categoria = 1;
                        cant_jugo += cantidad_comprada;
                    }
                    else if ((letra_codigo == 'B') && (numero_codigo == 2))
                    {
                        /* Agua - Bebida */
                        precio_actual = 0.80;
                        nombre_producto = "Agua";
                        categoria = 1;
                        cant_agua += cantidad_comprada;
                    }
                    else if ((letra_codigo == 'S') && (numero_codigo == 1))
                    {
                        /* Papas - Snack */
                        precio_actual = 1.20;
                        nombre_producto = "Papas";
                        categoria = 2;
                        cant_papas += cantidad_comprada;
                    }
                    else if ((letra_codigo == 'P') && (numero_codigo == 1))
                    {
                        /* Cuaderno - Papeleria */
                        precio_actual = 2.50;
                        nombre_producto = "Cuaderno";
                        categoria = 3;
                        cant_cuaderno += cantidad_comprada;
                    }
                    else if ((letra_codigo == 'P') && (numero_codigo == 2))
                    {
                        /* Lapiz - Papeleria */
                        precio_actual = 0.60;
                        nombre_producto = "Lapiz";
                        categoria = 3;
                        cant_lapiz += cantidad_comprada;
                    }
                    else
                    {
                        /* --- REGLA DE NEGACION (!) ---
                           Si el codigo no existe en el catalogo, el producto
                           se cancela y el cajero puede reintentar. */
                        printf("[ERROR] El codigo %c%d no existe en el catalogo.\n", letra_codigo, numero_codigo);
                        printf("        Use B001, B002, S001, P001 o P002.\n");
                        continue;
                    }

                    /* El producto ya esta bien: se sale del while */
                    producto_valido = 1;

                    /* ---------- CATEGORIAS CON SWITCH/CASE ----------
                       El catalogo ya dio la categoria del producto:
                       1 = Bebida, 2 = Snack, 3 = Papeleria.
                       Aqui se cuentan las unidades de cada categoria para el
                       reporte del dia. El enunciado pide que las categorias
                       se manejen con un switch/case, y eso hace este bloque.
                       Solo hace falta un break porque despues el producto
                       entra en la lista de la venta. */
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

                    /* --- CALCULO DEL SUBTOTAL DEL PRODUCTO ---
                       precio x cantidad. %.2f muestra el numero con 2
                       decimales (por ejemplo 3.00). */
                    subtotal_producto = precio_actual * cantidad_comprada;
                    subtotal_cliente += subtotal_producto;
                    unidades_cliente += cantidad_comprada;

                    printf("-> %s x%d = %.2f\n", nombre_producto, cantidad_comprada, subtotal_producto);
                }
            }

            /* --- REGLA DE NEGACION (!) ---
               Si la venta se quedo a medias (por ejemplo si el cajero cerro
               la entrada con Ctrl+D), el subtotal sigue en 0. En ese caso no
               se cobra nada y el cliente no cuenta para el dia, por eso se
               descuenta con total_clientes--. */
            if (!(subtotal_cliente > 0.0))
            {
                printf("[ERROR] La compra no tiene productos. No se puede cobrar.\n");
                total_clientes--;
                break;
            }

            /* ================================================================
               REGLAS DE NEGOCIO (cada una con su operador logico)
               ================================================================ */

            /* --- REGLA DE CONJUNCION (&&) ---
               Descuento del 10% si el cliente gasta mas de 50 Y es estudiante.
               El && significa "y": las dos condiciones tienen que ser
               verdaderas (si una sola es falsa, todo el resultado es falso). */
            aplica_descuento = (subtotal_cliente > 50.0) && (es_estudiante == 1);

            /* El operador ?: es un "si - sino" en una sola linea:
               si aplica_descuento es 1, el descuento es el 10%, si no, es 0. */
            descuento_cliente = aplica_descuento ? (subtotal_cliente * 0.10) : 0.0;
            total_a_pagar = subtotal_cliente - descuento_cliente;

            /* --- REGLA DE DISYUNCION (||) ---
               Lapiz de regalo si gasta mas de 100 O compra mas de 15 unidades.
               El || significa "o": basta con que una de las dos condiciones
               sea verdadera para que el resultado sea verdadero. */
            recibe_lapiz = (subtotal_cliente > 100.0) || (unidades_cliente > 15);

            /* --- REGLA DE BICONDICIONAL (==) ---
               Cliente VIP si y solo si gasta al menos 80 Y lleva 5 productos
               distintos. El == compara dos condiciones: si las dos valen 1
               (verdadero) el resultado es 1, o sea, es VIP. */
            es_vip = ((subtotal_cliente >= 80.0) && (cant_prod_distintos == 5)) == 1;

            /* --- REGLA DE BICONDICIONAL (==) ---
               El envio es gratis si y solo si el monto del cliente supera
               los 50. Misma idea que la regla anterior. */
            envio_gratis = (total_a_pagar > 50.0) == 1;

            /* ---------- TICKET DEL CLIENTE ---------- */
            printf("\n----------------------------------\n");
            printf("Subtotal : %.2f\n", subtotal_cliente);
            printf("Descuento : %.2f\n", descuento_cliente);
            printf("TOTAL A PAGAR : %.2f\n", total_a_pagar);
            printf("----------------------------------\n");

            /* Se muestran los beneficios que le tocan al cliente */
            if (recibe_lapiz == 1)
            {
                printf(">> Beneficio: Gana un LAPIZ DE REGALO!\n");
            }
            if (aplica_descuento == 1)
            {
                printf(">> Beneficio: Descuento de estudiante aplicado!\n");
            }
            if (es_vip == 1)
            {
                printf(">> Estado: CLIENTE VIP!\n");
            }
            if (envio_gratis == 1)
            {
                printf(">> Beneficio: ENVIO GRATIS!\n");
            }

            /* ---------- SE SUMA ESTA VENTA A LOS ACUMULADORES DEL DIA ---------- */
            monto_bruto_total += subtotal_cliente;
            total_descuentos += descuento_cliente;
            monto_neto_total += total_a_pagar;

            /* ---------- VENTA MAXIMA Y VENTA MINIMA ----------
               El primer cliente del dia es la base: su venta es por ahora
               la maxima y la minima. Despues se compara cada venta nueva
               con esos dos valores y se guardan tambien los numeros de
               cliente, para poder avisar de quien fue. */
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

        /* ============================================================
           CASO 2: VER EL REPORTE DEL DIA
           ============================================================ */
        case 2:
            printf("\n==================================================\n");
            printf("REPORTE FINAL DEL DIA - CAJARAPIDA\n");
            printf("==================================================\n");

            /* Si todavia no hay clientes no hay nada que mostrar */
            if (total_clientes == 0)
            {
                printf("Aun no se han registrado ventas el dia de hoy.\n");
                break;
            }

            /* Se suman las unidades de las 3 categorias para tener el total
               de unidades vendidas y poder sacar los porcentajes. */
            unidades_totales = unidades_bebidas + unidades_snacks + unidades_papeleria;

            /* ---------- CALCULOS DEL REPORTE ---------- */

            /* Promedio por cliente: monto neto / cantidad de clientes */
            promedio_cliente = monto_neto_total / total_clientes;

            /* Porcentaje de descuento: descuentos / monto bruto * 100 */
            porcentaje_descuento = (total_descuentos / monto_bruto_total) * 100.0;

            /* Porcentaje de cada categoria: unidades de la categoria /
               unidades totales * 100. El (double) se pone para indicar que
               la division es con decimales y no se pierdan unidades. */
            porcentaje_bebidas = (unidades_bebidas / (double)unidades_totales) * 100.0;
            porcentaje_snacks = (unidades_snacks / (double)unidades_totales) * 100.0;
            porcentaje_papeleria = (unidades_papeleria / (double)unidades_totales) * 100.0;

            /* ---------- SE MUESTRA EL REPORTE ----------
               %d muestra un numero entero y %.2f muestra un decimal con
               dos cifras. El %% imprime un signo % literal. */
            printf("Clientes atendidos    : %d\n", total_clientes);
            printf("Monto bruto total     : %.2f\n", monto_bruto_total);
            printf("Descuentos otorgados  : %.2f ( %.2f %% )\n", total_descuentos, porcentaje_descuento);
            printf("MONTO NETO RECAUDADO  : %.2f\n", monto_neto_total);
            printf("Promedio por cliente  : %.2f\n", promedio_cliente);
            printf("Venta maxima          : %.2f (Cliente #%d)\n", venta_maxima, cliente_maximo);
            printf("Venta minima          : %.2f (Cliente #%d)\n", venta_minima, cliente_minimo);
            printf("--- Ventas por categoria ---\n");
            printf("Bebidas   : %d unidades -> %.2f %%\n", unidades_bebidas, porcentaje_bebidas);
            printf("Snacks    : %d unidades -> %.2f %%\n", unidades_snacks, porcentaje_snacks);
            printf("Papeleria : %d unidades -> %.2f %%\n", unidades_papeleria, porcentaje_papeleria);
            printf("==================================================\n");

            break;

        /* ============================================================
           CASO 3: VER EL PRODUCTO MAS VENDIDO
           ============================================================ */
        case 3:
            printf("\n==================================================\n");
            printf("PRODUCTOS MAS VENDIDOS\n");
            printf("==================================================\n");

            if (total_clientes == 0)
            {
                printf("Aun no se han registrado ventas el dia de hoy.\n");
                break;
            }

            /* Se muestra cuanto se vendio de cada uno de los 5 productos */
            printf("Jugo (B001)      : %d unidades\n", cant_jugo);
            printf("Agua (B002)      : %d unidades\n", cant_agua);
            printf("Papas (S001)     : %d unidades\n", cant_papas);
            printf("Cuaderno (P001)  : %d unidades\n", cant_cuaderno);
            printf("Lapiz (P002)     : %d unidades\n", cant_lapiz);
            printf("----------------------------------\n");

            /* ---------- BUSQUEDA DEL MAXIMO ----------
               Se toma el Jugo como punto de partida y se compara con los
               otros 4 productos. Cada vez que uno tiene mas unidades que el
               actual ganador, ese producto pasa a ser el nuevo ganador. */
            max_cantidad = cant_jugo;
            nombre_max = "Jugo";
            codigo_max = "B001";

            if (cant_agua > max_cantidad)
            {
                max_cantidad = cant_agua;
                nombre_max = "Agua";
                codigo_max = "B002";
            }
            if (cant_papas > max_cantidad)
            {
                max_cantidad = cant_papas;
                nombre_max = "Papas";
                codigo_max = "S001";
            }
            if (cant_cuaderno > max_cantidad)
            {
                max_cantidad = cant_cuaderno;
                nombre_max = "Cuaderno";
                codigo_max = "P001";
            }
            if (cant_lapiz > max_cantidad)
            {
                max_cantidad = cant_lapiz;
                nombre_max = "Lapiz";
                codigo_max = "P002";
            }

            printf(">>> PRODUCTO MAS VENDIDO: %s (%s) con %d unidades\n", nombre_max, codigo_max, max_cantidad);
            printf("==================================================\n");

            break;

        /* ============================================================
           CASO 4: SALIR DEL PROGRAMA
           ============================================================ */
        case 4:
            printf("\nSaliendo del programa... Hasta luego!\n");
            break;

        /* Si el usuario escribe un numero que no es 1, 2, 3 ni 4 */
        default:
            printf("Opcion invalida. Ingrese un numero del 1 al 4.\n");
            break;
        }

    } while ((opcion != 4) && (feof(stdin) == 0));

    /* Si el usuario cerro la entrada con Ctrl+D, tambien se despide */
    if (feof(stdin) != 0)
    {
        printf("\nSaliendo del programa... Hasta luego!\n");
    }

    return 0; /* 0 significa que el programa termino sin errores */
}
