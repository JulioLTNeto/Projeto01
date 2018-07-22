#include <stdio.h>
#include <stdlib.h>

void menssagemEntrada(){
    puts("Bem vindo ao sistema!\n Porfavor escolha uma das opções no menu digitando seu ID\n");
}
void menu(){
    puts("-----Menu-----\n->Clientes\n->Imoveis\n");
}

int main(int argc, char** argv) {
    menssagemEntrada();
    menu();
    return 0;
}
