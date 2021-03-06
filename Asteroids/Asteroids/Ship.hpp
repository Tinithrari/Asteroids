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
#include "Laser.hpp"

#include <SFML/Graphics.hpp>
#include <cmath>

#define SPEED 0.2f
#define ACCELERATION 50.f
#define ANGLE_MAX 360

using namespace sf;
using namespace std;

class Application;

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
    class Ship : public Updatable
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
        ROT_RIGHT = 16, /*<! Quand le vaisseau tourne a droite */
        FIRE = 32 /*<! Quand le vaisseau fait feu */
    };
    private:
        Sprite _ship; /*<! Le sprite du vaisseau */
        bool _keyPressed; /*<! Objet pour �viter la duplication d'evenements clavier */
        control_event _event; /*<! Evenement de controle du vaisseau */
        sf::Vector2f _thrusterForces; /*<! Force des moteurs */
        sf::Vector2f _orientation; /*<! Orientation du vaiseau (facteur des translations) */
        static Texture* _Texture;
        static const int WIDTH;
        static const int HEIGHT;
        Laser       &_laser;
        
        /*<! Gere les evenements quand une touche est appuyee */
        void checkKeyPressed(sf::Event &e)
        {
            if (e.type == sf::Event::KeyPressed)
            {
                // Si touche haut appuyee
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    _event = (control_event)(_event | control_event::FORWARD);
                    _event = (control_event)(_event | 1);
                }

                // Si touche gauche appuyee
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    _event = (control_event)(_event | control_event::ROT_LEFT);
                    _event = (control_event)(_event | 1);
                }

                // Si touche droite appuyee
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    _event = (control_event)(_event | control_event::ROT_RIGHT);
                    _event = (control_event)(_event | 1);
                }

                // Si touche bas appuyee
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    _event = (control_event)(_event | control_event::BACKWARD);
                    _event = (control_event)(_event | 1);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    _event = (control_event)(_event | control_event::FIRE);
                    _event = (control_event)(_event | 1);
                }
            }
        }

        /*<! Gere les evenements quand une touche est relachee */
        void checkKeyReleased(sf::Event &e)
        {
            if (e.type == sf::Event::KeyReleased)
            {
                if (! sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    _event = (control_event)(_event & !control_event::FORWARD);
                }

                // Si touche gauche appuyee
                if (! sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    _event = (control_event)(_event & !control_event::ROT_LEFT);
                }

                // Si touche droite appuyee
                if (! sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    _event = (control_event)(_event & !control_event::ROT_RIGHT);
                }

                // Si touche bas appuyee
                if (! sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    _event = (control_event)(_event & !control_event::BACKWARD);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    _event = (control_event)(_event & !control_event::FIRE);
                }

                // Remise a zero des evenements si necessaire
                if (_event == 1)
                {
                    _event = control_event::NONE;
                }
            }
        }
    public:
        /**
         * Constructeur par d�faut
         */
        Ship(sf::Vector2f &position, Laser & laser): _keyPressed(false), _event(NONE), _orientation(0, -1),  _thrusterForces(), _laser(laser)
        {
            if (_Texture == nullptr)
            {
                _Texture = new Texture();
                if (!_Texture->loadFromFile("ship.png"))
                {
                    cerr << "Cannot find ship.png" << endl;
                    exit(1);
                }
            }

            _ship.setTexture(*_Texture);
            _ship.setPosition(position);
            _ship.setOrigin(_Texture->getSize().x / 2.f, _Texture->getSize().y / 2.f);
            _ship.setRotation(90);
        }

        /**
         * Destructeur
         */
        ~Ship()
        {

        }

        virtual void ProcessEvent(sf::Event & e) override
        {
            checkKeyPressed(e);
            checkKeyReleased(e);
        }

        virtual void Update(float delta) override
        {
            // Si il y a un evenement
            if (_event & !(control_event::NONE))
            {
                if (_event & control_event::FORWARD)
                {
                    _thrusterForces.x += _orientation.x * ACCELERATION * delta;
                    _thrusterForces.y += _orientation.y * ACCELERATION * delta;
                }

                if (_event & control_event::BACKWARD)
                {
                    _thrusterForces.x -= _orientation.x * ACCELERATION * delta;
                    _thrusterForces.y -= _orientation.y * ACCELERATION * delta;
                }

                if (_event & control_event::ROT_LEFT)
                {
                    int angle;
                    _ship.rotate(-0.2);
                    angle = _ship.getRotation();

                    // Calcul du vecteur d'orientation
                    _orientation.x = -cos(angle / 180.f * 3.1416);
                    _orientation.y = -sin(angle / 180.f * 3.1416);
                }

                if (_event & control_event::ROT_RIGHT)
                {
                    int angle;
                    _ship.rotate(0.2);
                    angle = _ship.getRotation();

                    // Calcul du vecteur d'orientation
                    _orientation.x = -cos(angle / 180.f * 3.1416);
                    _orientation.y = -sin(angle / 180.f * 3.1416);
                }
                if (_event & control_event::FIRE)
                {
                    _laser.fire(_ship.getPosition(), _orientation, _ship.getRotation());
                }
            }

            // Controle de vitesse maximale
            if (_thrusterForces.x > SPEED)
                _thrusterForces.x = SPEED;

            if (_thrusterForces.x < -SPEED)
                _thrusterForces.x = -SPEED;

            if (_thrusterForces.y > SPEED)
                _thrusterForces.y = SPEED;

            if (_thrusterForces.y < -SPEED)
                _thrusterForces.y = -SPEED;

            _ship.move(_thrusterForces);

            const Vector2f& pos = _ship.getPosition();

            if (pos.x > Ship::WIDTH + _ship.getOrigin().x)
                _ship.setPosition(0, pos.y);
            if (pos.y > Ship::HEIGHT + _ship.getOrigin().y)
                _ship.setPosition(pos.x, 0);
            if (pos.x < - (int) _ship.getTexture()->getSize().x + _ship.getOrigin().x)
                _ship.setPosition(Ship::WIDTH, pos.y);
            if (pos.y < -(int)_ship.getTexture()->getSize().y + _ship.getOrigin().y)
                _ship.setPosition(pos.x, Ship::HEIGHT);
        }

        virtual void draw(RenderTarget & target) const
        {
            target.draw(_ship);
        }
    };
    const int Ship::WIDTH(1280);
    const int Ship::HEIGHT(720);
    Texture* Ship::_Texture(nullptr);
}
