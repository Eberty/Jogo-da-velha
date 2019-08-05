/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo não é incluído mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef OBJETOS_PONTO_H
#define OBJETOS_PONTO_H

/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include "globais.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARIÁVEIS PÚBLICAS */
/* -------------------------------------- */

/* Comprimento maximo do nome do usuario */

#define TAM_MAX_NOME_JOGADOR 30

/* Os dois tipos de jogador */

typedef enum {tUsuario, tPrograma}
  tJogador;

/* Os tipos de pecas */

typedef enum {tNenhumaPeca, tUmaPeca, tOutraPeca}
  tPeca;

/* ------------------------------- */
/* PROTÓTIPOS DAS FUNÇÕES PÚBLICAS */
/* ------------------------------- */

extern void        salvarNomeUsuario     (const char *nomeUsuario);
extern void        salvarPecaJogador     (tJogador jogador, tPeca peca);
extern void        salvarVitoriasJogador (tJogador jogador, int vitorias);
extern void        salvarDerrotasJogador (tJogador jogador, int derrotas);
extern const char *lerNomeUsuario        (void);
extern tPeca       lerPecaJogador        (tJogador jogador);
extern int         lerVitoriasJogador    (tJogador jogador);
extern int         lerDerrotasJogador    (tJogador jogador);

#endif /* ifndef OBJETOS_PONTO_H */
