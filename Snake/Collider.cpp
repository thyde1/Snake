#include "Collider.h"
#include "GameObject.h"

Collider::Collider(int w, int h)
{
    this->x = 0;
    this->y = 0;
    this->w = w;
    this->h = h;
}

void Collider::setGameObject(GameObject* gameObject)
{
    Component::setGameObject(gameObject);
    this->x = gameObject->globalPosition->getX();
    this->y = gameObject->globalPosition->getY();
}

bool Collider::checkCollision(Collider* collider)
{
    return Collider::checkCollision(this->w, this->h, this->x, this->y, collider->w, collider->h, collider->x, collider->y);
}

bool Collider::checkCollision(int wA, int hA, int xA, int yA, int wB, int hB, int xB, int yB)
{
    if (xA > xB + wB) {
        return false;
    }

    if (xA + wA < xB) {
        return false;
    }

    if (yA > yB + hB) {
        return false;
    }

    if (yA + hA < yB) {
        return false;
    }

    return true;
}


