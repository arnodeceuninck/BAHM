#include <iostream>
#include <unordered_set>
#include <vector>

#include "photo.h"
#include "Slide.h"

int main(int argc, char* argv[]) {

  // Inlezen van het bestand

  int N;
  std::cin >> N;
  std::vector<Photo> photosV;
  std::vector<Photo> photosH;
  for (int n {0}; n < N; ++n) {
    char orientation;
    int tag_count;
    std::cin >> orientation >> tag_count;

    if(orientation == 'V') {
      photosV.emplace_back(Photo(n, orientation));
      while (tag_count--) {
        std::string curr_tag;
        std::cin >> curr_tag;
        photosV[photosH.size()-1].add_tag(curr_tag);
      }
  } else {
    photosH.emplace_back(Photo(n, orientation));
    while (tag_count--) {
      std::string curr_tag;
      std::cin >> curr_tag;
      photosH[photosH.size()-1].add_tag(curr_tag);
      // TODO: toevoegen aan stack en vergelijken
    }
  }
  }

  // Onze verzameling zit nu in photos


  return 0;
}
