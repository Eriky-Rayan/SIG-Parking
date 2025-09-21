all: 
	gcc -c -Wall *.h
	gcc -c -Wall *.c
	gcc -o SIG-Parking *.o
#Faz a compilação do programa
clean:
	rm -rf *.o SIG-Parking
#limpa os arquivos .o e o EXE ou seja o lixo
 run:
	./SIG-Parking
#executa o programa