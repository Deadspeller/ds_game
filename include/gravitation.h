/* Gravitation-Header File */

//#include "Timer.h"
#include <iostream>
using namespace std;


extern bool gravi_enable ;
extern float velocity;
extern float ypos;
extern float camheight;
extern bool jumping;
extern float hp;
extern bool colliding;
Timer t;

void lifecalc(float);

void gravi()
{
float g = 9.81;
float difTime = 0;

t.stop();
difTime = t.getElapsedTimeInSec();
t.start();

  if(gravi_enable == 1)
  {
	if(difTime < 0.2)
	velocity = velocity - (g*difTime); // new speed
	ypos = ypos + (velocity * difTime);// new position

  	if(ypos <= camheight) //ground
	{	
		if(ypos<0) hp = 100;
		ypos = camheight;
		lifecalc(velocity);	
		velocity = 0;
	}
	if(ypos > camheight) jumping = 1;
	else jumping = 0;
  }	
}


