# CAJARAPIDA - Tienda Escolar

Programa en C (modo consola) para registrar las ventas del dia de una tienda escolar
y generar el reporte de caja al final de la jornada.

## Compilar y ejecutar

```bash
gcc main.c -o main
./main
```

## Catalogo de productos

| Codigo | Nombre   | Precio | Categoria |
|--------|----------|--------|-----------|
| B001   | Jugo     | 1.50   | Bebida    |
| B002   | Agua     | 0.80   | Bebida    |
| S001   | Papas    | 1.20   | Snack     |
| P001   | Cuaderno | 2.50   | Papeleria |
| P002   | Lapiz    | 0.60   | Papeleria |

## Reglas de negocio y operador logico usado

| Regla | Operador |
|-------|----------|
| Descuento del 10% si gasta mas de 50 **y** es estudiante | Conjuncion `&&` |
| Lapiz de regalo si gasta mas de 100 **o** compra mas de 15 unidades | Disyuncion `\|\|` |
| Se cancela el producto si la cantidad no es mayor a cero o el codigo no existe | Negacion `!` |
| Cliente VIP si y solo si gasta al menos 80 **y** lleva 5 productos distintos | Bicondicional `==` |
| Envio gratis si y solo si el monto del cliente supera 50 | Bicondicional `==` |

## Opciones del menu

1. Registrar venta de un cliente
2. Ver reporte del dia (clientes, bruto, descuentos, neto, promedio, venta maxima y minima, ventas por categoria)
3. Ver producto mas vendido (unidades de cada producto y el ganador)
4. Salir

## Reparto de funciones (6 roles)

- **Integrante 1 - Menu Principal, Control de Flujo y Salida (Lider / Integrador)**
  Crear la estructura del `main()`, el bucle `do-while` y el `switch-case` del menu.
  Asegurarse de que el programa no se rompa si el usuario mete un numero invalido en el
  menu (opcion 4 para salir de forma limpia). Es quien une las partes de todos al final.

- **Integrante 2 - Captura de Cliente y Catalogo (Entrada de Datos)**
  La primera parte de la opcion 1 (Registrar Venta): pedir si es estudiante, pedir cuantos
  productos compra, validar los codigos del catalogo (B001, S001, etc.) e identificar a que
  categoria pertenecen (Bebida, Snack, Papeleria). Si el codigo no existe o la cantidad es
  menor o igual a 0, aplicar la regla de Negacion (`!`).

- **Integrante 3 - Motor de Reglas de Negocio (Logica de Cobro)**
  La segunda parte de la opcion 1 (Calculos por cliente): calcular el subtotal, aplicar la
  Conjuncion (`&&`) para el descuento del 10%, la Disyuncion (`||`) para el lapiz de regalo y
  las Bicondicionales (`==`) para cliente VIP y envio gratis. Imprimir el ticket del cliente.

- **Integrante 4 - Acumuladores y Estadisticas Generales del Dia**
  La parte de la opcion 2 (Ver reporte del dia): llevar los acumuladores de clientes
  atendidos, monto bruto, total de descuentos y monto neto. Calcular el promedio por cliente
  y el porcentaje de descuento respecto al monto bruto.

- **Integrante 5 - Registro de Ventas Maxima / Minima y Categorias**
  La otra parte de la opcion 2 (Filtros y Metricas avanzadas): comparar la venta de cada
  cliente para determinar la Venta Maxima y la Venta Minima guardando el numero de cliente
  asociado, acumular las unidades por categoria y calcular su porcentaje sobre el total.

- **Integrante 6 - Inventario y Producto Mas Vendido**
  La opcion 3 (Ver producto mas vendido): llevar el contador individual de cada uno de los
  5 productos, determinar cual tuvo la mayor cantidad acumulada e imprimir el resumen de
  cada producto junto con el ganador.
