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
    class Laser;
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
        float _size; /*<! taille de l'asteroid */
		float _speed; /*<! Vitesse de l'asteroid*/
		static const float ROTATION; /*<! Rotation de l'asteroid*/
        sf::Vector2f _orientation; /*<! Orientation de l'asteroid*/
        bool _initialized;

    public:
        static const int MAX_SIZE;
        static const int WIDTH;
        static const int HEIGHT;

        Asteroid(): _initialized(false)
        {

        }

        /**
         * Constructeur de l'asteroid
         * @param taille de l'asteroid
         * @param position Position de l'asteroid
         */
        explicit Asteroid(float size, Vector2f position, float speed, Vector2f orientation) : _size(size), _speed(speed), _orientation(orientation), _initialized(true)
        {
            if (ASTEROID_TEXTURE == nullptr)
            {
                ASTEROID_TEXTURE = new Texture();
                if (! ASTEROID_TEXTURE->loadFromFile("asteroid.png"))
                {
                    std::clog << "asteroid.png is missing" << std::endl;
                    exit(1);
                }
            }
            _sprite.setTexture(*ASTEROID_TEXTURE);
            _sprite.setPosition(position);
            _sprite.setOrigin(_sprite.getTexture()->getSize().x / 2.f, _sprite.getTexture()->getSize().y / 2.f);
            _sprite.scale(_size / Asteroid::MAX_SIZE, _size / Asteroid::MAX_SIZE);
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
            
        }

        virtual void Update(float delta) override
        {
            // L'asteroid tourne sur lui meme
            _sprite.rotate(ROTATION);
            _sprite.move(_orientation.x * _speed * delta * 1000, _orientation.y * _speed * delta * 1000);
            const sf::Vector2f& pos = _sprite.getPosition();

            if (pos.x > Asteroid::WIDTH + _sprite.getTexture()->getSize().x / 2)
                _sprite.setPosition(-(float)_sprite.getTexture()->getSize().x / 2, pos.y);
            if (pos.y > Asteroid::HEIGHT + _sprite.getTexture()->getSize().y / 2)
                _sprite.setPosition(pos.x, - (float) _sprite.getTexture()->getSize().y / 2);
            if (pos.x < -(int)(_sprite.getTexture()->getSize().x / 2) * _sprite.getScale().x)
                _sprite.setPosition(Asteroid::WIDTH + _sprite.getTexture()->getSize().x / 2, pos.y);
            if (pos.y < -(int)(_sprite.getTexture()->getSize().y / 2) * _sprite.getScale().y)
                _sprite.setPosition(pos.x, Asteroid::HEIGHT + _sprite.getTexture()->getSize().y / 2);
        }

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
            _initialized = a._initialized;
            _sprite = a._sprite;
            return *this;
        }

        bool isInitialized() const {
            return _initialized;
        }

        const sf::FloatRect getBoundingBox()
        {
            return _sprite.getGlobalBounds();
        }

        bool collide(Laser & l)
        {
            if (l.getBoundingBox().intersects(getBoundingBox()))
            {
                _initialized = false;
                l.setState(Laser::State::NONE);
            }
            return !_initialized;
        }

        int getSize()
        {
            return _size;
        }

        float getSpeed()
        {
            return _speed;
        }

        Vector2f getPosition()
        {
            return _sprite.getPosition();
        }

        Vector2f getOrientation()
        {
            return _orientation;
        }
    };
    const int Asteroid::WIDTH(1280);
    const int Asteroid::HEIGHT(720);
    sf::Texture* Asteroid::ASTEROID_TEXTURE(nullptr);
	const float Asteroid::ROTATION(0.01f);
    const int Asteroid::MAX_SIZE(3);
}
