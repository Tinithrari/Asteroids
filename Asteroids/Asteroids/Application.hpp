#pragma once

#include "Updatable.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class Application : private Updatable
{
private:
    sf::Clock _clock;
    sf::RenderWindow _window;
    virtual void ProcessEvent(sf::Event & e) override;
    virtual void Update(float delta) override;
    void render();
public:
    Application();
    ~Application();
    void run();
};
