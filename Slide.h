//
// Created by mateo on 28.02.19.
//

#ifndef BAHM_SLIDE_H
#define BAHM_SLIDE_H

#include "photo.h"
#include <vector>
#include <unordered_set>
#include <string>


class Slide {
public:
    std::vector<Photo> photos;

public:
  Slide(std::vector<Photo> slidePhotos)
    : photos(slidePhotos) {}

    void add_slide(Photo photo) {
        photos.push_back(photo);
    }

    std::unordered_set<std::string> tags_of_last_slide(){
        return photos.back().tags;
  }

  bool isEmpty(){
      return photos.size() == 0;
  }

  Photo last_slide(){
      return photos.back();
  }
};


#endif //BAHM_SLIDE_H
