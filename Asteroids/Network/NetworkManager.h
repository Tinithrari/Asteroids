/*
Joris Graaffe, Xavier Heugue. Asteroid-like game
Copyright (C) 2017  Joris Graaffe, Xavier Heugue

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/**
 * @file NetworkManager.hpp
 * @brief Fichier contenant le gestionnaire de réseau
 * @author Xavier Heugue
 * @version 1.0
 *
 * Gestionnaire de réseau du jeu asteroid
 */

#include <vector>
#include <SFML/Network.hpp>

using namespace std;

constexpr const int MAX_NB_PLAYER = 8; /*<! Nombre maximum de joueur pour une partie en reseau */

/**
 * @namespace network
 *
 * Espace de nommage contenant tous les objets relatifs au reseau
 */
namespace network
{
    /**
     * @class NetworkManager
     * @brief Gestionnaire de reseaux
     * 
     * Classe contenant les elements necessaire pour la gestion des communications pour le jeu
     */
    class NetworkManager
    {
    private:
        sf::UdpSocket _udpSocket; /*<! Socket UDP pour la phase ingame */
        sf::TcpListener _listener; /*<! Socket pour l'écoute de connexion */
        vector<sf::TcpSocket> _clientsConnections; /*<! Liste des sockets TCP pour la connexion de clients */
        // TODO liste d'objet client
    public:
        NetworkManager() : _clientsConnections(MAX_NB_PLAYER) {} /*<! Constructeur par defaut */
        ~NetworkManager() {} /*<! Destructeur par defaut */
        
        /**
         * Lance l'ecoute de clients sur le serveur
         */
        void beginListening() {}

        /**
         * @brief Retourne la liste des clients
         * @return la liste des clients
         *
         * Retourne une liste de clients (thread safe)
         */
        vector<sf::TcpSocket> getClients()
        {
            return _clientsConnections;
        }

    };
}
