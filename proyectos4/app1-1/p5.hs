-- Pregunta 5: Intercambiar posiciones de clientes en la cola
intercambiarPosiciones :: ListaCola -> Int -> Int -> ListaCola
intercambiarPosiciones listaCola i j
    | i < 0 || j < 0 || i >= length (clientes listaCola) || j >= length (clientes listaCola) = listaCola
    | otherwise = do
        let (listaSinI, maybeClienteI) = sacarDeLaCola listaCola
        case maybeClienteI of
            Just clienteI -> do
                let (listaSinJ, maybeClienteJ) = sacarDeLaCola listaSinI
                case maybeClienteJ of
                    Just clienteJ -> do
                        let listaConIEnJ = insertarEnPosicion listaSinJ clienteI j
                        let listaConJEnI = insertarEnPosicion listaConIEnJ clienteJ i
                        listaConJEnI
                    Nothing -> listaSinI
            Nothing -> listaCola
