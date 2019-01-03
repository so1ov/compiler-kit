#include "ExpressionParser.hpp"
#include "StringTools.hpp"

#include <iostream>

int main()
{
	std::string infix = "3 + 4.1 * 5 - 3 / 1";
	std::cout << "Infix string: " << infix << std::endl;

	cs::ExpressionParser parser;

	std::vector<cs::Token> infixTokens;
	std::vector<cs::Token> postfixTokens;

	auto error = parser.SplitLexemesBySpaceAndAcquireTokens(infix, infixTokens);
	if(error)
	{
		std::cout << error.GetErrorMessage();
		return -1;
	}

	error = parser.FromInfixToPostfix(infixTokens, postfixTokens);
	if(error)
	{
		std::cout << error.GetErrorMessage();
		return -1;
	}

	std::cout << "Postfix string: ";
	for(auto& it : postfixTokens)
	{
		std::cout << it.Body << ' ';
	}
	std::cout << std::endl;
	return 0;
}