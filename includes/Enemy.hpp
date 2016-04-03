#ifndef		ENEMY_HPP
#define		ENEMY_HPP

#include "std.hpp"
#include "sfml.hpp"

class				Enemy
{
	public:
	Enemy();
	Enemy(unsigned int damage, float speed, float scattering, float angle, sf::Vector2f position, sf::Vector2f size);
	Enemy(Enemy const & rhs);
	~Enemy();
	Enemy & operator =(Enemy const & rhs);

	void				setDamage(unsigned int damage);
	void				setSpeed(float speed);
	void				setScattering(float scattering);
	void				setAngle(float angle);
	void				setPosition(sf::Vector2f position);
	void				setSize(sf::Vector2f size);

	void				move(sf::Vector2f move);

	unsigned int		getDamage()const;
	float				getSpeed()const;
	float				getScattering()const;
	float				getAngle()const;
	sf::Vector2f		getPosition()const;
	sf::Vector2f		getSize()const;

	Enemy				data();
	void				updatePosition();
	
	private:

	unsigned int		m_damage;
	float				m_speed;
	float				m_scattering;
	float				m_angle;
	sf::Vector2f		m_position;
	sf::Vector2f		m_size;
};

#endif
