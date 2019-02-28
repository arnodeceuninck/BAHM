#include <iostream>
#include <unordered_set>
#include <vector>

namespace {

} // namespace

struct Photo {
public:
  int id;
  char orientation;
  std::unordered_set<std::string> tags;

public:
  Photo(int id, char orientation)
    : id(id), orientation(orientation) {}
  void add_tag(const std::string& tag) { tags.emplace(tag); }
};

struct Slide {
public:
    std::vector<Photo> photos;

public:
    Slide(std::vector<Photo> slidePhotos) {
      this->photos = slidePhotos;
    }
};

int main(int argc, char* argv[]) {
  int N;
  std::cin >> N;
  std::vector<Photo> photos;
  for (int n {0}; n < N; ++n) {
    char orientation;
    int tag_count;
    std::cin >> orientation >> tag_count;
    photos[n] = Photo{n, orientation};
    while (tag_count--) {
      std::string curr_tag;
      std::cin >> curr_tag;
      photos[n].add_tag(curr_tag);
    }
  }
  return 0;
}
