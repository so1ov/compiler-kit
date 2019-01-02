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
		std::vector<Lexeme> SplitTextToLexemes(std::string _text);
	};
}

#endif //SHUNTING_YARD_EXPRESSIONPARSER_H
