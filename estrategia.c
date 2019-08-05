/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include <stdlib.h>
#include <stdio.h>

#include "erros.h"
#include "estrategia.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARIÁVEIS PRIVADAS */
/* -------------------------------------- */

static tPeca
  tabuleiro[3][3];

/* Casas do tabuleiro ordenadas de modo que as mais promissoras        */
/* (com maiores chances de levar a vitoria) aparecem primeiro          */
/* Note que as casas 1, 3, 7 e 9 são simétricas, portanto poderiam ter */
/* sido listadas em qualquer ordem. Idem para as casas 2, 4, 6 e 8.    */

static int
  casaPrioritaria[9] = {5, 1, 3, 7, 9, 2, 4, 6, 8};

/* ------------------------------- */
/* PROTÓTIPOS DAS FUNÇÕES PRIVADAS */
/* ------------------------------- */

static void  casa2linCol         (int casa,  int *linha, int *coluna);
static int   linCol2casa         (int linha, int coluna);
static Bool  casasAlinhadas      (int casa1, int casa2);
static int   terceiraCasaDaLinha (int casa1, int casa2);
static int   casaParaVitoria     (tJogador jogador);

/* --------------------------------------------- */
/* IMPLEMENTAÇÃO DAS FUNÇÕES PÚBLICAS E PRIVADAS */
/* --------------------------------------------- */

/*
 * ENTRADA: nro de uma casa no tabuleiro, entre 1 e 9
 * AÇÂO:    converte o nro da casa na linha e coluna correspondentes, entre 0 e 2
 * SAÍDA:   linha e coluna, passadas por referencia
 */

static void casa2linCol (int casa, int *linha, int *coluna) {
  *linha = (int) ((casa - 1) / 3);
  *coluna = (casa - 1) % 3;
}

/*
 * ENTRADA: uma linha e uma coluna no tabuleiro, entre 0 e 2
 * AÇÂO:    converte a linha e coluna no nro da respectiva casa, entre 1 e 9
 * SAÍDA:   o nro da casa
 */

static int linCol2casa (int linha, int coluna) {
  return (3 * linha + coluna + 1);
}

/*
 * ENTRADA: nros de duas casas no tabuleiro
 * AÇÂO:    determina se as casas estão numa linha horizontal, vertical ou diagonal
 * SAÍDA:   Verdadeiro ou falso
 */

static Bool casasAlinhadas (int casa1, int casa2) {
  int
    linha1,
	linha2,
	coluna1,
	coluna2;

  casa2linCol (casa1, &linha1, &coluna1);
  casa2linCol (casa2, &linha2, &coluna2);

  if (linha1 == linha2)
    return (TRUE);
  if (coluna1 == coluna2)
    return (TRUE);
  if ((linha1 == coluna1) && (linha2 == coluna2))
    return (TRUE);
  if ((linha1 + coluna1 == 2) && (linha2 + coluna2 == 2))
    return (TRUE);
  return (FALSE);
}

/*
 * ENTRADA: nros de duas casas no tabuleiro
 * AÇÂO:    se as casas estiverem numa linha, determina o nro da terceira casa nessa linha
 * SAÍDA:   o nro da terceira casa na linha, ou zero se as casas não estiverem alinhadas
 */

static int terceiraCasaDaLinha (int casa1, int casa2) {
  int
    linha1,
	linha2,
	linha3,
	coluna1,
	coluna2,
	coluna3;

  casa2linCol (casa1, &linha1, &coluna1);
  casa2linCol (casa2, &linha2, &coluna2);

  if (linha1 == linha2) {
    linha3 = linha1;
	coluna3 = 3 - (coluna1 + coluna2);
	return (linCol2casa (linha3, coluna3));
  }
  if (coluna1 == coluna2) {
    coluna3 = coluna1;
	linha3 = 3 - (linha1 + linha2);
	return (linCol2casa (linha3, coluna3));
  }
  if ((linha1 == coluna1) && (linha2 == coluna2)) {
    linha3 = 3 - (linha1 + linha2);
	coluna3 = linha3;
	return (linCol2casa (linha3, coluna3));
  }
  if ((linha1 + coluna1 == 2) && (linha2 + coluna2 == 2)) {
    linha3 = 3 - (linha1 + linha2);
	coluna3 = 2 - linha3;
	return (linCol2casa (linha3, coluna3));
  }
  return (0);
}

/*
 * ENTRADA: um jogador (usuario ou programa)
 * AÇÂO:    determina se esse jogador pode ganhar jogando em alguma casa
 * SAÍDA:   nro da casa que leva `a vitoria, ou zero se nao houver nenhuma
 */

static int casaParaVitoria (tJogador jogador) {
  int
    iCasa,
    casa1,
    casa2,
    casa3,
    iPar,
    jPar,
    casasOcupadas [9],
    totalCasasOcupadas = 0;

  /* Examinar pares de pecas do jogador e determinar possiveis jogadas */

  for (iCasa=0; iCasa<9; iCasa++)
    casasOcupadas [iCasa] = 0;
  for (iCasa=1; iCasa<10; iCasa++) {
    if (casa2peca (iCasa) == lerPecaJogador (jogador))
      casasOcupadas[totalCasasOcupadas++] = iCasa;
  }
  for (iPar = 0; iPar < totalCasasOcupadas; iPar++) {
    for (jPar = iPar+1; jPar < totalCasasOcupadas; jPar++) {
      casa1 = casasOcupadas [iPar];
      casa2 = casasOcupadas [jPar];
      if (! casasAlinhadas (casa1, casa2))
        continue;
      casa3 = terceiraCasaDaLinha (casa1, casa2);
      if (! casaVazia (casa3))
        continue;
      return (casa3);
    }
  }

  /* O jogador nao pode vencer em uma unica jogada entao retorne 0
   * para indicar que nenhuma casa levara' a uma vitoria
   */

  return (0);
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    limpa o tabuleiro para uma nova partida
 * SAÍDA:   nenhuma
 */

void limparTabuleiro (void) {
  int
    iCasa,
    linha,
    coluna;

  for (iCasa = 1; iCasa < 10; iCasa++) {
    casa2linCol (iCasa, &linha, &coluna);
    tabuleiro[linha][coluna] = tNenhumaPeca;
  }
}

/*
 * ENTRADA: numero de uma casa no tabuleiro
 * AÇÂO:    determina a peca na casa fornecida
 * SAÍDA:   a peca na casa fornecida
 */

tPeca casa2peca (int casa) {
  int
    linha, coluna;

  casa2linCol (casa, &linha, &coluna);
  return (tabuleiro[linha][coluna]);
}

/*
 * ENTRADA: nro de uma casa no tabuleiro
 * AÇÂO:    determina se essa casa esta' vazia
 * SAÍDA:   verdadeiro ou falso
 */

Bool casaVazia (int casa) {
  return (casa2peca(casa) == tNenhumaPeca);
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    determina a casa (de 1 a 9) onde o programa deve jogar:
 *            - se o programa puder vencer nessa jogada, entao jogue na casa certa
 *            - se o usuário estiver prestes a vencer, jogue na casa em que ele jogaria, impedindo que ele vença
 *            - caso contrário, jogue na primeira casa vazia na sequencia listada no vetor casaPrioritaria[]
 * SAÍDA:   nro da casa
 */

int proximaJogadaPrograma (void) {
  int
    casa,
    iCasa;

  /* O programa nao pode vencer com uma unica jogada? */

  casa = casaParaVitoria (tPrograma);
  if (casa > 0)
    return (casa);

  /* O usuario pode vencer com uma unica jogada? */

  casa = casaParaVitoria (tUsuario);
  if (casa > 0)
    return (casa);

  /* Nenhum jogador pode vencer com uma unica jogada entao eh
   * necessario escolher a melhor jogada entre as varias possiveis
   * MAS POR ENQUANTO vamos apenas escolher a primeira casa vazia
   * na sequencia listada no vetor casaPrioritaria[]
   */

   for (iCasa=0; iCasa<9; iCasa++)
     if (casaVazia (casaPrioritaria[iCasa]))
       return (casaPrioritaria[iCasa]);

   /* Nenhuma casa vazia. Isso nunca deveria acontecer, pois proximaJogadaPrograma()  */
   /* só é chamada se não houve ainda uma vitória ou empate. Emitir mensagem de erro. */

   printf ("\n");
   printf ("ERRO em proximaJogadaPrograma(): nenhuma casa vazia.");
   printf ("Reveja a logica do codigo.");
   printf ("\n");
   fflush (NULL);
   exit (EXIT_FAILURE);
}

/*
 * ENTRADA: numero da casa onde um jogador acaba de jogar
 * AÇÂO:    atualiza o tabuleiro para refletir essa jogada
 * SAÍDA:   nenhuma
 */

void efetuarJogada (tJogador jogador, int casa) {
  int
    linha,
	coluna;

  casa2linCol (casa, &linha, &coluna);
  tabuleiro[linha][coluna] = lerPecaJogador (jogador);
}

/*
 * ENTRADA: um jogador (usuario ou programa)
 * AÇÂO:    determina se esse jogador venceu a partida
 * SAÍDA:   verdadeiro ou falso
 */

Bool venceuPartida (tJogador jogador) {
  tPeca
    peca = lerPecaJogador (jogador);

  /* Verifica as linhas */

  if ( (peca == casa2peca (1)) && (peca == casa2peca (2)) && (peca == casa2peca (3)) ) return (TRUE);
  if ( (peca == casa2peca (4)) && (peca == casa2peca (5)) && (peca == casa2peca (6)) ) return (TRUE);
  if ( (peca == casa2peca (7)) && (peca == casa2peca (8)) && (peca == casa2peca (9)) ) return (TRUE);

  /* Verifica as colunas */

  if ( (peca == casa2peca (1)) && (peca == casa2peca (4)) && (peca == casa2peca (7)) ) return (TRUE);
  if ( (peca == casa2peca (2)) && (peca == casa2peca (5)) && (peca == casa2peca (8)) ) return (TRUE);
  if ( (peca == casa2peca (3)) && (peca == casa2peca (6)) && (peca == casa2peca (9)) ) return (TRUE);

  /* Verifica as diagonais */

  if ( (peca == casa2peca (1)) && (peca == casa2peca (5)) && (peca == casa2peca (9)) ) return (TRUE);
  if ( (peca == casa2peca (3)) && (peca == casa2peca (5)) && (peca == casa2peca (7)) ) return (TRUE);

  return (FALSE);
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    determina se o jogo ficou empatado
 * SAÍDA:   verdadeiro ou falso
 */

Bool empatou (void) {
  int
    iCasa;

  if (venceuPartida (tUsuario))
    return (FALSE);
  if (venceuPartida (tPrograma))
    return (FALSE);
   for (iCasa=1; iCasa<10; iCasa++)
     if (casaVazia (iCasa))
       return (FALSE);
  return (TRUE);
}
