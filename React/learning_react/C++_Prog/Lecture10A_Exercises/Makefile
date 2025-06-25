# Makefile for PPPGUI-based projects

# Compiler and flags
CXX = g++
CXXFLAGS = -g -Ipppgui/include
LDFLAGS = -g -Lpppgui/lib -lfltk -lfltk_images -ljpeg -lz -lpng

# PPPGUI shared source files
PPPGUI_SRCS = \
    pppgui/lib/Graph.cpp \
    pppgui/lib/GUI.cpp \
    pppgui/lib/Simple_window.cpp \
    pppgui/lib/Window.cpp

# Project source files
SMILEY_SRCS     = circle.cpp       $(PPPGUI_SRCS)
CIRCLE2_SRCS    = circle2.cpp      $(PPPGUI_SRCS)
CIRCLE3_SRCS    = circle3.cpp      $(PPPGUI_SRCS)
TRIANGLE_SRCS   = triangle.cpp     $(PPPGUI_SRCS)
HELLO_SRCS      = hellofltk.cpp    $(PPPGUI_SRCS)
BOILER_SRCS     = boilerplate.cpp  $(PPPGUI_SRCS)
BLANK_SRCS      = blank.cpp        $(PPPGUI_SRCS)
MINECRAFT_SRCS  = minecraft.cpp    $(PPPGUI_SRCS)  # lowercase 'minecraft.cpp'

# Executable names
SMILEY_EXE     = circle.exe
CIRCLE2_EXE    = circle2.exe
CIRCLE3_EXE    = circle3.exe
TRIANGLE_EXE   = triangle.exe
HELLO_EXE      = hellofltk.exe
BOILER_EXE     = boilerplate.exe
BLANK_EXE      = blank.exe
MINECRAFT_EXE  = minecraft.exe

# Default target: build everything
all: $(SMILEY_EXE) $(CIRCLE2_EXE) $(CIRCLE3_EXE) \
     $(TRIANGLE_EXE) $(HELLO_EXE) $(BOILER_EXE) $(BLANK_EXE) \
     $(SMILEYHAT_EXE) $(MINECRAFT_EXE)

# Build rules
$(SMILEY_EXE): $(SMILEY_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(CIRCLE2_EXE): $(CIRCLE2_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(CIRCLE3_EXE): $(CIRCLE3_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(TRIANGLE_EXE): $(TRIANGLE_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(HELLO_EXE): $(HELLO_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BOILER_EXE): $(BOILER_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BLANK_EXE): $(BLANK_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(MINECRAFT_EXE): $(MINECRAFT_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Clean up
clean:
	rm -f *.o *.exe
