//
// Created by Octavia on 02.01.2019.
//

#ifndef SHUNTING_YARD_EXPRESSIONPARSER_H
#define SHUNTING_YARD_EXPRESSIONPARSER_H

#include "Token.hpp"

#include <vector>
#include <string>

namespace cs
{
	class ExpressionParser
	{
		protected:
			Token AcquireToken(std::string _lexeme);
		public:
			std::vector<Token> SplitLexemesBySpaceAndAcquireTokens(std::string _text);
			std::vector<Token> FromInfixToPostfix(std::vector<Token> __);
	};
}

#endif //SHUNTING_YARD_EXPRESSIONPARSER_H
