

int GP_LT = 8,GP_RT = 9, GP_LB = 10, GP_RB = 11, GP_LStick = 1, GP_RStick = 2, GP_Dreieck = 12;
int GP_Viereck = 15, GP_X = 14, GP_Kreis = 13, GP_DUp = 4, GP_DLeft = 7, GP_DDown = 6, GP_DRight = 5;
int GP_Select = 0, GP_Start = 3, GP_XBox = 16;

extern float gesTime;
extern float difTime;
extern float sprintpoints;
extern float zoomfact;
extern bool menushow;
extern int xres,yres;
extern  sf::RenderWindow DSWindow;
bool holdbreath = false;

bool scopeview = false;
bool MoveForwardKey, MoveLeftKey, MoveBackwardKey, MoveRightKey, MoveSneakKey, MoveLaydownKey, MoveJumpKey, MoveSprintKey;
bool LControlKeyDown, YKeyDown, FKeyDown, GKeyDown, EscKeyDown, SpaceKeyDown, RightClickDown;
bool MoveUseKey, MoveUpKey, MoveDownKey;

	//Movement height
float actheight = 1.5;
float camheight = 1.5;
float walkheight = 1.5;
float sneakheight = 1.0;
float layheight = 0.5;
	//Movement speed
float actspeed = 1;
float sprintspeed = 1.6;
float flyspeed = 8;
float walkspeed = 2;
float sneakspeed = 1;
float layspeed = 0.5;
	//Cam speed
float mousexspeed = 0.1, mouseyspeed = 0.1;
float joystickxspeed = 0.1, joystickyspeed = 0.1;
	//Movement scale
float sideway = 0.9;
float backway = 0.8;
bool jumping = 0;
bool laydown = 0, sneakdown = 0;

float upview;	

void movementcalc(float difTime)
{
	if (MoveSprintKey == true && sneakdown == 0 && laydown == 0)
	{
		if(sprintpoints > 0) 
			{
			actspeed = actspeed * sprintspeed;
			sprintpoints -= difTime*50;	
			}
		else sprintpoints = 0;
	}
	if(MoveSprintKey == true && (sneakdown == 1 || laydown == 1))
	{
		if(sprintpoints > 0) 
		{
			holdbreath = true;
			sprintpoints -= difTime*50;	
		}
		else 
		{	
			sprintpoints = 0;
			holdbreath = false;		
		}
	}
	if(MoveSprintKey == false)
	holdbreath = false;

if (RightClickDown == true)
	{
	scopeview = true;
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40, xres/yres, 0.01f, 500.f);
	glMatrixMode(GL_MODELVIEW);
	}
else
{
	scopeview = false;
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 640/480, 0.01f, 500.f);
	glMatrixMode(GL_MODELVIEW);
}



	if (MoveForwardKey)
	{	
		float xrotrad, yrotrad, zrotrad;
    		yrotrad = (yrot / 180 * 3.141592654f);
    		xrotrad = (xrot / 180 * 3.141592654f); 
		upview = float(sin(xrotrad));

		//x-richtungsgeschw.
		if(gravi_enable == 1)    xpos += float(sin(yrotrad))*actspeed*sprintspeed*difTime ;
		else 
		{
		if(upview < 0)	xpos += float(sin(yrotrad)+(upview*sin(yrotrad)))*flyspeed*difTime;
		if(upview > 0)	xpos += float(sin(yrotrad)-(upview*sin(yrotrad)))*flyspeed*difTime;
			}

		//z-richtungsgeschw.
		if(gravi_enable == 1)    	zpos -= float(cos(yrotrad))*actspeed*sprintspeed*difTime ;
		else
		{
		if(upview < 0)	zpos -= float(cos(yrotrad)+(upview*cos(yrotrad)))*flyspeed*difTime ;
		if(upview > 0)	zpos -= float(cos(yrotrad)-(upview*cos(yrotrad)))*flyspeed*difTime ;
		}
		if(gravi_enable == 0) ypos -= float(sin(xrotrad))*flyspeed*difTime;
	}


	if (MoveBackwardKey)
	{	float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f); 
		xpos -= float(sin(yrotrad))*actspeed*backway*difTime;
		zpos += float(cos(yrotrad))*actspeed*backway*difTime;
		if(gravi_enable == 0) ypos += float(sin(xrotrad))*flyspeed*difTime;
	}

	if (MoveRightKey)
	{	float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos += float(cos(yrotrad)) * actspeed*sideway*difTime;
		zpos += float(sin(yrotrad)) * actspeed*sideway*difTime;
	}

	if (MoveLeftKey)
	{	float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos -= float(cos(yrotrad)) * actspeed*sideway*difTime;
		zpos -= float(sin(yrotrad)) * actspeed*sideway*difTime;
	}

	if (FKeyDown)
	{	gravi_enable = 0;
	}

	if (GKeyDown)
	{	gravi_enable = 1;
	}

	if (MoveSneakKey)
	{	
		sneakdown = 1;
		camheight = sneakheight;
		actspeed = sneakspeed;
	}
	else if(laydown == 0)
	{
		camheight = walkheight;
		actspeed = walkspeed;
	}

	if (MoveLaydownKey)
	{	if(laydown == 1) laydown = 0;
		else laydown = 1;
		camheight = layheight;
		actspeed = layspeed;
	}	

	if (MoveJumpKey)
	{	
		camheight = walkheight;
		actspeed = walkspeed;
		if(gravi_enable == 1)
			if(velocity == 0) velocity = 4;
		if(gravi_enable == 0)
		ypos += 0.1;
		laydown = 0;
		sneakdown = 0;
	}
		
	if (EscKeyDown)
	{ menushow = 1;	 //DSWindow.close();
	}
}
