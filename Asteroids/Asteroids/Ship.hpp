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
 * @file Ship.hpp
 * @brief fichier contenant la definition d'un vaisseau
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
     * @class Ship
     * @brief Vaisseau du jeu
     *
     * La classe definit ce qu'est un vaisseau dans le jeu
     */
    class Ship : public Updatable, public Drawable
    {
    private:
        Sprite _ship; /*<! Le sprite du vaisseau */
    public:
        /**
         * Constructeur par défaut
         */
        Ship();

        /**
         * Destructeur
         */
        ~Ship();

        virtual void ProcessEvent(sf::Event & e) override;
        virtual void Update(float delta) override;

        virtual void draw(RenderTarget & target, RenderStates states) const override;
    };
}
