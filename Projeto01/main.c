#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int esc1, esc2, esc3;
//Bloco de Struct
typedef struct endereco{
    char cidade[50];
    char bairro[50];
    int numero;
}t_endereco;

typedef struct{
    int id;
    char areaConstruida[10];
    char areaTerreno[10];
    int numeroQuartos;
    int posicaoSituada;
    int andar;
    int situacao;
    float preco;
    int vagasGaragem;
    char descricao[200];
    t_endereco end;
}t_casa;

typedef struct{
    int id;
    char medida[10];
    int numeroQuartos;
    int posicaoSituada;
    int andar;
    float preco;
    int situacao;
    int vagasGaragem;
    char descricao[200];
    t_endereco end;
}t_terreno;

typedef struct{
    int id;
    char medida[10];
    int numeroQuartos;
    int posicaoSituada;
    int andar;
    float preco;
    int vagasGaragem;
    int situacao;
    char descricao[200];
    t_endereco end;
}t_apartamento;

t_apartamento apartamentos[500];

//Fim bloco de struct e inicio das funções

FILE* openConecction(char nomeArquivo[], char tipoEntrada[]){//Função responsável pela maioria das conexões com os arquivos txt, todos eles
    FILE *fl = fopen(nomeArquivo, tipoEntrada);
    if(fl == NULL){
        printf("Erro ao abrir arquivo %s\n", nomeArquivo);
    }
    return fl;
}

void closeConnection(FILE *fl){//Finaliza a conexão com o arquivo
    fclose(fl);
}

int testeArquivo(char nome[]){
    int arquivo = access(nome, F_OK);
    if(arquivo == ENOENT){
        printf("Arquivo nao exciste");
        return 0;
    }else{
        return 1;
    }
}

int buscarID(char arquivo[]){//Essa função pega o ultimo id dos usuarios, esse id é salvo em um txt separado
    int r = testeArquivo(arquivo);
    int id = 0;
    if(r == 0){
        FILE *ff = fopen(arquivo, "w");
        fclose(ff);
        return -5;
    }else{
        FILE *fl = fopen(arquivo, "r");
        if(fl == NULL){
            fl = fopen(arquivo, "w");
            fclose(fl);
        }
        fscanf(fl, "%i", &id);
        fclose(fl);
        return id;
    }
}
void inserirID(char arquivo[], int id){//Essa função Insere o id como citado acima
    FILE *fl = fopen(arquivo, "w+");
    fprintf(fl, "%i", id+1);
    fclose(fl);
}

int cadastroApartamento(t_apartamento apartamentos){//Cadastro de apartamento
    int cont = 0;
    int id = buscarID("apCfg.txt");
    if(id == -5){
        id = buscarID("apCfg.txt");
    }
    inserirID("apCfg.txt", id);
    FILE *fl = openConecction("apartamentos.txt", "a");
    
    fprintf(fl, "%i\n", id+1);
    fprintf(fl, "%i\n", apartamentos.andar);
    fprintf(fl, "%s", apartamentos.descricao);
    fprintf(fl, "%s", apartamentos.end.bairro);
    fprintf(fl, "%s", apartamentos.end.cidade);
    fprintf(fl, "%i\n", apartamentos.end.numero);
    fprintf(fl, "%s", apartamentos.medida);
    fprintf(fl, "%i\n", apartamentos.numeroQuartos);
    fprintf(fl, "%i\n", apartamentos.posicaoSituada);
    fprintf(fl, "%f\n", apartamentos.preco);
    fprintf(fl, "%i\n", apartamentos.situacao);
    fprintf(fl, "%i\n", apartamentos.vagasGaragem);
    
    closeConnection(fl);
}

void listagemApartamentos(){//Essa função lista os apartamentos
    int id = buscarID("apCfg.txt");
    FILE *fl = openConecction("apartamentos.txt", "rt");
    int cont;
    for(cont = 0; cont < id; cont++){
        fscanf(fl, "%i", &apartamentos[cont].id);
        fscanf(fl, "%i", &apartamentos[cont].andar);
        fgets(apartamentos[cont].descricao, 200, fl);
        fgets(apartamentos[cont].end.bairro, 50, fl);
        fgets(apartamentos[cont].end.cidade, 50, fl);
        fscanf(fl, "%i", &apartamentos[cont].end.numero);
        fscanf(fl, "%i", &apartamentos[cont].numeroQuartos);
        fgets(apartamentos[cont].medida, 10, fl);
        fscanf(fl, "%i", &apartamentos[cont].posicaoSituada);
        fscanf(fl, "%f", &apartamentos[cont].preco);
        fscanf(fl, "%i", &apartamentos[cont].situacao);
        fscanf(fl, "%i", &apartamentos[cont].vagasGaragem);
    }
    closeConnection(fl);
}

void menssagemEntrada(){
    printf("Bem vindo ao sistema!\nPorfavor escolha uma das opções no menu digitando seu ID\n\n");
}
void menu(){
    printf("-------O que voce deseja fazer?-------\n1->Voltar\n2->Apartamentos\n3->Casas\n4->Terrenos\n5->Sair\n------------------\n");
}
void subMenu(){
    printf("-----Listar-----\n\n1->Voltar\n2->Listar todos\n3->Consultar por descricao\n4->Listar por tipo\n5->Disporniveis para alugar -Tipo-\n6->Disponivel para alugar por bairro\n7->Disponivel para vender por bairro\n8->Descricao dos imoveis por cidade\n9->Sair\n---------------\n");
}

void menuOpcoes(){
    printf("------Menu------\n1->Cadastrar\n2->Listar\n");
    printf("3->Sair\n--------------\n");
}

int subMenuListar(){
    subMenu();
    int escolha = 0;
    printf("Digite o codigo: ");
    scanf("%i", &escolha);
    while(escolha < 1 || escolha > 9){
        printf("Digite corretamente!\n");
        subMenu();
        scanf("%i", &escolha);
    }
    return escolha;
}

int entrada(){
    int escolha2 = 0;
    menssagemEntrada();
    menuOpcoes();
    printf("Digite o codigo: ");
    scanf("%i", &escolha2);
    while(escolha2 < 1 || escolha2 > 12){   
        printf("Digite o codigo correto ----- YOU BURRO MAN -----\n");
        menuOpcoes();
        scanf("%i", &escolha2);
    }
    puts("\n");
    return escolha2;
}
int escolha1(){
    menu();
    int escolha = 0;
    printf("Digite o codigo: ");
    scanf("%i", &escolha);
    while(escolha < 1 || escolha > 12){   
        printf("\nDigite o codigo correto ----- YOU BURRO MAN -----\n");
        menuOpcoes();
        scanf("%i", &escolha);
    }
    return escolha;
}
int cadastrarApartamento(){//Função responsável por receber os dados para cadastrar apartamento
    while(1){
        int escolha = 0;
        t_apartamento apartamento;
        printf("1->Alugar\n2->Vender\n3->Alugar/Vender\nDigite o codigo: ");
        scanf("%i%*c", &apartamento.situacao);
        printf("Andar: ");
        scanf("%i%*c", &apartamento.andar);
        printf("Descricao: ");
        fgets(apartamento.descricao, 200, stdin);
        printf("Cidade: ");
        fgets(apartamento.end.cidade, 50, stdin);
        printf("Bairro: ");
        fgets(apartamento.end.bairro, 50, stdin);
        printf("Numero: ");
        scanf("%i%*c", &apartamento.end.numero);
        printf("Medida em metros(Ex: 30x30): ");
        fgets(apartamento.medida, 10, stdin);
        printf("Numero de quartos: ");
        scanf("%i%*c", &apartamento.numeroQuartos);
        printf("Posicao do predio\n1->Norte\n2->Sul\n3->Leste\n4->Oeste\nDigite: ");
        scanf("%i%*c", &apartamento.posicaoSituada);
        printf("Preco: ");
        scanf("%f%*c", &apartamento.preco);
        printf("Vagas na garagem: ");
        scanf("%i%*c", &apartamento.vagasGaragem);
        system("clear");
        printf("Salvar dados?\n1->Sim\n2->Nao\nDigite: ");
        scanf("%i", &escolha);
        while(escolha < 1 || escolha > 2){
            printf("Digite o codigo correto!\n\n");
            printf("Salvar dados?\n1->Sim\n2->Nao\nDigite: ");
            scanf("%i", &escolha);
        }
        if(escolha == 1){
            cadastroApartamento(apartamento);
            printf("Deseja realizar um novo cadastro?\n1->Sim\nQualquer outro para nao\nDigite: ");
            int escolher = 0;
            scanf("%i", &escolher);
            if(escolher == 1){
                continue;
            }else{
                return 5;
            }
        }else{
            return 0;
        }
    }
}

void listarApartamentos(){//Funcao para realizar a leitura dos dados
    int id = buscarID("apCfg.txt");
    int cont;
    for(cont = 0; cont < id; cont++){
        printf("ID: %i\n", apartamentos[cont].id);
        printf("Andar: %i\n", apartamentos[cont].andar);
        printf("Descricao: %s\n", apartamentos[cont].descricao);
        printf("Bairro: %s\n", apartamentos[cont].end.bairro);
        printf("Cidade: %s\n", apartamentos[cont].end.cidade);
        printf("Numero: %i\n", apartamentos[cont].end.numero);
        printf("Medida: %s\n", apartamentos[cont].medida);
        printf("Numero de Quartos: %i\n", apartamentos[cont].numeroQuartos);
        printf("Posicao Situada: %i\n", apartamentos[cont].posicaoSituada);
        printf("Preco: %f\n", apartamentos[cont].preco);
        printf("Situacao: %i\n", apartamentos[cont].situacao);
        printf("Vagas Garagem: %i\n", apartamentos[cont].vagasGaragem);
    }
}

int main(int argc, char** argv) {
    while(1){
        int vInicio = entrada();
        system("clear");
        if(vInicio == 3){
            return 0;
        }
        while(1){
            system("clear");
            if(vInicio == 2){
                listarApartamentos();
                int escolha = subMenuListar();
            }
            else if(vInicio == 1){
                int vE1 = escolha1();
                if(vE1 == 1){
                break;
            }
            else if(vE1 == 2){
                int i = cadastrarApartamento();
                if(i == 5){
                    break;
                }
            }
            else if(vE1 == 5){
                return 0;
            }
        }
        }
    }
    return 0;
}