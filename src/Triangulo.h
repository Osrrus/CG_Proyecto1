#include "Figure.h"

class Triangulo :public CFigure
{
	public:
		Triangulo();
		~Triangulo();
		void display();
		void pintarLinea(int, int, int, int);
		void putPixel(int, int);
};
