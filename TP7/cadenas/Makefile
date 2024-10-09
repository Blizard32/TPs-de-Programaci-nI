# Variables generales
CC = gcc
CFLAGS = -Wall -Wextra -g

# Archivos comunes, este es el lugar para cambiar el nombre
# o agregar más archivos a la compilación.
SRCS = cadenas.c
HDRS = cadenas.h

# Objetivos
LIBRARY_NAME = libcadenas.a
PROG_TARGET = main_bin

# Archivos para tests
TEST_TARGET = test_bin
TEST_SRCS = $(SRCS) prueba.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Archivos objeto de la librería
OBJS = $(SRCS:.c=.o)

# Compilar ambos: programa y tests
all: $(LIBRARY_NAME) $(TEST_TARGET)

# Crear la librería estática .a
$(LIBRARY_NAME): $(OBJS)
	@echo "generando librería estática $@"
	ar rcs $@ $^

# Compilar el ejecutable de pruebas
$(TEST_TARGET): $(TEST_OBJS)
	@echo "compilando $@"
	$(CC) $(CFLAGS) -o $@ $^

# Regla genérica para compilar archivos .o a partir de .c
%.o: %.c $(HDRS)
	@echo "compilando $<"
	$(CC) $(CFLAGS) -c $<

# Ejecutar el programa principal (si fuera necesario)
.PHONY: run
run: $(PROG_TARGET)
	@echo "ejecutando"
	./$(PROG_TARGET)

# Ejecutar las pruebas (nuevo nombre para evitar conflictos)
.PHONY: probar
test: $(TEST_TARGET)
	@echo "probando"
	./$(TEST_TARGET)

# Limpiar archivos objeto y ejecutables
.PHONY: clean
clean:
	@echo "limpiando"
	rm -f $(OBJS) $(TEST_OBJS) $(LIBRARY_NAME) $(TEST_TARGET)
