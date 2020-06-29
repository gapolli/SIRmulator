############################# Makefile ##########################
all: sir
sir: sir.c linkedList.c
				gcc -o sir sir.c linkedList.c 
#-----> Distancia com o botão TAB ### e não com espaços
clean:
			rm -rf sir