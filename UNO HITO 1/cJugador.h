#pragma once
#include <string>
#include "cCartas.h"
#include <vector>
#include "cCartaEspecial.h"
#include "cMaso.h"
#include <time.h>

using namespace std;
using namespace System;

class cJugador
{
private:
	
	string nombre;
	int N_Cartas = 0, puntaje = 0;
	vector<cCartas*> * cartas;
	cCartas * carta;
	cCartaEspecial * c;
	cMazo * mazo;
	int x = 200, y = 0;
	int icon;
	int time = 0;

public:

	cJugador (string n )
	{

		nombre = n;
		cartas = new vector<cCartas*>;
		carta = new cCartas();
		c = new cCartaEspecial();
		
	}

	~cJugador()
	{
	
	}

	cCartas * getCarta(int i)
	{
		return cartas->at(i);
	}

	void usarCarta(int i)
	{
		
		cartas->erase(cartas->begin()+i);
		N_Cartas = N_Cartas - 1;

	}

	

	void setIcon(int i)
	{
		icon = i;
	}
	cCartas * getLastCard()
	{
		return cartas->back();
	}

	void cogerAgregarCarta(cCartas * data)
	{
		cartas->push_back(data);
		N_Cartas = N_Cartas + 1;

	}

	void setNombre(string name)
	{
		nombre = name;
	}

	void setPuntaje(int p)
	{
		puntaje = p;
	}

	void clearHand()
	{
		cartas->clear();
		N_Cartas = 0;
	}

	string  getNombre()
	{
		return nombre;
	}

	bool verifyTime(double ti)
	{
		time = clock() - ti;

		if (time > 7000)
		{
			return true;
		}

	}

	double getTime()
	{
		int temp;
		if (time > 1000)
		{
			temp = 6;
		}
		if (time < 1000)
		{
			temp = 7;
		}
		if (time > 2000)
		{
			temp = 5;
		}if (time > 3000)
		{
			temp = 4;
		}if (time >4000)
		{
			temp = 3;
		}
		if (time > 5000)
		{
			temp = 2;
		}
		if (time > 6000)
		{
			temp = 1;
		}
		if (time > 7000)
		{
			temp = 0;
		}

		return temp;
	}

	int getNCartas()
	{
		return N_Cartas;
	}

	int getPuntaje()
	{
		return puntaje;
	}

	void setXYs(int w,int h)
	{
		x = w;
		y = h;
		for (int i = 0; i < N_Cartas; i++)
		{
			if (i ==7)
			{
				x = w;
				y = y + 70;
			}

			cartas->at(i)->setXY(x,y);
			
			x = x + 60;
			
			

		}
		
	
	}

	void showPlayerCards(BufferedGraphics ^ buffer, Bitmap ^ pic,Bitmap ^ back, bool turnoVer)
	{
		
		
		
		for (int i = 0; i < N_Cartas; i++)
		{
			carta = cartas->at(i);
			
				carta->showCard(carta->getX(), carta->getY(), buffer, pic,turnoVer,back);

			
			
				
		}
		
		
	}


	void showName(BufferedGraphics ^ buffer,int i,int w, int h)
	{
		Font ^ myfont = gcnew Font("Arial Black", 20);

		buffer->Graphics->DrawString("Player "+(i+1), myfont,Brushes::White, w/20, h/1.5 - 30);

	}

	void moveToUseCard(int i)
	{
		carta = cartas->at(i);
		carta->movetoUse();
	}
	void highlightCard(int i)
	{
		carta = cartas->at(i);
		carta->highlightCard();
	}
	void unHighlightCard(int i)
	{
		carta = cartas->at(i);
		carta->unHighlight();

	}

	Rectangle * getRecs(int i)
	{
		carta = cartas->at(i);

		return  &carta->getRec();
	}
	
	void addPuntaje(cCartas * data)
	{
		puntaje = puntaje + data->getPuntaje();
	}

};