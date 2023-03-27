#ifndef __UTILITY_HPP__
#define __UTILITY_HPP__

#include <string>
#include <vector>
#include <queue>

namespace Utility{

    // Replace all occurences of a string with another string
    std::string replace(std::string s, std::string old, std::string new_);

    // Remove all occurences of a string
    std::string remove_all(std::string s, std::string remove);
    std::string remove_all(std::string s, char remove);

    // Split a string into a vector of strings
    std::vector<std::string> split(std::string s, char delim = '\n');

    std::vector<std::string> split(std::string s, size_t max_length);

    std::vector<std::string> split_on_spaces(std::string s, size_t max_length);

    std::queue<std::string> splitQueue(std::string s, char delim = '\n');

    // Return a string with all leading and trailing spaces removed
    std::string strip(std::string s);

    // Return the number of differences between two strings(0 if they are equal) (char at the same position must be equal)
    unsigned difference(std::string s1, std::string s2);

    // Extend a string with a character; if the string is longer than the length, the string is returned
    std::string extend(std::string str, size_t length, char c = ' ', bool center = false);

    // Format an integer to a string with a certain length
    std::string format(int i, unsigned length);

    // return the number of characters in a string, count multibyte characters as one
    unsigned getNbchars(std::string s);

    char lower(char c);

    std::string lower(std::string s);

    std::string min_size(const std::vector<std::string>& v);
    std::string max_size(const std::vector<std::string>& v);

    std::vector<int> divide(int a, int b);

    std::string join(const std::vector<std::string>& v, std::string delim = " ");

    bool contains(const std::string& s, const std::string& sub);
    bool contains(const std::string& s, const char& sub);
    
}

#endif