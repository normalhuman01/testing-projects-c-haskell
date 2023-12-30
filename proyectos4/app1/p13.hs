distManha :: (Int, Int) -> (Int, Int) -> Int --ingresar los datos en formato integer
distManha (x1, y1) (x2, y2) = --funcion para la distancia hakuna manhattan
    abs (x1 - y1) + abs (x2 - y2) --utilizar abs para que sea valor positivo siempre y restar los los puntos x1 y1 y sumar x2 y y2
main :: IO ()
main = do
-- Muestra un mensaje en la consola pidiendo coordenadas para x1 y1
putStrLn "escribe coords para x1 y1:" -- Pedimos ingresar datos

-- Lee una línea de entrada del usuario y la almacena en 'pedido1'
pedido1 <- getLine 

-- Convierte la entrada 'pedido1' en un entero y asigna el valor a la variable 'x1'
let x1 = read pedido1 :: Int -- Transformar en integer

-- Lee una línea de entrada del usuario y la almacena en 'pedido2'
pedido2 <- getLine

-- Convierte la entrada 'pedido2' en un entero y asigna el valor a la variable 'y1'
let y1 = read pedido2 :: Int -- Transformar en integer

-- Muestra un mensaje en la consola pidiendo coordenadas para x2 y2
putStrLn "escribe coords x2 y2 :" -- Pedimos ingresar datos

-- Lee una línea de entrada del usuario y la almacena en 'pedido3'
pedido3 <- getLine

-- Convierte la entrada 'pedido3' en un entero y asigna el valor a la variable 'x2'
let x2 = read pedido3 :: Int -- Transformar en integer

-- Lee una línea de entrada del usuario y la almacena en 'pedido4'
pedido4 <- getLine

-- Convierte la entrada 'pedido4' en un entero y asigna el valor a la variable 'y2'
let y2 = read pedido4 :: Int -- Transformar en integer

-- Calcula la distancia de Manhattan entre los puntos (x1, y1) y (x2, y2) utilizando la función 'distManha'
let dist = distManha (x1, y1) (x2, y2) -- Llamado de la funcion hakuna manhattan

-- Muestra la distancia calculada en la consola después de convertirla a una cadena de caracteres
putStrLn $ "La distancia de Manhattan es: " ++ show dist -- Mostrar la distancia entre los puntos



