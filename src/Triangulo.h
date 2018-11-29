#include "Figure.h"

class Triangulo :public CFigure
{
	public:
		Triangulo();
		~Triangulo();
		void display();
		void pintarLinea(int, int, int, int);
		void trazarLinea(int x1, int y1, int x2, int y2, int id);
		void putPixel(int, int);
		void generarBonding();
		void generarBondingBox();
		void paint();
};
