/*
 g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello  usingnamespace.cpp
 */
import std;
namespace mycode {
    void foo()
    {
        std::println("foo() called in the mycode namespace");
    }
    
}

namespace MyLibraries {
    namespace Networking {
        namespace FTP {
            void ftp_init ()
            {
                std::println("ftp_init from MyLibraries::Networking::FTP");
            }
        }
    }
}
    using namespace mycode;
    using namespace std;
    

    int main() 
    {
        MyLibraries::Networking::FTP::ftp_init();
        foo();

        
println("int:");
println("Max int value: {}", numeric_limits<int>::max());
println("Min int value: {}", numeric_limits<int>::min());
println("Lowest int value: {}", numeric_limits<int>::lowest());
println("\ndouble:");
println("Max double value: {}", numeric_limits<double>::max());
println("Min double value: {}", numeric_limits<double>::min());
println("Lowest double value: {}", numeric_limits<double>::lowest());


enum class PieceType : unsigned long 
        { King = 1,
    Queen,
    Rook = 10,
    Pawn
};

PieceType piece {PieceType::Pawn};


int underlyingValue {to_underlying(piece)};

/*
 ./usingnamespace.cpp: In function 'int main()':
./usingnamespace.cpp:52:35: warning: narrowing conversion of 'std::to_underlying<main()::PieceType>(piece)' from 'std::underlying_type_t<main()::PieceType>' {aka 'long unsigned int'} to 'int' [-Wnarrowing]
   52 | int underlyingValue {to_underlying(piece)};
      |                      ~~~~~~~~~~~~~^~~~~~~

 */
std::println("underlying value of Pawn is {}", underlyingValue);


    }
