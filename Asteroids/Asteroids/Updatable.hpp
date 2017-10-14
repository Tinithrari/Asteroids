#pragma once

#include <SFML/Window/Event.hpp>

class Updatable
{
public:
    virtual void processEvent(sf::Event &e) = 0;
    virtual void update(float delta) = 0;
};
