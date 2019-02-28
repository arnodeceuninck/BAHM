#include "photo.h"

#include <string>
#include <unordered_set>

Photo::Photo() = default;

Photo::Photo(int id, char orientation)
  : id(id), orientation(orientation) {}

void Photo::add_tag(const std::string& tag) { tags.emplace(tag); }
