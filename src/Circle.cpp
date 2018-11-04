#include "Circle.h"
#include "stdlib.h"


CCircle::CCircle()
{
	mVertices = new float*[2];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];

	mType = Circle;
}


CCircle::~CCircle()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];
}

void CCircle::display()
{
	int r, rx, ry;
	glColor3fv(mColor);

	rx = mVertices[1][0] - mVertices[0][0];
	rx = abs(rx);
	ry = mVertices[1][1] - mVertices[0][1];
	ry = abs(ry);

	if (rx >= ry) {
		pintarCirculo(mVertices[0][0], mVertices[0][1], mVertices[1][0], mVertices[1][1],rx);
	}
	else {
		pintarCirculo(mVertices[0][0], mVertices[0][1], mVertices[1][0], mVertices[1][1], ry);
	}
	

}

void CCircle::pintarCirculo(int x1, int y1, int x2, int y2,int r) {
	int x, y, d;
	x = 0;
	y = r;
	d = 1 - r;

	octantes(x, y,x1,y1);
	while (y > x) {
		if (d < 0) {
			d += 2 * x + 3;
		}
		else {

			d += 2 * (x - y) + 5;
			y -= 1;
		}

		x++;
		octantes(x, y,x1,y1);
	}
}

void CCircle::octantes(int x,int y,int x1, int y1) {

	putPixel( x1 +x, y1+y);
	putPixel( x1 -x, y1+y);
	putPixel( x1 +x, y1-y);
	putPixel( x1 -x, y1-y);
	putPixel( x1 +y, y1+x);
	putPixel( x1 -y, y1+x);
	putPixel( x1 +y, y1-x);
	putPixel( x1 -y, y1-x);

}

void CCircle::putPixel(int x,int y) {
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}