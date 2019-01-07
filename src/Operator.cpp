//
// Created by Octavia on 06.01.2019.
//

#include <Operator.hpp>

cs::Operator::Operator(std::string _body, cs::TokenType _type, int _priority)
	:	Token(_body, _type)
{
	Priority = _priority;
}
