#include <stdio.h>
#include <stdlib.h>

void menssagemEntrada(){
    printf("Bem vindo ao sistema!\nPorfavor escolha uma das opções no menu digitando seu ID\n\n");
}
void menu(){
    printf("-------Menu-------\n 1->Clientes\n 2->Apartamentos\n 3->Casas\n 4->Terrenos\n------------------\n");
}
void menuOpcoes(){
    printf("------O que você deseja fazer?------\n\nn1->Atualizar\nn2->Cadastrar\nn3->Deletar\nn4->Listar\n");
}
void opcoesAdcionais(){
    printf("n5->Listar descricao\nn6->Listar para alugar\nn7->Listar para vender\n");
}

int main(int argc, char** argv) {
    menssagemEntrada();
    menu();
    int escolha = 0;
    while(escolha < 1 || escolha > 4){
        scanf("%i", &escolha);
        if(escolha >= 1 && escolha <= 4){
        }else{
            printf("Digite o codigo correto\n\n");
            menu();
        }
        
    }

        menuOpcoes();
    if(escolha != 1){
        opcoesAdcionais();
    }
        puts("");
    return 0;
}
