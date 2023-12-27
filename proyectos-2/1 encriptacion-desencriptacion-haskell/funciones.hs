-- Implementar una función que devuelva una lista de números enteros pares hasta el 100.
crearEnterosPares :: [Int]
crearEnterosPares = [x | x <- [1..100], mod x 2 == 0]

-- Implementar una función que permita operar una lista de números del 1 al 50,
-- utilizando una función que se pasa como argumento de entrada.
operarLista :: [Int] -> (Int -> Int) -> [Int]
operarLista listaEnteros f = [f x | x <- listaEnteros]

-- Función encriptar que recibe como argumento de entrada una cadena
-- y devuelve otra cadena con los valores desplazados 3 posiciones.
-- "ABC" -> "DEF"
-- Utilizando list comprehension
encriptar :: String -> String
encriptar cadena = [toEnum (fromEnum c + 3) :: Char | c <- cadena]

main :: IO ()
main = do
  let pares = crearEnterosPares
  putStrLn "Números pares hasta 100:"
  print pares

  let listaOperada = operarLista [1..50] (\x -> x * 2) -- Ejemplo de operar la lista multiplicando por 2
  putStrLn "Lista operada:"
  print listaOperada

  let mensajeEncriptado = encriptar "ABC"
  putStrLn "Mensaje encriptado:"
  putStrLn mensajeEncriptado
