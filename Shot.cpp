#include "Shot.hpp"

Shot::Shot():
m_damage(0),
m_speed(0),
m_scattering(0),
m_angle(0),
m_position(0, 0),
m_size(0, 0)
{
		
}

Shot::Shot(unsigned int damage, float speed, float scattering, float angle, sf::Vector2f position, sf::Vector2f size):
m_damage(damage),
m_speed(speed),
m_scattering(scattering),
m_angle(angle),
m_position(position),
m_size(size)
{
		
}

Shot::Shot (Shot const & rhs)
{
	*this = rhs;		
}

Shot::~Shot()
{
		
}

Shot &	Shot::operator=(Shot const & rhs)
{
	this->m_damage = rhs.getDamage();
	this->m_speed = rhs.getSpeed();
	this->m_scattering = rhs.getScattering();
	this->m_angle = rhs.getAngle();
	this->m_position = rhs.getPosition();
	this->m_size = rhs.getSize();
	return (*this);
}

void				Shot::setDamage(unsigned int damage)
{
	m_damage = damage;		
}

void				Shot::setSpeed(float speed)
{
	m_speed = speed;
	if (m_speed < 0)
		m_speed *= -1;		
}

void				Shot::setScattering(float scattering)
{
	m_scattering = scattering;
	if (m_scattering < 0)
		scattering *= -1;		
}

void				Shot::setAngle(float angle)
{
	while (angle >= 360)
		angle = angle - 360;
	m_angle = angle;		
}

void				Shot::setPosition(sf::Vector2f position)
{
	m_position = position;
}

void				Shot::setSize(sf::Vector2f size)
{
	m_size = size;		
}

void				Shot::move(sf::Vector2f move)
{
	m_position += move;		
}

unsigned int		Shot::getDamage()const
{
	return (m_damage);		
}

float				Shot::getSpeed()const
{
	return (m_speed);		
}

float				Shot::getScattering()const
{
	return (m_scattering);		
}

float				Shot::getAngle()const
{
	return (m_angle);		
}

sf::Vector2f		Shot::getPosition()const
{
	return (m_position);		
}

sf::Vector2f		Shot::getSize()const
{
	return (m_size);		
}

Shot				Shot::data()
{
	return (*this);		
}

void				Shot::updatePosition()
{
	float rad = (M_PI * m_angle / 180);
	
	m_position.x = m_position.x + m_speed * cos(rad);
	m_position.y = m_position.y + m_speed * sin(rad);
}
