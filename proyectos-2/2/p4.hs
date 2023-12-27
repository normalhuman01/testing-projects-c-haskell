validarTransmision :: [Int] -> Bool
validarTransmision bits = paridad bits == last bits
  where
    paridad xs = if even (countOnes xs) then 0 else 1
    countOnes = length . filter (== 1)
