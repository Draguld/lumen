#ifndef		SHOTLIST_HPP
#define		SHOTLIST_HPP

#include "std.hpp"
#include "Shot.hpp"

class		ShotList
{
	public:
	ShotList();
	ShotList(Shot *data);
	
	void					insert(ShotList *node);
	void					addEnd(ShotList *node);
	void					addBegin(ShotList *node);
	ShotList				*remove();
	void					clear();

	void					setData(Shot *data);
	void					setNext(ShotList *next);
	void					setPrevious(ShotList *previous);
	void					setIsAlive(bool alive);

	unsigned int			getSize();
	ShotList				*getFirst();
	ShotList				*getLast();
	ShotList				*getNext()const;
	ShotList				*getPrevious()const;
	ShotList				*getCurrent()const;
	Shot					*getData()const;
	bool					getIsAlive()const;

	ShotList				*removeUsed();

	private:

	Shot					*m_data;
	ShotList				*m_next;
	ShotList				*m_previous;
	bool					m_isAlive;
};

#endif
