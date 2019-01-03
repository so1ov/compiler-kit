//
// Created by Octavia on 04.01.2019.
//

#ifndef SHUNTING_YARD_ERRORDESCRIPTOR_H
#define SHUNTING_YARD_ERRORDESCRIPTOR_H

#include <string>

namespace cs
{
	class ErrorDescriptor
	{
		protected:
			bool isError_ = false;
			std::string errorMessage_; // TODO typical error messages extracted to another header
		public:
			void SetErrorPresence(bool _isError);

			void SetErrorMessage(std::string _errorMessage);
			std::string GetErrorMessage() const;

			explicit operator bool() const;
	};
}

#endif //SHUNTING_YARD_ERRORDESCRIPTOR_H
