#include "photo.h"

#include <string>
#include <unordered_set>

Photo::Photo()
  : id(id), orientation(orientation) {}

void Photo::add_tag(const std::string& tag) { tags.emplace(tag); }
