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

void StateGameOver()
{
	if(winnerState == 3)
		DrawString(0, 44, "   Tie Game!");
	else if(winnerState == 1)
	{
		DrawString(0, 44, "    P1 Won!");
		p1Score++;
	}
	if(winnerState == 2)
	{
		DrawString(0, 44, "    P2 Won!");
		p2Score++;
	}
	fadein(0, 255, 0, 0);
	
	WaitVsync(10);
	
	gameState = STATE_MENU;
	
	fadeout();
}
