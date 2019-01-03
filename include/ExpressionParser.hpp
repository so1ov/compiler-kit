//
// Created by Octavia on 02.01.2019.
//

#ifndef SHUNTING_YARD_EXPRESSIONPARSER_H
#define SHUNTING_YARD_EXPRESSIONPARSER_H

#include "Lexeme.hpp"

#include <vector>
#include <string>

namespace cs
{
	class ExpressionParser
	{
		protected:
			Lexeme AcquireLexeme(std::string _token);
		public:
			std::vector<Lexeme> SplitBySpaceAndDetermineType(std::string _text);
			std::vector<Lexeme> FromInfixToPostfix(std::vector<Lexeme> __);
	};
}

#endif //SHUNTING_YARD_EXPRESSIONPARSER_H
