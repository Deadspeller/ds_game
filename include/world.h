/* World-Header File for main.cpp */


#include <GL/glew.h> // Include the GLEW header file  
#include "collision.h"
#include "texture.h"

extern collobject testwall1, testwall2, testwall3, testwall4, testwall5, testwall6, testcube1;
float cubecol[3] = {1.0,0.4,0.4};

void world()	//Draw the world
{
glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, tex_ground[0]);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    	glColor3f(1,1,1); // If you do not set a color, the textured area will appear black.

    	glBegin(GL_POLYGON); //ground
    	glTexCoord2d(0,0);  glVertex3f(0, 0, 0);
    	glTexCoord2d(50,0);  glVertex3f(0, 0, 100);
    	glTexCoord2d(50,50);  glVertex3f(100, 0, 100);
    	glTexCoord2d(0,50);  glVertex3f(100, 0, 0);
    	glEnd();
    	glDisable(GL_TEXTURE_2D);

glBegin(GL_POLYGON); //wall1
	glColor3f(0.9,1,1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 100);
	glVertex3f(0, 50, 100);
	glVertex3f(0, 50, 0);
    	glEnd();

glBegin(GL_POLYGON); //wall2
	glColor3f(1,0.9,1);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 0, 0);
	glVertex3f(100, 50, 0);
	glVertex3f(0, 50, 0);
    	glEnd();

glBegin(GL_POLYGON); //wall3
	glColor3f(1,1,0.9);
	glVertex3f(100, 0, 0);
	glVertex3f(100, 0, 100);
	glVertex3f(100, 50, 100);
	glVertex3f(100, 50, 0);
    	glEnd();

glBegin(GL_POLYGON); //wall4
	glColor3f(0.9,0.9,1);
	glVertex3f(0, 0, 100);
	glVertex3f(100, 0, 100);
	glVertex3f(100, 50, 100);
	glVertex3f(0, 50, 100);
    	glEnd();

glBegin(GL_POLYGON); //top
	glColor3f(1,1,1);
	glVertex3f(0, 50, 0);
	glVertex3f(100, 50, 0);
	glVertex3f(100, 50, 100);
	glVertex3f(0, 50, 100);
    	glEnd();
glPopMatrix();
}

void room() //Draw the room
{

glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, tex_ground[2]);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1,1,1);
/////////////////////////////////////////////////////////////////
glPushMatrix();

glTranslatef( 20, 0.2, 10.0 );

// White side - FRONT
glBegin(GL_POLYGON);
glColor3f( cubecol[0],  cubecol[1], cubecol[2]);
glVertex3f(  -0.5, -0.5, -0.5 );
glVertex3f(  -0.5,  0.5, -0.5 );
glVertex3f( 0.5,  0.5, -0.5 );
glVertex3f( 0.5, -0.5, -0.5 );
glEnd();

	testcube1.min.x = 19.5;
	testcube1.max.x = 20.5;
	testcube1.min.y = 0.0;
	testcube1.max.y = 0.7;
	testcube1.min.z = 9.5;
	testcube1.max.z = 10.5;


// White side - BACK
glBegin(GL_POLYGON);
glVertex3f(  0.5, -0.5, 0.5 );
glVertex3f(  0.5,  0.5, 0.5 );
glVertex3f( -0.5,  0.5, 0.5 );
glVertex3f( -0.5, -0.5, 0.5 );
glEnd();
 
// Purple side - RIGHT
glBegin(GL_POLYGON);
glVertex3f( 0.5, -0.5, -0.5 );
glVertex3f( 0.5,  0.5, -0.5 );
glVertex3f( 0.5,  0.5,  0.5 );
glVertex3f( 0.5, -0.5,  0.5 );
glEnd();
 
// Green side - LEFT
glBegin(GL_POLYGON);
glVertex3f( -0.5, -0.5,  0.5 );
glVertex3f( -0.5,  0.5,  0.5 );
glVertex3f( -0.5,  0.5, -0.5 );
glVertex3f( -0.5, -0.5, -0.5 );
glEnd();
 
// Blue side - TOP
glBegin(GL_POLYGON);
glVertex3f(  0.5,  0.5,  0.5 );
glVertex3f(  0.5,  0.5, -0.5 );
glVertex3f( -0.5,  0.5, -0.5 );
glVertex3f( -0.5,  0.5,  0.5 );
glEnd();
 
// Red side - BOTTOM
glBegin(GL_POLYGON);
glVertex3f(  0.5, -0.5, -0.5 );
glVertex3f(  0.5, -0.5,  0.5 );
glVertex3f( -0.5, -0.5,  0.5 );
glVertex3f( -0.5, -0.5, -0.5 );
glEnd();

glPopMatrix();


glPushMatrix();
//////////////////////////////////////////////////////////////////
	glBegin(GL_POLYGON); //top
	glColor3f(1,1,1);
    glTexCoord2f(2,0); glVertex3f(0.5,4,0.5);
  	glTexCoord2f(2,1); glVertex3f(8.5,4,0.5);
  	glTexCoord2f(0,1); glVertex3f(8.5,4,16.5);
  	glTexCoord2f(0,0); glVertex3f(0.5,4,16.5);

  	glTexCoord2f(2,0); glVertex3f(0.5,4.1,0.5);
  	glTexCoord2f(2,1); glVertex3f(8.5,4.1,0.5);
  	glTexCoord2f(0,1); glVertex3f(8.5,4.1,16.5);
  	glTexCoord2f(0,0); glVertex3f(0.5,4.1,16.5);
  	glEnd();

	testwall6.min.x = 0.5;
	testwall6.max.x = 8.5;
	testwall6.min.y = 4;
	testwall6.max.y = 4.1;
	testwall6.min.z = 0.5;
	testwall6.max.z = 16.5;

	//glEnable(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, tex_ground[1]);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBegin(GL_POLYGON); //wall1
	glColor3f(1,1,1);
  	glTexCoord2f(0,0); glVertex3f(1,0,1);
  	glTexCoord2f(1,0); glVertex3f(8,0,1);
  	glTexCoord2f(1,1); glVertex3f(8,4,1);
  	glTexCoord2f(0,1); glVertex3f(1,4,1);
  	glEnd();
		
	testwall1.min.x = 1;
	testwall1.max.x = 8;
	testwall1.min.y = 0;
	testwall1.max.y = 4;
	testwall1.min.z = 1;
	testwall1.max.z = 1;

	glEnable(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, tex_ground[1]);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1,1,1);

  	glBegin(GL_POLYGON); //wall2
  	glTexCoord2f(0,0); glVertex3f(1,0,1);
	glTexCoord2f(2,0); glVertex3f(1,0,16);
	glTexCoord2f(2,1); glVertex3f(1,4,16);
  	glTexCoord2f(0,1); glVertex3f(1,4,1);
  	
	testwall2.min.x = 1;
	testwall2.max.x = 1;
	testwall2.min.y = 0;
	testwall2.max.y = 4;
	testwall2.min.z = 1;
	testwall2.max.z = 16;
  	
  	glEnd();

	glEnable(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, tex_ground[1]);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1,1,1);

  	glBegin(GL_POLYGON); //wall3
  	glTexCoord2f(0,0); glVertex3f(8,0,1);
	glTexCoord2f(2,0); glVertex3f(8,0,16);
	glTexCoord2f(2,1); glVertex3f(8,4,16);
  	glTexCoord2f(0,1); glVertex3f(8,4,1);
  	


	testwall3.min.x = 8;
	testwall3.max.x = 8;
	testwall3.min.y = 0;
	testwall3.max.y = 4;
	testwall3.min.z = 1;
	testwall3.max.z = 16;


  	glEnd();
	
	glEnable(GL_TEXTURE_2D);
   	glBindTexture(GL_TEXTURE_2D, tex_ground[1]);
   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1,1,1);

  	glBegin(GL_POLYGON); //wall4
  	glTexCoord2f(1,0); glVertex3f(1,0,16);
  	glTexCoord2f(1,1); glVertex3f(1,4,16);
  	glTexCoord2f(0,1); glVertex3f(6,4,16);
  	glTexCoord2f(0,0); glVertex3f(6,0,16);
  	glEnd();

	testwall4.min.x = 1;
	testwall4.max.x = 6;
	testwall4.min.y = 0;
	testwall4.max.y = 4;
	testwall4.min.z = 16;
	testwall4.max.z = 16;


glBegin(GL_POLYGON); //wall5
  	glTexCoord2f(0.5,0); glVertex3f(6,2.2,16);
  	glTexCoord2f(0.5,0.5); glVertex3f(6,4,16);
  	glTexCoord2f(0,0.5); glVertex3f(8,4,16);
  	glTexCoord2f(0,0); glVertex3f(8,2.2,16);
  	glEnd();

	testwall5.min.x = 6;
	testwall5.max.x = 8;
	testwall5.min.y = 2.2;
	testwall5.max.y = 4;
	testwall5.min.z = 16;
	testwall5.max.z = 16;



	glDisable(GL_TEXTURE_2D);

////////////////////////////////////
//INGRESS - INjection
////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
//Version 2.0: - create a cake
////////////// - promised the cake
////////////// - hide the cake
////////////////////////////////////

glPopMatrix();
//////////////////////////////

}

