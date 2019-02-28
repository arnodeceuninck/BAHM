#ifndef BAHM_PHOTO_H
#define BAHM_PHOTO_H

#include <string>
#include <unordered_set>

class Photo {
public:
  int id;
  char orientation;
  std::unordered_set<std::string> tags;

public:
  Photo() = default;
  Photo(int id, char orientation);
  void add_tag(const std::string& tag) { tags.emplace(tag); }
};

#endif // BAHM_PHOTO_H
