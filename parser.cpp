//
// Created by arno on 2/28/19.
//

#include "parser.h"

std::vector<std::string> split(const std::string& s, const std::string& c) {

    std::string str = s;

    size_t pos = 0;
    std::string token;

    std::vector<std::string> splitted;

    while ((pos = str.find(c)) != std::string::npos) {
        token = str.substr(0, pos);
        splitted.push_back(token);
        str.erase(0, pos + c.length());
    }

    splitted.push_back(str);
    return splitted;
}
