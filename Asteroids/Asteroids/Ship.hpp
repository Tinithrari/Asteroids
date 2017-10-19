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
    /**
     * @enum control_event
     *
     * Flag utilise lorsque une entree utilisateur a ete effectue
     */
    enum control_event 
    { 
        NONE = 0, /*<! Quand il n'y a pas d'evenement*/
        BACKWARD = 2, /*!< Quand le vaisseau fait marche arriere */
        FORWARD = 4,  /*<! Quand le vaisseau fait marche avant */
        ROT_LEFT = 8, /*<! Quand le vaisseau tourne a gauche */
        ROT_RIGHT = 16 /*<! Quand le vaisseau tourne a droite */
    };
    private:
        static const float MAX_ESSENCE; /*!< Maximum d'essence disponible */
        static const int ANGLE_MAX; /*!< Le plus grand angle en degre */
        static const float SPEED; /*<! Coefficient de vitesse */

        Sprite _ship; /*<! Le sprite du vaisseau */
        bool _keyPressed; /*<! Objet pour éviter la duplication d'evenements clavier */
        control_event _event; /*<! Evenement de controle du vaisseau */
        sf::Vector2f _thrusterForces; /*<! Force des moteurs */
        sf::Vector2f _orientation; /*<! Orientation du vaiseau (facteur des translations) */
        void checkKeyPressed(sf::Event &e); /*<! Gere les evenements quand une touche est appuyee */
        void checkKeyReleased(sf::Event &e); /*<! Gere les evenements quand une touche est relachee */
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
    const float Ship::MAX_ESSENCE(100.f);
    const float Ship::SPEED(10.f);
    const int Ship::ANGLE_MAX(360);
}
