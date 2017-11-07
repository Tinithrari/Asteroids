#pragma once

#include "Frame.hpp"
#include "StackAllocator.hpp"

#include <array>
#include <map>
#include <stdexcept>

#define NB_SCENE 3

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
        memory::StackAllocator&                         _allocator;         /*<! Allocateur mémoire */
        array<pair<world::Frame*, size_t>, NB_SCENE>    _frames;            /*<! Tableau contenant les pointeurs vers les scenes */
        int                                             _currentIndex;      /*<! Index de la scene courante */
    public:
        /**
         * Constructeur par defaut
         */
        FrameManager(memory::StackAllocator &allocator) : _frames(), _currentIndex(-1), _allocator(allocator) {}

        /**
         * Destructeur
         */
        ~FrameManager()
        {
        }

        /**
         * Alloue la memoire pour une nouvelle scene
         *
         * @brief Alloue une nouvelle scene
         * @param sceneSize taille de la scene
         * @return un pointeur sur la scene allouee
         */
        world::Frame *allocateNewScene(size_t sceneSize)
        {
            try 
            {
                world::Frame *scene = (world::Frame*) _allocator.allocate(sceneSize);
                _frames[++_currentIndex].first = scene;
                _frames[_currentIndex].second = sceneSize;
                return scene;
            } 
            catch (overflow_error &e)
            {
                throw overflow_error(e);
            }
        }

        /**
         * Retourne la scene precedente et desalloue la scene courante
         *
         * @brief Retourne la scene precedente
         * @return Un pointeur sur la scene precedente
         */
        world::Frame* getPrevious()
        {
            if (_currentIndex <= 0)
                throw runtime_error("Can't get a previous scene when this is the first scene, or when there is no scene");
            
            delete _frames[_currentIndex].first;
            _allocator.deallocate((u64*) _frames[_currentIndex].first, _frames[_currentIndex--].second);
        }
    };
}
