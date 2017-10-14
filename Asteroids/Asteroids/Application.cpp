#include "Application.hpp"

Application::Application() : _window(sf::VideoMode(1280, 720), "Asteroids")
{
}

Application::~Application()
{
}

void Application::ProcessEvent(sf::Event &e)
{
    if (e.type == sf::Event::Closed)
        _window.close();

    // Event dispatching
}

void Application::Update(float delta)
{
}

void Application::Update(float delta)
{
    // Application update
}

void Application::render()
{
    _window.clear();
    // Rendering chain here
    _window.display();
}

void Application::run()
{
    float lastRefresh;
    _clock.restart();

    lastRefresh = _clock.getElapsedTime().asSeconds();
    while (_window.isOpen())
    {
        float delta = _clock.getElapsedTime().asSeconds();
        sf::Event e;

        while (_window.pollEvent(e))
        {
            ProcessEvent(e);
        }

        Update(delta);
        render();
    }
}

void Application::ProcessEvent(sf::Event & e)
{
}
