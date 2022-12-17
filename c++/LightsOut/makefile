.PHONY : build_cui
build_cui :
	cmake -GNinja -S . -B build -D UI_MODE=CUI
	cmake --build build

.PHONY : build_wx
build_wx :
	cmake -GNinja -S . -B build -D UI_MODE=WX_WIDGETS
	cmake --build build

.PHONY : run
run :
	./build/src/LightsOut

.PHONY : clean
clean :
	rm -rf build/
