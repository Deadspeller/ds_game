#include <GL/glew.h> // Include the GLEW header file  
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>


extern float xpos, ypos, zpos;
extern float persrad, perstop, persbottom;
extern class collobject testwall1, testwall2, testwall3, testwall4, testwall5, testwall6, testcube1;
extern bool colliding;
extern float velocity;
using namespace std;


void collision()
{
	testcube1.colldetec();
	testwall1.colldetec();
	testwall2.colldetec();
	testwall3.colldetec();
	testwall4.colldetec();
	testwall5.colldetec();
	testwall6.colldetec();
}

void shootcollision()
{
for(int a = 0; a < 10; a++)
{
testcube1.collshoot(a);
testwall1.collshoot(a);
testwall2.collshoot(a);
testwall3.collshoot(a);
testwall4.collshoot(a);
testwall5.collshoot(a);
testwall6.collshoot(a);
}
}
