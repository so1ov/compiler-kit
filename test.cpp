#include "ExpressionParser.hpp"
#include "StringTools.hpp"

#include <iostream>

int main()
{
	std::string infix = "3 + 4.1 * 5 - 3 / 1";
	std::cout << "Infix string: " << infix << std::endl;

	cs::ExpressionParser parser;

	auto lexemes = parser.SplitBySpaceAndDetermineType(infix);

	auto postfixTokens = parser.FromInfixToPostfix(lexemes);

	std::cout << "Postfix string: ";
	for(auto& it : postfixTokens)
	{
		std::cout << it.Body << ' ';
	}
	std::cout << std::endl;
	return 0;
}