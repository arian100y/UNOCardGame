#pragma once
#include <string>

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


class cCartas
{
protected:
	/*Color  color;*/
	int puntaje;
	int x , y,xpor=0,ypor=0;
	Rectangle size;
	Rectangle portion;
	int Color;
	int numero;
	string  type;
	int temp = 0;
	int x2=0, y2=0;

public:

	cCartas()
	{
		type;
	}

	~cCartas()
	{}

	void setColor(int c)
	{
		Color = c;
	}
	int getColor()
	{
		return Color;
	}
	void setNumero(int n)
	{
		numero = n;
	}
	int getNumero()
	{
		return numero;
	}
	void setPuntaje(int p)
	{
		puntaje = p;
	}
	void setXY(int x1,int  y1)
	{
		x = x1;
		y = y1;
		temp = y1;
	}
	int getPuntaje()
	{
		return puntaje;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void setTipo(string  t)
	{
		type = t;
	}
	string getTipo()
	{
		return type;
	}
	void movetoUse()
	{
		
			

		
	}
	void highlightCard()
	{
		
		
		if (temp == 0 )
		{
temp = y;
		}

		if (y > temp -10)
		{
			y = y - 1;
		}
		
	}

	void unHighlight()
	{

		if (y < temp  )
		{
			y = y + 1;
		}

	}
	void showCard(int x,int y, BufferedGraphics ^ buffer,Bitmap ^ pic,bool turno,Bitmap ^ back)
	{
		if (turno == true)
		{
			size = Rectangle(x, y, 80, 110);
			if (type == "numero")
			{
				if (Color == 0)
				{
					ypor = 0;
				}
				if (Color == 1)
				{
					ypor = 1;
				}
				if (Color == 2)
				{
					ypor = 2;
				}
				if (Color == 3)
				{
					ypor = 3;
				}

				for (int i = 0; i < 10; i++)
				{
					if (numero == i + 1)
					{
						xpor = i;
					}
					if (numero == 0)
					{
						xpor = 9;
					}
				}


				portion = Rectangle(xpor*85.5, ypor * 134, 85, 133);
				buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);

			}

			if (type == "robaDos")
			{
				if (Color == 0)
				{
					ypor = 4;
					xpor = 2;
				}
				if (Color == 1)
				{
					ypor = 4;
					xpor = 5;
				}
				if (Color == 2)
				{
					ypor = 4;
					xpor = 8;
				}
				if (Color == 3)
				{
					ypor = 5;
					xpor = 1;
				}


				portion = Rectangle(xpor*85.5, ypor * 134, 85, 133);
				buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);

			}

			if (type == "cambioSentido")
			{
				if (Color == 0)
				{
					ypor = 4;
					xpor = 1;
				}
				if (Color == 1)
				{
					ypor = 4;
					xpor = 4;
				}
				if (Color == 2)
				{
					ypor = 4;
					xpor = 7;
				}
				if (Color == 3)
				{
					ypor = 5;
					xpor = 0;
				}


				portion = Rectangle(xpor*85.5, ypor * 134, 85, 133);
				buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);
			}
			if (type == "pierdeTurno")
			{
				if (Color == 0)
				{
					ypor = 4;
					xpor = 0;
				}
				if (Color == 1)
				{
					ypor = 4;
					xpor = 3;
				}
				if (Color == 2)
				{
					ypor = 4;
					xpor = 6;
				}
				if (Color == 3)
				{
					ypor = 4;
					xpor = 9;
				}


				portion = Rectangle(xpor*85.5, ypor * 134, 85, 133);
				buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);
			}
			if (type == "comodin")
			{
				ypor = 5;
				xpor = 3;

				portion = Rectangle(xpor*85.5, ypor * 134, 85, 135);
				buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);

			}

			if (type == "comodinRoba4")
			{
				ypor = 5;
				xpor = 4;

				portion = Rectangle(xpor*85.5, ypor * 134, 85, 135);
				buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);

			}
		}
		if (turno == false)
		{
			size = Rectangle(x, y, 80, 110);
			buffer->Graphics->DrawImage(back, size);
		}

	}

	Rectangle getRec()
	{
		return size;
	}
	
	void MoveCardsBeginning(BufferedGraphics ^ buffer, Bitmap ^ pic,int i)
	{
		size = Rectangle(x2, y2, 50, 80);

		if (type == "numero")
		{
			if (Color == 0)
			{
				ypor = 0;
			}
			if (Color == 1)
			{
				ypor = 1;
			}
			if (Color == 2)
			{
				ypor = 2;
			}
			if (Color == 3)
			{
				ypor = 3;
			}

			for (int i = 0; i < 10; i++)
			{
				if (numero == i + 1)
				{
					xpor = i;
				}
				if (numero == 0)
				{
					xpor = 9;
				}
			}

			size = Rectangle(x, y, 50, 80);
			portion = Rectangle(xpor*85.5, ypor * 134, 85, 133);
		
			
			
		}

		if (type == "robaDos")
		{
			if (Color == 0)
			{
				ypor = 4;
				xpor = 2;
			}
			if (Color == 1)
			{
				ypor = 4;
				xpor = 5;
			}
			if (Color == 2)
			{
				ypor = 4;
				xpor = 8;
			}
			if (Color == 3)
			{
				ypor = 5;
				xpor = 1;
			}

			size = Rectangle(x, y, 50, 80);
			portion = Rectangle(xpor*85.5, ypor * 134, 85, 133);
			buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);

		}

		if (type == "cambioSentido")
		{
			if (Color == 0)
			{
				ypor = 4;
				xpor = 1;
			}
			if (Color == 1)
			{
				ypor = 4;
				xpor = 4;
			}
			if (Color == 2)
			{
				ypor = 4;
				xpor = 7;
			}
			if (Color == 3)
			{
				ypor = 5;
				xpor = 0;
			}

			size = Rectangle(x2, y2, 50, 80);
			portion = Rectangle(xpor*85.5, ypor * 134, 85, 133);
			buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);
			
		}
		if (type == "pierdeTurno")
		{
			if (Color == 0)
			{
				ypor = 4;
				xpor = 0;
			}
			if (Color == 1)
			{
				ypor = 4;
				xpor = 3;
			}
			if (Color == 2)
			{
				ypor = 4;
				xpor = 6;
			}
			if (Color == 3)
			{
				ypor = 4;
				xpor = 9;
			}

			size = Rectangle(x, y, 50, 80);
			portion = Rectangle(xpor*85.5, ypor * 134, 85, 133);
			buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);
		}
		if (type == "comodin")
		{
			ypor = 5;
			xpor = 3;
			size = Rectangle(x, y, 50, 80);
			portion = Rectangle(xpor*85.5, ypor * 134, 85, 135);
			buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);
			
		}
		size = Rectangle(x2, y2, 50, 80);
		buffer->Graphics->DrawImage(pic, size, portion, GraphicsUnit::Pixel);
		x2 = x2 + 10 + (i*30);
		y2 = y2 + 50;

	}


	int verify(int h)
	{
		
		if (y2 > h/2)
		{
			return 1;
		}
		else return 0;
		
	}

};