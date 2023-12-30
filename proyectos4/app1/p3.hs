distManha :: (Int, Int) -> (Int, Int) -> Int --ingresar los datos en formato integer
distManha (x1, y1) (x2, y2) = --funcion para la distancia hakuna manhattan
    abs (x1 - y1) + abs (x2 - y2) --utilizar abs para que sea valor positivo siempre y restar los los puntos x1 y1 y sumar x2 y y2
main :: IO ()
main = do
    putStrLn "escribe coords para x1 y1:" --pedimos ingresar datos
    pedido1 <- getLine
    let x1 = read pedido1 :: Int --transformar en integer
    pedido2 <- getLine
    let y1 = read pedido2 :: Int--transformar en integer
    putStrLn "escribe coords x2 y  y2 :" --pedimos ingresar datos
    pedido3 <- getLine
    let x2 = read pedido3 :: Int--transformar en integer
    pedido4 <- getLine
    let y2 = read pedido4 :: Int--transformar en integer
    let dist = distManha (x1, y1) (x2, y2) --llamado de la funcion hakuna manhattan
    putStrLn $ "La distancia de Manhattan es: " ++ show dist --mostrar la distancia entre los puntos  