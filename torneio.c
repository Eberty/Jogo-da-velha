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
/* CONSTANTES, TIPOS E VARI�VEIS P�BLICAS */
/* -------------------------------------- */

int
  partidaAtual = 0,
  totalEmpates = 0;

/* Jogador que come�a cada partida */

tJogador
  quemComeca;

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARI�VEIS PRIVADAS */
/* -------------------------------------- */

static tJogador
  quemJogaAgora;

/* ------------------------------- */
/* PROT�TIPOS DAS FUN��ES PRIVADAS */
/* ------------------------------- */

static void alternarQuemComeca    (void);
static void alternarQuemJogaAgora (void);
static void realizarPartida       (void);

/* --------------------------------------------- */
/* IMPLEMENTA��O DAS FUN��ES P�BLICAS E PRIVADAS */
/* --------------------------------------------- */

/*
 * ENTRADA: nenhuma
 * A��O:    alterna o jogador que iniciara' a partida
 * SA�DA:   nenhuma
 */

static void alternarQuemComeca (void) {
  quemComeca = (quemComeca == tUsuario ? tPrograma : tUsuario);
}

/*
 * ENTRADA: nenhuma
 * A��O:    alterna o jogador que joga a seguir
 * SA�DA:   nenhuma
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
 * A��O:    realizacao do torneio
 * SA�DA:   nenhuma
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
 * A��O:    realizacao de uma partida
 * SA�DA:   nenhuma
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
 * A��O:    finalizacoes apos o termino do torneio: limpar a tela e mostrar o placar final do torneio
 * SA�DA:   nenhuma
 */

void encerrarTorneio (void) {
  limparTela();
  mostrarNomeJogo();
  mostrarPlacarFinal();
}

