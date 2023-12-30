-- Pregunta 3: Sacar a una persona de la cola y retornarla
sacarDeLaCola :: ListaCola -> (ListaCola, Maybe Cliente)
sacarDeLaCola listaCola
    | null (clientes listaCola) = (listaCola, Nothing)
    | otherwise = (nuevaLista, Just clienteAtendido)
    where
        clienteAtendido = head (clientes listaCola)
        nuevaLista = ListaCola {
            capacidadMaxima = capacidadMaxima listaCola,
            clientes = tail (clientes listaCola)
        }
