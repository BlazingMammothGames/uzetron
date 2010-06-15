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

#include "../gfx/mammoth.c"
#include "../gfx/logo.c"

void fadeout(){
	unsigned int r,g,b;	
	unsigned char pal[4];
	pal[0]=palette[0];
	pal[1]=palette[1];
	pal[2]=palette[2];
	pal[3]=palette[3];

	WaitVsync(50);

	for(int v=8;v>=0;v--){
		for(u8 i=0;i<4;i++){
			r=((pal[i]&7)*v)/8;
			g=(((pal[i]>>3)&7)*v)/8;
			b=((((pal[i]>>5)&6)*v)/8)&6;
			palette[i]=(b<<5)|(g<<3)|r;
		}
		WaitVsync(3);
	}

	ClearVram();
	WaitVsync(5);
}

void fadein(unsigned char pal0, unsigned char pal1, unsigned char pal2, unsigned char pal3){
	unsigned int r,g,b;	
	unsigned char pal[4];
	pal[0]=pal0;
	pal[1]=pal1;
	pal[2]=pal2;
	pal[3]=pal3;

	for(char v=0;v<=8;v++){
		for(u8 i=0;i<4;i++){
			r=((pal[i]&7)*v)/8;
			g=(((pal[i]>>3)&7)*v)/8;
			b=((((pal[i]>>5)&6)*v)/8)&6;
			palette[i]=(b<<5)|(g<<3)|r;
		}
		WaitVsync(3);
	}

	palette[0]=pal0;
	palette[1]=pal1;
	palette[2]=pal2;
	palette[3]=pal3;
}

void DrawMammoth()
{
	for(int i = 0; i < (30 * 96); i++)
		vram[i] = pgm_read_byte(&(mammoth[i]));
}

void DrawLogo()
{
	for(int i = 0; i < (30 * 96); i++)
		vram[i] = pgm_read_byte(&(logo[i]));
}

char EmptyPixel(char x, char y)
{
	char cx = x / 4;
	char cy = y;
	
	char ix = x % 4;
	
	return !(vram[(cy * 30) + cx] & (0b11000000 >> (ix * 2)));
}