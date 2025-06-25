# Makefile for Rectangle and Chessboard Projects using PPPGUI

# Compiler and flags
CXX = g++
CXXFLAGS = -g -Ipppgui/include
LDFLAGS = -Lpppgui/lib -lfltk -lfltk_images -ljpeg -lz -lpng

# PPPGUI source files (shared across all targets)
PPPGUI_SRCS = \
    pppgui/lib/Graph.cpp \
    pppgui/lib/GUI.cpp \
    pppgui/lib/Simple_window.cpp \
    pppgui/lib/Window.cpp

# Project source files
SMILEY_SRCS = Rectangle.cpp $(PPPGUI_SRCS)
CHESS_SRCS = chessboard.cpp $(PPPGUI_SRCS)

# Executable names
SMILEY_EXE = Rectangle.exe
CHESS_EXE = chessboard.exe

# Default target: build everything
all: $(SMILEY_EXE) $(CHESS_EXE)

# Build rules
$(SMILEY_EXE): $(SMILEY_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(CHESS_EXE): $(CHESS_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Clean rule
clean:
	rm -f *.o *.exe

# Rebuild rule
rebuild: clean all
