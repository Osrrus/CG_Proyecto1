
#include "Figure.h"
class CCircle : public CFigure
{
	public:
		CCircle();
		~CCircle();
		void display();
		void pintarCirculo(int, int, int, int,int);
		void octantes(int x, int y, int x1, int y1);
		void putPixel(int, int);
};
