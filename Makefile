CXX = g++
CXXFLAGS = -I"C:\Users\devan\OneDrive\Documents\Libraries\SFML-2.6.1\include" -DSFML_STATIC
LDFLAGS = -L"C:\Users\devan\OneDrive\Documents\Libraries\SFML-2.6.1\lib" -static
LIBS = -l sfml-graphics-s -l sfml-window-s -l sfml-system-s -l opengl32 -l freetype -l winmm -l gdi32

all: test

test: test.o
	$(CXX) $^ -o $@ $(LDFLAGS) $(LIBS)

test.o: test.cpp
	$(CXX) -c $< $(CXXFLAGS)

.PHONY: clean
clean:
	rm -f test test.o



#g++ -c test.cpp -I"C:\Users\devan\OneDrive\Documents\Libraries\SFML-2.6.1\include" -DSFML_STATIC
#g++ test.o -o test -L "C:\Users\devan\OneDrive\Documents\Libraries\SFML-2.6.1\lib" -l sfml-graphics-s -l sfml-window-s -l sfml-system-s -l opengl32 -l freetype -l winmm -l gdi32 -static

