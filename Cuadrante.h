#ifndef CUADRANTE_H
#define CUADRANTE_H
#include <vector>
#include "Objeto.h"
#include <utility>


class Cuadrante
{
	public:
		Cuadrante(std::vector<Objeto> obj, std::pair<int, int> p1, std::pair<int, int> p2)
		{
			this->objetos=obj;
			this->p1=p1; this->p2=p2;
		}
		Cuadrante(){}
		void setDatos(std::pair<int, int> p1, std::pair<int, int> p2)
		{
			this->p1=p1;this->p2=p2;
		}
		~Cuadrante()
		{

		}
	public:
		std::vector<Objeto> objetos;
		std::pair<int, int> p1,p2;
	
};

#endif