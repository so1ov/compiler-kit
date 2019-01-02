#include "ExpressionParser.hpp"
#include "StringTools.hpp"

#include <iostream>

int main()
{
	std::string infix = "3 + 4 + 5 - 3";

	cs::ExpressionParser parser;

	auto postfixTokens = parser.FromInfixToPostfix(infix);

	for(auto& it : postfixTokens)
	{
		std::cout << it.Body << ' ';
	}
	std::cout << std::endl;

	std::cout << "Hello, World!" << std::endl;
	return 0;
}