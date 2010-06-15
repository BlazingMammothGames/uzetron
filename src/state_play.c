/*
    This file is part of UzeTron.

    UzeTron is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    UzeTron is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with UzeTron.  If not, see <http://www.gnu.org/licenses/>.
*/

void StatePlay()
{
	// initialize the palette colours
	palette[0] = 0;   // black
	palette[1] = 192; // blue
	palette[2] = 14;  // red
	palette[3] = 255; // white
	
	ClearVram();
	
	// initialize the player information
	char x[2] = {20, 99};
	char vx[2] = {1, -1};
	char y[2] = {47, 47};
	char vy[2] = {0, 0};
	
	char gameOver = 0;
	
	char pDied[2] = {0, 0};
	
	// draw the border
	for(int xi = 0; xi < 120; xi++)
	{
		PutPixel(xi, 0, 3);
		PutPixel(xi, 95, 3);
	}
	for(int yi = 0; yi < 96; yi++)
	{
		PutPixel(0, yi, 3);
		PutPixel(119, yi, 3);
	}
	
	// the game loop
	while(!gameOver)
	{	
		WaitVsync(1);
		UpdateInputs();

		for(int i = 0; i < 2; i++)
		{
			if(btnPressed[i] & BTN_UP && vy[i] < 1)
			{
				vx[i] = 0;
				vy[i] = -1;
			}
			if(btnPressed[i] & BTN_DOWN && vy[i] > -1)
			{
				vx[i] = 0;
				vy[i] = 1;
			}
			if(btnPressed[i] & BTN_RIGHT && vx[i] > -1)
			{
				vx[i] = 1;
				vy[i] = 0;
			}
			if(btnPressed[i] & BTN_LEFT && vx[i] < 1)
			{
				vx[i] = -1;
				vy[i] = 0;
			}
			
			// set the old pixel to old colour
			PutPixel(x[i], y[i], i + 1);
			
			// update the positions
			x[i] += vx[i];
			y[i] += vy[i];
		}
		
		// check for game over
		for(int i = 0; i < 2; i++)
			// check for a collision
			if(!EmptyPixel(x[i], y[i]))
				pDied[i] = 1;
		
		if(pDied[0] && pDied[1])
		{
			gameOver = 1;
			winnerState = 3;
		}
		else if(pDied[0])
		{
			gameOver = 1;
			winnerState = 2;
		}
		else if(pDied[1])
		{
			gameOver = 1;
			winnerState = 1;
		}
		
		// only draw the new pixels if it's not game over
		if(!gameOver)
		{	
			// draw the new pixels
			PutPixel(x[0], y[0], 3);
			PutPixel(x[1], y[1], 3);
		}
		else
		{
			fadeout();
			ClearVram();
			palette[0] = 0;
			palette[1] = 255;
			DrawString(0, 44, "   Game Over");
			fadein(0, 255, 0, 0);
			WaitVsync(60);
			fadeout();
				
			gameState = STATE_GAMEOVER;
		}
	}
}
