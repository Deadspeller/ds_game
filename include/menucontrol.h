
extern bool MoveUpKey, MoveDownKey, MoveUseKey;
extern bool menushow;

void menucontrol(char keycode)
{
	if (keycode == 'U')
	{	
		if(drawoptions==0)
		{
			if(menusel == 0) menusel = 3;
			else if(menusel == 1) menusel = 0;
			else if(menusel == 2) menusel = 1;
			else if(menusel == 3) menusel = 2;
		}	
	}


	if (keycode == 'J')
	{	
		if(menusel == 3) menusel = 0;
		else if(menusel == 0) menusel = 1;
		else if(menusel == 1) menusel = 2;
		else if(menusel == 2) menusel = 3;
	}


	if (keycode == 'E')
	{
			if(menusel == 0) 
			{
				menushow=0;
			}
			if(menusel == 3) exit(0);
			if(menusel == 2) drawoptions=2;	
	}


		
	if (keycode == 'X')
	{	 
		if(drawoptions == 2) drawoptions = 0; 
		else DSWindow.close();
	}

}
