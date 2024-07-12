#include <stdio.h>
#include <stdlib.h>
/*
O objetivo desse exercício é treinar alocação dinâmica.
Exercício:
    Input:
        Na primeira linha serão dados dois inteiros N e M, sendo, respectivamente, o número de linhas e colunas. Logo após será dado um grid com N linhas e M colunas, composto por carácteres. Uma posição no grid (i, j) contém uma peça de Bruno se estiver marcada com o caracter ”X”. Já uma posição livre á marcada pelo caracter ”.”
    Output:
        Como saída você deve retornar a matriz com as peças de Bruno marcadas com ”X” e as posições em que Isa pode colocar uma peça marcadas com ”*”. Já as posições em que Isa não pode colocar uma peça basta manter o carácter que estava na leitura. Para esse exercício você deve utilizar funções, matrizes e alocação dinâmica.
*/

//Protótipos das funções:
char **aloca(int N, int M); 
void ler_matriz(char **tabuleiro, int N, int M); 
void disponivel(char **tabuleiro, int N, int M); 
void imprimir(char **tabuleiro, int N, int M);
void libera(char **tabuleiro, int N);

/*
A função aloca() recebe como parametros as variáveis N e M que definem a quantidade de linha e de colunas da matriz a ser inserida.
Ela tem como objetivo alocar memoria para essa determinada matriz usando os parametros dados, ou seja, ela primeiro aloca a quantidade de linhas e depois a quantidade de colunas e depois retorna a matriz para a função principal.
*/
char **aloca(int N, int M){
    int **tabuleiro = (char **)calloc(N, sizeof(char*));
    for(int i = 0; i < N; i++){
        tabuleiro[i] = (char*)calloc(M, sizeof(char));
    }
    return tabuleiro;
}

/*
A função ler_matriz() recebe como parametros a matriz tabuleiro e a quantidade de linhas (N) e de colunas (M).
Seu objetivo é ler os elementos da matriz inserida pelo usuario depois que a memoria foi alocada, para isso se utiliza da mesma logica da função anterior; primeiro percorrendo a linha e depois cada coluna dessa linha.
*/
void ler_matriz(char **tabuleiro, int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &tabuleiro[i][j]);
        }
    }
}

/*
A função disponivel() recebe como parametros a matriz tabuleiro e a qunatidade de linhas (N) e de colunas (M)
Seu objetivo é analisar todas as possições da matriz tabuleiro[][] inicialmente dada pelo usuario e modificá-la para mostrar os espaços disponíveis para uma jogada. Para isso:
    - Ela irá percorrer cada posição da matriz usando um loop;
    - Dentro do loop ele irá checar se o elemento é igual à um ".";
    - Se sim ele checará a quantidade de vizinhos "X" que o elemento possui (irá checar em cima, em baixo, na direita e na esquerda) e usará um contador para guardar essa qunatidade;
    - no final ele checará se o modulo do contador dividido por 2 resultará um 0; se sim ele mudara o elemento da matriz para um "*", se não ele manterá o "."
*/
void disponivel(char **tabuleiro, int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tabuleiro[i][j] == '.') { 
                int cont = 0;
                
                if(i > 0 && tabuleiro[i-1][j] == 'X'){ 
                    cont++;
                }
                if(i < N-1 && tabuleiro[i+1][j] == 'X'){
                    cont++;
                }
                if(j > 0 && tabuleiro[i][j-1] == 'X'){ 
                    cont++;
                }
                if(j < M-1 && tabuleiro[i][j+1] == 'X'){ 
                    cont++;
                }
                
                if(cont%2 == 0){ 
                    tabuleiro[i][j] = '*';
                }
            }
        }
    }
}

/*
A função imprimir() recebe como parametros a matriz tabuleiro e a quantidade de linhas (N) e de colunas (M).
Seu objetivo é imprimir a matriz já modificada com os espaços disponiveis ('*') no lugar de alguns '.'.
Para isso ela percorre as linhas e suas colunas mantendo o tamanho igual a da entrada.
*/
void imprimir(char **tabuleiro, int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/*
A função libera() tem como parametros a matriz tabuleiro e a quantidade de linhas (N).
Seu objetivo é liberar memoria antes alocada pela matriz tabuleiro por não ser mais necessária no fim do programa.
Para isso ela percorre todas as linhas da matriz.
*/
void libera(char **tabuleiro, int N){
    for(int i = 0; i < N; i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);
}   

/*
Função principal: apenas define (declara) as variáveis relacionadas
ao problema e coordena as chamadas a funções que irão resolver
o problema proposto.
    - a variavel N define a quantiade de linhas da matriz tabuleiro[N][];
    - a variavel M define a quantidade de colunas da matriz tabuleiro[][M];
    - a matriz tabuleiro[][] conterá os elementos inseridos pelo usuario e depois retornara na saida a mesma matriz, só que com pequenas modificações (lugares disponiveis para serem feitos uma jogada).
*/
int main(){
    int N, M; 
    scanf("%d %d", &N, &M);

    char **tabuleiro = aloca(N, M);
    ler_matriz(tabuleiro, N, M);

    disponivel(tabuleiro, N, M);

    imprimir(tabuleiro, N, M);

    libera(tabuleiro, N);

    return 0;
}
