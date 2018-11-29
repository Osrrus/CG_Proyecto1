#include "Besier.h"
#include <iostream>

CBesier::CBesier()
{
	mVertices = new float*[2];
	for (int i = 0; i < 10; ++i)
		mVertices[i] = new float[2];

	mType = Besier;
}


CBesier::~CBesier()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];

	puntosControl.clear();
}

void CBesier::display() {
	glColor3fv(mColor);
	
	glBegin(GL_LINE_STRIP);
		for (double tt = 0.0; tt < 1.0; tt += paso)
		{
			for (int rr = 0; rr < (numeroVertices-1); rr++)
			{
				for (int ii = 0; ii < (numeroVertices -1)-rr; ii++)
				{
					mVertices[ii][0] = float((1.0 - tt) * mVertices[ii][0]) + float(tt * mVertices[ii+1][0]);
					mVertices[ii][1] = float((1.0 - tt) * mVertices[ii][1]) + float(tt * mVertices[ii+1][1]);
				}
			}
			VertXY1[0] = mVertices[0][0];
			VertXY1[1] = mVertices[0][1];
			glVertex2fv(VertXY1);
		}
	glEnd();
}

void CBesier::agregarPunto(float x,float y) {

	punto = new std::pair <float, float>(x, y);
	puntosControl.push_back(punto);

}

void CBesier::generarBonding() {

	glColor3fv(mBondingColor);
	pintarLinea(mBonding[0][0], mBonding[0][1], mBonding[1][0], mBonding[0][1]);
	pintarLinea(mBonding[0][0], mBonding[0][1], mBonding[0][0], mBonding[1][1]);
	pintarLinea(mBonding[1][0], mBonding[1][1], mBonding[1][0], mBonding[0][1]);
	pintarLinea(mBonding[1][0], mBonding[1][1], mBonding[0][0], mBonding[1][1]);
}

void CBesier::generarBondingBox() {

	mBonding[0][0] = 0;
	mBonding[0][1] = 0;
	mBonding[1][0] = INT_MAX;
	mBonding[1][1] = INT_MAX;

	/*for (int i = 0; i < puntosControl.size(); i++) {
		if (puntosControl[i] ->first > mBonding[0][0]) {
			mBonding[0][0] = puntosControl[i]->first;
		}
		if (puntosControl[i]->first  < mBonding[1][0]) {
			mBonding[1][0] = puntosControl[i]->first;
		}
		if (puntosControl[i]->second > mBonding[0][1]) {
			mBonding[0][1] = puntosControl[i]->second;
		}
		if (puntosControl[i]->second < mBonding[1][1]) {
			mBonding[1][1] = puntosControl[i]->second;
		}
	}
	*/
}

void CBesier::pintarLinea(int x1, int y1, int x2, int y2) {
	int dx, dy, x, y, d, IncE, IncNE, incremento;

	dx = x2 - x1;
	dy = y2 - y1;



	x = x1;
	y = y1;

	putPixel(x, y);
	if (abs(dx) > abs(dy)) {

		if (dx >= 0) {

			if (y <= y2) {

				incremento = 1;
				d = dx - 2 * dy;
				IncE = -2 * dy;
				IncNE = 2 * (dx - dy);

			}
			else {

				incremento = -1;
				d = dx + 2 * dy;
				IncE = 2 * dy;
				IncNE = 2 * (dx + dy);
			}

			while (x < x2) {
				if (d <= 0) {

					d = d + IncNE;
					y += incremento;

				}
				else {
					d = d + IncE;
				}

				x++;
				putPixel(x, y);
			}
		}
		else {

			if (y <= y2) {
				incremento = 1;
				d = -dx - 2 * dy;
				IncE = -2 * dy;
				IncNE = 2 * (-dx - dy);
			}
			else {

				incremento = -1;
				d = -dx + 2 * dy;
				IncE = 2 * dy;
				IncNE = 2 * (-dx + dy);
			}

			while (x > x2) {

				if (d <= 0) {

					d = d + IncNE;
					y += incremento;

				}
				else {
					d = d + IncE;
				}

				x--;
				putPixel(x, y);
			}
		}
	}
	else {


		if (dy >= 0) {

			if (x > x2) {
				incremento = -1;
				d = dy + 2 * dx;
				IncE = 2 * dx;
				IncNE = 2 * (dy + dx);
			}
			else {
				incremento = 1;
				d = dy - 2 * dx;
				IncE = -2 * dx;
				IncNE = 2 * (dy - dx);
			}

			while (y < y2) {
				if (d <= 0) {

					d = d + IncNE;
					x += incremento;

				}
				else {
					d = d + IncE;
				}

				y++;
				putPixel(x, y);

			}

		}
		else {

			if (x > x2) {
				incremento = -1;
				d = -dy + 2 * dx;
				IncE = 2 * dx;
				IncNE = 2 * (-dy + dx);
			}
			else {
				incremento = 1;
				d = -dy - 2 * dx;
				IncE = -2 * dx;
				IncNE = 2 * (-dy - dx);
			}



			while (y > y2) {
				if (d <= 0) {

					d = d + IncNE;
					x += incremento;

				}
				else {
					d = d + IncE;
				}

				y--;
				putPixel(x, y);

			}
		}
	}

}

void CBesier::putPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void CBesier::setBack(int x, int y) {

	puntosControl.back()->first = x;
	puntosControl.back()->second = y;
}