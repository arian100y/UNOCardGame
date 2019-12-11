#pragma once
#include <string>
#include <vector>
#include "cCartas.h"
#include "cCartaEspecial.h"
#include "cCartaNumero.h"
#include <algorithm> 
#include <time.h>

struct RNG {
	int operator() (int n) {
		return std::rand() / (1.0 + RAND_MAX) * n;
	}
};

using namespace std;
using namespace System::Drawing;

class cMazo
{
private:
	int cantidad;
	vector<cCartas*> * cartas;
	int x= 200;
	cCartas * carta;
	int j = 0;
	int color = 0;
	Rectangle size;
	Rectangle sizeMazo;
	Rectangle portion2;
	bool  done= false;
	int xpor = 9, ypor = 6;
	
public:

	cMazo()
	{
		
		cartas = new vector<cCartas*>;
		
		for (int i = 0; i < 56; i++)
		{
			if (i < 40)
			{
				carta = new cCartaNumero();
				carta->setTipo("numero");

				if (j == 10)
				{
					j = 0;
					color = color + 1;
				}
				carta->setPuntaje(j);
				carta->setNumero(j);
				carta->setColor(color);


				j = j + 1;

			}
		
			if( i > 39 && i < 44)
			{
				if (i == 40)
				{
					color = 0;
					done = true;
				}
				
				carta = new cCartaEspecial();
				carta->setColor(color);
				carta->setTipo("pierdeTurno");
				carta->setPuntaje(20);
				color = color + 1;
				
			}

			if (i<48 && i > 43)
			{
				if (i == 44)
				{
					color = 0;
					done = true;
				}

				carta = new cCartaEspecial();
				carta->setColor(color);
				carta->setTipo("robaDos");
				carta->setPuntaje(20);
				color = color + 1;

			}
			if (47 < i && i<52)
			{
				if (i == 48)
				{
					color = 0;
					done = true;
				}
				carta = new cCartaEspecial();
				carta->setColor(color);
				carta->setTipo("cambioSentido");
				carta->setPuntaje(20);
				color = color + 1;

			}
			if (51 < i && i<54)
			{
				
				carta = new cCartaEspecial();
				carta->setColor(NULL);
				carta->setTipo("comodin");
				carta->setPuntaje(50);
				

			}
			if (53 < i && i<56)
			{

				carta = new cCartaEspecial();
				carta->setColor(NULL);
				carta->setTipo("comodinRoba4");
				carta->setPuntaje(50);


			}
			
			
			
			cartas->push_back(carta);
			
			x = x + 60;
			
		}
			

		
		

	}
	~cMazo()
	{}


	void getCardsPlayers(cCartas * data)
	{
		cartas->push_back(data);
	}
	void showMazo(BufferedGraphics ^ buffer, Bitmap ^ pic, int wf,int hf)
	{
		sizeMazo = Rectangle(wf/2-112, hf/2.5, 80, 110);
		portion2 = Rectangle(xpor*85.5, ypor * 134, 85, 133);
	
		buffer->Graphics->DrawImage(pic, sizeMazo,portion2,GraphicsUnit::Pixel);

	}
	Rectangle getSizeMazo()
	{
		return sizeMazo;
	}

	cCartas * repartirCartas(int i)
	{
		
		
			return cartas->at(i);
	
		
	}

	void deleteCard()
	{
		cartas->erase(cartas->begin());
	}

	void deleteTemp()
	{
		cartas->erase(cartas->begin() + pos);
	}

	void setCantidad(int c)
	{}

	int getCantidad()
	{}

	void addCard(cCartas * data)
	{
		cartas->push_back(data);
	}

	void mezclarMazo()
	{
		srand(time(0));
		cCartas * tempcard;
		random_shuffle(cartas->begin(), cartas->end());
	}
	int pos;
	
	cCartas * repartirNumberCard()
	{
		for (int i = 0; i < 54; i++)
		{
			if (cartas->at(i)->getTipo()== "numero")
			{
				pos = i;
				return cartas->at(i);
				

			}

		}
	}


};