convertirBinarioCola :: Int -> [Int]
convertirBinarioCola n = reverse (convertirBinarioCola' n [])
  where
    convertirBinarioCola' 0 acc = acc
    convertirBinarioCola' n acc = convertirBinarioCola' (n `div` 2) (n `mod` 2 : acc)
