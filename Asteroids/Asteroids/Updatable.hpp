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
 * @file Updatable.hpp
 * @brief Fichier contenant l'interface pour les objets pouvant subir des modifications
 * @author Xavier Heugue
 * @version 1.0
 */

#include <SFML/Window/Event.hpp>

/**
 * @class Updatable
 * @brief interface pour la mise a jour d'objet
 *
 * Interface à implementer pour la mise a jour d'objet dans le jeu
 */
class Updatable
{
public:
    /**
     * @brief Fonction de gestion des évènements
     * @param e Evenement a gerer
     * 
     * Fonction mettant a jour l'etat de l'objet
     */
    virtual void ProcessEvent(sf::Event &e) = 0;

    /**
     * @brief Met a jour l'objet
     * @param delta la duree entre deux mise à jour
     *
     * Met a jour l'objet en fonction de son état et du temps ecoule
     */
    virtual void Update(float delta) = 0;
};
