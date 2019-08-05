/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo não é incluído mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef TORNEIO_PONTO_H
#define TORNEIO_PONTO_H

/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include "globais.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARIÁVEIS PÚBLICAS */
/* -------------------------------------- */

extern int
  partidaAtual,
  totalEmpates;

/* Jogador que comeca cada partida */

extern tJogador
  quemComeca;

/* ------------------------------- */
/* PROTÓTIPOS DAS FUNÇÕES PÚBLICAS */
/* ------------------------------- */

extern void prepararTorneio (void);
extern void realizarTorneio (void);
extern void encerrarTorneio (void);

#endif /* ifndef TORNEIO_PONTO_H */
