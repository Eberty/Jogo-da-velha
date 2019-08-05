/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include <stdio.h>
#include <stdlib.h>

#include "erros.h"

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARI�VEIS P�BLICAS */
/* -------------------------------------- */

/*                                      */
/* Mensagens de erro de prop�sito geral */
/*                                      */

char
  msgErro [TAM_MAX_MSG_ERRO];

/* ---------------------------------- */
/* IMPLEMENTA��O DAS FUN��ES P�BLICAS */
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
