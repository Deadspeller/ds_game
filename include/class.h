#include <GL/glew.h> // Include the GLEW header file  
//include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Timer.h"
#include <cmath>

extern sf::RenderWindow DSWindow;
extern float camheight;
extern float bulletspeed;
extern float bulletpos;
extern float xpos, ypos, zpos;
extern float yrot, xrot, zrot;
extern int bullets;
extern float persrad, perstop, persbottom;
extern float camheight;
extern float velocity;
extern float cubecol[3];
extern float ximpact, yimpact, zimpact;

using namespace std;

void shootcollision();
void impactdraw(char);
class Bulletclass
{
public:
float difTime, gesTime;
float xspeed, zspeed, yspeed;
float xdif, zdif, ydif;
bool bulletcreated, bulletflying;
float yorigin, zorigin, xorigin;	
float yrotradbullet, zrotradbullet, xrotradbullet;	

Timer shoottimer1;
void bulletmove()
{
	if(bulletcreated)
	{ 
		bulletflying = 1;
		yspeed -= 0 * difTime;		
	
		xdif += xspeed * difTime;
		zdif += zspeed * difTime;
		ydif += yspeed * difTime;

if(yorigin+ydif < 0.5 && yspeed < 0) 
{
yspeed = yspeed * -0.7;
}


		glPushMatrix();
		glTranslated(xorigin+xdif,yorigin+ydif,zorigin+zdif);
		glScalef(0.2,0.2,0.2);
		glColor3f(1,0,0);
    
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 0, 1);
		glVertex3f(0, 0, 1);
		glEnd();
		 
		// Purple side - RIGHT
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(1, 1, 1);
		glVertex3f(1, 0, 1);
		glEnd();
		 
		// Green side - LEFT
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 1, 1);
		glVertex3f(0, 0, 1);
		glEnd();
		 
		// Blue side - TOP
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(1, 1, 1);
		glVertex3f(0, 1, 1);
		glEnd();
		 
		// Red side - BOTTOM
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(1, 0, 1);
		glVertex3f(1, 1, 1);
		glVertex3f(0, 1, 1);
		glVertex3f(0, 0, 1);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glEnd();
           
           	glEnd();

		glPopMatrix();

			shoottimer1.stop();
			difTime = shoottimer1.getElapsedTimeInSec();
			if(difTime > 0.1) difTime = 0;	//remove first time
			gesTime += difTime;
			shoottimer1.start();
}
if(gesTime >= 5)
{
	bulletcreated = 0;
 	bulletflying = 0;
}

}

void bulletinit()
{
if(bulletflying == 0)
{
	bulletcreated = true;
	gesTime = 0;
	xdif = 0;
	zdif = 0;
	ydif = 0;
	xspeed = 0;
	yspeed = 0;
	zspeed = 0;

	xrotradbullet = (xrot / 180 * 3.141592654f); 
	yrotradbullet = (yrot / 180 * 3.141592654f);
	zrotradbullet = (zrot / 180 * 3.141592654f);

		yorigin = ypos-0.2;
		zorigin = zpos;
		xorigin = xpos;	


//xspeed = (asin(sin(yrotradbullet))*(1/1.57))*bulletspeed;
//zspeed = -(asin(cos(yrotradbullet))*(1/1.57))*bulletspeed ;

yspeed = -sin(xrotradbullet)*bulletspeed;
xspeed = sin(yrotradbullet)*bulletspeed - (yspeed *sin(yrotradbullet));
zspeed = -cos(yrotradbullet)*bulletspeed + (yspeed *cos(yrotradbullet));

cout<<"yspeed: "<<-sin(xrotradbullet)*bulletspeed<<endl;
cout<<"xspeed: "<<xspeed<<endl;

cout<<"xrotradbullet "<<xrotradbullet<<endl;

cout<<"xspeed: "<<xspeed<<" yspeed: "<<yspeed<<" zspeed: "<<zspeed<<" gesamt: "<<abs(xspeed)+abs(yspeed)+abs(zspeed)<<endl;
}
}

};

extern class Bulletclass bulletarray[10];


///////Collision///////////

class collobject 
{
public:
sf::Vector3f max, min; //simple square
void colldetec()
	{
	float xpositiv = abs(xpos-max.x-persrad);
	float xnegativ = abs(xpos-min.x+persrad);
	float zpositiv = abs(zpos-max.z-persrad);
	float znegativ = abs(zpos-min.z+persrad);
	float ypositiv = abs(ypos-max.y-camheight);
	float ynegativ = abs(ypos-min.y+perstop);
	if(xpos < max.x+persrad && xpos > min.x-persrad && zpos < max.z+persrad && zpos > min.z-persrad && ypos < max.y+camheight && ypos > min.y-perstop) 
	{		
		if(xpositiv < 0.1) xpos = max.x + persrad + 0.01;
		else if(xnegativ < 0.1) xpos = min.x - persrad - 0.01;
		else if(zpositiv < 0.1) zpos = max.z + persrad + 0.01;
		else if(znegativ < 0.1) zpos = min.z - persrad - 0.01;
		else if(ypositiv < 0.1) {ypos = max.y + camheight + 0.01; velocity = 0;}
		else if(ynegativ < 0.1) ypos = min.y - perstop - 0.1;
	}
	
	};


void collshoot(int a)
	{
	float xpositiv = (bulletarray[a].xorigin+bulletarray[a].xdif)-max.x - 0.2;
	float xnegativ = (bulletarray[a].xorigin+bulletarray[a].xdif)-min.x + 0.2;
	float zpositiv = (bulletarray[a].zorigin+bulletarray[a].zdif)-max.z - 0.2;
	float znegativ = (bulletarray[a].zorigin+bulletarray[a].zdif)-min.z + 0.2;
	float ypositiv = (bulletarray[a].yorigin+bulletarray[a].ydif)-max.y - 0.2;
	float ynegativ = (bulletarray[a].yorigin+bulletarray[a].ydif)-min.y + 0.2;




	if((xpositiv + max.x) < max.x && (xnegativ + min.x) > min.x && (zpositiv + max.z) < max.z && (znegativ + min.z) > min.z && (ypositiv + max.y) < max.y && (ynegativ + min.y) > min.y)
	{	

 sf::Texture impacttexture;
 impacttexture.loadFromFile("textures/impact.jpg");
 // Create a sprite
 sf::Sprite impactsprite;
 //impactsprite.setTexture(impacttexture);
 impactsprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
 impactsprite.setColor(sf::Color(255, 255, 255, 200));
 impactsprite.setPosition(bulletarray[a].xorigin+bulletarray[a].xdif, 25);
 DSWindow.draw(impactsprite);

		if(xpositiv < 0.1 && xpositiv > -1 )
			{bulletarray[a].xspeed *= -1; 
			ximpact = bulletarray[a].xorigin+bulletarray[a].xdif+0.1;
			yimpact = bulletarray[a].yorigin+bulletarray[a].ydif;
			zimpact = bulletarray[a].zorigin+bulletarray[a].zdif;
			impactdraw('x');}
		else if(xnegativ < 0.1 && xnegativ > -1){bulletarray[a].xspeed *= -1;
			ximpact = bulletarray[a].xorigin+bulletarray[a].xdif-0.1;
			yimpact = bulletarray[a].yorigin+bulletarray[a].ydif;
			zimpact = bulletarray[a].zorigin+bulletarray[a].zdif;
			impactdraw('x');}
		else if(zpositiv < 0.1 && zpositiv > -1){bulletarray[a].zspeed *= -1; 
			ximpact = bulletarray[a].xorigin+bulletarray[a].xdif;
			yimpact = bulletarray[a].yorigin+bulletarray[a].ydif;
			zimpact = bulletarray[a].zorigin+bulletarray[a].zdif+0.1;
			impactdraw('z');}
		else if(znegativ < 0.1 && znegativ > -1){bulletarray[a].zspeed *= -1;
			ximpact = bulletarray[a].xorigin+bulletarray[a].xdif;
			yimpact = bulletarray[a].yorigin+bulletarray[a].ydif;
			zimpact = bulletarray[a].zorigin+bulletarray[a].zdif-0.1;
			impactdraw('z');}
		else if(ypositiv < 0.1 && ypositiv > -1){bulletarray[a].yspeed *= -1; 
			ximpact = bulletarray[a].xorigin+bulletarray[a].xdif;
			yimpact = bulletarray[a].yorigin+bulletarray[a].ydif+0.1;
			zimpact = bulletarray[a].zorigin+bulletarray[a].zdif;
			impactdraw('y');}
		else if(ynegativ < 0.1 && ynegativ > -1){bulletarray[a].yspeed *= -1; 
			ximpact = bulletarray[a].xorigin+bulletarray[a].xdif;
			yimpact = bulletarray[a].yorigin+bulletarray[a].ydif-0.1;
			zimpact = bulletarray[a].zorigin+bulletarray[a].zdif;
			impactdraw('y');}

	}
	
	};
};


extern class impactsprite impactspritearray[10];

class impactsprite
{
public:
char direction;
float ximpact, yimpact, zimpact;

void drawsprite()
{
		glPushMatrix();
		glTranslatef(ximpact, yimpact , zimpact );
		glScalef(0.2,0.2,0.2);
		glColor3f(1,0,0);

if(direction == 'x')
{

		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 1, 1);
		glVertex3f(0, 0, 1);
		glEnd();
}
else if(direction == 'y')
{
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 0, 1);
		glVertex3f(0, 0, 1);
		glEnd();
}
else if(direction == 'z')
{
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(0, 1, 0);
		glEnd();
}
		glPopMatrix();
}
};
