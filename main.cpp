#include <iostream>
#include <unordered_set>
#include <vector>

#include "photo.h"
#include "Slide.h"

int main(int argc, char* argv[]) {
  int N;
  std::cin >> N;
  std::vector<Photo> photos(N);
  for (int n {0}; n < N; ++n) {
    char orientation;
    int tag_count;
    std::cin >> orientation >> tag_count;
    photos[n] = Photo(n, orientation);
    while (tag_count--) {
      std::string curr_tag;
      std::cin >> curr_tag;
      photos[n].add_tag(curr_tag);
    }
  }
  return 0;
}
