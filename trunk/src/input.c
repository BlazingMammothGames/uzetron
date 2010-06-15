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

// for input..
int btnHeld[2];     // buttons that are held right now
int btnPressed[2];  // buttons that were pressed this frame
int btnReleased[2]; // buttons that were released this frame 
int btnPrev[2];     // buttons that were released this frame 

void UpdateInputs()
{
	for(int i = 0; i < 2; i++)
	{
		btnHeld[i] = ReadJoypad(i);
		btnPressed[i] = btnHeld[i] & (btnHeld[i] ^ btnPrev[i]);
		btnReleased[i] = btnPrev[i] & (btnHeld[i] ^ btnPrev[i]);
		btnPrev[i] = btnHeld[i];
	}
}