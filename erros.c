/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include <stdio.h>
#include <stdlib.h>

#include "erros.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARIÁVEIS PÚBLICAS */
/* -------------------------------------- */

/*                                      */
/* Mensagens de erro de propósito geral */
/*                                      */

char
  msgErro [TAM_MAX_MSG_ERRO];

/* ---------------------------------- */
/* IMPLEMENTAÇÃO DAS FUNÇÕES PÚBLICAS */
/* ---------------------------------- */

void assert (Bool condicao, const char *arquivo, const char *funcao, int linha) {
  if (! condicao) {
    fprintf (stderr, "\n");
    fprintf (stderr, "  Erro em %s::%s() linha %d\n", arquivo, funcao, linha);
    fprintf (stderr, "  %s\n", msgErro);
    fprintf (stderr, "\n");
#ifdef SO_WINDOWS
    system ("PAUSE");
#endif
    exit (EXIT_FAILURE);
  }
}
