#include <GL/glew.h> // Include the GLEW header file  

extern float sprintpoints;
extern float difTime;
extern bool MoveSprintKey;


void sprintcalc()
{
	sprintpoints += difTime*20;	
}

void lifecalc(float velocity)
{

if(velocity < -5 && velocity > -100) //falling damage
		{ 
			if(velocity < -5 && velocity > -8)	hp += velocity/2;
			if(velocity < -8 && velocity > -12)	hp += velocity*1.5;
			if(velocity < -12 && velocity > -15)	hp += velocity*4;
			if(velocity < -15)	hp = 0;
}
if(hp < 100)
{
hpcolor[0] = (100-hp)/100+0.2;
hpcolor[1] = hp/100+0.2;
hpcolor[2] = 0.2;
}

if(hp <= 0) 
{
hp = 0;

char gameover[10] = "GAME OVER";
int i = 0;
hp = 0;

glMatrixMode( GL_PROJECTION );
   glPushMatrix();
   glLoadIdentity();
   glOrtho( -100.0f, 100.0f, -100.0f, 100.0f, -0.01f, 1.0f );
   glMatrixMode( GL_MODELVIEW );

/*
		glPushMatrix();
   		glLoadIdentity();
		glColor3f( 1.0f, 0.0f, 0.0f );
		glTranslatef( -80.0f, -10.0f, 0.0f );
            	glScalef( 0.2f, 0.2f, 0.0f);
            	while( gameover[i] != '\0' )
    		{
            	glutStrokeCharacter( GLUT_STROKE_ROMAN, gameover[i]);
		i++;
 		}
*/
		glPushMatrix();
   		glLoadIdentity();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            	glColor4f( 0.1f, 0.1f, 0.1f, 0.75 );
            	glBegin( GL_QUADS);
             	glVertex2f( -90.0f, 20.0f );
             	glVertex2f( 90.0f, 20.0f );
             	glVertex2f( 90.0f, -20.0f );
              	glVertex2f( -90.0f, -20.0f );
           	glEnd();
		
		glPushMatrix();
   		glLoadIdentity();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            	glColor4f( 0.0f, 0.0f, 0.0f, 1 );
            	glBegin(GL_LINE_STRIP);
             	glVertex2f( -90.1f, 20.1f );
             	glVertex2f( 90.1f, 20.1f );
             	glVertex2f( 90.1f, -20.1f );
              	glVertex2f( -90.1f, -20.1f );
		glVertex2f( -90.1f, 20.1f );
           	glEnd();
		

   	glMatrixMode( GL_PROJECTION );					
   	glPopMatrix();	
				
  glMatrixMode( GL_MODELVIEW );		
  glPopMatrix();
}
}
