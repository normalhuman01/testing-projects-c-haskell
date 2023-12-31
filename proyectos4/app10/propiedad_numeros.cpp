-- Función para calcular la potencia de un número entero elevado a una potencia
potencia :: Integer -> Integer -> Integer
potencia base exp
    | otherwise = base * potencia base (exp - 1) --potencia^pos

-- Función que verifica si un número cumple con la propiedad
potencia2 :: Integer -> Bool --verificación de si cumple o no
potencia2 numb = potencia22 numb 1 0 --igualdad
  where
  --funcion que permite hacer la recursividad del numero cada vez que haga va avanzar un digito así como su posicion. De esta manera hará una suma.
    potencia22 0 _ suma = suma == numb
    potencia22 n pos suma =
        let digit = n `mod` 10 -- toma el digito y se saca
            acumula = suma + potencia digit pos --hacer la suma y llamado de la funcion potencia 
        in potencia22 (n `div` 10) (pos + 1) acumula -- recursividad divide entre 10 para hallar el proximo digito y avanza una posición para que sea la potencia.
main :: IO ()
main = do
    putStrLn "Ingresa: "
    num1 <- getLine --tomar el valor como string
    let num = read num1 :: Integer--tomar el valor y transformarlo a integer
    let result = potencia2 num --llamar funcion
    if result --cumple o no cumple
        then putStrLn $ show num ++ " falso."
        else putStrLn $ show num ++ " verdadero ."

