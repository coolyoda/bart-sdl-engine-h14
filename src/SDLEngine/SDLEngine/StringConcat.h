#pragma once

#include <sstream>

/**
* @brief A subclass of std::string that add operators to directly concatenate elements.
*/
class StringConcat : public std::string {
public:
	StringConcat& operator<<(const std::string& element);
	template <typename T> StringConcat& operator<<(const T &element);

private:
	std::ostringstream oss; /**< used to concatenate non string objects to this string */
};

/**
* @brief Appends a string to this string.
* @param element the string to append
* @return this string
*/
inline StringConcat& StringConcat::operator<<(const std::string& element)
{
	append(element);
	return *this;
}

/**
* @brief Appends an object to this string.
* @param element the object to append
* @return this string
*/
template <typename T> inline StringConcat& StringConcat::operator<<(const T &element)
{
	oss.str("");
	oss << element;
	append(oss.str());
	return *this;
}