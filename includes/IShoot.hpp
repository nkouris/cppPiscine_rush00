#ifndef ISHOOT_HPP
# define ISHOOT_HPP

class IShoot
{
public:

	virtual			~IShoot(void) { }
	virtual void	shoot(void) = 0;
	
};

#endif
