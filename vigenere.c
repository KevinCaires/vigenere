/*
Trabalho de criptografia de estrutura de dados.

Supervisor: Prof° Fagner.
Desenvolvedores: Kevin Caires e Vinicius Paiva.

Sintese:
    Objetivo: Implementar um sistema que realiza cirptografia e descriptografia de vigenere.

    Entradas : String.

    Respostas: String.

    Help: Param : --help
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


/*
    Constantes.
*/
#define MAX_SIZE 200
#define ERROR_MESSAGE "Algo de errado aconteceu, veja --help!"


/*
    Definição da função de limpesa de tela.
*/
#ifdef WIN32
    #define clean_screen system("cls");
#else
    #define clean_screen system("clear");
#endif


typedef struct xData{
    char key[MAX_SIZE];
    char clean_text[MAX_SIZE];
    char chiper_text[MAX_SIZE];
} Data;


/*
    Definição das funções.
*/
void help(void);
void encode(Data data);
void decode(Data data);


void main(int argc, char *argv[]){
    // Seta a linguagem para português.
    setlocale(LC_ALL, "portuguese");
    // Variável para controlar os parametros de cifragem.
    int control=3;

    if(argc == 1 || strcmp(argv[1], "--help")==0){
        // Mensagem de ajuda.
        clean_screen
        help();
    }
    else if(argc<6){
        // Mostra mensagem de erro se a quantidade de argumentos estiver errada.
        clean_screen
        printf(ERROR_MESSAGE);
    }
    else{
        Data data;
        
        // Percorre os argumentos para tratamento.
        for(int i=1; i<argc; i++){
            if(strcmp(argv[i], "--text")==0){
                strcpy(data.clean_text, argv[i+1]);
            }
            if(strcmp(argv[i], "--key")==0){
                strcpy(data.key, argv[i+1]);
            }
            if(strcmp(argv[i], "--encode")==0){
                control = 0;
            }
            if(strcmp(argv[i], "--decode")==0){
                control = 1;
            }
        }

        // Chama função conforme controle.
        if(control==0){
            encode(data);
        }
        else if(control==1){
            decode(data);
        }
        else{
            printf(ERROR_MESSAGE);
        }
    }
}


void encode(Data data){
    /*
        Função que realiza a criptografia do texto.
    */
    int txt_len = strlen(data.clean_text), key_len = strlen(data.key), character;

    for(int i=key_len, j=0; i<txt_len+1; i++, j++){
        // Realiza continuação da chave caso seja menor que o texo.
        data.key[i] = data.key[j];
    }

    for(int i; i<txt_len; i++){
        character=(int)data.clean_text[i] + data.key[i] - 97;
        
        if(character > 122){
            character = character - 26;
        }
        data.chiper_text[i] = character;
    }
    clean_screen
    printf("Criptografado: %s\n", data.chiper_text);
}


void decode(Data data){
    /*
        Função que realiza a descriptografia do texto.
    */
    int txt_len = strlen(data.clean_text), key_len = strlen(data.key), character;

    for(int i=key_len, j=0; i<txt_len+1; i++, j++){
        // Realiza continuação da chave caso seja menor que o texo.
        data.key[i] = data.key[j];
    }

    for(int i; i<txt_len; i++){
        character=(int)data.clean_text[i] - data.key[i] + 97;
        
        if(character < 97){
            character = character + 26;
        }
        data.chiper_text[i] = character;
    }
    clean_screen
    printf("Descriptografado: %s\n", data.chiper_text);
}


void help(void){
    printf(""
    "--help \t Mostra essa mensagem.\n\n"
    "PARAMETROS OBRIGATÓRIOS:\n"
    "--text \t Texto para criptografar ou descriptografar.\n"
    "--key \t Chave para criptografar ou descriptografar.\n\n"
    "PARAMETROS DE CIFRAGEM:\n"
    "--encode \t Argumento para realizar a criptografia do texto.\n"
    "--decode \t Argumento para realizar a descriptografia do texto.\n\n"
    "EXEMPLOS:\n"
    "[1] --text umtextoqualquer --key minhasuperchave --encode\n"
    "[2] --text guglxlifyrnxuzv --key minhasuperchave --decode\n\n"
    "CUIDADO:\n"
    "Os textos após espaços em branco serão ignorados!"
    );
}
