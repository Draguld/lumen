#include "VertexManipulator.hpp"


	void			VertexManipulator::buttonList(sf::Vertex *vertex, sf::FloatRect firstButton, sf::Vector2f threshold, unsigned int nbr)
	{
		for (unsigned int j = 0; j < nbr; j++)
		{
			vertex[0 + j * 4].position = sf::Vector2f(firstButton.left + j * threshold.x, firstButton.top + j * threshold.y);
			vertex[1 + j * 4].position = sf::Vector2f(firstButton.left + firstButton.width + j * threshold.x, firstButton.top + j * threshold.y);
			vertex[2 + j * 4].position = sf::Vector2f(firstButton.left + firstButton.width + j * threshold.x, firstButton.top + firstButton.height + j * threshold.y);
			vertex[3 + j * 4].position = sf::Vector2f(firstButton.left + j * threshold.x, firstButton.top + firstButton.height + j * threshold.y);
		}
	}

	void			VertexManipulator::positionFromRect(sf::Vertex *vertex, sf::FloatRect rect)
	{
		vertex[0].position = sf::Vector2f(rect.left, rect.top);
		vertex[1].position = sf::Vector2f(rect.left + rect.width, rect.top);
		vertex[2].position = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
		vertex[3].position = sf::Vector2f(rect.left, rect.top + rect.height);
	}
	
	void			VertexManipulator::positionFromVectors(sf::Vertex *vertex, sf::Vector2f position, sf::Vector2f size)
	{
		vertex[0].position = sf::Vector2f(position.x, position.y);
		vertex[1].position = sf::Vector2f(position.x + size.x, position.y);
		vertex[2].position = sf::Vector2f(position.x + size.x, position.y + size.y);
		vertex[3].position = sf::Vector2f(position.x, position.y + size.y);
	}
	void			VertexManipulator::positionFromFloat(sf::Vertex *vertex, float left, float top, float width, float height)
	{
		vertex[0].position = sf::Vector2f(left, top);
		vertex[1].position = sf::Vector2f(left + width, top);
		vertex[2].position = sf::Vector2f(left + width, top + height);
		vertex[3].position = sf::Vector2f(left, top + height);
	}
	
	void			VertexManipulator::color(sf::Vertex *vertex, sf::Color color, unsigned int vertexNumber)
	{
		for (unsigned int i = 0; i < vertexNumber; i++)
			vertex[i].color = color;
	}

	void			VertexManipulator::textureFromRect(sf::Vertex *vertex, sf::FloatRect rect)
	{
		vertex[0].texCoords = sf::Vector2f(rect.left, rect.top);
		vertex[1].texCoords = sf::Vector2f(rect.left + rect.width, rect.top);
		vertex[2].texCoords = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
		vertex[3].texCoords = sf::Vector2f(rect.left, rect.top + rect.height);
	}
	
	void			VertexManipulator::textureFromVectors(sf::Vertex *vertex, sf::Vector2f position, sf::Vector2f size)
	{
		vertex[0].texCoords = sf::Vector2f(position.x, position.y);
		vertex[1].texCoords = sf::Vector2f(position.x + size.x, position.y);
		vertex[2].texCoords = sf::Vector2f(position.x + size.x, position.y + size.y);
		vertex[3].texCoords = sf::Vector2f(position.x, position.y + size.y);
	}
	void			VertexManipulator::textureFromFloat(sf::Vertex *vertex, float left, float top, float width, float height)
	{
		vertex[0].texCoords = sf::Vector2f(left, top);
		vertex[1].texCoords = sf::Vector2f(left + width, top);
		vertex[2].texCoords = sf::Vector2f(left + width, top + height);
		vertex[3].texCoords = sf::Vector2f(left, top + height);
	}

	sf::FloatRect	VertexManipulator::getBound(sf::Vertex const *vertex)
	{
		return (sf::FloatRect(vertex[0].position.x, vertex[0].position.y, vertex[2].position.x - vertex[0].position.x, vertex[2].position.y - vertex[0].position.y));
	}

	sf::Color		VertexManipulator::getColor(sf::Vertex const *vertex)
	{
		return (vertex->color);
	}

	sf::Vector2f	VertexManipulator::getPoint(sf::Vertex const *vertex)
	{
		return (vertex->position);
	}

	bool			VertexManipulator::quadContain(sf::Vertex const *vertex, sf::Vector2f point)
	{
		sf::FloatRect	buffer;
		
		buffer = VertexManipulator::getBound(vertex);
		if (point.x >= buffer.left && point.x <= buffer.left + buffer.width)
			if (point.y >= buffer.top && point.y <= buffer.top + buffer.height)
				return (true);
		return (false);
	}

	void		VertexManipulator::positionFromPoints(sf::Vertex *vertex, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, sf::Vector2f d)
	{
		vertex[0].position = a;
		vertex[1].position = b;
		vertex[2].position = c;
		vertex[3].position = d;
	}
