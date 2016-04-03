#include "Lst.hpp"

Lst::Lst():
m_data(NULL),
m_next(NULL),
m_previous(NULL)
{
		
}

Lst::Lst(std::string *data):
m_data(data),
m_next(NULL),
m_previous(NULL)
{
		
}

void			Lst::insert(Lst *node)
{
	node->setNext(this->getNext());
	this->setNext(node);
	node->setPrevious(this);
	node->getNext()->setPrevious(node);
}

void			Lst::addEnd(Lst *node)
{
	Lst	*cur;

	cur = this;
	while (cur->getNext() != NULL)
	{
		cur = cur->getNext();
	}
	cur->setNext(node);
	node->setNext(NULL);
	node->setPrevious(cur);
}

void			Lst::addBegin(Lst *node)
{
	Lst	*cur;

	cur = this;
	while (cur->getPrevious() != NULL)
	{
		cur = cur->getPrevious();
	}
	cur->setPrevious(node);
	node->setNext(cur);
	node->setPrevious(NULL);
}

Lst			*Lst::remove()
{
	Lst		*cur;
	Lst		*ret;

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

void			Lst::clear()
{	
	Lst	*cur = this;
	while (cur != NULL)
		cur = cur->remove();
}

void			Lst::setData(std::string *data)
{
	this->m_data = data;
}

void			Lst::setNext(Lst *next)
{
	this->m_next = next;
}

void			Lst::setPrevious(Lst *previous)
{
	this->m_previous = previous;		
}

unsigned int	Lst::getSize()
{
	unsigned int	 size;
	Lst			*cur;
	
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

Lst			*Lst::getNext()const
{
	return (this->m_next);
}

Lst			*Lst::getPrevious()const
{
	return (this->m_previous);		
}

Lst			*Lst::getCurrent()const
{
	return ((Lst*)(this));		
}

std::string		*Lst::getData()const
{
	return (this->m_data);		
}
