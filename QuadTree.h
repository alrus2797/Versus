#ifndef QUADTREE_H
#define QUADTREE_H
#include "Nodo.h"
#include <iostream>
#include "Cuadrante.h"
#include "Objeto.h"

class QuadTree
{
	public:
		QuadTree()
		{
			this->raiz=new Nodo(std::make_pair(0,0),std::make_pair(400,400));
			this->window=new sf::RenderWindow(sf::VideoMode(400,400),"Colisiones");
		}
		void update()
		{
			sf::Vector2i pos;
			int x,y;
			bool release=false;
			std::vector<Objeto> objetos;	
			while (window->isOpen())
		    {
		        sf::Event event;
		        while (window->pollEvent(event))
		        {
		            if (event.type == sf::Event::Closed)
		                window->close();
		            if (event.type==sf::Event::KeyPressed)
		            {
		            	if(event.key.code==sf::Keyboard::Escape)
		            		window->close();
		            }
		            if (event.type==sf::Event::MouseButtonReleased)
		            {
		            	if (event.mouseButton.button==sf::Mouse::Left)
		            	{
		            		std::cout<<"se presiono "<<event.mouseButton.x<<"  "<<event.mouseButton.y<<std::endl;
		            		pos.x=event.mouseButton.x;
		            		pos.y=event.mouseButton.y;
		            		x=pos.x;
		            		y=pos.y;
		            		release=true;
		            	}
		            }
		        }
		        window->clear();
		        if (release)
		        {
		        	std::cout<<"exito: "<<pos.x<<" "<<pos.y<<std::endl;
		        	Objeto nuevo (5,sf::Color::Blue);
				    nuevo.setPosition(pos.x,pos.y);
				    nuevo.setOrigin(5,5);
				    objetos.push_back(nuevo);
		        	release=false;
		        }
		        for (auto i: objetos)
		        	window->draw(i);
		        window->draw(this->raiz->rect);



		        window->display();
		    }
		}

		~QuadTree(){}
	public:
		Nodo* raiz;
		sf::RenderWindow* window;
	
};

#endif