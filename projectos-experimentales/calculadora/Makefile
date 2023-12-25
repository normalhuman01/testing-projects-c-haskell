out = calculadora


build:
	stack --local-bin-path . install


run: build
	./$(out)


clean:
	rm -fr .stack-work stack.yaml.lock $(out) $(out).cabal