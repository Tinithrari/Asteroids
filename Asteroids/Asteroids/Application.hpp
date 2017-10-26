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

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

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

    // Hérite via Updatable
    virtual void ProcessEvent(sf::Event & e) override
    {
        if (e.type == sf::Event::Closed)
            _window.close();

        // Event dispatching
    }

    virtual void Update(float delta) override
    {
        // Application update
    }

public:
    /**
     * Constructeur par defaut
     */
    Application() : _window(sf::VideoMode(1280, 720), "Asteroids")
    {

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

    /**
    * Fonction effectuant le rendu de la scene
    */
    void render()
    {
        _window.clear();
        // Rendering chain here
        _window.display();
    }
};
