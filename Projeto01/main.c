#include <stdio.h>
#include <stdlib.h>

FILE *fCasa;
FILE *fApartamento;
FILE *fTerreno;
FILE *fClientes;

typedef struct endereco{
    char cidade[50];
    char bairro[50];
    int numero;
}t_endereco;

typedef struct{
    int medida;
    int medida2;
    int numeroQuartos;
    int posicaoSituada;
    int andar;
    float preco;
    int vagasGaragem;
    char descricao[200];
    t_endereco end;
}t_apartamento;

void openCasa(){
    fCasa = fopen("casa.txt", "w");
}
void openApartamento(){
    fApartamento = fopen("apartamento.txt", "w");
}
void openTerreno(){
    fTerreno = fopen("terreno.txt", "w");
}
void openClientes(){
    fClientes = fopen("clientes.txt", "w");
}

void menssagemEntrada(){
    printf("Bem vindo ao sistema!\nPorfavor escolha uma das opções no menu digitando seu ID\n\n");
}
void menu(){
    printf("-------Menu-------\n 1->Apartamentos\n 2->Casas\n 3->Terrenos\n 4->Sair\n------------------\n");
}
void menuOpcoes(){
    printf("------O que você deseja fazer?------\n\nn1<-Voltar\nn2->Atualizar\nn3->Cadastrar\nn4->Deletar\nn5->Listar\nn6->Listar descricao\nn7->Listar para alugar\nn8->Listar para vender\nn9->Buscar imoveis para vender por bairro\nn10->Buscar imoveis para alugar por bairro\nn11->Listar descricao por cidade\n");
    printf("12->Sair\n\n");
}
int entrada(){
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
    if(escolha == 4){
        return 0;
    }
    return 1;
}
int escolha1(){
    int escolha2 = 0;
    menuOpcoes();
    scanf("%i", &escolha2);
    while(escolha2 < 1 || escolha2 > 12){
        printf("Digite o codigo correto ----- YOU BURRO MAN -----\n");
        menuOpcoes();
        scanf("%i", &escolha2);
    }
    puts("\n");
    return escolha2;
}
int cadastrarApartamento(){
    t_apartamento apartament[50];
}

int main(int argc, char** argv) {
    while(1){
        int vInicio = entrada();
        if(vInicio == 0){
            return 0;
        }
        while(1){
            int vE1 = escolha1();
            if(vE1 == 12){
                return 0;
            }
            if(vE1 == 1){
                break;
            }
        }
    }
    return 0;
}
