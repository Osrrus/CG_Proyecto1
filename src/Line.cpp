#include "Line.h"
#include "stdlib.h"

CLine::CLine()
{
	mVertices = new float*[2];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];

	mType = LINE;
}

CLine::~CLine()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];
}

void CLine::display()
{
	glColor3fv(mColor);

	pintarLinea(mVertices[0][0], mVertices[0][1], mVertices[1][0],mVertices[1][1]);

	//glBegin(GL_LINES);
		//glVertex2fv(mVertices[0]);
		//glVertex2fv(mVertices[1]);
	//glEnd();
}

void CLine::pintarLinea(int x1,int y1, int x2, int y2) {
	int dx, dy, x, y, d, IncE, IncNE;

	dx = x2 - x1;
	dy = y2 - y1;
	
	

	x = x1;
	y = y1;
	
	putPixel(x, y);
	if (abs(dx) > abs(dy)) {

		if (dx >= 0) {

			d = dx - 2 * dy;
			IncE = -2 * dy;
			IncNE = 2 * (dx - dy);

			while (x < x2) {
				if (d <= 0) {

					d = d + IncNE;
					y++;

				}
				else {
					d = d + IncE;
				}

				x ++;
				putPixel(x, y);
			}
		}
		else {

			d = -(dx - 2 * dy);
			IncE = -2 * dy;
			IncNE = 2 * (-dx - dy);

			while (x > x2) {
				if (d <= 0) {

					d = d + IncNE;
					y++;

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

		d = dy - 2 * dx;
		IncE = -2 * dx;
		IncNE = 2 * (dy - dx);

		while (y < y2) {
			if (d <= 0) {

				d = d + IncNE;
				x++;

			}
			else {
				d = d + IncE;
			}

			y ++;
			putPixel(x, y);

		}
	}
		
}

void CLine::putPixel(int x,int y) {
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}