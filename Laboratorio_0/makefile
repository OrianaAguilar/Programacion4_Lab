TARGET = principal
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = inc
SRC_DIR = src
OBJS    = $(OBJ_DIR)/Biblioteca.o \
		  $(OBJ_DIR)/chatGPT.o \
		  $(OBJ_DIR)/DTFecha.o \
		  $(OBJ_DIR)/DTInfoEstudiante.o \
		  $(OBJ_DIR)/Estudiante.o \
		  $(OBJ_DIR)/Informacion.o \
		  $(OBJ_DIR)/Libro.o \
		  $(OBJ_DIR)/PaginaWeb.o \
		  $(OBJ_DIR)/principal.o \
		  $(OBJ_DIR)/utils.o 

CPP = g++
CPPFLAGS = -Wall -I$(INC_DIR)

$(TARGET) : $(OBJS)
	mkdir -p $(BIN_DIR)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CPP) -c -MD $(CPPFLAGS) $< -o $@

-include $(OBJ_DIR)/*.d

.PHONY: clean
clean :
	@rm -r $(OBJ_DIR) $(BIN_DIR)
