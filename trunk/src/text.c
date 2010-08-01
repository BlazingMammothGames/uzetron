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

#include "../gfx/font.c"

void DrawChar(char x, char y, char c)
{
	x /= 4;
	for(int line = 0; line < 8; line++)
	{
		vram[(30 * (y + line)) + x] = pgm_read_byte(&(font[(c * 16) + (2 * line)]));
		vram[(30 * (y + line)) + x + 1] = pgm_read_byte(&(font[(c * 16) + (2 * line) + 1]));
	}
}

void DrawNumber(char x, char y, char n)
{
	DrawChar(x, y, (char)((n / 8) + 48));
	DrawChar(x+8, y, (char)((n % 8) + 48));
}

void DrawString(char x, char y, char *str)
{
	for(int i = 0; i < strlen(str); i++)
	{
		DrawChar(x * 8, y, str[i]);
		x++;
	}
}
