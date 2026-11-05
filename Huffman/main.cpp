#include "Huffman.h"

#include <iostream>

int main()
{
	Huffman h;

	h.GenerateTree("mississippi");

	std::cout << h.Encode("mips") << std::endl; // 100111010

	std::cout << h.Decode("101011") << std::endl; // psi
}