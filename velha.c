/* --------------------------- */
/* BIBLIOTECAS E INCLUDE FILES */
/* --------------------------- */

#include <stdlib.h>
#include <stdio.h>

#include "objetos.h"
#include "erros.h"
#include "interface.h"
#include "estrategia.h"
#include "torneio.h"

/* ------------------------- */
/* IMPLEMENTA��O DAS FUN��ES */
/* ------------------------- */

int main (void)
{
  prepararTorneio();
  realizarTorneio();
  encerrarTorneio();
#ifdef SO_WINDOWS
  system("PAUSE");
#endif
  return 0;
}
