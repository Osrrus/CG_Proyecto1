
#include "Figure.h"
#include <vector>
#include <utility> 

class CBesier : public CFigure
{
	protected:
		std::vector<std ::pair <int,int> > puntosControl;
	public:
		CBesier();
		~CBesier();
};
