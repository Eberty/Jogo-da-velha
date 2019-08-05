/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo não é incluído mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef ESTRATEGIA_PONTO_H
#define ESTRATEGIA_PONTO_H

/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include "globais.h"
#include "objetos.h"

/* ------------------------------- */
/* PROTÓTIPOS DAS FUNÇÕES PÚBLICAS */
/* ------------------------------- */

extern void  limparTabuleiro       (void);
extern tPeca casa2peca             (int casa);
extern Bool  casaVazia             (int casa);
extern int   proximaJogadaPrograma (void);
extern void  efetuarJogada         (tJogador jogador, int casa);
extern Bool  venceuPartida         (tJogador jogador);
extern Bool  empatou               (void);

#endif /* ifndef ESTRATEGIA_PONTO_H */
