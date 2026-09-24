👥 Reparto de Funciones (6 Roles)

    👤 Integrante 1: Menú Principal, Control de Flujo y Salida (Líder / Integrador)Tarea: Crear la estructura del main(), el bucle do-while y el switch-case del menú.Responsabilidad clave: Asegurarse de que el programa no se rompa si el usuario mete un número inválido en el menú (Opción 4 para salir de forma limpia). Es quien une las partes de todos al final.
    
    👤 Integrante 2: Captura de Cliente y Catálogo (Entrada de Datos)Tarea: La primera parte de la Opción 1 (Registrar Venta).Responsabilidad clave:Pedir si es estudiante.Pedir cuántos productos comprará.Validar los códigos del catálogo (B001, S001, etc.) usando strcmp e identificar a qué categoría pertenecen (Bebida, Snack, Papelería). Si el código no existe o la cantidad es $\le 0$, aplicar la regla de Negación (!).
    
    👤 Integrante 3: Motor de Reglas de Negocio (Lógica de Cobro)Tarea: La segunda parte de la Opción 1 (Cálculos por cliente).Responsabilidad clave:Calcular el subtotal del cliente.Aplicar la Conjunción (&&) para el descuento del 10% (Estudiante Y > 50).Aplicar la Disyunción (||) para el lápiz de regalo (> 100 O > 15 unidades).Aplicar las Bicondicionales (==) para cliente VIP y Envío Gratis.Imprimir la factura/ticket del cliente individual.
    
    👤 Integrante 4: Acumuladores y Estadísticas Generales del DíaTarea: Parte de la Opción 2 (Ver reporte del día).Responsabilidad clave:Llevar las variables globales o acumuladores: clientes atendidos, monto bruto acumulado, total de descuentos otorgados, monto neto recaudado.Calcular el promedio de gasto por cliente ($Neto / Clientes$).Calcular el porcentaje de descuento respecto al monto bruto ($Descuentos / Bruto \times 100$).
    
    👤 Integrante 5: Rrecord de Ventas Máxima / Mínima y CategoríasTarea: La otra parte de la Opción 2 (Filtros y Métricas avanzadas).Responsabilidad clave:Comparar la venta de cada cliente para determinar cuál fue la Venta Máxima y la Venta Mínima (guardando el número de cliente asociado).Acumular las unidades vendidas por categoría (Bebidas, Snacks, Papelería) y calcular su porcentaje sobre el total de unidades.
    
    👤 Integrante 6: Inventario y Producto Más VendidoTarea: Opción 3 (Ver producto más vendido).Responsabilidad clave:Llevar el contador individual de cada uno de los 5 productos (cant_jugo, cant_agua, etc.).Determinar cuál de los 5 productos tuvo la mayor cantidad acumulada (algoritmo de búsqueda de máximo entre 5 valores).Diseñar e imprimir la pantalla que muestra el resumen de cada producto y resalta el ganador.# proyectoUnoIni
