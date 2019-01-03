//
// Created by Octavia on 04.01.2019.
//

#include <Expression.hpp>

#include "Expression.hpp"

cs::ExpressionType cs::Expression::GetType() const
{
	return type_;
}

void cs::Expression::SetType(cs::ExpressionType _newType)
{
	type_ = _newType;
}

std::string cs::Expression::GetBody() const
{
	return body_;
}

void cs::Expression::SetBody(std::string _newBody)
{
	body_ = std::move(_newBody);
}

cs::ErrorDescriptor cs::Expression::Evaluate()
{
	// TODO
	return cs::ErrorDescriptor();
}
