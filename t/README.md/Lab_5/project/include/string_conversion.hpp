#ifndef EE205_STRING_CONVERSION_HPP
#define EE205_STRING_CONVERSION_HPP

#include <string>
#include <vector>
#include <sstream>

template <typename T>
std::string lexical_cast(T obj) {
    // Create a std::stringstream
    std::stringstream string;
    // Using operator<<, output the object to it
    string << obj;
    // Take the std::string from the stringstream
    std::string s = string.str();
    return s;
}

template <typename T>
std::string vector_to_string(std::vector<T>& items) {

std::string s = "";
int i;
  for (i = 0; i <items.size(); i = i + 1)
   {
       s.append(lexical_cast(items[i]));
       
       if (i != items.size() - 1 )
       {
            s .append(",");
       }
   }
    return s;
}

#endif // EE205_STRING_CONVERSION_HPP 
