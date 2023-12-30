
-- Función recursiva para calcular la suma de los dígitos de un número entero
sumDigits :: Integer -> Integer
sumDigits num = sumDigits num 0

sumDigits :: Integer -> Integer -> Integer
sumDigits 0 acumular = acumular
 sumDigits num acumular = 
    let digit = num `mod` 10 -- dividir entre 10 para sacar digito por digito
        sumq = acumular + digit -- sumar esos digitos
        nNum = num `div` 10 -- nuevamente hacer el proceso de división
    in sumDigits nNum sumq

main :: IO ()
main = do
    putStrLn "Ingrese un número:"
    input <- getLine
    let entrada = read input :: Integer
    let result = sumDigits entrada
    putStrLn $ "La suma de los dígitos es: " ++ show result
