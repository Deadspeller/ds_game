#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <GL/glew.h> // Include the GLEW header file  

extern sf::RenderWindow DSWindow;
extern float difTime;
extern float sprintpoints;
extern float hp;
extern float hpcolor[3];
extern bool scopeview;
extern int xres, yres;
extern float inaccu_x, inaccu_y;


void DrawHUD()
{
int ammoleft = 0, i=0, a=0;
char cammoleft[10] = "default";
char chp[10] = "default";


   glMatrixMode( GL_PROJECTION );
   glPushMatrix();
   glLoadIdentity();
   glOrtho(0, xres, 0, yres, -0.01f, 1.0f );
   glMatrixMode( GL_MODELVIEW );



   				glPushMatrix(); 	//map
   				glLoadIdentity();

				glEnable(GL_BLEND);			//frame
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            	glColor4f(0.216f, 0.4f, 0.68f , 0.4f );
            	glBegin( GL_QUADS);
             	glVertex2f( xres*0.01, yres*0.99);
             	glVertex2f( xres*0.01, yres*0.99-150);
             	glVertex2f( xres*0.01+150, yres*0.99-150);
              	glVertex2f( xres*0.01+150, yres*0.99);
				glEnd();

				glColor3f( 0.66f, 0.9f, 0.98f );
            	glBegin( GL_LINE_LOOP);
             	glVertex2f( xres*0.01-1, yres*0.99);
             	glVertex2f( xres*0.01-1, yres*0.99-151);
             	glVertex2f( xres*0.01+150, yres*0.99-151);
              	glVertex2f( xres*0.01+150, yres*0.99);
           		glEnd();



		//fps

            	glColor3f( 0.56f, 0.8f, 0.88f );
				glBegin(GL_LINE_STRIP);
             	glVertex2f( xres*0.90, yres*0.80);
             	glVertex2f( xres*0.95, yres*0.80);
             	glVertex2f( xres*0.95, yres*0.95);
              	glVertex2f( xres*0.90, yres*0.95);
           		glEnd();

//if(1/difTime > 60) difTime = 0.01667;
            	glColor3f( 0.56f, 0.8f, 0.88f );
            	glBegin(GL_QUADS);
             	glVertex2f( xres*0.90, yres*0.80);
             	glVertex2f( xres*0.95, yres*0.80);
             	glVertex2f( xres*0.95, yres*0.80 + 1/difTime);
              	glVertex2f( xres*0.90, yres*0.80 + 1/difTime);
           		glEnd();

				glEnable(GL_BLEND);			//frame
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            	glColor4f(0.216f, 0.4f, 0.68f , 0.4f );
            	glBegin( GL_QUADS);
               	glVertex2f( xres*0.90, yres*0.80);
             	glVertex2f( xres*0.95, yres*0.80);
             	glVertex2f( xres*0.95, yres*0.95);
              	glVertex2f( xres*0.90, yres*0.95);
				glEnd();

				glColor3f( 0.66f, 0.9f, 0.98f );
				glBegin(GL_LINE_LOOP);
             	glVertex2f( xres*0.90, yres*0.80);
             	glVertex2f( xres*0.95, yres*0.80);
             	glVertex2f( xres*0.95, yres*0.95);
              	glVertex2f( xres*0.90, yres*0.95);
           		glEnd();

		//hp
            	glColor3f( 0.56f, 0.8f, 0.88f );
				glBegin(GL_LINE_STRIP);
               	glVertex2f( xres*0.94-100, yres*0.08);
             	glVertex2f( xres*0.94-100, yres*0.04);
              	glVertex2f( xres*0.96, yres*0.04);
              	glVertex2f( xres*0.96, yres*0.08);
           		glEnd();

            	glColor3f(hpcolor[0],hpcolor[1],hpcolor[2]);
            	glBegin(GL_QUADS);
             	glVertex2f( xres*0.95, yres*0.05);
             	glVertex2f( xres*0.95, yres*0.08);
             	glVertex2f( xres*0.95 -hp, yres*0.08);
              	glVertex2f( xres*0.95 -hp, yres*0.05);
           		glEnd();

			glEnable(GL_BLEND);			//frame
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            	glColor4f(0.16f, 0.4f, 0.68f , 0.4f );
            	glBegin( GL_QUADS);
               	glVertex2f( xres*0.93-100, yres*0.029);
             	glVertex2f( xres*0.93-100, yres*0.09);
              	glVertex2f( xres*0.97, yres*0.09);
              	glVertex2f( xres*0.97, yres*0.029);
				glEnd();

				glColor3f( 0.66f, 0.9f, 0.98f );
				glBegin(GL_LINE_LOOP);
               	glVertex2f( xres*0.93-101, yres*0.03-1);
             	glVertex2f( xres*0.93-101, yres*0.09);
              	glVertex2f( xres*0.97+1, yres*0.09);
              	glVertex2f( xres*0.97+1, yres*0.03-1);
           		glEnd();


		//sprint
            	glColor3f( 0.56f, 0.8f, 0.88f );
				glBegin(GL_LINE_STRIP);
             	glVertex2f( xres*0.06+100, yres*0.08);
             	glVertex2f( xres*0.06+100, yres*0.04);
              	glVertex2f( xres*0.04, yres*0.04);
              	glVertex2f( xres*0.04, yres*0.08);
           		glEnd();

            	glColor3f( 0.56f, 0.8f, 0.88f );
            	glBegin(GL_QUADS);
             	glVertex2f( xres*0.05, yres*0.05);
            	glVertex2f( xres*0.05, yres*0.08);
             	glVertex2f( xres*0.05 +sprintpoints, yres*0.08);
              	glVertex2f( xres*0.05 +sprintpoints, yres*0.05);
           		glEnd();

			glEnable(GL_BLEND);			//frame
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            	glColor4f(0.16f, 0.4f, 0.68f , 0.4f );
            	glBegin( GL_QUADS);
             	glVertex2f( xres*0.07+100, yres*0.03);
             	glVertex2f( xres*0.07+100, yres*0.09);
              	glVertex2f( xres*0.03, yres*0.09);
              	glVertex2f( xres*0.03, yres*0.03);
				glEnd();

				glColor3f( 0.66f, 0.9f, 0.98f );
				glBegin(GL_LINE_LOOP);
             	glVertex2f( xres*0.07+101, yres*0.03-1);
             	glVertex2f( xres*0.07+101, yres*0.09);
              	glVertex2f( xres*0.03-1, yres*0.09);
              	glVertex2f( xres*0.03-1, yres*0.03-1);
           		glEnd();

	//aim
				glLineWidth(3);
				glColor3f( 1.0f, 0.0f, 0.0f );
				glBegin( GL_LINES);
             	glVertex2f( xres/2-6+inaccu_x, yres/2-8+inaccu_y);
             	glVertex2f( xres/2+inaccu_x, yres/2+inaccu_y);
				glEnd();

				glBegin( GL_LINES);
             	glVertex2f(xres/2+6+inaccu_x, yres/2-8+inaccu_y);
             	glVertex2f( xres/2+inaccu_x, yres/2+inaccu_y);
				glEnd();
				glLineWidth(1);


//scope
if(scopeview)
{
//drawscope();
}

   	glMatrixMode( GL_PROJECTION );					
   	glPopMatrix();	
				
  glMatrixMode( GL_MODELVIEW );		
  glPopMatrix();
}
