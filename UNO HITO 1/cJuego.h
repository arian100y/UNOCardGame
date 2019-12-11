#pragma once
#include "cMaso.h"
#include "cJugador.h"
#include <vector>
#include "cPozo.h"
#include <string>

using namespace std;


class cJuego
{
private:
	int turno = 0;
	cMazo mazo;
	vector<cJugador*> * jugadores;
	cJugador * player;
	Rectangle size;
	Rectangle portion;
	int porx=5, pory=5;
	int sentido=1;
	int x=0, y=0;
	cPozo  *pozo;
	Rectangle Yes;
	Rectangle No;
	int color=0;
	int xA = 1;
	int stage = 1;

public:

	cJuego(int n,string namez,int width, int height)
	{
		
		
		
		jugadores = new vector<cJugador*>;
		for (int i = 0; i < n; i++)
		{
			player = new cJugador(namez);
			jugadores->push_back(player);
		}
		Yes = Rectangle(width / 3, height / 1.6, 100, 100);
		No = Rectangle(width / 2, height / 1.6, 100, 100);

	}

	~cJuego()
	{}

	void setXYSplayers(int width, int height)
	{

				jugadores->at(0)->setXYs(width/3, height/1.3);

			
		for (int i = 1; i < jugadores->size(); i++)
		{
			if (jugadores->size() == 2)
			{
				if (i == 1)
				{

				jugadores->at(i)->setXYs(width/3, height/10);

				}
			}
			if (jugadores->size() == 3)
			{
				if (i == 1)
				{

					jugadores->at(i)->setXYs(width /20, height / 2 - 30);

				}
				if (i == 2)
				{

					jugadores->at(i)->setXYs(width / 1.5, height / 2-30);

				}
			}

			if (jugadores->size() == 4)
			{
				if (i == 1)
				{

					jugadores->at(i)->setXYs(width / 20, height / 2 - 30);

				}
				if (i == 2)
				{

					jugadores->at(i)->setXYs(width / 3, height / 10);

				}
				if (i == 3)
				{

					jugadores->at(i)->setXYs(width / 1.5, height / 2 - 30);

				}
			}
			
			if (jugadores->size() == 5)
			{
				if (i == 1)
				{

					jugadores->at(i)->setXYs(width / 20, height / 2 - 30);

				}
				if (i == 2)
				{

					jugadores->at(i)->setXYs(width / 20, height / 10);

				}
				if (i == 3)
				{

					jugadores->at(i)->setXYs(width / 1.5, height /10);

				}
				if (i == 4)
				{

					jugadores->at(i)->setXYs(width / 1.5, height / 2 - 30);

				}
			}

		}
	}

	void showALL(BufferedGraphics ^ buffer, Bitmap ^ pic, Bitmap ^ back)
	{
		bool tempturn;
		for (int i = 0; i < jugadores->size(); i++)
		{
			if (i != turno)
			{
				tempturn = false;
			}
			else tempturn = true;
			jugadores->at(i)->showPlayerCards(buffer,pic,back,tempturn);
		}
	}

	void showPuntaje(BufferedGraphics ^ buffer,int wi, int hei)
	{
		System::Drawing::Font ^ font = gcnew System::Drawing::Font("Arial Black", 20);
		buffer->Graphics->DrawString("Puntaje: "+jugadores->at(turno)->getPuntaje(), font, Brushes::White, wi/20, hei/1.5);

	}

	void showCardNs(BufferedGraphics ^ buffer, Bitmap ^ white)
	{
		y = 50;
		System::Drawing::Font ^ font2 = gcnew System::Drawing::Font("Comic Sans MS", 20);
		for (int i = 0; i < jugadores->size(); i++)
		{
			

			buffer->Graphics->DrawString(Convert::ToString( jugadores->at(i)->getNCartas()), font2, Brushes::Orange, 1100, y);
			buffer->Graphics->DrawImage(white, 1100, y, 20, 30);
			y = y + 30;
		}
	}

	
	void showPlayersScores(BufferedGraphics ^ buffer,int w, int h)
	{
		y = h/1.25;
		System::Drawing::Font ^ font = gcnew System::Drawing::Font("Comic Sans MS", 20);
		
		
		for (int i = 0; i < jugadores->size(); i++)
		{
			buffer->Graphics->DrawString("Player "+(i+1) + " : " +jugadores->at(i)->getPuntaje(), font, Brushes::Orange, w/1.34, y);
		
			/*buffer->Graphics->DrawString(Convert::ToString( jugadores->at(i)->getNCartas()), font2, Brushes::Orange, 1100, y);*/
			/*buffer->Graphics->DrawImage(white, 1100, y, 20, 30);*/
			y = y + 30;
		}

	}
	void showTime(BufferedGraphics ^ buffer,int heigh, int width)
	{
		System::Drawing::Font ^ font = gcnew System::Drawing::Font("IMPACT", 80);
		buffer->Graphics->DrawString(Convert::ToString( jugadores->at(turno)->getTime()), font, Brushes::YellowGreen, width/1.5, heigh/1.5);

		
	}
	int getStage()
	{
		return stage;
	}
	void setPozo(cPozo * data)
	{
		pozo = data;
	}
	bool validateMazoCard(cJugador * player)
	{
		if (pozo->ValidarJugada(player->getLastCard()) == true || pozo->ValidarRobaDos(player->getLastCard()) == true || pozo->ValidarCambioSentido(player->getLastCard()) == true || pozo->ValidarComodin(player->getLastCard()) == true || pozo->ValidarPierdeTurno(player->getLastCard()) == true || pozo->ValidarComodinRoba4(player->getLastCard()) == true)
		{
			return true;
		}

	}
	void drawArrow(int width, int height, BufferedGraphics ^ buffer, Bitmap ^ pic)
	{
		if (sentido == -1)
		{
			size = Rectangle(width/1.15, height/1.5, 150, 110);
			if (pory < 6)
			{
				pory = 6;
			}
			portion = Rectangle(porx * 130, pory * 60, 143, 60);

			buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);

			porx = porx + 1;
			if (pory == 11)
			{
				pory = 6;
			}
			if (porx == 6)
			{
				porx = 0;
				pory = pory + 1;
			}

			

		}
		if (sentido == 1)
		{
			size = Rectangle(width / 1.15, height / 1.5, 150, 110);
			portion = Rectangle(porx * 130, pory * 60, 143, 60);

			buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);

			porx = porx - 1;
			if (pory == 0)
			{
				pory = 5;
			}
			if (porx == 0)
			{
				porx = 5;
				pory = pory - 1;
			}
		}
	
		

	}
	bool animacionMas(BufferedGraphics ^ buffer,int width, int height,int num)
	{
		

		System::Drawing::Font ^ font = gcnew System::Drawing::Font("Arial Black", xA);
		buffer->Graphics->DrawString("+"+Convert::ToString(num), font, Brushes::White, width / 3, height / 1.6);

		xA = xA + 3;

		if (xA > 60)
		{
			xA = 1;
			return false;
		}
		else return true;
	}
	
	bool animacionPierdeTurno(BufferedGraphics ^ buffer,int width, int height)
	{


		System::Drawing::Font ^ font = gcnew System::Drawing::Font("Arial Black", xA);
		buffer->Graphics->DrawString("Pierde Turno", font, Brushes::White, width / 3, height / 1.6);

		xA = xA + 3;

		if (xA > 60)
		{
			xA = 1;
			return false;
		}
		else return true;
	}

	int obtenerTurno()
	{
		return turno;
	}

	void cambioTurno(int i)
	{
		sentido = sentido * i;
		
		
			turno = turno + sentido;
		


		if (turno == jugadores->size())
		{
			turno = 0;
		}else 

		if (turno<0)
		{
			turno = jugadores->size()-1;

		}


	}
	void setTurno(int who)
	{
		turno = who;
		if (turno == jugadores->size())
		{
			turno = 0;
		}
		else

			if (turno<0)
			{
				turno = jugadores->size() - 1;

			}
	}
	int getNJugadores()
	{
		return jugadores->size();
	}

	void setMaso(cMazo * data)
	{

	}

	

	void setIcons()
	{
		for (int i = 0; i < jugadores->size(); i++)
		{
			jugadores->at(i)->setIcon(i + 1);
		}
	}

	cMazo getMaso()
	{}

	int verifyWinner()
	{
		for (int i = 0; i < jugadores->size(); i++)
		{
			if (jugadores->at(i)->getPuntaje()> 500 || jugadores->at(i)->getPuntaje()== 500)
			{
				return i;
			}
			
		}
		return 0;
	}
	bool verifyPartida()
	{
		for (int i = 0; i < jugadores->size(); i++)
		{
		
			if (jugadores->at(i)->getNCartas() == 0)
			{
				return true;
			}
		}

	}


	void showColor(BufferedGraphics ^ buffer, Bitmap ^ pic, int col,int height,int width)
	{
		if (col == 0)
		{
			portion = Rectangle(5, 5, 200, 200);
		}
		if (col == 3)
		{
			portion = Rectangle(200, 0, 200, 200);
		}
		if (col == 2)
		{
			portion = Rectangle(0, 200, 200, 200);
		}
		if (col == 1)
		{
			portion = Rectangle(200, 200, 200, 200);
		}

		size = Rectangle(width/20, height/1.3, 100, 100);
		System::Drawing::Font ^ font = gcnew System::Drawing::Font("Arial Black", 10);

	
		buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);

	}
	cPozo getPozo()
	{}

	cJugador * getJugador(int i)
	{

		return jugadores->at(i);
	
	}


	int fontSize = 1;

	void showRepartidor(BufferedGraphics ^ buffer,int width, int height)
	{
		if (fontSize< 30)
		{
			fontSize = fontSize + 3;
		}
		System::Drawing::Font ^ font = gcnew System::Drawing::Font("Arial Black", fontSize);
		buffer->Graphics->DrawString("Repartira el jugador " + (turno + 1), font, Brushes::White, width/3.2, height/20);
	}

	Rectangle getSi()
	{
		return Yes;
	}
	Rectangle getNO()
	{
		return No;
	}

	void showYesNO(BufferedGraphics ^ buffer,int width, int height)
	{
		
		System::Drawing::Font ^ font = gcnew System::Drawing::Font("Comic Sans MS", 20);
		buffer->Graphics->DrawString("DESEA JUGAR LA CARTA?", font, Brushes::Yellow, width/3, height/1.8);

		buffer->Graphics->DrawString("SI", font, Brushes::Red, Yes);
		buffer->Graphics->DrawString("NO", font, Brushes::Red, No);
	}

};