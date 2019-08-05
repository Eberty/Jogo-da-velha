/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo não é incluído mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef OPCOES_PONTO_H
#define OPCOES_PONTO_H

/* -------------------- */
/* OPÇÕES DE COMPILAÇÃO */
/* -------------------- */

/* Sistemas operacionais disponíveis */

#undef _SO_LINUX_
#undef _SO_WINDOWS_

/* Detecção do sistema operacional em uso, necessário */
/* para determinar p.ex. o comando de limpeza de tela */

#if defined(__unix__)  || \
    defined(__linux__) || \
    (defined(__CYGWIN__) && !defined(_WIN32)) /* Cygwin POSIX under Microsoft Windows */
# define _SO_LINUX_
#elif defined(__CYGWIN__) || defined(_WIN32) || defined(_WIN64)
# define _SO_WINDOWS_
#else
# error Sistema operacional desconhecido
#endif

#endif /* ifndef OPCOES_PONTO_H */
