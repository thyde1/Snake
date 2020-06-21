#include "ScoreBar.h"
#include <string>
#include "ScoreRenderer.h"
#include "UiRenderer.h"

GameObject* ScoreBar::create(GameObject *gameObject, int &score, Position position, Size size)
{
    return gameObject
        ->addRenderer(new UiRenderer(position, size))
        ->addRenderer(new ScoreRenderer(score))
        ->setGlobalPosition(position.x + 10, position.y + 10);
}
