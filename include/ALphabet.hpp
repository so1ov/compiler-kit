//
// Created by Octavia on 02.01.2019.
//

#ifndef SHUNTING_YARD_ALPHABET_H
#define SHUNTING_YARD_ALPHABET_H

#include <string>

namespace cs
{
	namespace ALphabet
	{
		std::string Numeric = "0123456789";
		char NumericDelimeter = '.';

		// Assume operators won't occupy more than 1 character.
		std::string BinaryOperators = "+-/*";

		// TODO implement unary operators support
		std::string UnaryOperators = "";
	};
}

#endif //SHUNTING_YARD_ALPHABET_H
