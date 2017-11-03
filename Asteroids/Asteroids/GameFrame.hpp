#pragma once

#include "Frame.hpp"
#include "Ship.hpp"
#include "FrameManager.hpp"

#include <SFML/Graphics.hpp>

#define NB_LIFE 3

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
        unsigned int    _life; /*<! Nombre de vie du joueur */
        Ship            _ship; /*<! Vaisseau du joueur */
        sf::Vector2u&   _spaceSize; /*<! Taille de l'espace */

    public:

        GameFrame(frame::FrameManager &manager, sf::Vector2u &spaceSize) : Frame(manager), _life(NB_LIFE), _spaceSize(spaceSize), _ship(sf::Vector2f(spaceSize.x / 2, spaceSize.y / 2))
        {
            
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