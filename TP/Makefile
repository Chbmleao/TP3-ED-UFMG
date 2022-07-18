#
# Copyright 2021 Alysson Ribeiro da Silva - Federal University of Minas Gerais
#
# Permission is hereby granted, free of charge, to any person obtaining a copy 
# of this software and associated documentation files (the "Software"), to deal 
# in the Software without restriction, including without limitation the rights 
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
# of the Software, and to permit persons to whom the Software is furnished to do 
# so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all 
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
# PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

# cc and flags
CC = g++
CXXFLAGS = -pg -std=c++11 -g -Wall

# folders
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/
ASSETS = ./assets/
OUT_FOLDER = ./out/

# all sources, objs, and header files
MAIN = Main
TARGET = tp3.exe
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))
EXE = $(BIN_FOLDER)/tp3.exe
ANALISAMEM = ./analisamem/bin/analisamem

all: build run

mem: $(EXE)
	$(EXE) -i entrada.txt -o saida.txt -p /tmp/tp3memlog.out -l

perf: $(EXE)
	$(EXE) -i $(ASSETS)perf_user_25k.txt -o $(OUT_FOLDER)perf_user_25kOut.txt -p /tmp/perf_user_25k.out
	$(EXE) -i $(ASSETS)perf_user_50k.txt -o $(OUT_FOLDER)perf_user_50kOut.txt -p /tmp/perf_user_50k.out
	$(EXE) -i $(ASSETS)perf_user_75k.txt -o $(OUT_FOLDER)perf_user_75kOut.txt -p /tmp/perf_user_75k.out
	$(EXE) -i $(ASSETS)perf_user_100k.txt -o $(OUT_FOLDER)perf_user_100kOut.txt -p /tmp/perf_user_100k.out
	$(EXE) -i $(ASSETS)perf_user_125k.txt -o $(OUT_FOLDER)perf_user_125kOut.txt -p /tmp/perf_user_125k.out
	$(EXE) -i $(ASSETS)perf_user_150k.txt -o $(OUT_FOLDER)perf_user_150kOut.txt -p /tmp/perf_user_150k.out
	$(EXE) -i $(ASSETS)perf_user_175k.txt -o $(OUT_FOLDER)perf_user_175kOut.txt -p /tmp/perf_user_175k.out
	$(EXE) -i $(ASSETS)perf_user_200k.txt -o $(OUT_FOLDER)perf_user_200kOut.txt -p /tmp/perf_user_200k.out
	$(EXE) -i $(ASSETS)perf_user_225k.txt -o $(OUT_FOLDER)perf_user_225kOut.txt -p /tmp/perf_user_225k.out
	$(EXE) -i $(ASSETS)perf_user_250k.txt -o $(OUT_FOLDER)perf_user_250kOut.txt -p /tmp/perf_user_250k.out
	$(EXE) -i $(ASSETS)perf_message_50.txt -o $(OUT_FOLDER)perf_message_50Out.txt -p /tmp/perf_message_50.out
	$(EXE) -i $(ASSETS)perf_message_100.txt -o $(OUT_FOLDER)perf_message_100Out.txt -p /tmp/perf_message_100.out
	$(EXE) -i $(ASSETS)perf_message_150.txt -o $(OUT_FOLDER)perf_message_150Out.txt -p /tmp/perf_message_150.out
	$(EXE) -i $(ASSETS)perf_message_200.txt -o $(OUT_FOLDER)perf_message_200Out.txt -p /tmp/perf_message_200.out
	$(EXE) -i $(ASSETS)perf_message_250.txt -o $(OUT_FOLDER)perf_message_250Out.txt -p /tmp/perf_message_250.out
	$(EXE) -i $(ASSETS)perf_message_300.txt -o $(OUT_FOLDER)perf_message_300Out.txt -p /tmp/perf_message_300.out
	$(EXE) -i $(ASSETS)perf_message_350.txt -o $(OUT_FOLDER)perf_message_350Out.txt -p /tmp/perf_message_350.out
	$(EXE) -i $(ASSETS)perf_message_400.txt -o $(OUT_FOLDER)perf_message_400Out.txt -p /tmp/perf_message_400.out
	$(EXE) -i $(ASSETS)perf_message_450.txt -o $(OUT_FOLDER)perf_message_450Out.txt -p /tmp/perf_message_450.out
	$(EXE) -i $(ASSETS)perf_message_500.txt -o $(OUT_FOLDER)perf_message_500Out.txt -p /tmp/perf_message_500.out
	$(EXE) -i $(ASSETS)perf_size_15.txt -o $(OUT_FOLDER)perf_size_15Out.txt -p /tmp/perf_size_15.out
	$(EXE) -i $(ASSETS)perf_size_100.txt -o $(OUT_FOLDER)perf_size_100Out.txt -p /tmp/perf_size_100.out
	$(EXE) -i $(ASSETS)perf_size_200.txt -o $(OUT_FOLDER)perf_size_200Out.txt -p /tmp/perf_size_200.out
	$(EXE) -i $(ASSETS)perf_frequency_normal.txt -o $(OUT_FOLDER)perf_frequency_normalOut.txt -p /tmp/perf_frequency_normal.out
	$(EXE) -i $(ASSETS)perf_frequency_random.txt -o $(OUT_FOLDER)perf_frequency_randomOut.txt -p /tmp/perf_frequency_random.out
	
build: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

run: $(EXE)
	$(EXE) -i entrada.txt -o saida.txt -p /tmp/runlog.out

