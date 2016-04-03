#include "Enemy.hpp"

Enemy::Enemy():
m_damage(0),
m_speed(0),
m_scattering(0),
m_angle(0),
m_position(0, 0),
m_size(0, 0)
{
		
}

Enemy::Enemy(unsigned int damage, float speed, float scattering, float angle, sf::Vector2f position, sf::Vector2f size):
m_damage(damage),
m_speed(speed),
m_scattering(scattering),
m_angle(angle),
m_position(position),
m_size(size)
{
		
}

Enemy::Enemy (Enemy const & rhs)
{
	*this = rhs;		
}

Enemy::~Enemy()
{
		
}

Enemy &	Enemy::operator=(Enemy const & rhs)
{
	this->m_damage = rhs.getDamage();
	this->m_speed = rhs.getSpeed();
	this->m_scattering = rhs.getScattering();
	this->m_angle = rhs.getAngle();
	this->m_position = rhs.getPosition();
	this->m_size = rhs.getSize();
	return (*this);
}

void				Enemy::setDamage(unsigned int damage)
{
	m_damage = damage;		
}

void				Enemy::setSpeed(float speed)
{
	m_speed = speed;
	if (m_speed < 0)
		m_speed *= -1;		
}

void				Enemy::setScattering(float scattering)
{
	m_scattering = scattering;
	if (m_scattering < 0)
		scattering *= -1;		
}

void				Enemy::setAngle(float angle)
{
	while (angle >= 360)
		angle = angle - 360;
	m_angle = angle;		
}

void				Enemy::setPosition(sf::Vector2f position)
{
	m_position = position;
}

void				Enemy::setSize(sf::Vector2f size)
{
	m_size = size;		
}

void				Enemy::move(sf::Vector2f move)
{
	m_position += move;		
}

unsigned int		Enemy::getDamage()const
{
	return (m_damage);		
}

float				Enemy::getSpeed()const
{
	return (m_speed);		
}

float				Enemy::getScattering()const
{
	return (m_scattering);		
}

float				Enemy::getAngle()const
{
	return (m_angle);		
}

sf::Vector2f		Enemy::getPosition()const
{
	return (m_position);		
}

sf::Vector2f		Enemy::getSize()const
{
	return (m_size);		
}

Enemy				Enemy::data()
{
	return (*this);		
}

void				Enemy::updatePosition()
{
	float rad = (M_PI * m_angle / 180);
	
	m_position.x = m_position.x + m_speed * cos(rad);
	m_position.y = m_position.y + m_speed * sin(rad);
}
