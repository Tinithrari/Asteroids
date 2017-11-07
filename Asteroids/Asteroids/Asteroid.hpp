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
#include "Application.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

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
    class Asteroid : public Updatable
    {
    private:
        static sf::Texture* ASTEROID_TEXTURE;
        Sprite _sprite; /*<! sprite de l'asteroid */
        int _size; /*<! taille de l'asteroid */
		float _speed; /*<! Vitesse de l'asteroid*/
		static const float ROTATION; /*<! Rotation de l'asteroid*/
		sf::Vector2f _orientation /*<! Orientation de l'asteroid*/;

    public:
        static const int MAX_SIZE;
        static const int WIDTH;
        static const int HEIGHT;

        /**
         * Constructeur de l'asteroid
         * @param taille de l'asteroid
         * @param position Position de l'asteroid
         */
        explicit Asteroid(int size, Vector2f position, float speed, Vector2f orientation) : _size(size), _speed(speed), _orientation(orientation)
        {
            if (ASTEROID_TEXTURE == nullptr)
            {
                ASTEROID_TEXTURE = new Texture();
                if (!ASTEROID_TEXTURE->loadFromFile("asteroid.png"))
                {
                    std::clog << "asteroid.png is missing" << std::endl;
                    exit(1);
                }
            }
            _sprite.setTexture(*ASTEROID_TEXTURE);
        }

        /**
         * Destructeur
         */
        ~Asteroid()
        {
        }

        // Herite via Updatable
        virtual void ProcessEvent(sf::Event & e) override
        {
            // L'asteroid tourne sur lui meme
            _sprite.rotate(ROTATION);
            _sprite.move(_orientation.x * _speed, _orientation.y * _speed);

            const sf::Vector2f& pos = _sprite.getPosition();

            if (pos.x > Asteroid::WIDTH)
                _sprite.setPosition(0, pos.y);
            if (pos.y > Asteroid::HEIGHT)
                _sprite.setPosition(pos.x, 0);
            if (pos.x < -(int)_sprite.getTexture()->getSize().x * _size)
                _sprite.setPosition(Asteroid::WIDTH, pos.y);
            if (pos.y < -(int)_sprite.getTexture()->getSize().y * _size)
                _sprite.setPosition(pos.x, Asteroid::HEIGHT);
        }

        virtual void Update(float delta) override;

        // Herite via Drawable
        virtual void draw(RenderTarget & target) const
        {
            target.draw(_sprite);
        }

        Asteroid& operator=(Asteroid &a)
        {
            _size = a._size;
            _speed = a._speed;
            _orientation = a._orientation;
        }

    };
    const int Ship::WIDTH(1280);
    const int Ship::HEIGHT(720);
    sf::Texture* Asteroid::ASTEROID_TEXTURE(nullptr);
	const float Asteroid::ROTATION(0.2f);
    const int Asteroid::MAX_SIZE(3);
}
