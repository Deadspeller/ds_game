#include <math.h>

float inaccu_x=0, inaccu_y=0;
extern float difTime;
extern bool holdbreath;


void aim_inaccuracy()
{
if(holdbreath == false)
{
	static float help_var_x, help_var_y;
	if(help_var_x < 360) help_var_x += difTime*50;
	else help_var_x = 0;
	if(help_var_y < 360) help_var_y += difTime*100;
	else help_var_y = 0;

	inaccu_x = 3*sin(help_var_x*3.1415/180);
	inaccu_y = 5*sin(help_var_y*3.1415/180); 
}
}

