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
* @file Ship.hpp
* @brief fichier contenant la definition d'un vaisseau
* @author Joris Graaffe
* @version 1.0
*/

#include "Updatable.hpp";

#include <SFML/Graphics.hpp>

#define SHOT_SIZE_X 0.f
#define SHOT_SIZE_Y 0.f

/**
* @namespace world
*
* espace de nommage regroupant les elements disponible dans le jeu
*/
namespace world
{
	/**
	* @class Shot
	* @brief Tir du jeu
	*
	* La classe definit ce qu'est un tir du vaisseau
	*/
	class Shot : public Updatable
	{
	private:
		static const sf::Vector2f SHOT_SIZE; /*<! Taille du tir*/
		sf::RectangleShape _shape; /*<! Forme du tir*/
		static const float SPEED; /*<! Vitesse du tir*/
		sf::Vector2f _orientation; /*<! Orientation du tir*/

	public:
		Shot(sf::Vector2f orientation) : _shape(SHOT_SIZE), _orientation(orientation)  {}
		~Shot() {}

		// Hérité via Updatable
		virtual void ProcessEvent(sf::Event & e) override;
		virtual void Update(float delta) override;
	};

	const sf::Vector2f Shot::SHOT_SIZE(SHOT_SIZE_X, SHOT_SIZE_Y);
	const float Shot::SPEED(80.f);


}
