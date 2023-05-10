//
// Created by vince on 4/24/2023.
//

#ifndef POKER_GAME_APPLYROTATION_H
#define POKER_GAME_APPLYROTATION_H
#include "PlayerHand.h"
class ApplyRotation
{
public:
    template <typename T>
    static void Rotate(std::vector<T>& vec);
};


#include "ApplyRotation.cpp"
#endif //POKER_GAME_APPLYROTATION_H
