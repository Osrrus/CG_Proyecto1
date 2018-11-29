
#include "Figure.h"
#include <vector>
#include <utility> 

class CBesier : public CFigure
{
	protected:
		std::vector<std ::pair <float,float>* > puntosControl;
		std::pair <float, float> *punto;
		double paso = 0.1;
		float VertXY1[2];
		int numeroVertices = 3;
	public:
		CBesier();
		~CBesier();
		void display();
		void agregarPunto(float x, float y);
		void generarBonding();
		void generarBondingBox();
		void pintarLinea(int x1, int y1, int x2, int y2);
		void putPixel(int x, int y);
		void setBack(int x, int y);
};
