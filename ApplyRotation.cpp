//
// Created by vince on 4/24/2023.
//

#include "ApplyRotation.h"
#ifndef POKER_GAME_APPLY_ROTATION_CPP
#define POKER_GAME_APPLY_ROTATION_CPP
template<typename T>
void ApplyRotation::Rotate(std::vector<T> &vec)
{
    if(vec.empty())
    {
        std::cout << "empty";
        exit(1);
    }
    if(!vec.empty())
    {
        vec.at(0).setRotation(-15);
        vec.at(1).setRotation(15);
    }
}

#endif

