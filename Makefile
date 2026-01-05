.PHONY: build_raylib compile_sim run_sim

build_raylib: #build once
	mkdir -p build
	cd external/raylib/src
	make PLATFORM=PLATFORM_DESKTOP -B

compile_sim: #assume already ran build_raylib
	g++ main.cpp \
	external/raylib/src/libraylib.a \
	-Iexternal/raylib/src \
	-lGL -lm -lpthread -ldl -lrt -lX11 \
	-no-pie -D_DEFAULT_SOURCE \
	-o build/sand_sim

run_sim: compile_sim #compile and run, USE THIS
	./build/sand_sim
