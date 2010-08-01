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

void FillArea1(char x1, char y1, char x2, char y2, char fill)
{
	for(char x = x1; x < x2; x++)
		for(char y = y1; y < y2; y++)
			if(!EmptyPixel(x, y))
				PutPixel(x, y, fill);
}

void StateMenu()
{	
//	DrawString(0, 15, "     Tron!");
	DrawLogo();
	DrawString(0, 87, "             P2");
	DrawString(0, 57, "   Ready Up!");
	DrawString(0, 67, "    (start)");
	DrawString(0, 87, "P1");
	DrawChar(56, 87, ':');
	DrawNumber(64, 87, p2Score);
	DrawNumber(40, 87, p1Score);
	
	if(firstMenu == 1)
		firstMenu = 0;
	else
		fadein(0, 255, 14, 192);
	
	/*palette[0] = 0;   // black
	palette[1] = 255; // white
	palette[2] = 14;  // red
	palette[3] = 192; // blue*/
	
	char pReady[2] = {0, 0};
	
	//FillArea1(0, 87, 16, 95, 2);
	//FillArea1(103, 87, 119, 95, 3);
	
	while(!pReady[0] || !pReady[1])
	{
		WaitVsync(1);
		
		UpdateInputs();
		
		for(int i = 0; i < 2; i++)
		{
			if(btnPressed[i] & BTN_START)
			{
				pReady[i] = 1;
				FillArea1(i * 103, 87, (i * 103) + 16, 95, 3 - i);
			}
		}
	}
	
	fadeout();
	
	gameState = STATE_PLAY;
	
	DrawString(0, 44, "      Go!");
	WaitVsync(30);
	ClearVram();
}
