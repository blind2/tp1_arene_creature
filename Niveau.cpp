#include "Niveau.h"
#include <iostream>


int Niveau::getIndexCarte(Point2D position)
{
	return position.getX() + constantes::dimension * position.getY();
}

Niveau::Niveau(int* carte, std::string nomCreature, Point2D positionDepart): m_carte{carte}
{
	m_creature = new Creature{nomCreature, positionDepart};
	m_carte[getIndexCarte(positionDepart)] = -1; //Initialize la position du joueur
}

Niveau::~Niveau()
{
	delete m_creature;
} 

int* Niveau::getCarte()
{
    return m_carte;
}

std::string Niveau::getNomCreature()
{
	return m_creature->getNom();
}

void Niveau::getDeplacementPossible(bool* tabDeplacements)
{
	Point2D pointGauche{ m_creature->getPosition()->getX() - 1, m_creature->getPosition()->getY() };
	Point2D pointDroit{ m_creature->getPosition()->getX() + 1, m_creature->getPosition()->getY() };
	Point2D pointHaut{ m_creature->getPosition()->getX(), m_creature->getPosition()->getY() - 1 };
	Point2D pointBas{ m_creature->getPosition()->getX(), m_creature->getPosition()->getY() + 1 };

	tabDeplacements[0] = m_carte[getIndexCarte(pointGauche)];
	tabDeplacements[1] = m_carte[getIndexCarte(pointDroit)];
	tabDeplacements[2] = m_carte[getIndexCarte(pointHaut)];
	tabDeplacements[3] = m_carte[getIndexCarte(pointBas)];

	for (int i = 0; i < 4; i++)
	{
		if (tabDeplacements[i] == 0) 
			tabDeplacements[i] = true;
		else tabDeplacements[i] = false;
	}
}

void Niveau::deplacerCreature(constantes::Direction direction)
{
	//Remplace la position précédente du joueur par un zéro
	m_carte[getIndexCarte(*m_creature->getPosition())] = 0;

	switch (direction)
	{
	case constantes::gauche:
		m_creature->deplacerCreature(-1, 0);
		break;
	case constantes::droite:
		m_creature->deplacerCreature(1, 0);
		break;
	case constantes::haut:
		m_creature->deplacerCreature(0, -1);
		break;
	case constantes::bas:
		m_creature->deplacerCreature(0, +1);
		break;
	}

	//Update la position du joueur
	m_carte[getIndexCarte(*m_creature->getPosition())] = -1;
}
