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

/**
 * @namespace world
 *
 * Contient tous les éléments définissant le monde du jeu
 */
namespace world
{
    /**
     * @class Scene
     * @brief Conteneur d'éléments graphiques
     *
     * Définit le contexte affiché à l'écran
     */
    class Scene : public Updatable, public sf::Drawable
    {
    public:
        virtual void reinit() = 0;
    };
}
