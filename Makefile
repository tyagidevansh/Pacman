CXX = g++
CXXFLAGS = -I"C:\Users\devan\OneDrive\Documents\Libraries\SFML-2.6.1\include" -DSFML_STATIC
LDFLAGS = -L"C:\Users\devan\OneDrive\Documents\Libraries\SFML-2.6.1\lib" -static
LIBS = -l sfml-graphics-s -l sfml-window-s -l sfml-system-s -l opengl32 -l freetype -l winmm -l gdi32

all: tutorial-sfml

tutorial-sfml: tutorial-sfml.o
	$(CXX) $^ -o $@ $(LDFLAGS) $(LIBS)

tutorial-sfml.o: tutorial-sfml.cpp
	$(CXX) -c $< $(CXXFLAGS)

.PHONY: clean
clean:
	rm -f tutorial-sfml tutorial-sfml.o



#g++ -c tutorial-sfml.cpp -I"C:\Users\devan\OneDrive\Documents\Libraries\SFML-2.6.1\include" -DSFML_STATIC
#g++ tutorial-sfml.o -o tutorial-sfml -L "C:\Users\devan\OneDrive\Documents\Libraries\SFML-2.6.1\lib" -l sfml-graphics-s -l sfml-window-s -l sfml-system-s -l opengl32 -l freetype -l winmm -l gdi32 -static

