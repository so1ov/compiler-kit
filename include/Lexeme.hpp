//
// Created by Octavia on 02.01.2019.
//

#ifndef SHUNTING_YARD_LEXEME_H
#define SHUNTING_YARD_LEXEME_H

#include "LexemeType.hpp"

#include <string>

namespace cs
{
	struct Lexeme
	{
		std::string Body;
		LexemeType Type = LexemeType::Undefined;
	};
}

#endif //SHUNTING_YARD_LEXEME_H
