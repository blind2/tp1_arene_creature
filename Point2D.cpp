#include "Point2D.h"
#include"constantes.h"

Point2D::Point2D(){}

Point2D::Point2D(int x, int y) : m_x{ x }, m_y{ y }{}

int Point2D::getX()
{
	return m_x;
}

int Point2D::getY()
{
	return m_y;
}

void Point2D::setPoint(int x, int y)
{
	if (m_x < constantes::dimension) m_x = x;
	if (m_y < constantes::dimension) m_y = y;		
}
