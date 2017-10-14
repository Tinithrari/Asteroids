#pragma once

/**
 * @file Ship.hpp
 * @brief fichier contenant la d�finition d'un vaisseau
 * @author Xavier Heugue
 * @version 1.0
 */

#include "Updatable.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

/**
 * @namespace world
 *
 * espace de nommage regroupant les �l�ments disponible dans le jeu 
 */
namespace world
{
    /**
     * @class Ship
     * @brief Vaisseau du jeu
     *
     * La classe d�finit ce qu'est un vaisseau dans le jeu
     */
    class Ship : public Updatable, public Drawable
    {
    private:
        Sprite _ship; /*<! Le sprite du vaisseau */
    public:
        /**
         * Constructeur par d�faut
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
}
