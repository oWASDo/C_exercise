CC=C:\Program Files\LLVM\bin\clang.exe
CPPCHECK=C:\Program Files\Cppcheck\cppcheck.exe
CFLAGS=-Wall -Werror -Wno-pragma-pack
LDFLAGS=-lSDL2 -L.
BINARY=clc
BINARY_TESTS=clc_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

clc: main.o clock.o gfx.o
	$(CC) -o $(BINARY) $(LDFLAGS) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

clock.o: clock.c header.h
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CPPCHECK) $^

gfx.o: gfx.c header.h
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CPPCHECK) $^

tests.o: tests.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

clc_test: tests.o clock.o
	$(CC) -o $(BINARY_TESTS) $(LDFLAGS) $^
	./$(BINARY_TESTS)
