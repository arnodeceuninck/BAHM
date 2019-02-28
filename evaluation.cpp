//
// Created by arno on 2/28/19.
//

#include "evaluation.h"
#include <iterator>
#include <algorithm>

int evaluation::score(const std::unordered_set<std::string>& tags1, const std::unordered_set<std::string>& tags2) {
  // Bepaal de doorsnede van  de photo's
  std::unordered_set<std::string> output_intersection;
  int common_tags = 0;
  int not_in_2 = 0;
  for (auto tag1 = tags1.begin(); tag1 != tags1.end(); tag1++){
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
  return std::min(std::min(common_tags, (int) tags2.size() - common_tags), not_in_2);
}
