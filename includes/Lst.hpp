#ifndef		LST_HPP
#define		LST_HPP

#include "std.hpp"

class		Lst
{
	public:
	Lst();
	Lst(std::string *data);
	
	void			insert(Lst *node);
	void			addEnd(Lst *node);
	void			addBegin(Lst *node);
	Lst				*remove();
	void			clear();

	void			setData(std::string *data);
	void			setNext(Lst *next);
	void			setPrevious(Lst *previous);
	
	unsigned int	getSize();
	Lst				*getNext()const;
	Lst				*getPrevious()const;
	Lst				*getCurrent()const;
	std::string		*getData()const;

	private:

	std::string		*m_data;
	Lst				*m_next;
	Lst				*m_previous;		
};

#endif
