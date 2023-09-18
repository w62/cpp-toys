 #include <iostream>

void doB ()
{
	std::cout << "In doB()\n";
}

void doA ()
{
	std::cout << "In doA()\n";
	doB();
	std::cout << "In doA()\n";
}


// C++ 係後call前，即係話main 一定要係最底,𨳒。。。
int main() {
	std::cout << "Starting main()\n";
	doA();
	std::cout << "Ending main()\n";


 return 0;
}


