#include <iostream>
#include <unordered_set>
#include <vector>

#include "photo.h"
#include "Slide.h"
#include "evaluation.h"

int main(int argc, char* argv[]) {

  // Inlezen van het bestand

  int N;
  std::cin >> N;
  std::vector<Photo> photosV;
  std::vector<Photo> photosH;
  std::vector<Photo> rejected_H;

  Slide slideshow();
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

      // Als er nog geen slides zijn
      if(slideshow().isEmpty()){
        slideshow().add_slide(photosH[photosH.size()]);

        // Als de match score kleiner is dan 5
      } else if (evaluation::score(slideshow().last_slide().tags, photosH[photosH.size()-1].tags) < 5){
        slideshow().add_slide(photosH[photosH.size()-1]);

        // Als de match verwerpt wordt
      } else {
        rejected_H.emplace_back(photosH[photosH.size()-1]);
      }

    }
  }
  }



  // Onze verzameling zit nu in photos


  return 0;
}
