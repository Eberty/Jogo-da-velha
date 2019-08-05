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
/* CONSTANTES, TIPOS E VARIÁVEIS PÚBLICAS */
/* -------------------------------------- */

int
  partidaAtual = 0,
  totalEmpates = 0;

/* Jogador que começa cada partida */

tJogador
  quemComeca;

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARIÁVEIS PRIVADAS */
/* -------------------------------------- */

static tJogador
  quemJogaAgora;

/* ------------------------------- */
/* PROTÓTIPOS DAS FUNÇÕES PRIVADAS */
/* ------------------------------- */

static void alternarQuemComeca    (void);
static void alternarQuemJogaAgora (void);
static void realizarPartida       (void);

/* --------------------------------------------- */
/* IMPLEMENTAÇÃO DAS FUNÇÕES PÚBLICAS E PRIVADAS */
/* --------------------------------------------- */

/*
 * ENTRADA: nenhuma
 * AÇÂO:    alterna o jogador que iniciara' a partida
 * SAÍDA:   nenhuma
 */

static void alternarQuemComeca (void) {
  quemComeca = (quemComeca == tUsuario ? tPrograma : tUsuario);
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    alterna o jogador que joga a seguir
 * SAÍDA:   nenhuma
 */

static void alternarQuemJogaAgora (void) {
  quemJogaAgora = (quemJogaAgora == tUsuario ? tPrograma : tUsuario);
}

void prepararTorneio (void) {
  limparTela();
  mostrarNomeJogo();
  obterNomeUsuario();
  obterPecaUsuario();
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    realizacao do torneio
 * SAÍDA:   nenhuma
 */

void realizarTorneio (void) {
  Bool
    continueJogando = TRUE;

  partidaAtual = 0;
  quemComeca = tPrograma;
  while (continueJogando) {
    alternarQuemComeca();
    realizarPartida();
    continueJogando = (obterSIMouNAO ("Deseja jogar outra partida [S/N] ?") == 'S');
  }
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    realizacao de uma partida
 * SAÍDA:   nenhuma
 */

static void realizarPartida (void) {
  int
    casaJogada;

  limparTabuleiro();
  partidaAtual++;
  quemJogaAgora = quemComeca;

  while (! (venceuPartida (tUsuario) || venceuPartida (tPrograma) || empatou())) {
    if (quemJogaAgora == tUsuario)
      casaJogada = obterJogadaUsuario();
    else
      casaJogada = proximaJogadaPrograma();
    efetuarJogada (quemJogaAgora, casaJogada);
    alternarQuemJogaAgora();
  }
  limparTela();
  mostrarNomeJogo();
  mostrarTabuleiro();
  if (venceuPartida (tUsuario)) {
    printf ("Voce ganhou esta partida \n");
	salvarVitoriasJogador (tUsuario,  lerVitoriasJogador(tUsuario)  + 1);
	salvarDerrotasJogador (tPrograma, lerDerrotasJogador(tPrograma) + 1);
  }
  else if (venceuPartida (tPrograma)) {
    printf ("Eu ganhei esta partida \n");
	salvarVitoriasJogador (tPrograma, lerVitoriasJogador(tPrograma) + 1);
	salvarDerrotasJogador (tUsuario,  lerDerrotasJogador(tUsuario)  + 1);
  }
  else {
    printf ("Partida empatada\n");
    totalEmpates++;
  }
  printf ("\n");
  printf ("Ate agora voce teve %d vitorias, %d derrotas e %d empates\n",
    lerVitoriasJogador(tUsuario),
    lerDerrotasJogador(tUsuario),
    totalEmpates);
  printf ("\n");
}

/*
 * ENTRADA: nenhuma
 * AÇÂO:    finalizacoes apos o termino do torneio: limpar a tela e mostrar o placar final do torneio
 * SAÍDA:   nenhuma
 */

void encerrarTorneio (void) {
  limparTela();
  mostrarNomeJogo();
  mostrarPlacarFinal();
}

