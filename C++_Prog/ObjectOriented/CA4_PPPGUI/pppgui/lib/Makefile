# Makefile for first PPPGUI library
# 28/3/2025 GB initial revision
# Variable values gleaned from last historic FLTK Code::Blocks project
CXX=g++
AR=ar rcs
INCLUDE_DIRS=../include
CXXFLAGS=-g -I$(INCLUDE_DIRS)
OBJFILES=GUI.o Graph.o Simple_window.o Window.o
LIBFILE=libpppgui.a

# $@ means the target name
# $^ is all the prerequisites (here hellofltk.o)
$(LIBFILE): $(OBJFILES)
	$(AR) $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
	
clean:
	rm -f *.o *.exe *.a