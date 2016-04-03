#include "std.hpp"
#include "sfml.hpp"
#include "SettingManager.hpp"
#include "VertexManipulator.hpp"
#include "Lst.hpp"
#include "ShotList.hpp"
#include "Shot.hpp"

/*
	int angle = 0;//Angle en degres.
	int	d = 100;//Distance (Vitesse * temps).

	sf::Vector2f	posInit(0, 0);
	sf::Vector2f	posFinal;

//	posFinal_X et la position resultant de la somme de la position initial_X et de la distance (V*t) multiplier par le cosinus de l'angle en radian (pi * angle en degres / 180);
//	posFinal_Y et la position resultant de la somme de la position initial_Y et de la distance (V*t) multiplier par le sinus de l'angle en radian (pi * angle en degres / 180);
//
//	(angle modulo 360 permet de normaliser l'angle sur un cercle de 360degres).

	posFinal.x = posInit.x + d * cos(__pi * (angle % 360) / 180);
	posFinal.y = posInit.y + d * sin(__pi * (angle % 360) / 180);
*/

int		main(int argc, char **argv)
{
//	Shot	tir1(10, 4.0f, 4.0f, 4.0f, sf::Vector2f(10, 10), sf::Vector2f(20,20));

	if (argc != 2)
		return(0);
	std::ifstream		f_read;
	std::string			buffer;
	Lst					*cur = NULL;

	f_read.open(argv[1]);
	if (!f_read)
		return(1);
	while (std::getline(f_read, buffer))
	{
		if (cur == NULL)
			cur = new Lst(new std::string((buffer + '\n').data()));
		else
			cur->addEnd(new Lst(new std::string((buffer + '\n').data())));
	}

	while (cur->getPrevious() != NULL)
	{
		cur = cur->getPrevious();
	}

	while (42)
	{	
		std::cout << cur->getData()->data();
		if (cur->getNext() == NULL || cur == NULL)
			break;
		cur = cur->getNext();
	}

//	while (cur != NULL)
//		cur = cur->remove();

	cur->clear();
	cur = NULL;
	return (0);		
}
