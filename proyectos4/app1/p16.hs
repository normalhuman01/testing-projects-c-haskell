module Main where

import Data.Char

distManha :: (Int, Int) -> (Int, Int) -> Int
distManha (x1, y1) (x2, y2) = abs (x1 - x2) + abs (y1 - y2)

main :: IO ()
main = do
    putStrLn "Escribe coordenadas para x1 y1:"
    input1 <- getLine
    let [x1, y1] = map read (words input1)

    putStrLn "Escribe coordenadas para x2 y2:"
    input2 <- getLine
    let [x2, y2] = map read (words input2)

    let dist = distManha (x1, y1) (x2, y2)

    putStrLn $ "La distancia de Manhattan es: " ++ show dist
