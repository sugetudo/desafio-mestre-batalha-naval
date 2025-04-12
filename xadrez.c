#include <stdio.h>

const int casas_torre_rec = 5;
const int casas_bispo_rec = 5; // Usaremos esta para ambas as implementações do bispo
const int casas_rainha_rec = 8;
const int casas_cavalo_vertical_cima = 2;
const int casas_cavalo_horizontal_dir = 1;


/*função que se baseia em chamada recursiva
 ela verifica se o numero de casas é maior que zero,se sim:
    -executa oque tem dentro e chama a função denovo
*/
void mover_torre_rec(int casas_restantes) {
    if (casas_restantes >0) {
        printf("Direita\n");
        mover_torre_rec(casas_restantes - 1);
    }
}
/*função que se baseia em chamada recursiva
 ela verifica se o numero de casas é maior que zero,se sim:
    -executa oque tem dentro e chama a função denovo
*/
void mover_rainha_rec(int casas_restantes){
    if(casas_restantes>0){
        printf("Esquerda\n");
        mover_rainha_rec(casas_restantes - 1);
    }
}

// --- IMPLEMENTAÇÃO Nº 1 DO BISPO: PURAMENTE RECURSIVA ---
/*função que se baseia em chamada recursiva(fiz separado)
 ela verifica se o numero de casas é maior que zero,se sim:
    -executa oque tem dentro e chama a função denovo
*/
void mover_bispo_rec(int casas_restantes){
    if(casas_restantes > 0){
        printf("Cima, Direita\n"); // Imprime a saída correta
        mover_bispo_rec(casas_restantes - 1); // Passo recursivo
    }
}

// --- IMPLEMENTAÇÃO Nº 2 DO BISPO: LOOPS ANINHADOS ---
//função baseada em loops aninhados como a descrição do projeto pedia(fiz 2 separadas).
/*se baseia em 2 for onde o de fora inicia até ser maior ou igual que as casas que deve andar.
  Já a de dentro inicia 1 vez para cada chamada de retorno da de fora
*/
void mover_bispo_aninhado(int num_passos_diagonal) {
    // Loop Externo: Controla o movimento VERTICAL (e o passo diagonal geral).
    for (int v_step = 0; v_step < num_passos_diagonal; v_step++) {
        // Loop Interno: Controla o movimento HORIZONTAL correspondente.
        // Para uma diagonal 1:1 (Cima, Direita), executa 1 vez.
        for (int h_step = 0; h_step < 1; h_step++) {
            // Ação combinada para o passo diagonal atual
            printf("Cima, Direita (Aninhado - Passo %d)\n", v_step + 1);
        }
    }
}


// --- Função Principal (Main) ---
int main() {

    printf("Simulando movimentos complexos das pecas de xadrez:\n\n");

    /*chama a função da Torr na qual se baseia em uma função recursiva e mostra
    */
    printf("--- Movimento da Torre (Recursivo - %d casas para Direita) ---\n", casas_torre_rec);
    mover_torre_rec(casas_torre_rec);
    printf("----fim do movimento da Torre----\n");
    printf("\n");

    /*chama a função da Rainha na qual se baseia em uma função recursiva e mostra
    */
    printf("--- Movimento da Rainha (Recursivo - %d casas para Esquerda) ---\n", casas_rainha_rec);
    mover_rainha_rec(casas_rainha_rec);
    printf("----fim do movimento da rainha----\n");
    printf("\n");

    /*chama a função do Bispo na qual se baseia em uma função recursiva e mostra
    */
    printf("--- Movimento do Bispo (Implementacao 1: Recursivo - %d casas Cima, Direita) ---\n", casas_bispo_rec);
    mover_bispo_rec(casas_bispo_rec); // Chama a função recursiva CORRETA
    printf("----fim do movimento do Bispo (Recursivo)----\n");
    printf("\n");

    /*chama a função do bispo na qual se baseia em loops aninhados e mostra
    */
    printf("--- Movimento do Bispo (Implementacao 2: Loops Aninhados - %d casas Cima, Direita) ---\n", casas_bispo_rec);
    mover_bispo_aninhado(casas_bispo_rec); // Chama a NOVA função com loops aninhados
    printf("----fim do movimento do Bispo (Aninhado)----\n");
    printf("\n");


    /*movimento do cavalo funciona da seguinte maneira:
        -loop 1-> for:ele cria um variavel i para contagem de apenas uma vez,para no final mostrar que o caval terminou de se mexer
        -loop 2-> for:ele cria uma variavel v e uma m,enquanto v é menor que m:
            -executa um if para ver se v é igual 2,se não for ele irá printar "cimar".Caso contrario ele irá mostrar "Direita"
    */
    printf("--- Movimento do Cavalo (Loops Aninhados - %d Cima, %d Direita) ---\n",
           casas_cavalo_vertical_cima, casas_cavalo_horizontal_dir);
    for (int i = 0; i<1;i++) {
        printf("cavalo se move:\n");
        for (int v = 0,m = 3; v < m; v++) {
            if(v==2){
                printf("Direita\n");
            }else{
                printf("Cima\n");
            }
        }
        printf("----fim do movimento do cavalo----\n\n");
    }

    printf("Simulacao de movimentos Mestre concluida.\n");

    return 0;
}