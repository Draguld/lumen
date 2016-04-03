#ifndef		VERTEXMANIPULATOR_HPP
#define		VERTEXMANIPULATOR_HPP

#include "std.hpp"
#include "sfml.hpp"

class	VertexManipulator
{
	public:

	static void				buttonList(sf::Vertex *vertex, sf::FloatRect firstButton, sf::Vector2f threshold, unsigned int nbr);
	static void				positionFromRect(sf::Vertex *vertex, sf::FloatRect rect);
	static void				positionFromVectors(sf::Vertex *vertex, sf::Vector2f position, sf::Vector2f size);
	static void				positionFromFloat(sf::Vertex *vertex, float left, float top, float widht, float height);

	static void				color(sf::Vertex *vertex, sf::Color color, unsigned int vertexNumber);
	
	static void				textureFromRect(sf::Vertex *vertex, sf::FloatRect);
	static void				textureFromVectors(sf::Vertex *vertex, sf::Vector2f position, sf::Vector2f size);
	static void				textureFromFloat(sf::Vertex *vertex, float left, float top, float widht, float height);

	static sf::FloatRect	getBound(sf::Vertex const *vertex);
	static sf::Color		getColor(sf::Vertex const *vertex);
	static sf::Vector2f		getPoint(sf::Vertex	const *vertex);

	static bool				quadContain(sf::Vertex const *vertex, sf::Vector2f point);
	static void				positionFromPoints(sf::Vertex *vertex, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, sf::Vector2f d);
};

#endif
