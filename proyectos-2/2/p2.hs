agregarBitAdicional :: [Int] -> [Int]
agregarBitAdicional bits = bits ++ [paridad bits]
  where
    paridad xs = if even (countOnes xs) then 0 else 1
    countOnes = length . filter (== 1)
