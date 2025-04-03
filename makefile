#ejecutable
TARGET = $(BIN_DIR)/laboratorio_PAV

#compilador
CC = g++

# carpeta con los archivos .h
HEAD_DIR = headers

# carpeta con los archivos .cpp
SRC_DIR = src

OBJ_DIR = obj

BIN_DIR = bin

#flags
CFLAGS = -Wall -g

#archivos fuente
SOURCES = $(SRC_DIR)/Mascota.cpp \
          $(SRC_DIR)/Socio.cpp \
          $(SRC_DIR)/Perro.cpp \
          $(SRC_DIR)/Gato.cpp \
          $(SRC_DIR)/Consulta.cpp \
          $(SRC_DIR)/DtFecha.cpp \
          $(SRC_DIR)/DtMascota.cpp \
          $(SRC_DIR)/DtPerro.cpp \
          $(SRC_DIR)/DtGato.cpp \
          $(SRC_DIR)/DtConsulta.cpp \
          $(SRC_DIR)/main.cpp

#Archivos encabezado
HEADERS = $(HEAD_DIR)/Mascota.h \
          $(HEAD_DIR)/Socio.h \
          $(HEAD_DIR)/Perro.h \
          $(HEAD_DIR)/Gato.h \
          $(HEAD_DIR)/Consulta.h \
          $(HEAD_DIR)/DtFecha.h \
          $(HEAD_DIR)/DtMascota.h \
          $(HEAD_DIR)/DtPerro.h \
          $(HEAD_DIR)/DtGato.h \
          $(HEAD_DIR)/DtConsulta.h \
          $(HEAD_DIR)/TipoPelo.h \
          $(HEAD_DIR)/RazaPerro.h \
          $(HEAD_DIR)/Genero.h

#objetos
# patsubst = sustitución de patrones, convierte automaticamente los archivos src/archivo.cpp en obj/archivo.o
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
#OBJS = $(OBJ_DIR)/Mascota.o \
       $(OBJ_DIR)/Socio.o \
       $(OBJ_DIR)/Perro.o \
       $(OBJ_DIR)/Gato.o \
       $(OBJ_DIR)/Consulta.o \
       $(OBJ_DIR)/DtFecha.o \
       $(OBJ_DIR)/DtMascota.o \
       $(OBJ_DIR)/DtPerro.o \
       $(OBJ_DIR)/DtGato.o \
       $(OBJ_DIR)/DtConsulta.o \
	$(OBJ_DIR)/main.o 


#crea el target
$(TARGET) :  $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) 

# $@ va con $(OBJ_DIR)/%.o  y  $< con $(SRC_DIR)/%.cpp
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADERS)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS)  $< -o $@

# -r ya que estoy borrando carpetas 
.PHONY: clean
clean:
	rm -r $(BIN_DIR) $(OBJ_DIR)

run : $(TARGET)
	./$(TARGET)

