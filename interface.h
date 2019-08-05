/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo não é incluído mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef INTERFACE_PONTO_H
#define INTERFACE_PONTO_H

/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include "globais.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARIÁVEIS PÚBLICAS */
/* -------------------------------------- */

/* Carateres usados para imprimir na tela as pecas do tabuleiro */

#define CHAR_NENHUMA_PECA  ' '  /* Branco para casas vazias */
#define CHAR_UMA_PECA      'X'
#define CHAR_OUTRA_PECA    'O'

extern char
  charPeca[3];

/* Descricao textual do caracter usado para cada peca */

extern char
  descricaoPeca[3][10];

/* ------------------------------- */
/* PROTÓTIPOS DAS FUNÇÕES PÚBLICAS */
/* ------------------------------- */

extern char peca2charPeca      (tPeca peca);
extern void obterNomeUsuario   (void);
extern void obterPecaUsuario   (void);
extern int  obterJogadaUsuario (void);
extern void limparTela         (void);
extern void mostrarNomeJogo    (void);
extern void mostrarTabuleiro   (void);
extern char obterSIMouNAO      (const char *pergunta);
extern void mostrarPlacarFinal (void);

#endif /* ifndef INTERFACE_PONTO_H */
