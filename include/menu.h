#include <GL/glew.h> // Include the GLEW header file  
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

bool menukeyStates[256]; // Keybuffer for multiple key-input
int menuplay = 0, continueplay=0;
int drawoptions = 0;
float selecty[4][2]={{55,35}, {25,5}, {-5,-25},{-35,-55}};
int menusel = 0;
void menukeyPressed (unsigned char key, int x, int y);
void menukeyUp (unsigned char key, int x, int y);
void menukeyOperations (void);
extern float hp;
extern sf::RenderWindow DSWindow;

void DrawMainMenu();
void DrawCredits();
Timer keytimer;
Timer waittimer;
float geskeyTime=0;
float geswaitTime=0;



void DrawMenu()
{

	switch(drawoptions)
	{
		case 0: DrawMainMenu(); break;
		case 1: ; break;
		case 2: DrawCredits(); break;
		case 3: ; break;
		case 4: ; break;
	}
		
}

void DrawMainMenu()
{
int a =0;
sf::Text menuTitel, menu1s, menu1c, menu1, menu2, menu3, menu4;
menuTitel.setString("Game made by Deadspeller");
menu1s.setString("Start Game");
menu1c.setString("Resume Game");
menu1.setString("Start Game");
menu2.setString("Options");
menu3.setString("Credits");
menu4.setString("Exit");

//sf::Text menuTitel("Game made by Deadspeller"), menu1s("Start Game"), menu1c("Resume Game"), menu1("Start Game"), menu2("Options"), menu3("Credits"), menu4("Exit");
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear color buffer and depth buffer
   	glLoadIdentity();  // Load the Identity Matrix to reset our drawing locations 

   glMatrixMode( GL_PROJECTION );
   glPushMatrix();
   glLoadIdentity();
   glOrtho( -100.0f, 100.0f, -100.0f, 100.0f, -0.01f, 1.0f );
   glMatrixMode( GL_MODELVIEW );
   		
   		glPushMatrix(); 	//Frame
   		glLoadIdentity();
            	glColor3f( 1.0f, 1.0f, 1.0f );
            	glBegin( GL_LINE_LOOP);
             	glVertex2f( -95.0f, 95.0f );
             	glVertex2f( 95.0f, 95.0f );
             	glVertex2f( 95.0f, -95.0f );
              	glVertex2f( -95.0f, -95.0f );
           	glEnd();


		menuTitel.setPosition(-75,90);//Titel
		menuTitel.setScale(0.4,-0.4);
//		DSWindow.draw(menuTitel);

		menu1.setPosition(-25,55);		//Menu1
		menu1.setScale(0.4,-0.4);
//		DSWindow.draw(menu1);
	
		menu2.setPosition(-15,25);		//Menu2
		menu2.setScale(0.4,-0.4);
//		DSWindow.draw(menu2);

		menu3.setPosition(-15,-5);		//Menu3
		menu3.setScale(0.4,-0.4);
//		DSWindow.draw(menu3);

		menu4.setPosition(-10,-35);		//Menu3
		menu4.setScale(0.4,-0.4);
//		DSWindow.draw(menu4);


		glPushMatrix(); 	//Select Frame
   		glLoadIdentity();
		glBegin( GL_LINE_LOOP);
		glColor3f( 1.0f, 0.0f, 0.0f);
		glVertex2f( -50.1f, selecty[menusel] [0] +0.1);
             	glVertex2f( 50.1f, selecty[menusel] [0] +0.1);
             	glVertex2f( 50.1f, selecty[menusel] [1] +0.1);
              	glVertex2f( -50.1f, selecty[menusel] [1] +0.1);
           	glEnd();

		glPushMatrix(); 	//Select
   		glLoadIdentity();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            	glColor4f( 1.0f, 1.0f, 1.0f, 0.1f );
            	glBegin( GL_QUADS);
             	glVertex2f( -50.0f, selecty[menusel] [0]);
             	glVertex2f( 50.0f, selecty[menusel] [0]);
             	glVertex2f( 50.0f, selecty[menusel] [1]);
              	glVertex2f( -50.0f, selecty[menusel] [1]);
		glEnd();
		
   	glMatrixMode( GL_PROJECTION );					
   	glPopMatrix();	
				
  glMatrixMode( GL_MODELVIEW );		
  glPopMatrix();

		

}


void DrawCredits()
{
int a=0;
sf::Text credits1, credits2;

credits1.setString("Code by Deadspeller");
credits2.setString("Textures from the Internet");

glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear color buffer and depth buffer
	glLoadIdentity();  // Load the Identity Matrix to reset our drawing locations 

   glMatrixMode( GL_PROJECTION );
   glPushMatrix();
   glLoadIdentity();
   glOrtho( -100.0f, 100.0f, -100.0f, 100.0f, -0.01f, 1.0f );
   glMatrixMode( GL_MODELVIEW );
   		
   		glPushMatrix(); 	//Frame
   		glLoadIdentity();
            	glColor3f( 1.0f, 1.0f, 1.0f );
            	glBegin( GL_LINE_LOOP);
             	glVertex2f( -95.0f, 95.0f );
             	glVertex2f( 95.0f, 95.0f );
             	glVertex2f( 95.0f, -95.0f );
              	glVertex2f( -95.0f, -95.0f );
           	glEnd();
		
		credits1.setPosition(-50,35);		//Credits1
		credits1.setScale(0.4,-0.4);
		DSWindow.draw(credits1);

		credits2.setPosition(-60, 0);		//Credits2
		credits2.setScale(0.4,-0.4);
		DSWindow.draw(credits2);


   	glMatrixMode( GL_PROJECTION );					
   	glPopMatrix();	
				
  glMatrixMode( GL_MODELVIEW );		
  glPopMatrix();
}

