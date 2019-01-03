//
// Created by Octavia on 04.01.2019.
//

#ifndef SHUNTING_YARD_EXPRESSION_HPP
#define SHUNTING_YARD_EXPRESSION_HPP

#include "Token.hpp"
#include "ExpressionType.hpp"
#include "ErrorDescriptor.hpp"

#include <vector>

namespace cs
{
	class Expression
	{
		protected:
			std::string body_;
			ExpressionType type_;
		public:
			std::string GetBody() const;
			void SetBody(std::string _newBody);

			ExpressionType GetType() const;
			void SetType(ExpressionType _newType);

			ErrorDescriptor Evaluate(); // TODO parameters?
	};
}

#endif //SHUNTING_YARD_EXPRESSION_HPP
