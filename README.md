ds_game
=======
+-----------------+
|Before Compiling:|
+-----------------+
You probably need the following Librarys:

- sudo apt-get install libsfml-dev //SFML Library
- sudo apt-get install libglew-dev //GLEW Library
- sudo apt-get install freeglut3-dev //Glut Library

+-----------------+
|Compile the Game:|
+-----------------+

Makefile:
- "$ make" to compile and then start the game	
- "$ make install" to compile the game
- "$ make run" to start the game
- "$ make count" to count all the lines of code


+----------------------+
|Controlls in the Game:|
+----------------------+
- WASD		-	Movement
- Mouse		-	Camera
- "SPACE" 	-	Jumping
- "F"		- 	Free-Flying
- "G"		-	Normal Gravity
- "ESC"		- 	Exit-Game
- "C"		-	Sneak
- "Y"		-	Lay-Down
- LMouse 	- 	Shoot a red Ball
- RMouse	-	Zoom


+-----------+
|Known Bugs:|
+-----------+

- Text in the Menu is not visible
- Shooting and flying inaccuracy 
- Problems with the collision
- Problems with texture drawing
