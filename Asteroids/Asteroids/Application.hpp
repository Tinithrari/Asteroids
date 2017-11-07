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

#pragma once

/**
 * @file.h Application.hpp
 * @brief Definition d'une application
 * @author Xavier Heugue
 * @version 1.0
 */

#include "Updatable.hpp"
#include "StackAllocator.hpp"
#include "FrameManager.hpp"
#include "GameFrame.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#define MEMORY_SPACE 200000000
constexpr size_t MEMORY_SIZE = MEMORY_SPACE / 8;

using namespace std;

/**
 * @class Application
 * @brief Définition de l'application et de son fonctionnement
 *
 * Définit l'application et son mode de fonctionnement
 */
class Application : private Updatable
{
private:
    sf::Clock _clock; /*!< L'horloge servant à mesurer le temps entre chaque frame */
    sf::RenderWindow _window; /*!< Fenêtre de rendu du jeu */
    
    memory::StackAllocator  _allocator; /*<! Memory Allocator */
    frame::FrameManager     _fManager; /*<! Frame Manager */
    world::Frame*           _currentFrame; /*<! A pointer on the current frame */

    // Hérite via Updatable
    virtual void ProcessEvent(sf::Event & e) override
    {
        if (e.type == sf::Event::Closed)
            _window.close();

        _currentFrame->ProcessEvent(e);
    }

    virtual void Update(float delta) override
    {
        _currentFrame->Update(delta);
    }

public:
    static const int        WIDTH; /*<! Width of the window */
    static const int        HEIGHT; /*<! Height of the window */

    /**
     * Constructeur par defaut
     */
    Application() : _window(sf::VideoMode(Application::WIDTH, Application::HEIGHT), "Asteroids"), _allocator(MEMORY_SIZE), _fManager(_allocator)
    {
        _currentFrame = _fManager.allocateNewScene(sizeof(world::GameFrame));
        new(_currentFrame) world::GameFrame(_fManager, _window.getSize());
    }

    /**
     * Destructeur
     */
    ~Application()
    {

    }

    /**
     * @brief lance l'application
     *
     * Lance l'application et effectue toutes les allocations necessaires
     */
    void run()
    {
        float lastRefresh;
        _clock.restart();

        lastRefresh = _clock.getElapsedTime().asSeconds();
        while (_window.isOpen())
        {
            float delta = _clock.getElapsedTime().asSeconds() - lastRefresh;
            sf::Event e;

            while (_window.pollEvent(e))
            {
                ProcessEvent(e);
            }

            Update(delta);
            render();
            lastRefresh = _clock.getElapsedTime().asSeconds();
        }
    }

    /**
    * Fonction effectuant le rendu de la scene
    */
    void render()
    {
        _window.clear();
        _currentFrame->draw(_window);
        _window.display();
    }
};
const int Application::WIDTH(1280);
const int Application::HEIGHT(720);
