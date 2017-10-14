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
 * @brief interface pour la mise � jour d'objet
 *
 * Interface � impl�menter pour la mise � jour d'objet dans le jeu
 */
class Updatable
{
public:
    /**
     * @brief Fonction de gestion des �v�nements
     * @param e Evenement � g�rer
     * 
     * Fonction mettant � jour l'�tat de l'objet
     */
    virtual void ProcessEvent(sf::Event &e) = 0;

    /**
     * @brief Met � jour l'objet
     * @param delta la dur�e entre deux mise � jour
     *
     * Met � jour l'objet en fonction de son �tat et du temps �coul�
     */
    virtual void Update(float delta) = 0;
};
