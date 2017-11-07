#pragma once

#include <SFML/Graphics.hpp>
#include "Updatable.hpp"

namespace world
{
    class Laser : public Updatable
    {
    public:
        enum State { NONE, INITIALIZED};
    private:
        State _state;
        static const float SPEED;
        sf::Vector2f _position;
        sf::Vector2f _orientation;
        sf::Sprite  _sprite;
        static sf::Texture * TEXTURE;
        static const int WIDTH;
        static const int HEIGHT;
    public:

        explicit Laser() : _state(NONE)
        {
            if (TEXTURE == nullptr)
            {
                TEXTURE = new sf::Texture();
                TEXTURE->loadFromFile("laser.png");
            }

            _sprite.setTexture(*TEXTURE);
            _sprite.setOrigin(TEXTURE->getSize().x / 2, TEXTURE->getSize().y / 2);
        }

        void fire(const sf::Vector2f & position, sf::Vector2f & orientation, float angle)
        {
            if (_state == INITIALIZED)
                return;

            _state = INITIALIZED;
            _sprite.setPosition(position);
            _sprite.setRotation(angle);
            _orientation = orientation;
        }

        // Hérité via Updatable
        virtual void ProcessEvent(sf::Event & e) override
        {
        }

        virtual void Update(float delta) override
        {
            if (_state == INITIALIZED)
            {
                _sprite.move(_orientation.x * delta * Laser::SPEED * 10000, _orientation.y * delta * Laser::SPEED * 10000);

                const sf::Vector2f & pos = _sprite.getPosition();

                if (pos.x > Laser::WIDTH + _sprite.getTexture()->getSize().x / 2)
                    _state = NONE;
                if (pos.y > Laser::HEIGHT + _sprite.getTexture()->getSize().y / 2)
                    _state = NONE;
                if (pos.x < -(int)(_sprite.getTexture()->getSize().x / 2) * _sprite.getScale().x)
                    _state = NONE;
                if (pos.y < -(int)(_sprite.getTexture()->getSize().y / 2) * _sprite.getScale().y)
                    _state = NONE;
            }
        }

        const sf::FloatRect getBoundingBox()
        {
            return _sprite.getGlobalBounds();
        }

        void setState(State state)
        {
            _state = state;
        }

        State getState()
        {
            return _state;
        }

        void draw(sf::RenderTarget &target) const
        {
            if (_state == INITIALIZED)
            target.draw(_sprite);
        }
    };
    const int Laser::WIDTH(1280);
    const int Laser::HEIGHT(720);
    const float Laser::SPEED(100.f);
    sf::Texture * Laser::TEXTURE(nullptr);
}