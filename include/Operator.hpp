//
// Created by Octavia on 06.01.2019.
//

#ifndef SHUNTING_YARD_OPERATOR_HPP
#define SHUNTING_YARD_OPERATOR_HPP

#include "Token.hpp"
#include "TokenType.hpp"

#include <string>

namespace cs
{
	struct Operator : public Token
	{
		Operator(std::string _body, TokenType _type, int _priority);
		int Priority;
	};
}

#endif //SHUNTING_YARD_OPERATOR_HPP
