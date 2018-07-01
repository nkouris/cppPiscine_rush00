#include "Scene.class.hpp"

Scene::Scene(int x, int y, char const symbol, int const moveSpeed) : AMoving(x, y, symbol, moveSpeed)
{
}

Scene::Scene(Scene const & src)
{
}

Scene::~Scene(void)
{
}
