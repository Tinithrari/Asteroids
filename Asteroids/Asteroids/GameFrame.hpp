#pragma once

#include "Frame.hpp"
#include "Ship.hpp"
#include "FrameManager.hpp"
#include "Asteroid.hpp"

#include <SFML/Graphics.hpp>
#include <array>
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
        array<Asteroid, NB_ASTEROIDS>               _asteroids;
        sf::Vector2u&                               _spaceSize; /*<! Taille de l'espace */

    public:

        GameFrame(frame::FrameManager &manager, sf::Vector2u &spaceSize) : Frame(manager), _life(NB_LIFE), _spaceSize(spaceSize), _ship(sf::Vector2f(spaceSize.x / 2, spaceSize.y / 2)), _asteroids()
        {
            std::default_random_engine randomEngine;
            std::uniform_real_distribution<float> orientationDist(-1, 1);
            std::uniform_int_distribution<int> xPositionDist(0, Asteroid::WIDTH);
            std::uniform_int_distribution<int> yPositionDist(0, Asteroid::HEIGHT);
            std::uniform_real_distribution<float> speedDist(0, 10);
            for (int i = 0; i < NB_ASTEROIDS; ++i)
            {
                _asteroids[i] = Asteroid(Asteroid::MAX_SIZE, sf::Vector2f(xPositionDist(randomEngine), yPositionDist(randomEngine)), speedDist(randomEngine), sf::Vector2f(orientationDist(randomEngine), orientationDist(randomEngine)));
            }
        }

        ~GameFrame() 
        {
        }

        // Hérité via Frame
        virtual void ProcessEvent(sf::Event & e) override
        {
            _ship.ProcessEvent(e);
        }

        virtual void Update(float delta) override
        {
            _ship.Update(delta);
        }

        virtual void draw(sf::RenderTarget & target) const override
        {
            _ship.draw(target);
        }

        // Hérité via Frame
        virtual void reinit() override
        {

        }
    };
}