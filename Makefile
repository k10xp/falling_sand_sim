.PHONY: build_raylib compile run sm_download sm_update

build_raylib: #build once
	sh ./scripts/build_raylib.sh

compile: #assume already ran build_raylib
	g++ -std=c++20 -Wall -Wextra main.cpp \
	external/raylib/src/libraylib.a \
	-Iexternal/raylib/src \
	-lGL -lm -lpthread -ldl -lrt -lX11 \
	-no-pie -D_DEFAULT_SOURCE \
	-o build/sand_sim

run: compile #compile and run, USE THIS
	./build/sand_sim

sm_download: #download submodules from remote, first run
	git submodule update --init

sm_update:
	git submodule update --remote
