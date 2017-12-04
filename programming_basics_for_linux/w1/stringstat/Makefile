all:	lib

exe:	solution.c
		gcc -o solution solution.c

lib:	solution.c
		gcc -shared solution.c -fPIC -o libsolution.so

clean:
		rm solution libsolution.so 2>/dev/null
