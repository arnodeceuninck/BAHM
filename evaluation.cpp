//
// Created by arno on 2/28/19.
//

#include "evaluation.h"
#include <iterator>

// TODO: optimize for loops

int evaluation::score(const std::unordered_set<std::string>& tags1, const std::unordered_set<std::string>& tags2) {

    // Bepaal de doorsnede van  de photo's
    std::unordered_set<std::string> output_intersection;

    int common_tags = 0;
    int not_in_2 = 0;

    for(auto tag1 = tags1.begin(); tag1 != tags1.end(); tag1++){

        bool in_tags2 = false;

        for(auto tag2 = tags2.begin(); tag2 != tags2.end(); tag2++){
            if(*tag1 == *tag2){
                in_tags2 = true;
                common_tags++;
            }
        }

        if(!in_tags2){
            not_in_2++;
        }
    }

    int not_in_1 = 0;

    for(auto tag2 = tags2.begin(); tag2 != tags2.end(); tag2++){

        bool in_tags1 = false;

        for(auto tag1 = tags1.begin(); tag1 != tags1.end(); tag1++){
            if(*tag2 == *tag1){
                in_tags1 = true;
            }
        }

        if(!in_tags1){
            not_in_1++;
        }
    }

    // Bereken het minimum
    int min = common_tags < not_in_1 ? common_tags : not_in_1;
    min = not_in_1 < not_in_2 ? common_tags : not_in_2;

    return min;
}

