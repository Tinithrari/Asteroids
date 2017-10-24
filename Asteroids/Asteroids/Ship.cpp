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

#include "Ship.hpp"

/**
 * @file Ship.cpp
 * @author Xavier Heugue
 * @brief Implementation de la classe Ship
 * @version 1.0
 * @see Ship.hpp
 */

world::Ship::Ship(): _keyPressed(false), _event(NONE), _orientation(0,1)
{
}


world::Ship::~Ship()
{

}

void world::Ship::ProcessEvent(sf::Event & e)
{
    checkKeyPressed(e);
    checkKeyReleased(e);
}

void world::Ship::Update(float delta)
{
    // Si il y a un evenement
    if (_event & !(control_event::NONE))
    {
        if (_event & control_event::FORWARD)
        {
            _thrusterForces.x += _orientation.x * Ship::SPEED * delta;
            _thrusterForces.y += _orientation.y * Ship::SPEED * delta;
        }

        if (_event & control_event::BACKWARD)
        {
            _thrusterForces.x -= -_orientation.x * Ship::SPEED * delta;
            _thrusterForces.y -= -_orientation.y * Ship::SPEED * delta;
        }

        if (_event & control_event::ROT_LEFT)
        {
            float angle;
            _ship.rotate(-Ship::ANGLE_MAX * delta);
            angle = _ship.getRotation();

            // Calcul du vecteur d'orientation
            _orientation.x = cos(angle);
            _orientation.y = sin(angle);
        }

        if (_event & control_event::ROT_RIGHT)
        {
            float angle;
            _ship.rotate(Ship::ANGLE_MAX * delta);
            angle = _ship.getRotation();

            // Calcul du vecteur d'orientation
            _orientation.x = cos(angle);
            _orientation.y = sin(angle);
        }
    }

    // Controle de vitesse maximale
    if (_thrusterForces.x > Ship::SPEED)
        _thrusterForces.x = Ship::SPEED;

    if (_thrusterForces.x < -Ship::SPEED)
        _thrusterForces.x = -Ship::SPEED;

    if (_thrusterForces.y > Ship::SPEED)
        _thrusterForces.y = Ship::SPEED;

    if (_thrusterForces.y < -Ship::SPEED)
        _thrusterForces.y = -Ship::SPEED;

    _ship.move(_thrusterForces);

    // Controle de position (Todo)
}

void world::Ship::draw(RenderTarget & target, RenderStates states) const
{
}

void world::Ship::checkKeyPressed(sf::Event &e)
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
    }
}

void world::Ship::checkKeyReleased(sf::Event &e)
{
    if (e.type == sf::Event::KeyReleased)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            _event = (control_event)(_event & !control_event::FORWARD);
        }

        // Si touche gauche appuyee
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            _event = (control_event)(_event & !control_event::ROT_LEFT);
        }

        // Si touche droite appuyee
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _event = (control_event)(_event & !control_event::ROT_RIGHT);
        }

        // Si touche bas appuyee
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            _event = (control_event)(_event & !control_event::BACKWARD);
        }

        // Remise a zero des evenements si necessaire
        if (_event == 1)
            _event == control_event::NONE;
    }
}
