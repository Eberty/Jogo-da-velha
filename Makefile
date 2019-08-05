CC = gcc
ANSI= -ansi -pedantic -std=c99
WARNINGS = -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes -Wnested-externs -Wswitch-default -Wswitch-enum -Wmissing-declarations -Wunreachable-code -Winline -Wfloat-equal -Wundef -Wcast-align -Wredundant-decls -Winit-self -Wshadow
FLAGS = -O3 $(ANSI) $(WARNINGS)
RM = rm -f

.PHONY: all clean

#----------------------------------------------------------------------
# Todos os arquivos fonte e objeto no diretorio atual
#----------------------------------------------------------------------

SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:%.c=%.o)

#----------------------------------------------------------------------
# Os make targets principais
#----------------------------------------------------------------------

BIN = velha
all: clean $(BIN)

#----------------------------------------------------------------------
#	Regra: Atualize e inclua os arquivos de dependencias
#----------------------------------------------------------------------

include $(SOURCES:.c=.dep)

%.dep: %.c 
	@echo "Updating \"$@\" ..."
	@$(SHELL) -ec '$(CC) -MM $< | \
	sed '\''s/$*.o/& $@/g'\'' > $@'

#----------------------------------------------------------------------
#	Rule: Compile todos os arquivos objeto
#----------------------------------------------------------------------

$(OBJECTS): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

#----------------------------------------------------------------------
#	Regra: Compile o executavel
#----------------------------------------------------------------------

$(BIN): $(OBJECTS)
	$(CC) $(FLAGS) $^ -o $@ $(MATH)

#----------------------------------------------------------------------
#	Regra: Limpe o diretorio atual apagando o que nao eh necessario
#----------------------------------------------------------------------

clean:
	$(RM) $(BIN) $(OBJECTS) *.dep *~ *.*~

