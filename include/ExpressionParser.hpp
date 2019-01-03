//
// Created by Octavia on 02.01.2019.
//

#ifndef SHUNTING_YARD_EXPRESSIONPARSER_H
#define SHUNTING_YARD_EXPRESSIONPARSER_H

#include "Token.hpp"
#include "ErrorDescriptor.hpp"

#include <vector>
#include <string>

namespace cs
{
	class ExpressionParser
	{
		protected:
			Token AcquireToken(std::string _lexeme);
		public:
			ErrorDescriptor SplitLexemesBySpaceAndAcquireTokens(std::string _text, std::vector<Token>& _outTokens);
			ErrorDescriptor FromInfixToPostfix(std::vector<Token> _infixTokens, std::vector<Token>& _outTokens); // TOOD std::vector<Token> -> Expression
	};
}

#endif //SHUNTING_YARD_EXPRESSIONPARSER_H
