#ifndef POOP_HPP
# define POOP_HPP

# include "AEntity.hpp"

class Poop : public AEntity
{
public:

	Poop(int const x, int const y);
	~Poop(void);

	void					update(Board *board);

private:

	Poop(void);
	Poop(Poop const &src);
	Poop &					operator=(Poop const &rhs);

};

#endif
