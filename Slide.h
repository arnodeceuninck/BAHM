//
// Created by mateo on 28.02.19.
//

#ifndef BAHM_SLIDE_H
#define BAHM_SLIDE_H

#include <vector>

class Photo;

class Slide {
public:
    std::vector<Photo> photos;

public:
    Slide(std::vector<Photo> slidePhotos) {
        this->photos = slidePhotos;
    }
};


#endif //BAHM_SLIDE_H
