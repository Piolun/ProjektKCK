#ifndef REVERSEFRUIT_H
#define REVERSEFRUIT_H
#include "pickup.h"

class ReverseFruit: public Pickup
{
public:
    ReverseFruit(int PosX, int PosY);
    void OnCollision() override;
};

#endif // REVERSEFRUIT_H

// in soviet russia the fruit eats you
