#include "Creature.h"

Creature::Creature(std::string nom, Point2D position): m_nom{nom},m_position{position}{}

std::string Creature::getNom()
{
	return m_nom;
}

Point2D* Creature::getPosition()
{
	return &m_position;
}

void Creature::deplacerCreature(int x, int y)
{
	m_position.setPoint(m_position.getX() + x, m_position.getY() + y);
}
