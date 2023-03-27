#include "cutility.hpp"

#include <string>
#include <vector>


namespace Utility{

    /**
     * @brief replace all occurences of a string with another string, don't change the original string
     * 
     * @param s the string to modify
     * @param old the string to replace
     * @param new_ the replacement string
     * @return the modified string
     */
    std::string replace(std::string s, std::string old, std::string new_){
        std::string buffer;
        while (s.size()){
            if (s.substr(0, old.size()) == old){
                buffer += new_;
                s = s.substr(old.size());
            }
            else{
                buffer += s[0];
                s = s.substr(1);
            }
        }
        return buffer;
    }

	/**
	 * @brief remove all occurences of a string from another string, don't change the original string
	 * 
	 * @param s the string to modify
	 * @param remove the string to remove
	 * @return the modified string
	 */
    std::string remove_all(std::string s, std::string remove){
        std::string buffer;
        while (s.size()){
            if (s.substr(0, remove.size()) == remove){
                s = s.substr(remove.size());
            }
            else{
                buffer += s[0];
                s = s.substr(1);
            }
        }
        return buffer;
    }

	/**
	 * @brief remove all occurences of a character from a string, don't change the original string
	 * 
	 * @param s the string to modify
	 * @param remove the character to remove
	 * @return the modified string
	 */
    std::string remove_all(std::string s, char remove){
        std::string buffer;
        while (s.size()){
            if (s[0] == remove){
                s = s.substr(1);
            }
            else{
                buffer += s[0];
                s = s.substr(1);
            }
        }
        return buffer;
    }

    /**
     * @brief split a string into a vector of strings, don't change the original string
     * 
     * @param s the string to split
     * @param delim the delimiter
     * @return a vector of strings that were split from the original string
     */
    std::vector<std::string> split(std::string s, char delim){
        std::vector<std::string> elems;
        std::string buffer;
        while (s.size()) {
            if (s[0] != delim){
                buffer += s[0];
            }
            else if (buffer.size()){
                elems.push_back(buffer);
                buffer = "";
            }
            else{
                elems.push_back("");
            }
            s = s.substr(1);
        }
        if (buffer.size()){
            elems.push_back(buffer);
        }
        return elems;
    }

	/**
	 * @brief split a string into a vector of strings, but split on spaces, if a word has to be
	 * 			split, it will be splitted in the middle of the word
	 * 
	 * @param s the string to split
	 * @param max_length the maximum length of a string in the vector
	 * @return the splitted string
	 */
	std::vector<std::string> split(std::string s, size_t max_length){
		std::vector<std::string> elems;
		std::string buffer;
		while (s.size()){
			if (buffer.size() < max_length){
				buffer += s[0];
			}
			else if (buffer.size()){
				elems.push_back(buffer);
				buffer = "";
			}
			s = s.substr(1);
		}
		if (buffer.size()){
			elems.push_back(buffer);
		}
		return elems;
	}
    
    /**
     * @brief split a string into a vector of strings, but split on spaces, if a word has to be splitted, we will split it at the last space
     * 
     * @param s the string to split
     * @param max_length the maximum length of a string in the vector
     * @return the splitted string
     */
    std::vector<std::string> split_on_spaces(std::string s, size_t max_length){
        std::vector<std::string> elems;
        std::string buffer;
        std::size_t last_space = 0;
        while (s.size()){
            if (buffer.size() < max_length){ //if the buffer is not full
                buffer += s[0];
                if(s[0] == ' '){
                    last_space = buffer.size();
                }
            }
            else if (buffer.size()){ //if there is something in the buffer
                if(last_space > 0){
                    elems.push_back(buffer.substr(0, last_space));
                    buffer = buffer.substr(last_space);
                    buffer += s[0];
                    last_space = 0;
                }else{
                    elems.push_back(buffer);
                    buffer = "";
                }
            }
            s = s.substr(1);
        }
        if (buffer.size()){ //if there is something left in the buffer
            elems.push_back(buffer); //add it to the vector
        }
        return elems;
    }


    /**
     * @brief split a string into a queue of strings, don't change the original string
     * 
     * @param s the string to split
     * @param delim the delimiter
     * @return  a queue of strings that were split from the original string
     */
    std::queue<std::string> splitQueue(std::string s, char delim){
        std::queue<std::string> elems;
        std::string buffer;
        while (s.size()) {
            if (s[0] != delim){
                buffer += s[0];
            }
            else if (buffer.size()){
                elems.push(buffer);
                buffer = "";
            }
            s = s.substr(1);
        }
        if (buffer.size()){
            elems.push(buffer);
        }
        return elems;
    }

	/**
	 * @brief remove all occurences of space, tab, newline and carriage return at the end and beginning of a string
	 * 
	 * @param s the string to modify
	 * @return the modified string
	 */
    std::string strip(std::string s){
        const std::vector<char> chars = {' ', '\t', '\n', '\r'};
        bool found = false; //end of string found
        while(!found){
            found = true;
            for(std::size_t i = 0; i < chars.size(); i++){
                if(s[s.size() - 1] == chars[i]){
                    s = s.substr(0, s.size() - 1);
                    found = false;
                }
            }
        }
        found = false;
        while(!found){
            found = true;
            for(std::size_t i = 0; i < chars.size(); i++){
                if(s[0] == chars[i]){
                    s = s.substr(1);
                    found = false;
                }
            }
        }
        return s;
    }

	/**
	 * @brief calculate the difference between two strings (the more characters are different, the higher the difference)
	 * 
	 * @param s1 the first string
	 * @param s2 the second string
	 * @return the difference between the two strings
	 */
    unsigned difference(std::string s1, std::string s2){
        unsigned diff = 0;
        if (s1.size() == s2.size()){
            for(std::size_t i = 0; i < s1.size(); i++){
                if(s1[i] != s2[i]){
                    diff++;
                }
            }
        }
        else if (s1.size() > s2.size()){
            unsigned smaller = s2.size();
            unsigned diff2 = s1.size() - s2.size();
            for(unsigned i = 0; i <= diff2; ++i){
                unsigned r = difference(s1.substr(i, s2.size()), s2);
                if(r < smaller){
                    smaller = r;
                }
                if (smaller == 0){ //if the difference is 0, there is no need to continue
                    break;
                }
            }
            diff = smaller;
            diff += diff2; //add the difference in size
        }
        else{
            diff = difference(s2, s1);
        }
        return diff;
    }

    /**
     * @brief extend tne string with the character c until the string has the length length
     * 
     * @param str the original string
     * @param length the length of the string to return
     * @param c the character to use to extend the string
     * @param center if true, the string will be centered, if false, the string will be extended at the end
     * @return the extended string
     */
    std::string extend(std::string str, size_t length, char c, bool center){
        if(str.length() < length){
            if(center){
                int left = (length - Utility::getNbchars(str)) / 2;
                int right = length - Utility::getNbchars(str) - left;
                for(int i = 0; i < left; ++i){
                    str = c + str;
                }
                for(int i = 0; i < right; ++i){
                    str = str + c;
                }
            }else{
				size_t nbchars = Utility::getNbchars(str);
                for(size_t i = 0; i < length - nbchars; ++i){
                    str += c;
                }
            }
        }
        return str;
    }

	/**
	 * @brief format an integer to a string with a certain length
	 * 
	 * @param i the integer to format
	 * @param length the length of the string to return
	 * @return the formatted string
	 */
    std::string format(int i, unsigned length){
        std::string s = std::to_string(i);
        while(s.length() < length){
            s = "0" + s;
        }
        return s;
    }

    /**
     * @brief get the number of characters in a string (work wit multybyte characters)
     * 
     * @param s the string to analyze
     * @return the number of characters in the string
     */
    unsigned getNbchars(std::string s){
        unsigned nbchars = 0;
        for(unsigned i = 0; i < s.length(); i++){
            if((s[i] & 0xC0) != 0x80){
                nbchars++;
            }
        }
        return nbchars;
    }

	/**
	 * @brief convert a uppercase character to a lowercase character
	 * 
	 * @param c the character to convert
	 * @return the converted character
	 */
    char lower(char c){
        if(c >= 'A' && c <= 'Z') c += 32;
        return c;
    }

	/**
	 * @brief convert a uppercase string to a lowercase string
	 * 
	 * @param s the string to convert
	 * @return the converted string
	 */
    std::string lower(std::string s){
        for(std::size_t i = 0; i < s.size(); i++){
            lower(s[i]);
        }
        return s;
    }

	/**
	 * @brief find the smallest string in a vector of strings
	 * 
	 * @param v the vector of strings
	 * @return the smallest string
	 */
    std::string min_size(const std::vector<std::string>& v){
        std::string min = v[0];
        for(std::size_t i = 1; i < v.size(); i++){
            if(getNbchars(v[i]) < getNbchars(min)){
                min = v[i];
            }
        }
        return min;
    }

	/**
	 * @brief find the biggest string in a vector of strings
	 * 
	 * @param v the vector of strings
	 * @return the biggest string
	 */
    std::string max_size(const std::vector<std::string>& v){
        std::string max = v[0];
        for(std::size_t i = 1; i < v.size(); i++){
            if(getNbchars(v[i]) > getNbchars(max)){
                max = v[i];
            }
        }
        return max;
    }

	/**
	 * @brief split 'a' in 'b' parts, return a vector of the parts
	 * 
	 * @param a the number to split
	 * @param b the number of parts
	 * @return a vector of the parts
	 */
    std::vector<int> divide(int a, int b){
        size_t crt = 0;
        std::vector<int> parts;
        for (int i = 0; i < b; i++){
            parts.push_back(0);
        }
        for (int i = 0; i < a; i++){
            parts[crt]++;
            crt++;
            crt %= b;
        }
        return parts;
    }

	/**
	 * @brief merge all string in the vector with the delimiter delim between each string
	 * 
	 * @param v the vector of strings to merge
	 * @param delim the delimiter to use
	 * @return the merged string
	 */
    std::string join(const std::vector<std::string>& v, std::string delim){
        std::string s;
        for(std::size_t i = 0; i < v.size(); i++){
            s += v[i];
            if(i < v.size() - 1){
                s += delim;
            }
        }
        return s;
    }

	/**
	 * @brief search for a substring in a string
	 * 
	 * @param s the string to search in
	 * @param sub the substring to search
	 * @return true if the substring is found, false otherwise
	 */
    bool contains(const std::string& s, const std::string& sub){
        return s.find(sub) != std::string::npos;
    }

	/**
	 * @brief search for a character in a string
	 * 
	 * @param s the string to search in
	 * @param c the character to search
	 * @return true if the character is found, false otherwise
	 */
    bool contains(const std::string& s, const char& c){
        return s.find(c) != std::string::npos;
    }
}
