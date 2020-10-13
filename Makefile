CFLAGS= -mno-mips16 -mgp32 -mfp32 -gpubnames  -mlong32 -mips1 -mabicalls -mlong-calls -mframe-header-opt -march=r2k

OBJS= tp0

all: tp0

prof: tp2_pf

tp0: main.c filereader.c
	gcc -g $^ -o $@

clean:
	rm tp0*