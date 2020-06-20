#pragma once
#include "Component.h"

class Collider : public Component
{
public:
    Collider(int w, int h);
    void setGameObject(GameObject* gameObject);
    bool checkCollision(Collider* collider);
    int x;
    int y;
    int w;
    int h;
    static bool checkCollision(int wA, int hA, int xA, int yA, int wB, int hB, int xB, int yB);
};

