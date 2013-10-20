#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "include/class.h"
#include "include/world.h"
#include "include/gravitation.h"
#include "include/aimmove.h"
#include "include/shoot.h"
#include "include/drawscope.h"
#include "include/menu.h"
#include "include/hud.h"
#include "include/pointcalc.h"
#include "include/movement.h"
#include "include/menucontrol.h"
#include "include/impact.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdio.h>
//#include <SFML/Window.hpp>

//include von makefile: -lSOIL

#include <list>

#include <GL/glew.h> // Include the GLEW header file  

using namespace std;
int xres = 640, yres = 480;
float zoomfact = 90; //90 is normal
//--Variables--
	//Fog
GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};
GLfloat density = 0.01;
	//Light
GLfloat qaAmbientLight[] = {0.2,0.2,0.2,1.0};
GLfloat qaDiffuseLight[] = {0.8,0.8,0.8,1.0};
GLfloat qaSpecularLight[] = {1,1,1,1.0};
GLfloat qaLightPosition[] = {50,50,10,1.0};
GLfloat globalAmbient[] = { 0.2, 0.2, 0.2, 0.0 };
//Person
float persrad = 0.6;
float persbottom = 1.5;
float perstop = 0.3;
	//Position and Direction
float xpos = 0, ypos = 0, zpos = 0; 
float xrot = 0, yrot = 0, zrot = 0;
	//Mouse-Help-Variables
int diffx, diffy;
float lastx, lasty; //position of the mouse-pointer
sf::Vector2i center(xres/2, yres/2);
	//Gravitation
bool gravi_enable = 1;
bool menushow = 1;
float velocity = 0;
float hp = 100;
float hpcolor[3] = {0.2,1.0,0.2};
float sprintpoints = 100;

//shoot
float bulletspeed = 30;
int bullets = 10;


void keyPressed(unsigned char, int, int);
void keyPressedswitch(unsigned char, int, int);
void keyUp(unsigned char, int, int);
void keyUpswitch(unsigned char, int, int);

float gesTime;
float difTime;
Bulletclass kugel1;
Bulletclass kugel2;
Bulletclass kugel3;
Timer maintimer;

Bulletclass bulletarray[10];
collobject testwall1, testwall2, testwall3, testwall4, testwall5, testwall6, testcube1;
impactsprite impactspritearray[10]; 

 sf::RenderWindow DSWindow(sf::VideoMode(xres, yres, 32), "Game by Deadspeller");


void drawswitch() //change between menu and game
{
	if(menushow == 1)
	DrawMenu();
	else
	{
	world();	//build ground
	room();	//build room
	drawscope();
	DrawHUD();
	}
}


void enable (void) {
	//Light
   	
	glEnable (GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); 

	float specular[] = {0.1f, 0.1f, 0.1f , 1.0f};
	float diffuse[] = {0.5f, 0.5f, 0.5f , 1.0f};
	float ambient[] = {0.4f, 0.4f, 0.4f , 1.0f};
	float light_pos[] = {50, 10, 50 , 1.0f};
	float light_dir[] = {1.0f, 1.0f, 1.0f , 0.0f};
 glPushMatrix;
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse); 
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular); 
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient); 
//	glLightfv(GL_LIGHT0, GL_POSITION, light_pos); 
	glLightfv(GL_LIGHT0, GL_POSITION, light_dir); 
  glPopMatrix;


float specReflection[] = { 0.5f, 0.5f, 0.5f, 1.0f };
float diffReflection[] = { 0.5f, 0.5f, 0.5f, 1.0f };
float ambiReflection[] = { 0.5f, 0.5f, 0.5f, 1.0f };
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specReflection);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffReflection);
glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiReflection);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	//FOG
	glEnable (GL_FOG);
	glFogi (GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2
	glFogfv (GL_FOG_COLOR, fogColor);
	glFogf (GL_FOG_DENSITY, density);
	glHint (GL_FOG_HINT, GL_NICEST); // set the fog to look the nicest

	glShadeModel (GL_SMOOTH); //set the shader to smooth shader
}

void camera (void) {

    	glRotatef(xrot,1.0,0.0,0.0);  //rotate our camera on teh x-axis (left and right)
    	glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    	glTranslated(-xpos,-ypos,-zpos); //translate the screen to the position of our camera
}



////////////////////////////////////////////////////////////////////////////////////////


int main (int argc, char **argv) {
	//Init
	xpos=15;
 	ypos=1.5;
 	zpos=15;
	xrot=0;
	yrot=0;


    // Set the color and depth clear values
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);

    gluPerspective(zoomfact, xres/yres, 0.01f, 500.f);
	LoadTextures();
    // Start the game loop
    while (DSWindow.isOpen())
    {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
///////////////////////////////////
 glViewport(0, 0, xres, yres);	
//////////////////////////////////////

//Timer for main loop
	maintimer.stop();
	difTime = maintimer.getElapsedTimeInSec();
	if(difTime > 0.1) difTime = 0;	//remove first time
	gesTime += difTime;
	maintimer.start();
		

	sf::Event Event;

	sf::Keyboard KeyboardInput;
	sf::Joystick JoystickInput;
	sf::Mouse MouseInput;
//Keyboard
	MoveForwardKey = KeyboardInput.isKeyPressed(sf::Keyboard::W);
	MoveLeftKey = KeyboardInput.isKeyPressed(sf::Keyboard::A);
	MoveBackwardKey = KeyboardInput.isKeyPressed(sf::Keyboard::S);
	MoveRightKey = KeyboardInput.isKeyPressed(sf::Keyboard::D);
	MoveSneakKey = KeyboardInput.isKeyPressed(sf::Keyboard::LControl);
	MoveSprintKey = KeyboardInput.isKeyPressed(sf::Keyboard::LShift);
	MoveLaydownKey = KeyboardInput.isKeyPressed(sf::Keyboard::Y);
	FKeyDown = KeyboardInput.isKeyPressed(sf::Keyboard::F);
	GKeyDown = KeyboardInput.isKeyPressed(sf::Keyboard::G);
	EscKeyDown = KeyboardInput.isKeyPressed(sf::Keyboard::Escape);
	MoveJumpKey = KeyboardInput.isKeyPressed(sf::Keyboard::Space);
//Joystick
	MoveForwardKey |= JoystickInput.isButtonPressed(0, GP_DUp);
	MoveLeftKey |= JoystickInput.isButtonPressed(0, GP_DLeft);
	MoveBackwardKey |= JoystickInput.isButtonPressed(0, GP_DDown);
	MoveRightKey |= JoystickInput.isButtonPressed(0, GP_DRight);
	MoveSneakKey |= JoystickInput.isButtonPressed(0, GP_LStick);
	MoveSprintKey |= JoystickInput.isButtonPressed(0, GP_LT);
	MoveJumpKey |= JoystickInput.isButtonPressed(0, GP_LB);
//Mouse
	RightClickDown = MouseInput.isButtonPressed(sf::Mouse::Right);
//Joystick Axis
	if(JoystickInput.getAxisPosition(0, sf::Joystick::Y) < 0) MoveForwardKey = true;
	if(JoystickInput.getAxisPosition(0, sf::Joystick::Y) > 0) MoveBackwardKey = true;
	if(JoystickInput.getAxisPosition(0, sf::Joystick::X) > 0) MoveRightKey = true;
	if(JoystickInput.getAxisPosition(0, sf::Joystick::X) < 0) MoveLeftKey = true;
	

	if(xrot < -90) xrot = -90;
	else
	yrot = yrot + joystickyspeed * 0.2 * JoystickInput.getAxisPosition(0, sf::Joystick::Z);

	if(xrot > 90) xrot = 90;
	else
	xrot = xrot - joystickxspeed * 0.1 * JoystickInput.getAxisPosition(0, sf::Joystick::R);


		while (DSWindow.pollEvent(Event))
       		{
			
			if(menushow == 1)
			{
				if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::E))
	        		menucontrol('E');
				if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::W))
	        		menucontrol('U');
				if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::S))
	        		menucontrol('J');
				if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
	        		menucontrol('X');
			}

			if(Event.type == sf::Event::MouseMoved)	
			{
				diffx = (Event.mouseMove.x-lastx); //check the difference
				diffy = (Event.mouseMove.y-lasty); //check the difference
				if(xrot > 90) xrot = 90;
				else
				xrot += ((float) diffy)*mousexspeed; //set the xrot				
				if(xrot < -90) xrot = -90;
				else
				yrot += ((float) diffx)*mouseyspeed;// set the yrot
				lastx += diffx;
				lasty += diffy;
				//MouseInput.setPosition(center, DSWindow);
				//lastx=xres/2; //set lastx to the current x position
				//lasty=yres/2; //set lasty to the current y position
			}

			if (Event.type == sf::Event::MouseLeft) {
				MouseInput.setPosition(center, DSWindow);
				lastx=xres/2; //set lastx to the current x position
				lasty=yres/2; //set lasty to the current y position
		         }
			
			if(Event.type == sf::Event::JoystickButtonPressed)
			{		
				if(JoystickInput.isButtonPressed(0, GP_RT)) Bullethandler("handle");
			}
		

			// Close window : exit
            		if (Event.type == sf::Event::Closed)
               		DSWindow.close();

			if(Event.type == sf::Event::MouseButtonPressed)	
			{
				if(Event.mouseButton.button == sf::Mouse::Left) Bullethandler("handle");
			}
		}


        DSWindow.setActive();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    enable();	//enable graphic-settings
	DSWindow.setMouseCursorVisible(false); // hide mouse
	if(menushow == 0) movementcalc(difTime);
	gravi(); //calc new ypos
	aim_inaccuracy();
	camera();	//set camera to new position
	collision();
	shootcollision();
	impactdraw('0');
	Bullethandler("move");
	drawswitch();


	if(hp <= 0) lifecalc(1);

	if(sprintpoints < 100 && MoveSprintKey == false) sprintcalc();      
        // Finally, display the rendered frame on screen

/////////////////////////////////////
	if(menushow == 0)
{
 glViewport(xres*0.01, yres*0.99-150, 150, 150);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, xres/yres, 0.01f, 500.f);
 //  glOrtho(0, xres, 0, yres, -0.01f, 1.0f );
	glMatrixMode(GL_MODELVIEW);


	glLoadIdentity();	
	glDisable(GL_DEPTH_TEST);
	
	glRotatef(90,1.0,0.0,0.0);  //rotate our camera on the x-axis (left and right)
	glRotatef(90,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
	glRotatef(yrot-90,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
	glTranslated(-xpos-1,-10,-zpos-1); //translate the screen to the position of our camera
	world();
	room();

	glBegin(GL_POINTS); //wall2
	glColor3f(1,0.0,0);
	glVertex3f(0, 0, 0);
    glEnd();
}

DSWindow.display();
}

return EXIT_SUCCESS;
}
