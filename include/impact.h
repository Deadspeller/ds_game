#include <GL/glew.h> // Include the GLEW header file  
//include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

float ximpact, yimpact, zimpact;
int iselect;
void impactdraw(char choose)
{
if(choose == '0')
{
for(int i = 0; i < 9 ; i++)
{
impactspritearray[i].drawsprite();
}

}
else if(choose == 'x' || choose == 'y' || choose == 'z')
{
impactspritearray[iselect].direction = choose;
impactspritearray[iselect].ximpact = ximpact;
impactspritearray[iselect].yimpact = yimpact;
impactspritearray[iselect].zimpact = zimpact;
if(iselect < 9) 
iselect+=1;
else 
iselect = 0;
}
}
