#include "ExpressionParser.hpp"
#include "StringTools.hpp"

#include <iostream>

int main()
{
	std::string infix = "3 + 4.1 * 5 - 3 / 1";
	std::cout << "Infix string: " << infix << std::endl;

	cs::ExpressionParser parser;

	auto infixTokens = parser.SplitLexemesBySpaceAndAcquireTokens(infix);

	auto postfixTokens = parser.FromInfixToPostfix(infixTokens);

	std::cout << "Postfix string: ";
	for(auto& it : postfixTokens)
	{
		std::cout << it.Body << ' ';
	}
	std::cout << std::endl;
	return 0;
}