#pragma once

#include "Frame.hpp"
#include "Ship.hpp"
#include "FrameManager.hpp"
#include "Asteroid.hpp"

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <random>

#define NB_LIFE 3
#define NB_ASTEROIDS 20

/**
 * @namespace world
 *
 * Contient tous les éléments définissant le monde du jeu
 */
namespace world
{
    /**
     * @class GameFrame
     *
     * Frame du jeu
     */
    class GameFrame : Frame
    {
    private:
        unsigned int                                _life; /*<! Nombre de vie du joueur */
        Ship                                        _ship; /*<! Vaisseau du joueur */
        std::vector<Asteroid>                         _asteroids;
        sf::Vector2u&                               _spaceSize; /*<! Taille de l'espace */
        Laser                                       _laser;

    public:

        GameFrame(frame::FrameManager &manager, sf::Vector2u &spaceSize) : Frame(manager), _life(NB_LIFE), _spaceSize(spaceSize), _ship(sf::Vector2f(spaceSize.x / 2, spaceSize.y / 2), _laser), _asteroids(5)
        {
            std::default_random_engine randomEngine;
            std::uniform_real_distribution<float> orientationDist(-1, 1);
            std::uniform_int_distribution<int> xPositionDist(0, Asteroid::WIDTH);
            std::uniform_int_distribution<int> yPositionDist(0, Asteroid::HEIGHT);
            std::uniform_real_distribution<float> speedDist(0, 10);
            for (int i = 0; i < 5; ++i)
            {
                _asteroids.push_back(Asteroid(Asteroid::MAX_SIZE, sf::Vector2f(xPositionDist(randomEngine), yPositionDist(randomEngine)), speedDist(randomEngine), sf::Vector2f(orientationDist(randomEngine), orientationDist(randomEngine))));
            }
        }

        ~GameFrame() 
        {
        }

        // Hérité via Frame
        virtual void ProcessEvent(sf::Event & e) override
        {
            _ship.ProcessEvent(e);
            _laser.ProcessEvent(e);
            for (Asteroid a : _asteroids)
                a.ProcessEvent(e);
        }

        virtual void Update(float delta) override
        {
            _ship.Update(delta);
            _laser.Update(delta);

            for (Asteroid & a : _asteroids)
                if (a.isInitialized())
                    a.Update(delta);

            for (Asteroid & a : _asteroids)
            {
                if (a.isInitialized())
                {
                    if (a.collide(_laser))
                        break;
                }
            }

            int destroyed = 0;

            for (int i = 0; i < _asteroids.size(); i++)
            {
                if (!_asteroids[i].isInitialized())
                {
                    if (_asteroids[i].getSize() > 1)
                    {
                        _asteroids.push_back(Asteroid(_asteroids[i].getSize() - 1, _asteroids[i].getPosition(), _asteroids[i].getSpeed(), sf::Vector2f(_asteroids[i].getOrientation().x,-_asteroids[i].getOrientation().y)));
                        _asteroids.push_back(Asteroid(_asteroids[i].getSize() - 1, _asteroids[i].getPosition(), _asteroids[i].getSpeed(), sf::Vector2f(_asteroids[i].getOrientation().x, _asteroids[i].getOrientation().y)));
                    }
                    swap(_asteroids[_asteroids.size() - 1 - destroyed], _asteroids[i]);
                    _asteroids.pop_back();
                }
            }

            if (_asteroids.size() < 5)
            {
                std::default_random_engine randomEngine;
                std::uniform_real_distribution<float> orientationDist(-1, 1);
                std::uniform_int_distribution<int> xPositionDist(0, Asteroid::WIDTH);
                std::uniform_int_distribution<int> yPositionDist(0, Asteroid::HEIGHT);
                std::uniform_real_distribution<float> speedDist(0, 10);
                while (_asteroids.size() < 5)
                    _asteroids.push_back(Asteroid(Asteroid::MAX_SIZE, sf::Vector2f(xPositionDist(randomEngine), yPositionDist(randomEngine)), speedDist(randomEngine), sf::Vector2f(orientationDist(randomEngine), orientationDist(randomEngine))));
            }
        }

        virtual void draw(sf::RenderTarget & target) const override
        {
            _ship.draw(target);
            _laser.draw(target);
            for (Asteroid a : _asteroids)
                if (a.isInitialized())
                    a.draw(target);
        }

        // Hérité via Frame
        virtual void reinit() override
        {

        }
    };
}