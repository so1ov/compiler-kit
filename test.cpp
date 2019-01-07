#include "ExpressionParser.hpp"
#include "StringTools.hpp"

#include <iostream>

int main()
{
	cs::Expression expr;
	expr.SetType(cs::ExpressionType::Infix);
	expr.SetBody("( 3.14 - 2 * ( 1  * 2 + 1 ) / ( 1.88 + 3 ) - 9 ) + ( ( 3 + 4 ) * 2 )");

	std::cout << "Infix expression: " << expr.GetBody() << std::endl;

	cs::ExpressionParser parser;
	cs::Expression exprAsPostfix;
	exprAsPostfix.SetType(cs::ExpressionType::Postfix);

	auto error = parser.TransformNotation(expr, exprAsPostfix);
	if(error)
	{
		std::cout << error.GetErrorMessage();
		return -1;
	}

	std::cout << "Postfix expression: " << exprAsPostfix.GetBody();

	return 0;
}