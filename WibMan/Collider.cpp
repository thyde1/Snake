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
    if (this->x > collider->x + collider->w) {
        return false;
    }

    if (this->x + this->w < collider->x) {
        return false;
    }

    if (this->y > collider->y + collider->h) {
        return false;
    }

    if (this->y + this->h < collider->y) {
        return false;
    }

    return true;
}
