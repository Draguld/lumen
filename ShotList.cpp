#include "ShotList.hpp"

ShotList::ShotList():
m_data(NULL),
m_next(NULL),
m_previous(NULL),
m_isAlive(true)
{
		
}

ShotList::ShotList(Shot *data):
m_data(data),
m_next(NULL),
m_previous(NULL),
m_isAlive(true)
{
		
}

void			ShotList::insert(ShotList *node)
{
	node->setNext(this->getNext());
	this->setNext(node);
	node->setPrevious(this);
	node->getNext()->setPrevious(node);
}

void			ShotList::addEnd(ShotList *node)
{
	ShotList	*cur;

	cur = this;
	while (cur->getNext() != NULL)
	{
		cur = cur->getNext();
	}
	cur->setNext(node);
	node->setNext(NULL);
	node->setPrevious(cur);
}

void			ShotList::addBegin(ShotList *node)
{
	ShotList	*cur;

	cur = this;
	while (cur->getPrevious() != NULL)
	{
		cur = cur->getPrevious();
	}
	cur->setPrevious(node);
	node->setNext(cur);
	node->setPrevious(NULL);
}

ShotList			*ShotList::remove()
{
	ShotList		*cur;
	ShotList		*ret;

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

void			ShotList::clear()
{	
	ShotList	*cur = this;
	while (cur != NULL)
		cur = cur->remove();
}

void			ShotList::setData(Shot *data)
{
	this->m_data = data;
}

void			ShotList::setNext(ShotList *next)
{
	this->m_next = next;
}

void			ShotList::setPrevious(ShotList *previous)
{
	this->m_previous = previous;		
}

void			ShotList::setIsAlive(bool alive)
{
	this->m_isAlive = alive;	
}

unsigned int	ShotList::getSize()
{
	unsigned int	 size;
	ShotList			*cur;
	
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

ShotList			*ShotList::getFirst()
{
	ShotList	*cur;

	cur = this;
	while (cur->getPrevious() != NULL)
		cur = cur->getPrevious();
	return (cur);
}

ShotList			*ShotList::getLast()
{
	ShotList	*cur;

	cur = this;
	while (cur->getNext() != NULL)
		cur = cur->getNext();
	return (cur);
}

ShotList			*ShotList::getNext()const
{
	return (this->m_next);
}

ShotList			*ShotList::getPrevious()const
{
	return (this->m_previous);		
}

ShotList			*ShotList::getCurrent()const
{
	return ((ShotList*)(this));		
}

Shot		*ShotList::getData()const
{
	return (this->m_data);		
}

bool		ShotList::getIsAlive()const
{
	return (this->m_isAlive);		
}
