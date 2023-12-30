data Cliente = Cliente {
    nombre :: String,
    dni :: String,
    cantidadEntradas :: Int
} deriving (Show)

data ListaCola = ListaCola {
    capacidadMaxima :: Int,
    clientes :: [Cliente]
} deriving (Show)

-- Constructor de ListaCola
crearListaCola :: Int -> ListaCola
crearListaCola capacidad = ListaCola {
    capacidadMaxima = capacidad,
    clientes = []
}

-- Método para encolar un cliente
encolar :: ListaCola -> String -> String -> Int -> Int
encolar listaCola nombreCliente dniCliente cantEntradas
    | length (clientes listaCola) >= capacidadMaxima listaCola = -1
    | otherwise = length (clientes listaCola) - indice
    where
        nuevoCliente = Cliente {
            nombre = nombreCliente,
            dni = dniCliente,
            cantidadEntradas = cantEntradas
        }
        nuevaLista = clientes listaCola ++ [nuevoCliente]
        indice = length nuevaLista

-- Método para atender al cliente que está primero en la cola
atender :: ListaCola -> IO ()
atender listaCola
    | null (clientes listaCola) = putStrLn "La cola está vacía"
    | otherwise = do
        let clienteAtendido = head (clientes listaCola)
        putStrLn $ "Cliente atendido: " ++ nombre clienteAtendido ++
                   ", DNI: " ++ dni clienteAtendido ++
                   ", Cantidad de entradas: " ++ show (cantidadEntradas clienteAtendido)
        let nuevaLista = tail (clientes listaCola)
        putStrLn "Cliente atendido y eliminado de la cola"
        return ()
