//
// Created by arno on 2/28/19.
//

#ifndef BAHM_PARSER_H
#define BAHM_PARSER_H

#include <vector>
#include <string>

using namespace std;

namespace parser {

    /*
     * \brief:  splits een string s in groepen, op plaats waar char c staat wordt de string "gekapt" (char c wordt verwijderd)
     *
     * \param s:    De te splitsen string
     * \param c:    Het character waarop er gesplitst moet worden
     *
     * \return: Een vector bestaande uit strings, zijnde deelstrings van s, gesplitst op char c, maar zonder c
     *
     * \reference:  https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
     */
    std::vector<std::string> split(std::string s, std::string c);

}


#endif //BAHM_PARSER_H
