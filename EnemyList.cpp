#include "EnemyList.hpp"

EnemyList::EnemyList():
m_data(NULL),
m_next(NULL),
m_previous(NULL),
m_isAlive(true)
{
		
}

EnemyList::EnemyList(Enemy *data):
m_data(data),
m_next(NULL),
m_previous(NULL),
m_isAlive(true)
{
		
}

void			EnemyList::insert(EnemyList *node)
{
	node->setNext(this->getNext());
	this->setNext(node);
	node->setPrevious(this);
	node->getNext()->setPrevious(node);
}

void			EnemyList::addEnd(EnemyList *node)
{
	EnemyList	*cur;

	cur = this;
	while (cur->getNext() != NULL)
	{
		cur = cur->getNext();
	}
	cur->setNext(node);
	node->setNext(NULL);
	node->setPrevious(cur);
}

void			EnemyList::addBegin(EnemyList *node)
{
	EnemyList	*cur;

	cur = this;
	while (cur->getPrevious() != NULL)
	{
		cur = cur->getPrevious();
	}
	cur->setPrevious(node);
	node->setNext(cur);
	node->setPrevious(NULL);
}

EnemyList			*EnemyList::remove()
{
	EnemyList		*cur;
	EnemyList		*ret;

	cur = this;
	ret = NULL;
	if (this->getData() != NULL)
	{
		delete this->getData();
		this->setData(NULL);
	}
	if (this->getNext() != NULL && this->getPrevious() != NULL)
	{
		this->getNext()->setPrevious(this->getPrevious());
		this->getPrevious()->setNext(this->getNext());
		ret = this->getNext();
	}
	else if (this->getPrevious() != NULL)
	{
		this->getPrevious()->setNext(NULL);
		ret = this->getPrevious();
	}
	else if (this->getNext() != NULL)
	{
		this->getNext()->setPrevious(NULL);
		ret = this->getNext();
	}
	cur->setPrevious(NULL);
	cur->setNext(NULL);
	delete cur;
	cur = NULL;
	return(ret);
}

void			EnemyList::clear()
{	
	EnemyList	*cur = this;
	while (cur != NULL)
		cur = cur->remove();
}

void			EnemyList::setData(Enemy *data)
{
	this->m_data = data;
}

void			EnemyList::setNext(EnemyList *next)
{
	this->m_next = next;
}

void			EnemyList::setPrevious(EnemyList *previous)
{
	this->m_previous = previous;		
}

void			EnemyList::setIsAlive(bool alive)
{
	this->m_isAlive = alive;	
}

unsigned int	EnemyList::getSize()
{
	unsigned int	 size;
	EnemyList			*cur;
	
	size = 0;
	cur = this;

	while (cur->getPrevious() != NULL)
		cur = cur->getPrevious();
	while (cur->getNext() != 0)
	{
		cur = cur->getNext();
		size++;
	}
	return (size + 1);
}

EnemyList			*EnemyList::getFirst()
{
	EnemyList	*cur;

	cur = this;
	while (cur->getPrevious() != NULL)
		cur = cur->getPrevious();
	return (cur);
}

EnemyList			*EnemyList::getLast()
{
	EnemyList	*cur;

	cur = this;
	while (cur->getNext() != NULL)
		cur = cur->getNext();
	return (cur);
}

EnemyList			*EnemyList::getNext()const
{
	return (this->m_next);
}

EnemyList			*EnemyList::getPrevious()const
{
	return (this->m_previous);		
}

EnemyList			*EnemyList::getCurrent()const
{
	return ((EnemyList*)(this));		
}

Enemy		*EnemyList::getData()const
{
	return (this->m_data);		
}

bool		EnemyList::getIsAlive()const
{
	return (this->m_isAlive);		
}
