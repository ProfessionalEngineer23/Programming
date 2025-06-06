# Makefile for first PPPGUI program
# 28/3/2025 GB initial revision
# Variable values gleaned from last historic FLTK Code::Blocks project
CC=g++
PPPGUI_DIR=..
CPPFLAGS=-g -I$(PPPGUI_DIR)/include
LDFLAGS=-g
LDLIBS=-L$(PPPGUI_DIR)/lib -lpppgui -lfltk -lfltk_images

# $@ means the target name
# $^ is all the prerequisites (here hellofltk.o)
helloPPP.exe: helloPPP.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<
	
clean:
	rm -f *.o *.exe