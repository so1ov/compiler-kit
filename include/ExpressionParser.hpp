//
// Created by Octavia on 02.01.2019.
//

#ifndef SHUNTING_YARD_EXPRESSIONPARSER_H
#define SHUNTING_YARD_EXPRESSIONPARSER_H

#include "Lexeme.h"

#include <vector>
#include <string>

namespace cs
{
	class ExpressionParser
	{
		std::vector<Lexeme> SplitTextOntoLexemes(std::string _text);
	};
}

#endif //SHUNTING_YARD_EXPRESSIONPARSER_H
