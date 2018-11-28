#pragma once

#include "Figure.h"

class CLine : public CFigure
{
	public:
		CLine();
		~CLine();
		void display();
		void pintarLinea(int,int,int,int);
		void putPixel(int, int);
		void generarBonding();
		void generarBondingBox();
};

