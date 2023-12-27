validarTransmisionCuatro :: [Int] -> Bool
validarTransmisionCuatro bits = paridad bits == paridadBits (take 2 (reverse bits))
  where
    paridad xs = if even (countOnes xs) then 0 else 1
    countOnes = length . filter (== 1)
    paridadBits [0, 0] = 0
    paridadBits [0, 1] = 1
    paridadBits [1, 0] = 2
    paridadBits _ = 3
