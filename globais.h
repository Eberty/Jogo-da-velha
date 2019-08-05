/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo não é incluído mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef GLOBAIS_PONTO_H
#define GLOBAIS_PONTO_H

/* -------------------------------------- */
/* CONSTANTES, TIPOS E VARIÁVEIS PÚBLICAS */
/* -------------------------------------- */

/* Sistemas operacionais disponíveis */

#undef SO_LINUX
#undef SO_WINDOWS

/* Detecção do sistema operacional em uso, necessário */
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
