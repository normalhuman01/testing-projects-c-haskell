-- Pregunta 4: Insertar un cliente en una posición arbitraria de la cola
insertarEnPosicion :: ListaCola -> Cliente -> Int -> ListaCola
insertarEnPosicion listaCola nuevoCliente posicion
    | posicion < 0 || posicion > length (clientes listaCola) = listaCola
    | otherwise = ListaCola {
        capacidadMaxima = capacidadMaxima listaCola,
        clientes = parteAnterior ++ [nuevoCliente] ++ partePosterior
    }
    where
        (parteAnterior, partePosterior) = splitAt posicion (clientes listaCola)
