.PHONY : build
build_cui :
	cmake -GNinja -S . -B build
	cmake --build build

.PHONY : run
run :
	./build/src/Minesweeper

.PHONY : clean
clean :
	rm -rf build/
