all: 
	gcc -c -Wall include/*.h
	gcc -c -Wall *.c -I include
	gcc -o SIG-Parking *.o
#Faz a compilação do programa
clean:
	rm *.o *.gch SIG-Parking *.gch ./include/*.gch
#limpa os arquivos .o e o EXE ou seja o lixo
 run:
	./SIG-Parking
#executa o programa / arquivo executavel