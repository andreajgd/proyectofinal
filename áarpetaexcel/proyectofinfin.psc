Algoritmo Normal
	
	
	
	Definir op Como Entero
	
	
	
	Mientras (op <> 4)
		
		Escribir "-----------------------------------------------------------------"
		
		Escribir "                         MENU"
		
		Escribir "-----------------------------------------------------------------"
		
		Escribir "Elige una de las opciones siguientes:"
		
		Escribir "1. øDeseas ver nuestros servicios?"
		
		Escribir "2. øDeseas agendar una cita?"
		
		Escribir "3. øDeseas ver nuestros productos?"
		
		Escribir "4. Salir."
		
		Leer op
		
		
		
		Segun op Hacer
			
			Caso 1:
				
				Escribir "1. CALZAS DENTALES."
				
				Escribir "2. ORTODONCIA."
				
				Escribir "3. LIMPIEZA."
				
				Escribir "øDeseas agendar alguno de nuestros servicios?"
				
				Escribir "Escribe 1 para confirmar."
				
				Escribir "Escribe 2 para volver al men? principal."
				
				Escribir "Escribe otra tecla para salir."
				
				Leer confirmar
				
				Si confirmar = 1 Entonces
					
					agendarCita()
					
				FinSi
				
			Caso 2:
				
				agendarCita()
				
			Caso 3:
				
				mostrarProductos()
				
			De Otro Modo:
				
				Escribir "Ingrese una opciÛn v·lida"
				
		FinSegun
		
	FinMientras
	
	
	
	
	
	
	
FinAlgoritmo



SubProceso agendarCita
	
	Definir diasEnMes, diaSemanaInicio, i Como Entero
	
	
	
	Escribir "Ingresa los datos de su cita:"
	
	Escribir "Mes (1-12):"
	
	Leer mes
	
	
	
	Segun mes Hacer
		
		Caso 1: mesTexto = "ENERO"; diasEnMes = 31; diaSemanaInicio = 1
			
		Caso 2: mesTexto = "FEBRERO"; diasEnMes = 28; diaSemanaInicio = 4
			
		Caso 3: mesTexto = "MARZO"; diasEnMes = 31; diaSemanaInicio = 4
			
		Caso 4: mesTexto = "ABRIL"; diasEnMes = 30; diaSemanaInicio = 7
			
		Caso 5: mesTexto = "MAYO"; diasEnMes = 31; diaSemanaInicio = 2
			
		Caso 6: mesTexto = "JUNIO"; diasEnMes = 30; diaSemanaInicio = 5
			
		Caso 7: mesTexto = "JULIO"; diasEnMes = 31; diaSemanaInicio = 7
			
		Caso 8: mesTexto = "AGOSTO"; diasEnMes = 31; diaSemanaInicio = 3
			
		Caso 9: mesTexto = "SEPTIEMBRE"; diasEnMes = 30; diaSemanaInicio = 6
			
		Caso 10: mesTexto = "OCTUBRE"; diasEnMes = 31; diaSemanaInicio = 1
			
		Caso 11: mesTexto = "NOVIEMBRE"; diasEnMes = 30; diaSemanaInicio = 4
			
		Caso 12: mesTexto = "DICIEMBRE"; diasEnMes = 31; diaSemanaInicio = 6
			
	FinSegun
	
	
	
	Escribir "Fechas disponibles en color blanco, las grises ya est·n reservadas."
	
	Escribir "Mes: ", mesTexto
	
	Escribir "DOM      LUN      MAR      MIE      JUE      VIE      SAB"
	
	i = 1
	
	Mientras  (i < diaSemanaInicio) Hacer
		
		Escribir "         "
		
		i = i + 1
		
	FinMientras
	
	
	
	Para dia = 1 Hasta diasEnMes Con Paso 1 Hacer
		
		Escribir dia, "       "
		
		Si (diaSemanaInicio Mod 7) = 0 Entonces
			
			Escribir ""
			
		FinSi
		
		diaSemanaInicio = diaSemanaInicio + 1
		
	FinPara
	
	
	
	Escribir "øDeseas agendar una cita en las fechas disponibles? (s/n)"
	
	Leer confirmar
	
	Si confirmar = "s" Entonces
		
		Escribir "Ingrese los datos para agendar su cita."
		
		Escribir "Ingresa el dÌa de la cita (1-31):"
		
		Leer dia
		
		Escribir "Ingresa la hora de la cita (8-11, 13-17, excluyendo las 12):"
		
		Leer hora
		
		Escribir "Fecha y hora agendadas correctamente."
		
		Escribir "Ingresa el nombre del paciente:"
		
		Leer nombre
		
		Escribir "Ingresa el apellido del paciente:"
		
		Leer apellido
		
		Escribir "Ingresa el n?mero de contacto del paciente:"
		
		Leer telefono
		
		Escribir "Ingresa el correo del paciente:"
		
		Leer correo
		
	FinSi
	
FinSubProceso



SubProceso mostrarProductos
	
    Definir producto, cantidad, categoria, indiceFactura Como Entero
	
    Dimension categorias[4,6,3]
	
    Dimension num_productos[3]
	
    Dimension DatosFactura[100,4]
	
    Definir precioUnitario, totalProducto, subtotal, iva, total Como Real
	
    Definir productosTexto, cantidadesTexto, preciosTexto, totalesTexto Como Cadena
	
	
	
	Limpiar Pantalla
	
	
	
    categorias[1, 1, 1] <- "Cepillos est·ndar"
	
    categorias[1, 1, 2] <- "1.5"
	
    categorias[1, 2, 1] <- "Cepillos elÈctricos"
	
    categorias[1, 2, 2] <- "15.0"
	
    categorias[1, 3, 1] <- "Cepillos interdentales"
	
    categorias[1, 3, 2] <- "2.0"
	
    categorias[1, 4, 1] <- "Cepillos para niÒos"
	
    categorias[1, 4, 2] <- "1.0"
	
    num_productos[1] <- 4
	
	
	
    categorias[2, 1, 1] <- "Enjuague bucal sensitive"
	
    categorias[2, 1, 2] <- "3.0"
	
    categorias[2, 2, 1] <- "Enjuague bucal terapÈutico"
	
    categorias[2, 2, 2] <- "3.5"
	
    categorias[2, 3, 1] <- "Spray mentol"
	
    categorias[2, 3, 2] <- "2.5"
	
    categorias[2, 4, 1] <- "Limpiador de lengua"
	
    categorias[2, 4, 2] <- "1.5"
	
    categorias[2, 5, 1] <- "Pasta dental con o sin fluor"
	
    categorias[2, 5, 2] <- "2.0"
	
    num_productos[2] <- 5
	
	
	
    categorias[3, 1, 1] <- "Cera para brackets"
	
    categorias[3, 1, 2] <- "1.2"
	
    categorias[3, 2, 1] <- "Ligas surtidas"
	
    categorias[3, 2, 2] <- "0.5"
	
    categorias[3, 3, 1] <- "Gel para aftas y llagas bucales"
	
    categorias[3, 3, 2] <- "3.0"
	
    num_productos[3] <- 3
	
	
	
	categoria = 1
	
	indiceFactura = 1
	
	productosTexto = ""
	
	cantidadesTexto = ""
	
	preciosTexto = ""
	
	totalesTexto = ""
	
	subtotal = 0
	
	iva = 0
	
	total = 0
	
	
	
	Mientras (categoria <> 0)
		
		Escribir "========== PRODUCTOS ============"
		
		Escribir "1. Cepillos dentales"
		
		Escribir "2. Higiene bucal"
		
		Escribir "3. Articulos para brackets"
		
		Escribir "0. Regresar"
		
		Escribir "Seleccione una opciÛn (0 para regresar):"
		
		Leer categoria
		
		
		
        Si categoria >= 1 Y categoria <= 3 Entonces
			
            Escribir "Productos en la categorÌa seleccionada:"
			
            Para producto = 1 Hasta num_productos[categoria] Con Paso 1 Hacer
				
                Escribir producto, ". ", categorias[categoria, producto, 1], " - $", categorias[categoria, producto, 2]
				
            Fin Para
			
			
			
			// Seleccionar productos
			
            Repetir
				
                Escribir "Seleccione un producto (0 para terminar):"
				
                Leer producto
				
                Si producto > 0 Y producto <= num_productos[categoria] Entonces
					
                    Escribir "Ingrese la cantidad:"
					
                    Leer cantidad
					
					
					
                    precioUnitario <- ConvertirANumero(categorias[categoria, producto, 2])
					
                    totalProducto  <- precioUnitario * cantidad
					
					
					
                    cantidadesTexto <- convertirATexto(cantidad)
					
                    preciosTexto <- "$" + categorias[categoria, producto, 2]
					
                    totalesTexto <- "$" + convertirATexto(totalProducto)
					
					
					
					DatosFactura[indiceFactura, 1] <- categorias[categoria, producto, 1]
					
                    DatosFactura[indiceFactura, 2] <- preciosTexto
					
                    DatosFactura[indiceFactura, 3] <- cantidadesTexto
					
                    DatosFactura[indiceFactura, 4] <- totalesTexto
					
                    indiceFactura <- indiceFactura + 1
					
                Fin Si
				
            Hasta Que producto = 0
			
			subtotal <- subtotal + totalProducto
			
			iva <- subtotal * 0.15
			
		fin si
		
	FinMientras
	
	generarFactura(DatosFactura, indiceFactura, subtotal, iva, total)
	
FinSubProceso



SubProceso generarFactura(DatosFactura, indiceFactura, subtotal, iva, total)
	
	
	
	
	
	
	
	Escribir "---------------------------------------------"
	
	Escribir "                  FACTURA"
	
	Escribir "---------------------------------------------"
	
	Escribir "---------------------------------------------"
	
	Escribir "                  "
	
	Escribir "Producto            Precio    Cantidad  Total"
	
	Escribir "---------------------------------------------"
	
	
	
	Definir i Como Entero
	
    Para i = 1 Hasta indiceFactura Con Paso 1 Hacer
		
		Escribir DatosFactura[i, 1], "      ", DatosFactura[i, 2], "    ", DatosFactura[i, 3], "  ", DatosFactura[i, 4]
		
    Fin Para	
	
	Escribir "---------------------------------------------"
	
	Escribir "Subtotal                                ", subtotal
	
	Escribir "IVA (15%)                               ", iva
	
	Escribir "Total                                   ", total
	
	Escribir "---------------------------------------------"
	
	
	
FinSubProceso



 
