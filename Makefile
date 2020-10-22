CFLAGS= -mno-mips16 -mgp32 -mfp32 -gpubnames  -mlong32 -mips1 -mabicalls -mlong-calls -mframe-header-opt -march=r2k

OBJS= tp0

all: tp0

tp0: main.c filereader.c filewriter.c encoder.c decoder.c
	gcc -g $^ -o $@

clean:
	rm tp0*