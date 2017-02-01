#ifndef NODO_H
#define NODO_H
#include "Cuadrante.h"
#include <vector>
#include <stdlib.h>
#include <utility>
#include <SFML/Graphics.hpp>

class Nodo
{
	public:
		Nodo(std::pair<int, int> p1, std::pair<int, int> p2)
		{
			this->mpson=new Nodo*[4];
			this->p1=p1;this->p2=p2;
			for (int i = 0; i < 4; ++i)
			{
				this->mpson[i]=0;
			}
			int anchura,altura;
			anchura=abs(p2.first-p1.first);
			altura=abs(p2.second-p1.second);
			this->rect.setSize(sf::Vector2f(anchura-2,altura-2));
		    this->rect.setFillColor(sf::Color::Transparent);
    		this->rect.setPosition(p1.first+1,p1.second+1);
    		this->rect.setOutlineColor(sf::Color::Red);
    		this->rect.setOutlineThickness(1);

		}
		void Update()
		{
			if (objetos.size()>=2)
				this->Dividir();
		}
		void Dividir()
		{
			std::pair<int,int>paux,pauy,centro;
			int x,y;
			x=p1.first+abs(p1.first-p2.first)/2;
			y=p1.second+abs(p1.second-p2.second)/2;
			centro=std::make_pair(x,y);
			int aux,auy;
			aux=p1.first+abs(p2.first-p1.first)/2;
			auy=p1.second;
			paux=std::make_pair(aux,auy);
			aux=p2.first;
			auy=p1.second+abs(p2.second-p1.second)/2;
			pauy=std::make_pair(this->p1.first,this->p2.second);
			this->mpson[0]=new Nodo(p1,centro);
			this->mpson[1]=new Nodo(paux,pauy);
			aux=p1.first;
			auy=p1.second+abs(p2.second-p1.second)/2;
			pauy=std::make_pair(aux,auy);
			aux=p1.first+abs(p1.first-p2.first)/2;
			auy=p2.second;
			paux=std::make_pair(aux,auy);
			this->mpson[2]=new Nodo(pauy,paux);
			this->mpson[3]=new Nodo(centro,p2);
		}
		~Nodo()
		{
			Nodo* aux=this->mpson[0];
			while(aux)
			{
				delete aux;
				aux++;
			}
		}
	public:
		std::vector<Objeto> objetos;
		std::pair<int, int> p1,p2;
		Nodo** mpson;
		sf::RectangleShape rect;

	
};

#endif