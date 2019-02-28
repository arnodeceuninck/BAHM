#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

#include "output.h"
#include "photo.h"
#include "Slide.h"
#include "evaluation.h"

using  namespace std;

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cerr << "No input file." << '\n';
    return 0;
  }
  std::ifstream fin {argv[1]};
  // Inlezen van het bestand
  cout << "Start reading..." << endl;

  int N;
  fin >> N;
  std::vector<Photo*> photosV;
  std::vector<Photo*> photosH;
  std::vector<Photo*> rejected_H;

  Slide slideshow = Slide({});

  cout << "voor for loop" << endl;
  for (int n {0}; n < N; ++n) {
      cout << "in for loop" << endl;
    char orientation;
    int tag_count;
    fin >> orientation >> tag_count;

    if(orientation == 'V') {
      photosV.push_back(new Photo(n, orientation));
      while (tag_count--) {
        std::string curr_tag;
        fin >> curr_tag;
        photosV[photosV.size()-1]->add_tag(curr_tag);
      }
  } else {
    photosH.push_back(new Photo(n, orientation));
    while (tag_count--) {
      std::string curr_tag;
      fin >> curr_tag;
      photosH[photosH.size()-1]->add_tag(curr_tag);
      // TODO: toevoegen aan stack en vergelijken

      // Als er nog geen slides zijn
      if(slideshow.isEmpty()){
        slideshow.add_slide(photosH[photosH.size()-1]);

        // Als de match score kleiner is dan 5
      } else if (evaluation::score(slideshow.last_slide().tags, photosH[photosH.size()-1].tags) < 5){
        cout << "slide added" << endl;

        slideshow.add_slide(photosH[photosH.size()-1]);

        // Als de match verwerpt wordt
      } else {
        cout << "slide rejected" << endl;
        rejected_H.push_back(photosH[photosH.size()-1]);
      } 

    }
  }
  }


  int try_count = 0;
  while (try_count < 100 and rejected_H.size() > 0){
      cout << "Trying to optimize: try " << try_count << endl;
    try_count++;
    std::vector<Photo*> rejected_H_2 = {};

    for(auto photo: rejected_H){
      if (evaluation::score(slideshow.last_slide().tags, photo.tags) < 5){
        slideshow.add_slide(photo);

        // Als de match verwerpt wordt
      } else {
        rejected_H_2.push_back(photo);
      }
    }

    rejected_H = rejected_H_2;
  }

  cout << "Adding rejected photos" << endl;
  for(auto photo: rejected_H){
    slideshow.add_slide(photo);
  }

  // Vanaf hier zit de te outputten data in slideshow

  exportSlides(slideshow.photos);

  return 0;
}
