//
// Created by Octavia on 04.01.2019.
//

#include <ErrorDescriptor.hpp>

void cs::ErrorDescriptor::SetErrorPresence(bool _isError)
{
	isError_ = _isError;
}

void cs::ErrorDescriptor::SetErrorMessage(std::string _errorMessage)
{
	if(!_errorMessage.empty())
	{
		errorMessage_ = std::move(_errorMessage);
		isError_ = true;
	}
	else
	{
		isError_ = false;
	}
}

std::string cs::ErrorDescriptor::GetErrorMessage() const
{
	return errorMessage_;
}

cs::ErrorDescriptor::operator bool() const
{
	return isError_;
}

cs::ErrorDescriptor::ErrorDescriptor(std::string _errorMessage)
	:	errorMessage_(std::move(_errorMessage))
{

}
