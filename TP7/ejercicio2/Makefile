# Variables generales
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -Wextra -pedantic -g

# Nombres de las librerías (sin el prefijo lib y la extensión .a)
LIB_NAME = cadenas

# Directorios de las librerías generados a partir de los nombres
LIB_DIR = $(addprefix ../,$(LIB_NAME))

# Archivos de las librerías
LIBRARY = $(addprefix -l,$(LIB_NAME))
LIBRARY_DIRS = $(addprefix -L,$(LIB_DIR))
INCLUDE_DIRS = $(addprefix -I,$(LIB_DIR))

# Archivos comunes (código fuente y cabeceras)
SRCS = stack.c
HDRS = stack.h

# Objetivo del programa principal
PROG_TARGET = programa
PROG_SRCS = main.c
PROG_OBJS = $(PROG_SRCS:.c=.o)

# Objetivo de los tests
TEST_TARGET = test_bin
TEST_SRCS = prueba.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Compilar ambos: programa y tests
all: $(PROG_TARGET) $(TEST_TARGET)

# Compilar el programa principal
$(PROG_TARGET): $(PROG_OBJS) $(SRCS:.c=.o)
	$(CC) $(CFLAGS) -o $@ $(PROG_OBJS) $(SRCS:.c=.o) $(LIBRARY_DIRS) $(LIBRARY)

# Compilar el ejecutable de pruebas
$(TEST_TARGET): $(TEST_OBJS) $(SRCS:.c=.o)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) $(SRCS:.c=.o) $(LIBRARY_DIRS) $(LIBRARY)

# Regla genérica para compilar archivos .o a partir de .c
%.o: %.c $(HDRS)
	@echo "Compilando $<"
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $<

# Ejecutar el programa principal
.PHONY: run
run: $(PROG_TARGET)
	@echo "Ejecutando el programa"
	./$(PROG_TARGET)

# Ejecutar las pruebas
.PHONY: test
test: $(TEST_TARGET)
	@echo "Ejecutando pruebas"
	./$(TEST_TARGET)

# Limpiar archivos objeto y ejecutables
.PHONY: clean
clean:
	@echo "Limpiando archivos objeto y ejecutables..."
	rm -f $(PROG_OBJS) $(TEST_OBJS) $(SRCS:.c=.o) $(PROG_TARGET) $(TEST_TARGET)
