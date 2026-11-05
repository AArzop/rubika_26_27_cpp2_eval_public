#pragma once

#include <string>

// Feel free to add anything you need

struct Node
{
	char Token;
	float Frequency;

	Node* Left;
	Node* Right;
};

class Huffman
{
public:
	bool GenerateTree(const std::string& inputMessage);

	std::string Encode(const std::string& message) const;

	std::string Decode(const std::string& encodedMessage) const;

private:
	Node* RootNode;
};