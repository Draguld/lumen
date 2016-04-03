#ifndef		ENEMYLIST_HPP
#define		ENEMYLIST_HPP

#include "std.hpp"
#include "Enemy.hpp"

class		EnemyList
{
	public:
	EnemyList();
	EnemyList(Enemy *data);
	
	void					insert(EnemyList *node);
	void					addEnd(EnemyList *node);
	void					addBegin(EnemyList *node);
	EnemyList				*remove();
	void					clear();

	void					setData(Enemy *data);
	void					setNext(EnemyList *next);
	void					setPrevious(EnemyList *previous);
	void					setIsAlive(bool alive);

	unsigned int			getSize();
	EnemyList				*getFirst();
	EnemyList				*getLast();
	EnemyList				*getNext()const;
	EnemyList				*getPrevious()const;
	EnemyList				*getCurrent()const;
	Enemy					*getData()const;
	bool					getIsAlive()const;

	EnemyList				*removeUsed();

	private:

	Enemy					*m_data;
	EnemyList				*m_next;
	EnemyList				*m_previous;
	bool					m_isAlive;
};

#endif
