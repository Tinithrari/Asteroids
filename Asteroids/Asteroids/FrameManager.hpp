#pragma once

#include "Scene.hpp"
#include <array>

using namespace std;

/**
 * @namespace frame
 *
 * Espace de nommage regroupant les classes necessaire a la gestion des frames
 */
namespace frame
{
    /**
     * @class FrameManager
     * @brief gestionnaire de frame (scene)
     *
     * Classe reunissant l'ensemble des scenes et permettant de naviguer entre elles, et d'en allouer de nouvelles
     */
    class FrameManager
    {
    private:
        array<world::Scene*, 3> _frames;        /*<! Tableau contenant les pointeurs vers les scenes */
        int                     _currentIndex;  /*!< Index de la scene courante */
    public:
        FrameManager(); /*<! Constructeur par defaut */
        ~FrameManager(); /*<! Destructeur */

        /**
         * Alloue la memoire pour une nouvelle scene
         *
         * @brief Alloue une nouvelle scene
         * @param sceneSize taille de la scene
         * @return un pointeur sur la scene allouee
         */
        world::Scene *allocateNewScene(size_t sceneSize);

        /**
         * Retourne la scene precedente
         *
         * @brief Retourne la scene precedente
         * @return Un pointeur sur la scene precedente
         */
        world::Scene* getPrevious();
    };
}
