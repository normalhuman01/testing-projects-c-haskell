sumDig :: Integer -> Integer --entrada y salida de integer
sumDig num = sumDIG num 0 --asignamos que la suma de digitos

sumDIG :: Integer -> Integer -> Integer
sumDIG 0 acumular = acumular --acumulamos
sumDIG num acumular = 
    let digit = num `mod` 10 -- dividir entre 10 para sacar digito por digito
        sumq = acumular + digit -- sumar esos digitos
        nNum = num `div` 10 -- nuevamente hacer el proceso de división
    in sumDIG nNum sumq

main :: IO ()
main = do
    putStrLn "Ingresa: " --pedimos el ingreso de un numero 
    num1 <- getLine --tomamos el valor del numero en formato string 
    let entrada = read num1 :: Integer --lo pasamos a convertir en integer
    let result = sumDig entrada -- lo asignamos a result y llamamos a la función sumDig
    putStrLn $ "suma:  " ++ show entrada ++ "=" ++ show result --mostramos resultados
    