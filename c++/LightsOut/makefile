.PHONY : build
build :
	cmake -GNinja -S . -B build
	cmake --build build

.PHONY : run
run :
	./build/src/LightsOut

.PHONY : clean
clean :
	rm -rf build/
