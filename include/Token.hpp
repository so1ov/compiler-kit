//
// Created by Octavia on 02.01.2019.
//

#ifndef SHUNTING_YARD_TOKEN_H
#define SHUNTING_YARD_TOKEN_H

#include "TokenType.hpp"

#include <string>

namespace cs
{
	struct Token
	{
		std::string Body;
		TokenType Type = TokenType::Undefined;
	};
}

#endif //SHUNTING_YARD_TOKEN_H
