

#include "QuadTree.h"





int main()
{
	QuadTree hola;
	hola.update();
}

















int maino()
{
    sf::RenderWindow window(sf::VideoMode(500,500), "Colisiones");
    Objeto nuevo(5,sf::Color::Blue);
    sf::RectangleShape rect(sf::Vector2f(200,300));
    rect.setFillColor(sf::Color::Transparent);
    rect.setPosition(50,60);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(1);
	std::pair<int,int>p1,p2;
	p1=std::make_pair(50,60);
	p2=std::make_pair(250,360);
	int aux,auy;
	aux=p1.first+abs(p1.first-p2.first)/2;
	auy=p1.second+abs(p1.second-p2.second)/2;
	std::cout<<aux<<"  "<<auy<<std::endl;
    nuevo.setPosition(aux,auy);
    nuevo.setOrigin(5,5);
    int angle;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type==sf::Event::KeyPressed)
            {
            	if(event.key.code==sf::Keyboard::Escape)
            		window.close();
            }
        }

        window.clear();
        window.draw(nuevo);
        window.draw(rect);
        window.display();
    }

    return 0;
}	