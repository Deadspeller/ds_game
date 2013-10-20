#include <GL/glew.h> // Include the GLEW header file  
extern int xres, yres;
extern bool scopeview;

void drawscope()
{
glTranslated(xpos,ypos,zpos); //translate the screen to the position of our camera

glRotatef(-yrot,0.0,1.0,0.0); 
if(xrot < 0) glRotatef(abs(xrot),1.0,0.0,0.0);
else glRotatef(-abs(xrot),1.0,0.0,0.0);

if(zrot < 0) glRotatef(abs(zrot),0.0,0.0,1.0); 
else glRotatef(-abs(zrot),0.0,0.0,1.0);


if(scopeview)		//in zoom
{
	glBegin(GL_QUADS); //Weapon
	glColor3f(0.1,0.1,0.1);
	glVertex3f(-0.03,-0.1,0.1);
	glVertex3f(-0.03,-0.07,-0.5);
	glVertex3f(0.03,-0.07,-0.5);
	glVertex3f(0.03,-0.1,0.1);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor4f(0.1,0.1,0.2, 0.6);
	glVertex3f(-0.03,0.03,-0.2);
	glVertex3f(-0.03,-0.03,-0.2);
	glVertex3f(0.03,-0.03,-0.2);
	glVertex3f(0.03,0.03,-0.2);
	glEnd();
}
else
{
	glBegin(GL_QUADS); //Weapon
	glColor3f(0.1,0.1,0.1);
	glVertex3f(0,-0.1,0);
	glVertex3f(0,-0.1,-0.5);
	glVertex3f(0.1,-0.1,-0.5);
	glVertex3f(0.1,-0.1,0);
	glEnd();

	glEnable(GL_BLEND);			//zoom
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.1, 0.1, 0.3, 0.2);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f( 0.05,-0.1, 0.1);
	glVertex3f( 0.05,-0.1, -0.1);
	glVertex3f( -0.05,-0.1, -0.1);
	glVertex3f( -0.05,-0.1, 0.1);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glColor4f(0.1,0.1,0.2, 0.6);
	glVertex3f(0,0,-0.2);
	glVertex3f(0,-0.1,-0.2);
	glVertex3f(0.1,-0.1,-0.2);
	glVertex3f(0.1,0,-0.2);
	glEnd();
}
	

/*
				glColor3f(0.1, 0.1, 0.1);
            	glBegin( GL_QUADS);
             	glVertex2f( xres/2-50+inaccu_x, 0);
             	glVertex2f( xres/2+50+inaccu_x, 0);
             	glVertex2f( xres/2+50+inaccu_x, yres/2-100+inaccu_y);
              	glVertex2f( xres/2-50+inaccu_x, yres/2-100+inaccu_y);
				glEnd();

        		glBegin(GL_QUADS);
             	glVertex2f( xres/2-100+inaccu_x, 0);
             	glVertex2f( xres/2+100+inaccu_x, 0);
             	glVertex2f( xres/2+70+inaccu_x, yres/2-150+inaccu_y);
              	glVertex2f( xres/2-70+inaccu_x, yres/2-150+inaccu_y);
				glEnd();

				glEnable(GL_BLEND);			//zoom
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            	glColor4f(1, 1, 1, 0.2);
            	glBegin(GL_TRIANGLE_FAN);
             	glVertex2f( xres/2+40+inaccu_x, yres/2-80+inaccu_y);
             	glVertex2f( xres/2-40+inaccu_x, yres/2-80+inaccu_y);
             	glVertex2f( xres/2-80+inaccu_x, yres/2-40+inaccu_y);
             	glVertex2f( xres/2-80+inaccu_x, yres/2+40+inaccu_y);
             	glVertex2f( xres/2-40+inaccu_x, yres/2+80+inaccu_y);
             	glVertex2f( xres/2+40+inaccu_x, yres/2+80+inaccu_y);
             	glVertex2f( xres/2+80+inaccu_x, yres/2+40+inaccu_y);
             	glVertex2f( xres/2+80+inaccu_x, yres/2-40+inaccu_y);
				glEnd();
	
				glColor3f(0,0,0);
            	glBegin(GL_TRIANGLE_FAN);
             	glVertex2f( xres/2+50+inaccu_x, yres/2-100+inaccu_y);
             	glVertex2f( xres/2-50+inaccu_x, yres/2-100+inaccu_y);
             	glVertex2f( xres/2-100+inaccu_x, yres/2-50+inaccu_y);
             	glVertex2f( xres/2-100+inaccu_x, yres/2+50+inaccu_y);
             	glVertex2f( xres/2-50+inaccu_x, yres/2+100+inaccu_y);
             	glVertex2f( xres/2+50+inaccu_x, yres/2+100+inaccu_y);
             	glVertex2f( xres/2+100+inaccu_x, yres/2+50+inaccu_y);
             	glVertex2f( xres/2+100+inaccu_x, yres/2-50+inaccu_y);
           		glEnd();

*/
}
