#include <stdio.h>

#define TAMANHO_TABULEIRO 10    // Tamanho do tabuleiro
#define TAMANHO_HABILIDADE 5    // Tamanho das matrizes de habilidades (5x5)

//---------------------------
// Função para inicializar o tabuleiro com água (0)
void inicializaTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0; 
        }
    }
}

//---------------------------
// Função para posicionar navios no tabuleiro
void posicionaNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int linhaNavioH = 2, colunaNavioH = 4; // Navio horizontal
    int linhaNavioV = 2, colunaNavioV = 1; // Navio vertical
    int linhaNavioDiagDesc = 5, colunaNavioDiagDesc = 5; // Navio diagonal descendente '\'
    int linhaNavioDiagAsc = 7, colunaNavioDiagAsc = 2;   // Navio diagonal ascendente '/'

    // Navio horizontal (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavioH][colunaNavioH + i] = 3; 
    }

    // Navio vertical (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavioV + i][colunaNavioV] = 3; 
    }

    // Navio diagonal descendente '\' (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavioDiagDesc + i][colunaNavioDiagDesc + i] = 3;
    }

    // Navio diagonal ascendente '/' (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavioDiagAsc - i][colunaNavioDiagAsc + i] = 3;
    }
}

//---------------------------
// Função para criar a matriz de habilidade 'Cone'
void criaCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            if (coluna >= (TAMANHO_HABILIDADE / 2 - linha) && coluna <= (TAMANHO_HABILIDADE / 2 + linha)) {
                cone[linha][coluna] = 1;
            } else {
                cone[linha][coluna] = 0;
            }
        }
    }
}

//---------------------------
// Função para criar a matriz de habilidade 'Cruz'
void criaCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;

    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            if (linha == centro || coluna == centro) {
                cruz[linha][coluna] = 1; 
            } else {
                cruz[linha][coluna] = 0;
            }
        }
    }
}

//---------------------------
// Função para criar a matriz de habilidade 'Octaedro'
void criaOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;

    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            if (coluna >= centro - (centro - abs(linha - centro)) && coluna <= centro + (centro - abs(linha - centro))) {
                octaedro[linha][coluna] = 1;
            } else {
                octaedro[linha][coluna] = 0;
            }
        }
    }
}

//---------------------------
// Função para aplicar a matriz de habilidade no tabuleiro
void aplicaHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    int meio = TAMANHO_HABILIDADE / 2; // Para centralizar a matriz no ponto de origem

    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            if (habilidade[linha][coluna] == 1) {
                int linhaTabuleiro = linhaOrigem - meio + linha;
                int colunaTabuleiro = colunaOrigem - meio + coluna;

                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Marca habilidade
                    }
                }
            }
        }
    }
}

//---------------------------
// Função para imprimir o tabuleiro no console
void imprimeTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro Batalha Naval com Habilidades:\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

//---------------------------
// Função principal
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializaTabuleiro(tabuleiro);
    posicionaNavios(tabuleiro);

    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criaCone(cone);
    criaCruz(cruz);
    criaOctaedro(octaedro);

    int linhaOrigemCone = 3, colunaOrigemCone = 3;
    int linhaOrigemCruz = 6, colunaOrigemCruz = 6;
    int linhaOrigemOctaedro = 8, colunaOrigemOctaedro = 2;

    aplicaHabilidade(tabuleiro, cone, linhaOrigemCone, colunaOrigemCone);
    aplicaHabilidade(tabuleiro, cruz, linhaOrigemCruz, colunaOrigemCruz);
    aplicaHabilidade(tabuleiro, octaedro, linhaOrigemOctaedro, colunaOrigemOctaedro);

    imprimeTabuleiro(tabuleiro);

    return 0;
}
