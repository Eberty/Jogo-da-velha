/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo n�o � inclu�do mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef ESTRATEGIA_PONTO_H
#define ESTRATEGIA_PONTO_H

/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include "globais.h"
#include "objetos.h"

/* ------------------------------- */
/* PROT�TIPOS DAS FUN��ES P�BLICAS */
/* ------------------------------- */

extern void  limparTabuleiro       (void);
extern tPeca casa2peca             (int casa);
extern Bool  casaVazia             (int casa);
extern int   proximaJogadaPrograma (void);
extern void  efetuarJogada         (tJogador jogador, int casa);
extern Bool  venceuPartida         (tJogador jogador);
extern Bool  empatou               (void);

#endif /* ifndef ESTRATEGIA_PONTO_H */
