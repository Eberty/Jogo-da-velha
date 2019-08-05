/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo n�o � inclu�do mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef GLOBAIS_PONTO_H
#define GLOBAIS_PONTO_H

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARI�VEIS P�BLICAS */
/* -------------------------------------- */

/* Sistemas operacionais dispon�veis */

#undef SO_LINUX
#undef SO_WINDOWS

/* Detec��o do sistema operacional em uso, necess�rio */
/* para determinar p.ex. o comando de limpeza de tela */

#if defined(__unix__)  || \
    defined(__linux__) || \
    (defined(__CYGWIN__) && !defined(_WIN32)) /* Cygwin POSIX under Microsoft Windows */
# define SO_LINUX
#elif defined(__CYGWIN__) || defined(_WIN32) || defined(_WIN64)
# define SO_WINDOWS
#else
# error Sistema operacional desconhecido
#endif

/* Tipo Booleano */

#undef Bool
#undef TRUE
#undef FALSE

typedef enum {FALSE, TRUE}
  Bool;

#endif /* ifndef GLOBAIS_PONTO_H */
