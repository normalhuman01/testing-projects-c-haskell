agregarBitAdicionalCuatro :: [Int] -> [Int]
agregarBitAdicionalCuatro bits = bits ++ paridadBits (countOnes bits `mod` 4)
  where
    countOnes = length . filter (== 1)
    paridadBits 0 = [0, 0]
    paridadBits 1 = [0, 1]
    paridadBits 2 = [1, 0]
    paridadBits _ = [1, 1]
