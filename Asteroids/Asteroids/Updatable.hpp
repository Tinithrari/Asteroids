#pragma once

/**
 * @file Updatable.hpp
 * @brief Fichier contenant l'interface pour les objets pouvant subir des modifications
 * @author Xavier Heugue
 * @version 1.0
 */

#include <SFML/Window/Event.hpp>

/**
 * @class Updatable
 * @brief interface pour la mise à jour d'objet
 *
 * Interface à implémenter pour la mise à jour d'objet dans le jeu
 */
class Updatable
{
public:
    /**
     * @brief Fonction de gestion des évènements
     * @param e Evenement à gérer
     * 
     * Fonction mettant à jour l'état de l'objet
     */
    virtual void ProcessEvent(sf::Event &e) = 0;

    /**
     * @brief Met à jour l'objet
     * @param delta la durée entre deux mise à jour
     *
     * Met à jour l'objet en fonction de son état et du temps écoulé
     */
    virtual void Update(float delta) = 0;
};
