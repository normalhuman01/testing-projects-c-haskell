-- Otro tipo de algoritmo de ocutamiento de informacion son los referntes a la transpiocion de carateres. Para esto se le pide impementar
-- una funcion llamada pregunta2 que reciba como argumento de entrada un String y devuelva un String encriptado. El algoritmo por imple4mentar 
-- es el siguiente: La cadena recibida devera dividirse en 3 subcadenas. Cada caractere segun su posicion ira en una subcadena determinada. 
pregunta2 :: String -> String
pregunta2 str = concatMap quitarAsteriscos subcadenas
  where
    subcadenas = [subcadena i str | i <- [0 .. 2]] -- Obtener las 3 subcadenas
    subcadena i s = [if j `mod` 3 == i then s !! j else '*' | j <- [0 .. length s - 1]] -- Crear subcadena i
    quitarAsteriscos = filter (/= '*') -- Eliminar asteriscos

-- FunciÃ³n principal para probar las funciones
main :: IO ()
main = do
  putStrLn $ pregunta1a "ABC" 3
  putStrLn $ pregunta1b "DEF" 3
  putStrLn $ pregunta2 "HOLA QUE TAL"