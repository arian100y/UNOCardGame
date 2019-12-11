#pragma once
#include <iostream>
#include "cCartas.h"
#include "cJugador.h"
#include "cMaso.h"
#include <string>
#include <vector>
#include <array>
#include "cJuego.h"
#include <typeinfo>
#include <ctime>


namespace UNOHITO1 {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			sprites = gcnew Bitmap("images\\sprites.png");
			arrow = gcnew Bitmap("images\\arrow.png");
			background = gcnew Bitmap("images\\bak.jpg");
			foldedCard = gcnew Bitmap("images\\back.png");
			colors2 = gcnew Bitmap("images\\colors2.png");
			graficador = this->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(graficador, ClientRectangle);
			cobj = new cCartas();
			mazo = new cMazo();
			pozo = new cPozo();
			UNO = gcnew Bitmap("images\\UNO.png");
			sound = gcnew Media::SoundPlayer("sounds\\llzz.wav");
			t3 = NULL;
			colors = gcnew Bitmap("images\\colors.png");
			white = gcnew Bitmap("images\\whitecard.png");
			 red = Rectangle(this->Width / 3, this->Height / 2, 150, 150);
			 blue = Rectangle(this->Width / 2.5, this->Height / 2, 150, 150);
			 green = Rectangle(this->Width / 2.1, this->Height / 2, 150, 150);
			 yellow = Rectangle(this->Width / 1.8, this->Height / 2, 150, 150);
			
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 


	private: System::ComponentModel::IContainer^  components;
			 Rectangle red;
			 Rectangle blue;
			 Rectangle green;
			 Rectangle yellow;
			 Graphics ^ graficador;
			 BufferedGraphics ^ buffer;
			 BufferedGraphicsContext ^ espacio;
			 Bitmap ^ sprites;
			 Bitmap ^ foldedCard;
			 Bitmap ^ colors;
			 int t3;
			 Bitmap ^ colors2;
	private: System::Windows::Forms::Timer^  timer1;
			 Bitmap ^ background;
			 Bitmap ^ arrow;
			 Bitmap ^ white;
			 Bitmap ^ UNO;
	
			
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::Button^  button1;
			 Media::SoundPlayer ^ sound;
			 int * playerscores;

			 cPozo * pozo;
			 cJugador * player;
			 cJuego * game;
			 cCartas * cobj;

	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Timer^  interlude;
	private: System::Windows::Forms::Timer^  timer4;
			 cMazo * mazo;

		/// <summary>
		/// Required designer variable.
		/// </summary>

		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->interlude = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick_1);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(300, 300);
			this->maskedTextBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->maskedTextBox1->Mask = L"00000";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox1->TabIndex = 1;
			this->maskedTextBox1->ValidatingType = System::Int32::typeid;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(689, 645);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Enabled = true;
			this->timer3->Interval = 20;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// interlude
			// 
			this->interlude->Enabled = true;
			this->interlude->Tick += gcnew System::EventHandler(this, &MyForm::interlude_Tick);
			// 
			// timer4
			// 
			this->timer4->Enabled = true;
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1348, 721);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->maskedTextBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		int X=50, Y=200;
		
#pragma endregion
	private:	

			 Rectangle ^ rec = gcnew Rectangle(X, Y, 60, 90);
			 bool used = false;
			 bool move = false;
			bool gamestart = true;
			int xpor = 0;

			

			
			
			bool mas2Animacion = false;
			bool pierdeTurnoAnimacion = false;
			double time;
			int mascuanto;

private: System::Void timer1_Tick_1(System::Object^  sender, System::EventArgs^  e) {
		
		buffer->Graphics->Clear(Color::White);


		buffer->Graphics->DrawImage(background, 0, 0, this->Width,this->Height);
		//da cartas al mazo del pozo

		pozo->giveCardstoDeck(mazo);
	
		
		if (colorChangee == true)
		{
			
			xpor = 0;
			
			Rectangle por = Rectangle(10, 0, 200, 200);
			buffer->Graphics->DrawImage(colors, red,por,GraphicsUnit::Pixel);
			
			Rectangle por1 = Rectangle(200, 0, 200, 200);
			buffer->Graphics->DrawImage(colors, blue, por1, GraphicsUnit::Pixel);
			
			Rectangle por2 = Rectangle(390 , 0, 200, 200);
			buffer->Graphics->DrawImage(colors, green, por2, GraphicsUnit::Pixel);
			Rectangle por3 = Rectangle(580, 0, 200, 200);
			buffer->Graphics->DrawImage(colors,yellow, por3, GraphicsUnit::Pixel);

		}

		if (gamestart == true)
		{
			time = clock();

			if (pozo->verifyBeginning() == 1)
			{
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());
				colorChangee = true;
				gamestart = false;

			}
			else if (pozo->verifyBeginning() == 2)
			{
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());

				for (int i = 0; i < 4; i++)
				{
					player->cogerAgregarCarta(mazo->repartirCartas(0));
					mazo->deleteCard();
				}


				
				game->setXYSplayers(Width, Height);
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());
				colorChangee = true;
			}
			else if (pozo->verifyBeginning() == 3)
			{
				game->cambioTurno(-1);
			}
			else if (pozo->verifyBeginning() == 4)
			{
				
				player = game->getJugador(game->obtenerTurno());

				for (int i = 0; i < 2; i++)
				{
					player->cogerAgregarCarta(mazo->repartirCartas(0));
					mazo->deleteCard();
				}


		
				game->setXYSplayers(Width, Height);
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());

			}
			else if (pozo->verifyBeginning() == 5)
			{
				game->cambioTurno(1);
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());
			}
			gamestart = false;

		}

		if (verifyMazo== true)
		{
			game->setPozo(pozo);
			if (game->validateMazoCard(player)==true)
			{
				game->showYesNO(buffer,Width,Height);

			}
			else
			{

				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());
				verifyMazo = false;
				game->setXYSplayers(Width, Height);
				time = clock();
			}
				

			
		}

		if (mas2Animacion == true)
		{
			mas2Animacion = game->animacionMas(buffer,Width,Height,mascuanto);
		}
		if (pierdeTurnoAnimacion == true)
		{
			pierdeTurnoAnimacion = game->animacionPierdeTurno(buffer,Width,Height);
		}



	if (game->getJugador(game->obtenerTurno())->verifyTime(time) == true)
		{

			colorChangee = false;
			verifyMazo = false;
			player->cogerAgregarCarta(mazo->repartirCartas(0));
			mazo->deleteCard();

			game->setXYSplayers(Width, Height);
			game->cambioTurno(1);
			time = clock();
			mas2Animacion = true;
			mascuanto = 1;
			player = game->getJugador(game->obtenerTurno());
			
		}

		game->showALL(buffer, sprites,foldedCard);
		game->showTime(buffer,Height,Width);
	
		game->showPlayersScores(buffer,Width,Height);
		game->showColor(buffer,colors2,pozo->returnColor(),Height,Width);

		game->showPuntaje(buffer,this->Width,this->Height);
pozo->showCard(buffer, sprites,move,this->Width/2,this->Height);

move = pozo->verify(move,Width,Height);

if (game->verifyPartida() == true && gamestart == false)
{
	for (int i = 0; i < game->getNJugadores(); i++)
	{
		playerscores[i] = game->getJugador(i)->getPuntaje();
	}

	/*timer1->Stop();
	running = false;
	cobj = new cCartas();
	mazo = new cMazo();
	pozo = new cPozo();
	cJugador * player;
	running = false;
	game = new cJuego(Njugadores,"",Width,Height);
	mazo->mezclarMazo();
	t3 = NULL;
	for (int i = 0; i < Njugadores; i++)
	{
		player = game->getJugador(i);

		player->cogerAgregarCarta(mazo->repartirNumberCard());
		mazo->deleteTemp();

	}

	time = clock();
	stage = 1;
	
	interlude->Start();*/
	//new
	move = false;
	pozo->clearPozo();
	for (int i = 0; i < game->getNJugadores(); i++)
	{
		for (int j = 0; j < game->getJugador(i)->getNCartas(); j++)
		{
			mazo->getCardsPlayers(game->getJugador(i)->getCarta(j));
			
		}
	}

	for (int i = 0; i < game->getNJugadores(); i++)
	{
		game->getJugador(i)->clearHand();
	}

	for (int i = 0; i < game->getNJugadores(); i++)
	{
		player = game->getJugador(i);

		for (int j = 0; j < 7; j++)
		{

			player->cogerAgregarCarta(mazo->repartirCartas(0));
			mazo->deleteCard();

		}
	}
	verifyMazo = false;
	colorChangee = false;
	gamestart = true;
	mas2Animacion = false;
	pierdeTurnoAnimacion = false;
	running = false;
	pozo->agregarCarta(mazo->repartirCartas(0));
	mazo->deleteCard();
	game->setXYSplayers(Width, Height);
	player = game->getJugador(game->obtenerTurno());
	timer1->Stop();
	interlude->Start();

}
if (game->verifyWinner() > 0)
{
	ganador = game->verifyWinner();
	timer1->Stop();
	timer4->Start();

}

		mazo->showMazo(buffer, sprites,this->Width,this->Height);
		game->drawArrow(this->Width,this->Height,buffer,arrow);
		player->showName(buffer,game->obtenerTurno(),Width,Height);
	


		
		buffer->Render(graficador);
		

	}

	private: bool colorChangee = false;
			 bool roba4;
				 bool verifyMazo = false;

private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Point ^ mousePt = gcnew Point(e->X, e->Y);


	if (running==true && colorChangee == false && verifyMazo == false) // for cards click
	{
	
			for (int i = 0; i < player->getNCartas(); i++)
			{

				if (player->getRecs(i)->Contains(*mousePt))
				{
					
					

					
					if (pozo->ValidarJugada(player->getCarta(i)) == true)
					{
						move = true;
						pozo->agregarCarta(player->getCarta(i));
						
						player->addPuntaje(player->getCarta(i));
						player->usarCarta(i);
						
						game->setXYSplayers(Width, Height);
						game->cambioTurno(1);
						player = game->getJugador(game->obtenerTurno());
						time = clock();

					}else
					if (pozo->ValidarRobaDos(player->getCarta(i))==true)
					{
						pozo->agregarCarta(player->getCarta(i));
						move = true;
						player->addPuntaje(player->getCarta(i));
						player->usarCarta(i);
						
						game->setXYSplayers(Width, Height);
						game->cambioTurno(1);
						player = game->getJugador(game->obtenerTurno());

						for (int i = 0; i < 2; i++)
						{
							player->cogerAgregarCarta(mazo->repartirCartas(0));
							mazo->deleteCard();
						}
						
							
				
						game->setXYSplayers(Width, Height);
						game->cambioTurno(1);
						player = game->getJugador(game->obtenerTurno());
						game->setXYSplayers(Width, Height);
						sound->Play();
						mas2Animacion = true;
						mascuanto = 2;
						time = clock();

					}else
						if (pozo->ValidarCambioSentido(player->getCarta(i)) == true)
						{
							move = true;
							pozo->agregarCarta(player->getCarta(i));
							player->addPuntaje(player->getCarta(i));
							player->usarCarta(i);
							
							game->setXYSplayers(Width, Height);

							game->cambioTurno(-1);
							player = game->getJugador(game->obtenerTurno());
							sound->Play();
							time = clock();
							game->setXYSplayers(Width, Height);
						}else
							if (pozo->ValidarPierdeTurno(player->getCarta(i))==true)
							{
								move = true;
								pozo->agregarCarta(player->getCarta(i));
								player->addPuntaje(player->getCarta(i));
								player->usarCarta(i);
								
								game->setXYSplayers(Width, Height);
								game->cambioTurno(1);
								game->cambioTurno(1);
								player = game->getJugador(game->obtenerTurno());
								
								game->setXYSplayers(Width, Height);
								sound->Play();
								pierdeTurnoAnimacion = true;
								time = clock();

							}else
								if (pozo->ValidarComodin(player->getCarta(i)) == true)
								{
									pozo->agregarCarta(player->getCarta(i));
									player->addPuntaje(player->getCarta(i));
									player->usarCarta(i);
							
									game->setXYSplayers(Width, Height);
									colorChangee = true;
									
								}else 
									
										if (pozo->ValidarComodinRoba4(player->getCarta(i)) == true)
										{
											if (pozo->verifyRoba4(player) == false)
											{
												pozo->agregarCarta(player->getCarta(i));
												player->addPuntaje(player->getCarta(i));
												player->usarCarta(i);

												game->setXYSplayers(Width, Height);
												colorChangee = true;

												roba4 = true;
											}

										}
									
									
					
					
					

				}
				
			}

			if (mazo->getSizeMazo().Contains(*mousePt))
			{
				player->cogerAgregarCarta(mazo->repartirCartas(0));
				mazo->deleteCard();
				
				game->setXYSplayers(Width, Height);
				verifyMazo = true;
				
			}

		



	}
		
	if (running == true && colorChangee == true)
	{
		if (red.Contains(*mousePt))
		{
			if (roba4 == false)
			{
pozo->setColor(0);
			
			game->setXYSplayers(Width, Height);
			game->cambioTurno(1);
			player = game->getJugador(game->obtenerTurno());
			
			ontopof = false;
			colorChangee = false;
			time = clock();

			}
			else
			{
				pozo->setColor(0);

				game->setXYSplayers(Width, Height);
				
				player = game->getJugador(game->obtenerTurno());
				ontopof = false;
				colorChangee = false;
				time = clock();
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());

				for (int i = 0; i < 4; i++)
				{
					player->cogerAgregarCarta(mazo->repartirCartas(0));
					mazo->deleteCard();
				}

				mas2Animacion = true;
				mascuanto = 4;
				
				game->setXYSplayers(Width, Height);
				game->cambioTurno(1);

				player = game->getJugador(game->obtenerTurno());
				roba4 = false;
			}
			
		}
		if (blue.Contains(*mousePt))
		{
			if (roba4 == false)
			{
pozo->setColor(3);
			
			game->setXYSplayers(Width, Height);
			game->cambioTurno(1);
			player = game->getJugador(game->obtenerTurno());
			ontopof = false;
			colorChangee = false;
			time = clock();
			}
			else
			{
				pozo->setColor(3);

				game->setXYSplayers(Width, Height);
				
				player = game->getJugador(game->obtenerTurno());
				ontopof = false;
				colorChangee = false;
				time = clock();
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());

				for (int i = 0; i < 4; i++)
				{
					player->cogerAgregarCarta(mazo->repartirCartas(0));
					mazo->deleteCard();
				}

				mas2Animacion = true;
				mascuanto = 4;
				
				game->setXYSplayers(Width, Height);
				game->cambioTurno(1);

				player = game->getJugador(game->obtenerTurno());
				roba4 = false;
			}
			
		}
		if (green.Contains(*mousePt))
		{
			if (roba4 == false)
			{
pozo->setColor(2);
			
			game->setXYSplayers(Width, Height);
			game->cambioTurno(1);
			player = game->getJugador(game->obtenerTurno());
			ontopof = false;
			colorChangee = false;
			time = clock();
			}
			else
			{
				pozo->setColor(2);

				game->setXYSplayers(Width, Height);
			
				player = game->getJugador(game->obtenerTurno());
				ontopof = false;
				colorChangee = false;
				time = clock();
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());

				for (int i = 0; i < 4; i++)
				{
					player->cogerAgregarCarta(mazo->repartirCartas(0));
					mazo->deleteCard();
				}

				mas2Animacion = true;
				mascuanto = 4;
				
				game->setXYSplayers(Width, Height);
				game->cambioTurno(1);

				player = game->getJugador(game->obtenerTurno());
				roba4 = false;
			}
			
		}
		if (yellow.Contains(*mousePt))
		{
			if (roba4 == false)
			{
pozo->setColor(1);
			
			game->setXYSplayers(Width, Height);
			game->cambioTurno(1);
			player = game->getJugador(game->obtenerTurno());
			ontopof = false;
			colorChangee = false;
			time = clock();
			}
			else
			{
				pozo->setColor(1);

				game->setXYSplayers(Width, Height);
				
				player = game->getJugador(game->obtenerTurno());
				ontopof = false;
				colorChangee = false;
				time = clock();
				game->cambioTurno(1);

				player = game->getJugador(game->obtenerTurno());

				for (int i = 0; i < 4; i++)
				{
					player->cogerAgregarCarta(mazo->repartirCartas(0));
					mazo->deleteCard();
				}

				mas2Animacion = true;
				mascuanto = 4;
	
				game->setXYSplayers(Width, Height);
				game->cambioTurno(1);

				player = game->getJugador(game->obtenerTurno());
				
				roba4 = false;
			}
			
		}
		
		
	}

	if (running == true && verifyMazo == true)
	{
		Rectangle Yes;
		Rectangle No;
		Yes = game->getSi();
		No = game->getNO();

		if (Yes.Contains(*mousePt))
		{
			if (pozo->ValidarJugada(player->getCarta(player->getNCartas() - 1)) == true)
			{
				move = true;
				pozo->agregarCarta(player->getCarta(player->getNCartas() - 1));

				player->addPuntaje(player->getCarta(player->getNCartas() - 1));
				player->usarCarta(player->getNCartas() - 1);

				game->setXYSplayers(Width, Height);
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());
				time = clock();

			}
			else
				if (pozo->ValidarRobaDos(player->getCarta(player->getNCartas() - 1)) == true)
				{
					pozo->agregarCarta(player->getCarta(player->getNCartas() - 1));
					move = true;
					player->addPuntaje(player->getCarta(player->getNCartas() - 1));
					player->usarCarta(player->getNCartas() - 1);

					game->setXYSplayers(Width, Height);
					game->cambioTurno(1);
					player = game->getJugador(game->obtenerTurno());

					for (int i = 0; i < 2; i++)
					{
						player->cogerAgregarCarta(mazo->repartirCartas(0));
						mazo->deleteCard();
					}



					game->setXYSplayers(Width, Height);
					game->cambioTurno(1);
					player = game->getJugador(game->obtenerTurno());
					game->setXYSplayers(Width, Height);
					sound->Play();
					mas2Animacion = true;
					mascuanto = 2;
					time = clock();

				}
				else
					if (pozo->ValidarCambioSentido(player->getCarta(player->getNCartas() - 1)) == true)
					{
						move = true;
						pozo->agregarCarta(player->getCarta(player->getNCartas() - 1));
						player->addPuntaje(player->getCarta(player->getNCartas() - 1));
						player->usarCarta(player->getNCartas() - 1);

						game->setXYSplayers(Width, Height);

						game->cambioTurno(-1);
						player = game->getJugador(game->obtenerTurno());
						sound->Play();
						time = clock();
						game->setXYSplayers(Width, Height);
					}
					else
						if (pozo->ValidarPierdeTurno(player->getCarta(player->getNCartas() - 1)) == true)
						{
							move = true;
							pozo->agregarCarta(player->getCarta(player->getNCartas() - 1));
							player->addPuntaje(player->getCarta(player->getNCartas() - 1));
							player->usarCarta(player->getNCartas() - 1);

							game->setXYSplayers(Width, Height);
							game->cambioTurno(1);
							game->cambioTurno(1);
							player = game->getJugador(game->obtenerTurno());

							game->setXYSplayers(Width, Height);
							sound->Play();
							pierdeTurnoAnimacion = true;
							time = clock();

						}
						else
							if (pozo->ValidarComodin(player->getCarta(player->getNCartas() - 1)) == true)
							{
								pozo->agregarCarta(player->getCarta(player->getNCartas() - 1));
								player->addPuntaje(player->getCarta(player->getNCartas() - 1));
								player->usarCarta(player->getNCartas() - 1);

								game->setXYSplayers(Width, Height);
								colorChangee = true;

							}
							else
								if (pozo->ValidarComodinRoba4(player->getCarta(player->getNCartas()-1)) == true)
								{
									pozo->agregarCarta(player->getCarta(player->getNCartas() - 1));
									player->addPuntaje(player->getCarta(player->getNCartas() - 1));
									player->usarCarta(player->getNCartas() - 1);

									game->setXYSplayers(Width, Height);
									colorChangee = true;

									roba4 = true;


								}
			
								
								verifyMazo = false;
								
		}
		else
			if (No.Contains(*mousePt))
			{
				game->cambioTurno(1);
				player = game->getJugador(game->obtenerTurno());
				mas2Animacion = true;
				mascuanto = 1;
				verifyMazo = false;
				time = clock();
			}

	}
	
}

		 
		 private: float t;
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	
	interlude->Stop();

	/*for (int i = 0; i < Njugadores; i++)
	{
		game->getJugador(i)->setPuntaje(playerscores[i]);
	}*/
	timer1->Stop();
	timer3->Stop();
	timer4->Stop();
timer2->Start();
maskedTextBox1->Location = System::Drawing::Point(this->Width / 3 + 20, Height / 1.8); 


	


}
		 private: bool running= false;
				  private: int Njugadores;

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Njugadores = Convert::ToInt32(maskedTextBox1->Text);

	playerscores = new int[Njugadores];

	if (Njugadores> 0 && Njugadores < 6)
	{
		game = new cJuego(Njugadores, "",Width,Height);


		mazo->mezclarMazo();

		for (int i = 0; i < game->getNJugadores(); i++)
		{
			player = game->getJugador(i);

			player->cogerAgregarCarta(mazo->repartirNumberCard());
			mazo->deleteTemp();
		
			

		}

	
		timer2->Stop();
		button1->Hide();
		button1->Enabled = false;
		maskedTextBox1->Enabled = false;
		maskedTextBox1->Hide();

	

		timer3->Start();


	}
	
	

}
	private:	System::Windows::Forms::Cursors ^ lol;
				bool ontopof = false;

private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Point ^ mousePt = gcnew Point(e->X, e->Y);

	//card movement
	if (running == true )
	{
		for (int i = 0; i < player->getNCartas(); i++)
		{
			if (player->getRecs(i)->Contains(*mousePt) == true)
			{
				ontopof = true;
				this->Cursor = lol->Hand;

				player->highlightCard(i);

				for (int j = i-1; j > 0; j--)
				{
					player->unHighlightCard(j);
				}
				for (int j = i + 1; j < player->getNCartas(); j++)
				{
					player->unHighlightCard(j);
				}
				break;
				
			}else
			{
				ontopof = false;
				player->unHighlightCard(i);
				
			}

			
		}

		
		

	}
	
	if (running == true && colorChangee == true)
	{
		if (red.Contains(*mousePt))
		{
			ontopof = true;
			
		}
		else if (blue.Contains(*mousePt))
		{
			ontopof = true;
			
		}
		else if (green.Contains(*mousePt))
		{
			ontopof = true;
			
		}
		else if (yellow.Contains(*mousePt))
		{

			ontopof = true;
		}
	

		
		if (ontopof == true)
		{
			this->Cursor = lol->Hand;
		}

	}
	
	if (ontopof == false)
	{
		this->Cursor = lol->Default;
	}

	

}

		 private: int stage = 1;
				 int playerSelected = 0;
				 bool cont = false;

private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {

	buffer->Graphics->Clear(Color::White);
	buffer->Graphics->DrawImage(background, 0, 0, this->Width, this->Height);
	Drawing::Font ^miFuente = gcnew Drawing::Font("Arial Black", 24);
	buffer->Graphics->DrawImage(UNO, this->Width / 3, this->Height/6, 400, 300);
	buffer->Graphics->DrawString("Cuantos Jugadores?", miFuente, Brushes::White, this->Width/3 - 20, this->Height/2);

	

	buffer->Render(graficador);
}

		 private: 
			 int who,val;
			 bool idk = false;
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {

	buffer->Graphics->Clear(Color::White);
	buffer->Graphics->DrawImage(background, 0, 0, this->Width, this->Height);
	

	if (stage==1)
	{
		val = 0;
		for (int i = 0; i < game->getNJugadores(); i++)
		{
			player = game->getJugador(i);

			cobj = player->getCarta(0);
			cobj->MoveCardsBeginning(buffer,sprites,i);

		stage = stage + cobj->verify(this->Height);

			if (stage==2)
			{
				t3 = clock();
				break;
			}

		}

	}


	if (stage == 2)
	{

		for (int i = 0; i < game->getNJugadores(); i++)
		{
			player = game->getJugador(i);
			cobj = player->getCarta(0);

			System::Drawing::Font ^ font = gcnew System::Drawing::Font("Comic Sans MS", 20);
			buffer->Graphics->DrawString("Player " + (i + 1), font, Brushes::Yellow, 110 + (i * 200), 350);

			cobj->showCard(150 + (i * 200), 400, buffer, sprites,true,foldedCard);


		}
	}
		if (clock() - t3 > 4500 && stage == 2)
		{
			stage = 3;
			
			t3 = clock();
		}
		
		if (stage == 3)
		{
			
				for (int i = 0; i < game->getNJugadores(); i++)
				{
					player = game->getJugador(i);
					cobj = player->getCarta(0);

					if (cobj->getNumero() > val)
					{
						val = cobj->getNumero();
					}


				}
				for (int i = 0; i < game->getNJugadores(); i++)
				{
					player = game->getJugador(i);
					cobj = player->getCarta(0);

					if (cobj->getNumero() == val)
					{
						who = i;
					}


				}
				game->setTurno(who);
				for (int i = 0; i < game->getNJugadores(); i++)
				{
					player = game->getJugador(i);
					cobj = player->getCarta(0);

					System::Drawing::Font ^ font = gcnew System::Drawing::Font("Comic Sans MS", 18);
					buffer->Graphics->DrawString("Player " + (i + 1), font, Brushes::Yellow, 110 + (i * 200), 350);

					cobj->showCard(150 + (i * 200), 400, buffer, sprites, true, foldedCard);


				}
		


			
		
			game->showRepartidor(buffer, this->Width, this->Height);

		
		}

		if (clock() - t3 > 4500 && stage == 3)
		{
			stage = 4;

			t3 = clock();
		}

		
if (stage == 4)
		{
			for (int i = 0; i <game->getNJugadores(); i++)
			{
				player = game->getJugador(i);
				mazo->addCard(player->getCarta(0));
				player->usarCarta(0);
					
			}

			for (int i = 0; i < game->getNJugadores(); i++)
				{
					player = game->getJugador(i);

					for (int j = 0; j < 7; j++)
					{

						player->cogerAgregarCarta(mazo->repartirCartas(0));
						mazo->deleteCard();

					}
					

				}

			game->setXYSplayers(Width,Height);
			game->setTurno(who);
				pozo->agregarCarta(mazo->repartirCartas(0));
				mazo->deleteCard();

				player = game->getJugador(game->obtenerTurno());
				

verifyMazo = false;
				colorChangee = false;
				gamestart = true;
				mas2Animacion = false;
				pierdeTurnoAnimacion = false;
			timer3->Stop();
			timer1->Start();
				/*cobj = mazo->repartirCartas(0);*/
		
	

	
			
		running = true;		

		}

	



	buffer->Render(graficador);
}









bool dun= false;
private: System::Void interlude_Tick(System::Object^  sender, System::EventArgs^  e) {
	buffer->Graphics->Clear(Color::White);
	System::Drawing::Font ^ font = gcnew System::Drawing::Font("Comic Sans MS", 50);

	buffer->Graphics->DrawString("Empieza una nueva partida...", font, Brushes::Blue, this->Width / 3.4, this->Height / 2);


	if (clock() - time > 5000)
	{
		timer1->Start();
		interlude->Stop();
		running = true;
	}

	
	
	buffer->Render(graficador);
}
		 int ganador;
private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {

	buffer->Graphics->Clear(Color::White);
	System::Drawing::Font ^ font = gcnew System::Drawing::Font("Comic Sans MS", 50);

	buffer->Graphics->DrawString("GANO EL JUGADOR " + (ganador+1), font, Brushes::Red, 100, 100);

	buffer->Render(graficador);
}
};
}
