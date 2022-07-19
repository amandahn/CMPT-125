# makefile

# Summer 2021 CMPT 125 SFML makefile template

# Set the C++ compiler options:
#   -std=c++17 compiles using the C++17 standard (or at least as 
#    much as is implemented by the compiler, e.g. for g++ see
#    http://gcc.gnu.org/projects/cxx0x.html)
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g

red_square: red_square.o
	g++ red_square.o -o red_square -lsfml-graphics -lsfml-window -lsfml-system
red_square.o: red_square.cpp
	g++ $(CPPFLAGS) -c red_square.cpp

clean:
	rm -f red_square red_square.o
