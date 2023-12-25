{- Module -}
module Main where




{- Imports -}
import System.Console.Isocline
import Text.Read (readMaybe)
import Text.Parsec
import Data.Fixed
import Data.List




{- Stack Type -}
type Stack = [Double]




{- Print Stack Function -}
printStack :: Stack -> IO ()
printStack = putStr . foldl' (\acc x -> (if mod' x 1 == 0 then show (floor x :: Int) else show x) ++ '\n' : acc) ""




{- Parser Function -}
parser :: Parsec String Stack Stack
parser = sepBy1 term spaces >> getState where
	term = choice $ map try [
		(many1 $ oneOf "-.0123456789") >>= maybe (unexpected "invalid number") apply0 . readMaybe,
		string "negate" >> apply1 negate,
		string "log" >> apply2 logBase,
		string "clear" >> putState [],
		char 'e' >> (apply0 $ exp 1),
		string "acos" >> apply1 acos,
		string "asin" >> apply1 asin,
		string "atan" >> apply1 atan,
		string "cos" >> apply1 cos,
		string "sin" >> apply1 sin,
		string "tan" >> apply1 tan,
		string "pi" >> apply0 pi,
		char '^' >> apply2 (**),
		char '*' >> apply2 (*),
		char '+' >> apply2 (+),
		char '-' >> apply2 (-),
		char '/' >> apply2 (/)]
	apply2 f = getState >>= \s -> case s of
		x : y : s' -> putState (f y x : s')
		_ -> unexpected "stack overflow"
	apply1 f = getState >>= \s -> case s of
		x : s' -> putState (f x : s')
		_ -> unexpected "stack overflow"
	apply0 x = modifyState (x :)




{- Main Function -}
main :: IO ()
main = do
	setDefaultCompleter $ const $ const $ return ()
	setHistory "/dev/null" -1
	sequence_ $ map (\f -> f False) [
		enableCompletionPreview,
		enableMultilineIndent,
		enableBraceInsertion,
		enableBraceMatching,
		enableInlineHelp,
		enableHighlight,
		enableBeep,
		enableHint]
	let loop s = printStack s >> readlineMaybe "" >>= maybe (putStrLn "Goodbye! :D") (either (\e -> print e >> loop s) loop . runParser parser s "")
	loop []