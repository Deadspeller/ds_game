


#include <GL/glew.h> // Include the GLEW header file  
#include <vector> 
#include <iostream>

using namespace std;

extern float camheight;
extern float bulletspeed;
extern float bulletpos;
extern float xpos, zpos;
extern float yrot, xrot;
extern int bullets;
extern class Bulletclass bulletarray[10];


void Bullethandler(string action)
{
	if(action == "move")	//move the existing Bullets
	{	
		for(int movecounter = 0; movecounter<bullets; movecounter++)
		{
			if(bulletarray[movecounter].bulletcreated == 1) 
			{
			bulletarray[movecounter].bulletmove();
			
			}
		}	
	}

	if(action == "handle")	//create new Bullet
	{	
	
		for(int handlecounter=0; handlecounter<bullets; handlecounter++)
		{
			if(bulletarray[handlecounter].bulletflying == 0)
			{
			bulletarray[handlecounter].bulletinit();
			handlecounter = bullets;
			}			
		}

			
	}
}

