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

#include "Updatable.hpp"
#include <SFML/Graphics.hpp>

namespace frame
{
    class FrameManager;
}

/**
 * @namespace world
 *
 * Contient tous les �l�ments d�finissant le monde du jeu
 */
namespace world
{
    /**
     * @class Frame
     * @brief Conteneur d'�l�ments graphiques
     *
     * D�finit le contexte affich� � l'�cran
     */
    class Frame : public Updatable
    {
    protected:
        frame::FrameManager&    _manager;
    public:

        /**
         * Constructeur par defaut
         */
        Frame(frame::FrameManager &manager) : _manager(manager) {}

        /**
         * Destructeur virtuel
         */
        virtual ~Frame() {}

        /**
         * Reinitialise l'etat de la scene
         */
        virtual void reinit() = 0;

        virtual void draw(sf::RenderTarget &target) const = 0;
    };
}
