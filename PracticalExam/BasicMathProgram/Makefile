
compile_exe : main.o error_functions.o
	gcc -o compile_exe main.o error_functions.o

error_functions.o : error_functions.c
	gcc -c -o error_functions.o error_functions.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o
