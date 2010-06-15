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

#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "uzebox.h"

#include "text.c"
#include "input.c"
#include "gfx.c"

#define STATE_MENU	(0)
#define STATE_PLAY	(1)
#define STATE_GAMEOVER	(2)

int gameState = STATE_MENU;
int winnerState = 0;

#include "state_menu.c"
#include "state_play.c"
#include "state_gameover.c"

int main()
{
	// clear the vram..
	ClearVram();
	SetColorBurstOffset(4);
	
	// initialize the palette colours
	/*palette[0] = 0;   // black
	palette[1] = 192; // blue
	palette[2] = 14;  // red
	palette[3] = 255; // white*/
	
	DrawMammoth();
	fadein(0, 47, 13, 255);
	WaitVsync(120);
	fadeout();
	
	DrawLogo();
	fadein(0, 192, 14, 255);
	WaitVsync(120);
	fadeout();
	
	while(1)
	{
		if(gameState == STATE_MENU)
			StateMenu();
		else if(gameState == STATE_PLAY)
			StatePlay();
		else if(gameState == STATE_GAMEOVER)
			StateGameOver();
	}
}
