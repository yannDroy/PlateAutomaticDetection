CC = gcc
CFLAGS = -g -Werror -O3
LFLAGS = -lm -fopenmp

SOURCE_DIR = source
INC_DIR = source/include
BIN_DIR = bin
VIZ_DIR = visualization

OUTNAME = PAD

all: $(OUTNAME)

$(OUTNAME): pad.o die.o load_data.o debug.o vector.o model_process.o model_create.o out.o	
	$(CC) $(CFLAGS) $(BIN_DIR)/pad.o $(BIN_DIR)/die.o $(BIN_DIR)/load_data.o $(BIN_DIR)/debug.o $(BIN_DIR)/vector.o $(BIN_DIR)/model_process.o $(BIN_DIR)/model_create.o $(BIN_DIR)/out.o -o $(BIN_DIR)//$(OUTNAME) $(LFLAGS)

pad.o: $(SOURCE_DIR)/pad.c
	$(CC) $(CFLAGS) $(SOURCE_DIR)/pad.c -c -o $(BIN_DIR)/pad.o $(LFLAGS)

die.o: $(SOURCE_DIR)/die.c $(INC_DIR)/die.h
	$(CC) $(CFLAGS) $(SOURCE_DIR)/die.c -c -o $(BIN_DIR)/die.o $(LFLAGS)

load_data.o: $(SOURCE_DIR)/load_data.c $(INC_DIR)/load_data.h
	$(CC) $(CFLAGS) $(SOURCE_DIR)/load_data.c -c -o $(BIN_DIR)/load_data.o $(LFLAGS)

debug.o: $(SOURCE_DIR)/debug.c $(INC_DIR)/debug.h
	$(CC) $(CFLAGS) $(SOURCE_DIR)/debug.c -c -o $(BIN_DIR)/debug.o $(LFLAGS)

vector.o: $(SOURCE_DIR)/vector.c $(INC_DIR)/vector.h
	$(CC) $(CFLAGS) $(SOURCE_DIR)/vector.c -c -o $(BIN_DIR)/vector.o $(LFLAGS)

out.o: $(SOURCE_DIR)/out.c $(INC_DIR)/out.h
	$(CC) $(CFLAGS) $(SOURCE_DIR)/out.c -c -o $(BIN_DIR)/out.o $(LFLAGS)

model_process.o: $(SOURCE_DIR)/model_process.c $(INC_DIR)/model_process.h
	$(CC) $(CFLAGS) $(SOURCE_DIR)/model_process.c -c -o $(BIN_DIR)/model_process.o $(LFLAGS)

model_create.o: $(SOURCE_DIR)/model_create.c $(INC_DIR)/model_create.h
	$(CC) $(CFLAGS) $(SOURCE_DIR)/model_create.c -c -o $(BIN_DIR)/model_create.o $(LFLAGS)

clean:
	rm -rf $(BIN_DIR)/* $(VIZ_DIR)/in/*.out $(VIZ_DIR)/out/jpg/*.jpg $(VIZ_DIR)/out/ps/*.ps
