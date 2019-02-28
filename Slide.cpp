//
// Created by mateo on 28.02.19.
//

#include "Slide.h"
#include "photo.h"

Slide::Slide(Photo* p1, Photo* p2) {
  photos.emplace_back(p1);
  photos.emplace_back(p2);
  for (const std::string& tag : p1->tags) {
    if (!tags.count(tag)) { tags.emplace(tag); }
  }
  for (const std::string& tag : p2->tags) {
    if (!tags.count(tag)) { tags.emplace(tag); }
  }
}
