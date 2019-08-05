/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo n�o � inclu�do mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef ERROS_PONTO_H
#define ERROS_PONTO_H

/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include "globais.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARI�VEIS P�BLICAS */
/* -------------------------------------- */

/*                                      */
/* Mensagens de erro de prop�sito geral */
/*                                      */

#define TAM_MAX_MSG_ERRO  1000

extern char
  msgErro [TAM_MAX_MSG_ERRO];

#define SHORT_FILE_NAME              \
  (strrchr(__FILE__, '/') ?          \
     strrchr(__FILE__, '/') + 1 :    \
     strrchr(__FILE__, '\\') ?       \
       strrchr(__FILE__, '\\') + 1 : \
       __FILE__)

#define ASSERT(condicao,...)                                   \
  snprintf (msgErro, TAM_MAX_MSG_ERRO, __VA_ARGS__);           \
  assert ((condicao), SHORT_FILE_NAME, __FUNCTION__, __LINE__)

/* ------------------------------- */
/* PROT�TIPOS DAS FUN��ES P�BLICAS */
/* ------------------------------- */

extern void assert (Bool condicao, const char *arquivo, const char *funcao, int linha);

#endif /* ifndef ERROS_PONTO_H */
