#pragma once
#include "cCartas.h"
#include <vector>

using namespace std;

class cPozo
{
private:
	int cantidad=0;
	 vector<cCartas*> * pozo;
	 Rectangle size;
	 cCartas * carta;
	 int y=400;
	 bool t = false;
	 int color = 0;
	 //red = 1, yellow =2,green 3, blue = 4

public:

	cPozo()
	{
		pozo = new vector<cCartas*>;
		
	}
	~cPozo()
	{
	}

	void setCantidad(int c)
	{
	}
	int getCantidad()
	{
	}

	

	bool ValidarJugada(cCartas * carta)
	{
		
		if (carta->getTipo()=="numero")
		{
			if (carta->getColor() == color)
			{
				
				return true;
			}else
			if ( carta->getNumero() == pozo->back()->getNumero())
			{
				
				return true;
			}
		}
		

	}
	bool ValidarRobaDos(cCartas * carta)
	{
		if (carta->getTipo() == "robaDos")
		{
			if (carta->getColor() ==color || carta->getTipo() == pozo->back()->getTipo())
			{
				
				return true;
			}
		}
		
	}
	bool ValidarCambioSentido(cCartas * carta)
	{
		if (carta->getTipo() == "cambioSentido")
		{
			if (carta->getColor() == color || carta->getTipo() == pozo->back()->getTipo())
			{
				
				return true;
			}
		}

	}

	bool verifyRoba4(cJugador * player)
	{
		for (int i = 0; i < player->getNCartas(); i++)
		{
			if (player->getCarta(i)->getColor() == color)
			{
				return true;
			}
		}
		return false;
	}
	void clearPozo()
	{
		pozo->clear();
	}

	bool ValidarPierdeTurno(cCartas * carta)
	{
		if (carta->getTipo() == "pierdeTurno")
		{
			if (carta->getColor() == color || carta->getTipo() == pozo->back()->getTipo())
			{
				
				return true;
			}
		}
	}

	bool ValidarComodin(cCartas * carta)
	{
		if (carta->getTipo() == "comodin")
		{
			return true;
		}

	}
	bool ValidarComodinRoba4(cCartas * carta)
	{
		if (carta->getTipo() == "comodinRoba4")
		{
			return true;
		}

	}


	void showCard(BufferedGraphics ^ buffer, Bitmap ^ pic, bool move,int wf,int hf)
	{
		if (move == false)
		{
			carta = pozo->back();
			carta->showCard(wf-35, hf/2.5, buffer, pic,true,pic);
			
		}
		if (move == true)
		{
	
			carta = pozo->at(pozo->size() - 2);
	
			carta->showCard(wf-35, hf/2.5, buffer, pic,true,pic);

			carta = pozo->back();
			y = y - 20;
			carta->showCard(wf-35, y, buffer, pic,true,pic);

		}
		

	

	}

	cMazo * giveCardstoDeck(cMazo *mazo)
	{
		if (pozo->size() > 8)
		{
			for (int i = 0; i < pozo->size()-1; i++)
			{
				mazo->addCard(pozo->at(i));

				pozo->erase(pozo->begin() + i);

			}

			return mazo;
		}
		else return mazo;

	}

	bool verify(bool move,  int wf, int hf)
	{
		if (move == true)
		{
	if (y < 260)
			{
				y = 400;
				return false;
			}
		else return true;
		}
		
	}


	void agregarCarta(cCartas * data)
	{
		if (data->getTipo()!= "comodin" || data->getTipo() != "comodinRoba4")
		{
pozo->push_back(data);
			color = pozo->at(pozo->size() - 1)->getColor();
		}else pozo->push_back(data);
			
		
		

	}

	void setColor(int col)
	{
	 color = col;
	}

	int returnColor()
	{
		return color;
	}

	cCartas * retornarCarta(int i)
	{
		return pozo->at(i);
	}

	int verifyBeginning()
	{
		if (pozo->at(0)->getTipo()=="comodin")
		{
			return 1;
		}else if (pozo->at(0)->getTipo() == "comodinRoba4")
		{
			return 2;
		}
		else if (pozo->at(0)->getTipo() == "cambioSentido")
		{
			return 3;
		}
		else if (pozo->at(0)->getTipo() == "robaDos")
		{
			return 4;
		}
		else if (pozo->at(0)->getTipo() == "pierdeTurno")
		{
			return 5;
		}
	}
	
};