/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo n�o � inclu�do mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef TORNEIO_PONTO_H
#define TORNEIO_PONTO_H

/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include "globais.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARI�VEIS P�BLICAS */
/* -------------------------------------- */

extern int
  partidaAtual,
  totalEmpates;

/* Jogador que comeca cada partida */

extern tJogador
  quemComeca;

/* ------------------------------- */
/* PROT�TIPOS DAS FUN��ES P�BLICAS */
/* ------------------------------- */

extern void prepararTorneio (void);
extern void realizarTorneio (void);
extern void encerrarTorneio (void);

#endif /* ifndef TORNEIO_PONTO_H */
