/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo não é incluído mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef ERROS_PONTO_H
#define ERROS_PONTO_H

/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include "globais.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARIÁVEIS PÚBLICAS */
/* -------------------------------------- */

/*                                      */
/* Mensagens de erro de propósito geral */
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
/* PROTÓTIPOS DAS FUNÇÕES PÚBLICAS */
/* ------------------------------- */

extern void assert (Bool condicao, const char *arquivo, const char *funcao, int linha);

#endif /* ifndef ERROS_PONTO_H */
