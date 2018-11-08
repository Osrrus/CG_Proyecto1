#pragma once

#include "../headers/glfw3.h"

enum FigureType
{
	NONE,
	LINE,
	QUAD,
	Circle,
	Triangle,
};

class CFigure
{
protected:
	float **mVertices, mColor[3], mPaintColor[3];
	bool mPaint;
	int mType;

public:
	CFigure();
	virtual ~CFigure();
	void setVertex(int id, float x, float y);
	void setColor(float r, float g, float b);
	void setPaintColor(float r, float g, float b);
	void paintFigure(bool a);
	virtual void display() = 0;
	int getType();
	float* getVertex(int id);
	float* getColor();
	float* getPaintColor();
	bool getPaintFigure();
};