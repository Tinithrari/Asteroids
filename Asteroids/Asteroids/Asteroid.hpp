#pragma once

/**
 * @file Asteroid.hpp
 * @brief Fichier contenant la définition d'un asteroid
 * @author Xavier Heugue
 * @version 1.0
 */

#include "Updatable.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

/**
* @namespace world
*
* espace de nommage regroupant les éléments disponible dans le jeu
*/
namespace world
{
    /**
     * @class Asteroid
     * @brief Définition d'un asteroid
     * 
     * Définition de ce qu'est un asteroid dans le jeu
     */
    class Asteroid : public Updatable, public Drawable
    {
    private:
        Sprite _sprite; /*<! sprite de l'asteroid */
        int _size; /*<! taille de l'asteroid */
    public:
        /**
         * Constructeur de l'asteroid
         * @param taille de l'asteroid
         * @param position Position de l'asteroid
         */
        explicit Asteroid(int size, Vector2f position);

        /**
         * Destructeur
         */
        ~Asteroid();

        // Hérité via Updatable
        virtual void ProcessEvent(sf::Event & e) override;
        virtual void Update(float delta) override;

        // Hérité via Drawable
        virtual void draw(RenderTarget & target, RenderStates states) const override;
    };
}
