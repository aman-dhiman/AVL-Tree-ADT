avl:
	gcc src/helper.c src/wrapper.c src/compAndDest.c src/testADT.c -Wall -ansi -pedantic -Iinclude -o bin/testAdt

fileio:
	gcc -D_BSD_SOURCE src/compAndDest.c src/wrapper.c src/helper.c src/fileIO.c src/testFIO.c -Iinclude -Wall -pedantic -ansi -o bin/file
main:
	gcc -Wall -ansi src/main.c src/compAndDest.c src/fileIO.c src/wrapper.c src/helper.c src/treeFile.c -Iinclude -D_BSD_SOURCE -o bin/main
