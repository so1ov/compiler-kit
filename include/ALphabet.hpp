//
// Created by Octavia on 02.01.2019.
//

#ifndef SHUNTING_YARD_ALPHABET_H
#define SHUNTING_YARD_ALPHABET_H

#include "Operator.hpp"

#include <string>
#include <map>
#include <memory>

namespace cs
{
	namespace ALphabet
	{
		std::map<std::string, std::shared_ptr<Operator>> Operators = {
				{"+", std::make_shared<Operator>( "+", TokenType::BinaryOperator, 10 ) },
				{"-",  std::make_shared<Operator>( "-", TokenType::BinaryOperator, 10 ) },

				{"*", std::make_shared<Operator>( "*", TokenType::BinaryOperator, 20 ) },
				{"/",  std::make_shared<Operator>( "/", TokenType::BinaryOperator, 20 ) },

				{"^",  std::make_shared<Operator>( "^", TokenType::BinaryOperator, 30 ) },

				{"(", std::make_shared<Operator>( "(", TokenType::OpeningBracket, -1 ) },
				{")",  std::make_shared<Operator>( ")", TokenType::ClosingBracket, -1 ) }
		};

		std::string Numeric = "0123456789";
		char NumericDelimeter = '.';

		std::string OpeningBracket = "(";
		std::string ClosingBracket = ")";

		// Assume operators won't occupy more than 1 character.
		std::string OldBinaryOperators = "+-/*";

		// char is an operator itself, int is operator priority
		std::map<char, int> BinaryOperators = {
				{'+', 10}, // We need a 10-th multiple priority to insert additional operators later saving their rank
				{'-', 10},
				{'*', 20},
				{'/', 20}
		};

		// TODO implement unary operators support
		std::string UnaryOperators = "";
	};
}

#endif //SHUNTING_YARD_ALPHABET_H
