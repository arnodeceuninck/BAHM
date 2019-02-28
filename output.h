//
// Created by Basil Rommens on 28/02/2019.
//

#include <fstream>
#include <vector>
#include "Slide.h"


#ifndef BAHM_OUTPUT_H
#define BAHM_OUTPUT_H

void exportSlides(std::vector<Slide>& slideShow){
    std::ofstream file("batch1.txt");
    file << slideShow.size() << std::endl;
    for (Slide slide: slideShow){
        for (auto photo: slide.photos){
            file << photo.id << " ";
        }
        file << std::endl;
    }
    file.close();
}

#endif //BAHM_OUTPUT_H
