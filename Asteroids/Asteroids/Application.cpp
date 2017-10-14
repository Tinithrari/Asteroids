/*
Joris Graaffe, Xavier Heugue. Asteroid-like game
Copyright (C) 2017  Joris Graaffe, Xavier Heugue

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Application.hpp"

/**
 * @file Application.cpp
 * @brief implementation de la classe Application
 * @author Xavier Heugue
 * @version 1.0
 */

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

void Application::ProcessEvent(sf::Event & e)
{
}
