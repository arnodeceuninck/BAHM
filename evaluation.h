//
// Created by arno on 2/28/19.
//

#ifndef BAHM_EVALUATION_H
#define BAHM_EVALUATION_H

#include "photo.h"

namespace evaluation{
  int score(const std::unordered_set<std::string>& tags1, const std::unordered_set<std::string>& tags2);
}

#endif //BAHM_EVALUATION_H
