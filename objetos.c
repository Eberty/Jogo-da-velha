/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "erros.h"
#include "objetos.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARI�VEIS PRIVADAS */
/* -------------------------------------- */

/* Dados relevantes a cada jogador */

typedef struct {
  char  nome[TAM_MAX_NOME_JOGADOR];
  tPeca peca;
  int   totalVitorias;
  int   totalDerrotas;
}
  tDadosJogador;

static tDadosJogador
  dadosJogador [2];

/* ---------------------------------- */
/* IMPLEMENTA��O DAS FUN��ES P�BLICAS */
/* ---------------------------------- */

/*
 * ENTRADA: um string contendo o nome do usuario, fornecido pelo teclado
 * A��O:    salva o nome do usuario na estrutura de dados apropriada
 * SA�DA:   nenhuma
 */

void salvarNomeUsuario (const char *nomeUsuario) {
  strncpy (dadosJogador[tUsuario].nome, nomeUsuario, TAM_MAX_NOME_JOGADOR);
}

/*
 * ENTRADA: nenhuma
 * A��O:    nenhuma
 * SA�DA:   ponteiro para o nome do usuario, que est� guardado na estrutura de dados apropriada
 */

const char *lerNomeUsuario (void) {
  return (dadosJogador[tUsuario].nome);
}

/*
 * ENTRADA: um jogador (tUsuario ou tPrograma) e sua peca (tUmaPeca ou tOutraPeca)
 * A��O:    salva na estrutura de dados apropriada a correspondencia jogador <--> peca
 * SA�DA:   nenhuma
 */

void salvarPecaJogador (tJogador jogador, tPeca peca) {
  ASSERT ((jogador == tUsuario) || (jogador == tPrograma), "Jogador invalido (%d)", jogador);
  ASSERT ((peca == tUmaPeca) || (peca == tOutraPeca), "Peca invalida (%d)", peca);
  dadosJogador[jogador].peca = peca;
}

/*
 * ENTRADA: um jogador (tUsuario ou tPrograma) e sua quantidade de vitorias (int)
 * A��O:    salva na estrutura de dados apropriada a correspondencia jogador <--> vitorias
 * SA�DA:   nenhuma
 */

void salvarVitoriasJogador (tJogador jogador, int vitorias) {
  ASSERT ((jogador == tUsuario) || (jogador == tPrograma), "Jogador invalido (%d)", jogador);
  ASSERT (vitorias > 0, "Nro de vitorias invalido (%d)", vitorias);
  dadosJogador[jogador].totalVitorias = vitorias;
}

/*
 * ENTRADA: um jogador (tUsuario ou tPrograma) e sua quantidade de derrotas (int)
 * A��O:    salva na estrutura de dados apropriada a correspondencia jogador <--> derrotas
 * SA�DA:   nenhuma
 */

void salvarDerrotasJogador (tJogador jogador, int derrotas) {
  ASSERT ((jogador == tUsuario) || (jogador == tPrograma), "Jogador invalido (%d)", jogador);
  ASSERT (derrotas > 0, "Nro de derrotas invalido (%d)", derrotas);
  dadosJogador[jogador].totalDerrotas = derrotas;
}

/*
 * ENTRADA: um jogador (tUsuario ou tPrograma)
 * A��O:    nenhuma
 * SA�DA:   a peca desse jogador
 */

tPeca lerPecaJogador (tJogador jogador) {
  ASSERT ((jogador == tUsuario) || (jogador == tPrograma), "Jogador invalido (%d)", jogador);
  return (dadosJogador[jogador].peca);
}

/*
 * ENTRADA: um jogador (tUsuario ou tPrograma)
 * A��O:    nenhuma
 * SA�DA:   o numero de vitorias desse jogador
 */

int lerVitoriasJogador (tJogador jogador) {
  ASSERT ((jogador == tUsuario) || (jogador == tPrograma), "Jogador invalido (%d)", jogador);
  return (dadosJogador[jogador].totalVitorias);
}

/*
 * ENTRADA: um jogador (tUsuario ou tPrograma)
 * A��O:    nenhuma
 * SA�DA:   o numero de derrotas desse jogador
 */

int lerDerrotasJogador (tJogador jogador) {
  ASSERT ((jogador == tUsuario) || (jogador == tPrograma), "Jogador invalido (%d)", jogador);
  return (dadosJogador[jogador].totalDerrotas);
}
