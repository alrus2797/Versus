#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics.hpp>

class Objeto: public sf::CircleShape
{
	public:
		Objeto(int a,sf::Color color) : sf::CircleShape(a)
		{
			this->setFillColor(color);
		}
		~Objeto(){}
	
};

#endif