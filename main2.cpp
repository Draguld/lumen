#include "std.hpp"
#include "sfml.hpp"
#include "SettingManager.hpp"
#include "VertexManipulator.hpp"
#include "Lst.hpp"
#include "ShotList.hpp"
#include "Shot.hpp"
#include "ft_itos.hpp"

int		ft_rand(int min, int max, int mod=0)
{
	srand(time(0) + mod);
	return (rand() % (max - min + 1) + min);
}

int		main()
{
	sf::Clock				clock;
	unsigned int			elapsedCooldown = 0;
	unsigned int			elapsedRechargement = 0;
	
	unsigned int			cooldown_fire = 80;
	unsigned int			cooldown_fire_modification = 0;

	unsigned int			rechargement_time = 1200;
	bool					isOnRecharge = false;
	
	bool					semiAuto = false;
	bool					semiShotAllowed = true;

	sf::Font				basic;

	basic.loadFromFile("fonts/Ubuntu-B.ttf");

	sf::Text				ammo;
	
	ammo.setFont(basic);
	ammo.setCharacterSize(24);
	
//				weapon:
//	Path to the shot sound,
//	Path to the reload sound,
//	Graphics...
//	magasin size
//	shot to (xxxx Milliseconds)
//	time to recharge (xxx Milliseconds)

	sf::SoundBuffer 		sfx_1;
	sf::SoundBuffer 		sfx_2;
	sf::SoundBuffer 		sfx_3;
	sf::SoundBuffer 		sfx_4;
	
	sf::SoundBuffer			sec;

	sf::Sound				tir;
	sf::Sound				rec;

	sfx_1.loadFromFile("shotSound/shot_01.wav");
	sfx_2.loadFromFile("shotSound/shot_02.wav");
	sfx_3.loadFromFile("shotSound/shot_03.wav");
	sfx_4.loadFromFile("shotSound/shot_04.wav");
	
	sec.loadFromFile("R.ogg");

	tir.setVolume(10);
	rec.setBuffer(sec);
	rec.setVolume(30);
	sf::Texture				reloadSign;
	sf::Texture				ammo1;

	reloadSign.loadFromFile("reload.png");
	ammo1.loadFromFile("ammo1.png");

	sf::RenderWindow		win;
	sf::Event				event;
	sf::VertexArray			shot(sf::Quads, 0);
	sf::VertexArray			player(sf::Quads, 4);
	sf::VertexArray			reload(sf::Quads, 4);

	ShotList				*lst = NULL;

	unsigned int			chargeur_max = 31;
	unsigned int			chargeur_max_empty = 30;
	unsigned int			current_chargeur = 0;

	sf::Vector2f			p_position(400, 300);
	sf::Vector2f			p_size(14, 14);
	sf::Vector2f			p_center(p_position.x + p_size.x/2, p_position.y + p_size.y/2);
	float					p_angle = 0;
	
	Shot					cpyShot;

	VertexManipulator::positionFromRect(&player[0], sf::FloatRect(p_position.x, p_position.y, p_size.x, p_size.y));
	VertexManipulator::positionFromRect(&reload[0], sf::FloatRect(307, 550, 213, 35));
	VertexManipulator::textureFromRect(&reload[0], sf::FloatRect(0, 0, 213, 35));
	VertexManipulator::color(&player[0], sf::Color(255, 255, 255, 255), 4);
	VertexManipulator::color(&reload[0], sf::Color(255, 255, 255, 255), 4);
	
	bool					rotateRight 	= false;
	bool					rotateLeft 		= false;
	bool					space 			= false;
	
	bool					moveUp			= false;
	bool					moveDown		= false;
	bool					moveRight		= false;
	bool					moveLeft		= false;
	bool					pushR			= false;
	bool					selectFireMode	= false;

	unsigned int			nLoop = 0;

	win.create(sf::VideoMode(800, 600), "NONAME");
	win.setFramerateLimit(30);
	while (win.isOpen())
	{
		ammo.setString(ft_itos(current_chargeur));
		cpyShot = Shot(0, 24.7f, 0.0f, p_angle, p_center, sf::Vector2f(4, 2));
		nLoop++;
		elapsedCooldown += clock.getElapsedTime().asMilliseconds();
		if (isOnRecharge)
			elapsedRechargement += clock.getElapsedTime().asMilliseconds();
		clock.restart();
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
					space = true;
				if (event.key.code == sf::Keyboard::Right)
					rotateRight = true;
				if (event.key.code == sf::Keyboard::Left)
					rotateLeft = true;
				if (event.key.code == sf::Keyboard::W)
					moveUp = true;
				if (event.key.code == sf::Keyboard::S)
					moveDown = true;
				if (event.key.code == sf::Keyboard::D)
					moveRight = true;
				if (event.key.code == sf::Keyboard::A)
					moveLeft = true;
				if (event.key.code == sf::Keyboard::R)
					pushR = true;
				if (event.key.code == sf::Keyboard::X)
					selectFireMode = true;

			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					space = false;
					semiShotAllowed = true;
				}
				if (event.key.code == sf::Keyboard::Right)
					rotateRight = false;
				if (event.key.code == sf::Keyboard::Left)
					rotateLeft = false;
				if (event.key.code == sf::Keyboard::W)
					moveUp = false;
				if (event.key.code == sf::Keyboard::S)
					moveDown = false;
				if (event.key.code == sf::Keyboard::D)
					moveRight = false;
				if (event.key.code == sf::Keyboard::A)
					moveLeft = false;
				if (event.key.code == sf::Keyboard::R)
					pushR = false;
				if (event.key.code == sf::Keyboard::X)
					selectFireMode = false;
			}
		}

		if (semiShotAllowed && space == true && elapsedCooldown >= (cooldown_fire + ft_rand(-cooldown_fire_modification, cooldown_fire_modification, nLoop)) && current_chargeur > 0 && !isOnRecharge)
		{
			if (lst == NULL)
				lst = new ShotList(new Shot(cpyShot));
			else
				lst->addEnd(new ShotList(new Shot(cpyShot)));
				
				int	thisRand = ft_rand(0, 3, nLoop);
				if (thisRand == 0)
					tir.setBuffer(sfx_1);
				if (thisRand == 1)
					tir.setBuffer(sfx_2);
				if (thisRand == 2)
					tir.setBuffer(sfx_3);
				if (thisRand == 3)
					tir.setBuffer(sfx_4);
				tir.play();
				current_chargeur--;
				elapsedCooldown = 0;
			if (semiAuto == true)
				semiShotAllowed = false;
		}
		if (rotateRight == true)
			p_angle += 6.2f;
		if (rotateLeft == true)
			p_angle -= 6.2f;
		if (moveUp)
			p_position.y -= 5;
		if (moveDown)
			p_position.y += 5;
		if (moveRight)
			p_position.x += 5;
		if (moveLeft)
			p_position.x -= 5;
		if (pushR && !isOnRecharge && current_chargeur < 31)
		{	
			isOnRecharge = true;
			rec.play();
		}
		if (selectFireMode == true)
		{
			semiAuto = !semiAuto;
			selectFireMode = false;
		}

		if (isOnRecharge && elapsedRechargement >= rechargement_time)
		{
			if (current_chargeur > 0)
				current_chargeur = chargeur_max;
			else
				current_chargeur = chargeur_max_empty;
			elapsedRechargement = 0;
			isOnRecharge = false;
		}
		
		p_center = sf::Vector2f(p_position.x + p_size.x/2, p_position.y + p_size.y/2);

		if (lst != NULL)
		{		
			lst = lst->getFirst();
				lst->getData()->updatePosition();
			while (lst->getNext() != NULL)
			{
				lst = lst->getNext();
				lst->getData()->updatePosition();
			}
			while (lst->getPrevious() != NULL)
				lst = lst->getPrevious();
			shot.clear();
			shot.resize(lst->getSize() * 4);
			lst = lst->getLast();
		
			for (unsigned int i = 0; i < lst->getSize() * 4; i += 4)
			{
				VertexManipulator::positionFromVectors(&shot[i], lst->getData()->getPosition(), lst->getData()->getSize());
				VertexManipulator::textureFromVectors(&shot[i], sf::Vector2f(0, 0), sf::Vector2f(16, 16));
				if (lst->getPrevious() != NULL)
					lst = lst->getPrevious();
			}
		//	VertexManipulator::color(&shot[0], sf::Color::Red, shot.getVertexCount());
		}
		VertexManipulator::positionFromRect(&player[0], sf::FloatRect(p_position.x, p_position.y, p_size.x, p_size.y));

		if (lst != NULL)
			lst = lst->getFirst();
		while (lst != NULL && lst->getNext() != NULL)
		{
			sf::FloatRect	a_pos;
			sf::FloatRect	screen(0, 0, 800, 600);
			
			a_pos.left = lst->getData()->getPosition().x;		
			a_pos.top = lst->getData()->getPosition().y;		
			a_pos.width = lst->getData()->getSize().x;		
			a_pos.height = lst->getData()->getSize().y;

			if (a_pos.intersects(screen) == false)
				lst->setIsAlive(false);
			lst = lst->getNext();
		}
		
		if (lst != NULL)
			lst = lst->getFirst();
		while (lst != NULL && lst->getNext() != NULL)
		{
			if(lst->getIsAlive() == false)
				lst = lst->remove();
			else
				lst = lst->getNext();
		}
		if (lst == NULL)
		{
			shot.clear();
	//		shot.resize(0);
		}
		
		win.clear(sf::Color::Black);

		if (shot.getVertexCount() != 0)
			win.draw(shot, &ammo1);
		win.draw(player);
		if (current_chargeur == 0)
			win.draw(reload, &reloadSign);
		win.draw(ammo);

		win.display();
	}
	lst->clear();
	lst = NULL;
	return(0);		
}
