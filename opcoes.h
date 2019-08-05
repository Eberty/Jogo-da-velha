/* ------------------------------------------------------------- */
/* Certifique-se que este arquivo n�o � inclu�do mais de uma vez */
/* ------------------------------------------------------------- */

#ifndef OPCOES_PONTO_H
#define OPCOES_PONTO_H

/* -------------------- */
/* OP��ES DE COMPILA��O */
/* -------------------- */

/* Sistemas operacionais dispon�veis */

#undef _SO_LINUX_
#undef _SO_WINDOWS_

/* Detec��o do sistema operacional em uso, necess�rio */
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
