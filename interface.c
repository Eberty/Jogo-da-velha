/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include <stdlib.h>
#include <stdio.h>

#include "erros.h"
#include "objetos.h"
#include "interface.h"
#include "estrategia.h"
#include "torneio.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARIÁVEIS PRIVADAS */
/* -------------------------------------- */

/* Carateres usados para imprimir na tela as pecas do tabuleiro */

char
  charPeca[3] = {CHAR_NENHUMA_PECA, CHAR_UMA_PECA, CHAR_OUTRA_PECA};

/* Descricao textual do caracter usado para cada peca */

char
  descricaoPeca[3][10] = {"", "um xis", "um zero"};

/* ------------------------------- */
/* PROTÓTIPOS DAS FUNÇÕES PRIVADAS */
/* ------------------------------- */

/* --------------------------------------------- */
/* IMPLEMENTAÇÃO DAS FUNÇÕES PÚBLICAS E PRIVADAS */
/* --------------------------------------------- */

/*
 * ENTRADA: uma peca
 * AÇÂO:    determina o caracter correspondente a peca fornecida
 * SAÍDA:   caracter para imprimir a peca
 */

char peca2charPeca (tPeca peca) {
  return (charPeca [peca]);
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    obtem, via teclado, o nome do usuario e guarda-o na estrutura apropriada
 *          eh seguro supor que o usuario nao digitara´ espacos em branco
 * SAÍDA:   nenhuma
 */

void obterNomeUsuario (void) {
  char
    nomeUsuario[TAM_MAX_NOME_JOGADOR];

  printf ("Digite seu nome, sem espacos: ");
  scanf ("%s", nomeUsuario);
  printf ("\n");
  salvarNomeUsuario (nomeUsuario);
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    obtem, via teclado, a peca do usuario e guarda-a na estrutura apropriada
 *          eh seguro supor que o usuario nao digitara´ espacos em branco
 * SAÍDA:   nenhuma
 */

void obterPecaUsuario (void) {
  int
    opcaoEscolhida;

  printf ("Escolha \n");
  printf ("  [1] para jogar com %c (%s)\n", charPeca[tUmaPeca],   descricaoPeca[tUmaPeca]);
  printf ("  [2] para jogar com %c (%s)\n", charPeca[tOutraPeca], descricaoPeca[tOutraPeca]);
  printf ("Sua escolha? ");
  scanf ("%d", &opcaoEscolhida);
  while (opcaoEscolhida != 1 && opcaoEscolhida != 2) {
    printf ("*** Opcao invalida *** \n");
    printf ("Escolha \n");
    printf ("  [1] para jogar com %c (%s)\n", charPeca[tUmaPeca],   descricaoPeca[tUmaPeca]);
    printf ("  [2] para jogar com %c (%s)\n", charPeca[tOutraPeca], descricaoPeca[tOutraPeca]);
    printf ("Sua escolha? ");
    scanf ("%d", &opcaoEscolhida);
  }
  printf ("\n");
  if (opcaoEscolhida == 1) {
    salvarPecaJogador (tUsuario,  tUmaPeca);
	salvarPecaJogador (tPrograma, tOutraPeca);
  }
  else {
    salvarPecaJogador (tUsuario,  tOutraPeca);
	salvarPecaJogador (tPrograma, tUmaPeca);
  }
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    pergunta ao usuario onde ele quer jogar
 *          eh seguro supor que o usuario nao digitara´ espacos em branco
 * SAÍDA:   numero da casa
 */

int obterJogadaUsuario (void) {
  int
    casaEscolhida;

  limparTela();
  mostrarNomeJogo();
  mostrarTabuleiro();
  printf ("Joga em qual casa? ");
  scanf ("%d", &casaEscolhida);
  while ((casaEscolhida < 1) || (casaEscolhida > 9) || (! casaVazia (casaEscolhida))) {
    printf ("*** Casa invalida *** \n");
    printf ("Joga em qual casa? ");
    scanf ("%d", &casaEscolhida);
  }
  printf ("\n");
  return (casaEscolhida);
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    limpa a tela
 * SAÍDA:   nenhuma
 */

void limparTela (void) {
#ifdef SO_WINDOWS
  system ("cls");
#endif
#ifdef SO_LINUX
  system ("clear");
#endif
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    imprime na tela uma breve mensagem sobre o jogo
 * SAÍDA:   nenhuma
 */

void mostrarNomeJogo (void) {
  printf ("---------------\n");
  printf (" Jogo da Velha \n");
  printf ("---------------\n");
  printf ("\n");
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    imprime na tela o tabuleiro com as pecas jogadas ate´ entao e uma legenda mostrando a numeracao das casas
 * SAÍDA:   nenhuma
 */

void mostrarTabuleiro (void) {
  int
    iCasa;
  char
    charTabuleiro[9];

  for (iCasa = 1; iCasa < 10; iCasa++)
    charTabuleiro[iCasa-1] = peca2charPeca (casa2peca (iCasa));

  printf ("   LEGENDA             PARTIDA %2d \n", partidaAtual);
  printf ("\n");
  printf ("  1 | 2 | 3            %c | %c | %c  \n", charTabuleiro[0], charTabuleiro[1], charTabuleiro[2]);
  printf (" ---+---+---          ---+---+--- \n");
  printf ("  4 | 5 | 6            %c | %c | %c  \n", charTabuleiro[3], charTabuleiro[4], charTabuleiro[5]);
  printf (" ---+---+---          ---+---+--- \n");
  printf ("  7 | 8 | 9            %c | %c | %c  \n", charTabuleiro[6], charTabuleiro[7], charTabuleiro[8]);
  printf ("\n");
  printf ("Quem comeca: %s \n", quemComeca == tUsuario ? lerNomeUsuario() : "Programa");
  printf ("\n");
}

/*
 * ENTRADA: uma pergunta a ser feita ao usuario
 * AÇÂO:    pede ao usuario que responda sim ou nao `a pergunta; aceita como resposta 's', 'S', 'n' ou 'N'
 *          eh seguro supor que o usuario nao digitara´ espacos em branco
 * SAÍDA:   a resposta convertida para maiusculo, ou seja, 'S' ou 'N'
 */

char obterSIMouNAO (const char *pergunta) {
  char
    resposta[2];

  printf ("%s", pergunta);
  scanf ("%s", resposta);
  if (resposta[0] == 's')
    resposta[0] = 'S';
  if (resposta[0] == 'n')
    resposta[0] = 'N';
  while ((resposta[0] != 'S') && (resposta[0] != 'N')) {
    printf ("*** Resposta '%c' invalida *** \n", resposta[0]);
    printf ("%s", pergunta);
    scanf ("%s", resposta);
    if (resposta[0] == 's')
      resposta[0] = 'S';
    if (resposta[0] == 'n')
      resposta[0] = 'N';
  }
  return (resposta[0]);
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    mostra na tela o placar final do torneio
 * SAÍDA:   nenhuma
 */

void mostrarPlacarFinal (void) {
  printf ("\n");
  printf ("Placar final: \n");
  printf ("\n");
  printf ("  %s %d X %d Programa \n", lerNomeUsuario(), lerVitoriasJogador(tUsuario), lerVitoriasJogador(tPrograma));
  printf ("  %d empates \n", totalEmpates);
  printf ("\n");
}

