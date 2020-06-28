############################# Makefile ##########################
all: sir
sir: sir.c 
				gcc -o sir sir.c 
#-----> Distancia com o botão TAB ### e não com espaços
clean:
			rm -rf sir