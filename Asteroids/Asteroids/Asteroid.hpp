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
 * @file Asteroid.hpp
 * @brief Fichier contenant la definition d'un asteroid
 * @author Xavier Heugue
 * @version 1.0
 */

#include "Updatable.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

/**
* @namespace world
*
* espace de nommage regroupant les elements disponible dans le jeu
*/
namespace world
{
    /**
     * @class Asteroid
     * @brief Définition d'un asteroid
     * 
     * Définition de ce qu'est un asteroid dans le jeu
     */
    class Asteroid : public Updatable, public Drawable
    {
    private:
        Sprite _sprite; /*<! sprite de l'asteroid */
        int _size; /*<! taille de l'asteroid */
    public:
        /**
         * Constructeur de l'asteroid
         * @param taille de l'asteroid
         * @param position Position de l'asteroid
         */
        explicit Asteroid(int size, Vector2f position);

        /**
         * Destructeur
         */
        ~Asteroid();

        // Herite via Updatable
        virtual void ProcessEvent(sf::Event & e) override;
        virtual void Update(float delta) override;

        // Herite via Drawable
        virtual void draw(RenderTarget & target, RenderStates states) const override;
    };
}
