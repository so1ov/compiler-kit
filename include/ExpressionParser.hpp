//
// Created by Octavia on 02.01.2019.
//

#ifndef SHUNTING_YARD_EXPRESSIONPARSER_H
#define SHUNTING_YARD_EXPRESSIONPARSER_H

#include "Token.hpp"
#include "ErrorDescriptor.hpp"
#include "Expression.hpp"

#include <vector>
#include <string>

namespace cs
{
	/**
	 * @class ExpressionParser
	 * Expression parser class.
	 */
	class ExpressionParser
	{
		public:
			/**
			 * TransformNotation - transform postfix expression to infix etc.
			 * @param _source Input expression with known expression type (notation type)
			 * @param _destination Reference to an output expression with insignificant body (it will be overwritten) and already set output type.
			 * @return ErrorDescriptor.
			 * 	@note It's not an error when source and destination belong to the same type.
			 */
			ErrorDescriptor TransformNotation(Expression _source, Expression& _destination);

		protected:
			/**
			 * VectorOfTokensToString
			 * @param _tokens input vector, can be empty
			 * @return std::string with sequence of tokens separated by spaces.
			 */
			std::string VectorOfTokensToString(std::vector<Token>& _tokens);

			/**
			 * AcquireToken - fill Token object from lexeme with unknown token type.
			 * @param _lexeme
			 * @return Token object with determined token type, token object with type = ::Unknown otherwise.
			 */
			Token AcquireToken(std::string _lexeme);

			/**
			 * SplitLexemesBySpaceAndAcquireTokens
			 * @param _text input text, will be split by spaces // TODO: generalize by implement custom delimeters support
			 * @param _outTokens reference to out vector to be filled with tokens of unknown notation (postfix, infix or prefix).
			 * @return ErrorDescriptor
			 */
			ErrorDescriptor SplitLexemesBySpaceAndAcquireTokens(std::string _text, std::vector<Token>& _outTokens);

			/**
			 * FromInfixToPostfix - convert infix tokens to postfix ones
			 * @param _infixTokens
			 * @param _outTokens reference to out vector to be filled with postfix ones
			 * @return ErrorDescriptor
			 */
			ErrorDescriptor FromInfixToPostfix(std::vector<Token> _infixTokens, std::vector<Token>& _outTokens); // TOOD std::vector<Token> -> Expression
	};
}

#endif //SHUNTING_YARD_EXPRESSIONPARSER_H
