//
// Created by mateo on 28.02.19.
//

#ifndef BAHM_SLIDE_H
#define BAHM_SLIDE_H

#include "photo.h"
#include <vector>


class Slide {
public:
    std::vector<Photo> photos;

public:
  Slide(std::vector<Photo> slidePhotos)
    : photos(slidePhotos) {}
};


#endif //BAHM_SLIDE_H
