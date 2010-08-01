#!/usr/bin/env python
'''
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
'''

from PIL import Image

def GetPixel(ls, x, y, width):
	return ls[(y * width) + x]

im = Image.open("tron.png")

px = list(im.getdata())

file = open("logo.c", "w")

# rearrange colors
for i in range(0, len(px)):
	if px[i] == 1:
		px[i] = 3
	elif px[i] == 3:
		px[i] = 1

file.write("const char logo[] PROGMEM = { ")
for y in range(0, 96):
	for x in range(0, 30):
		c = 0
		
		c += GetPixel(px, (x * 4) + 0, y, 120) << 6
		c += GetPixel(px, (x * 4) + 1, y, 120) << 4
		c += GetPixel(px, (x * 4) + 2, y, 120) << 2
		c += GetPixel(px, (x * 4) + 3, y, 120) << 0

		file.write(str(hex(c)) + ", ")

file.write("};")
file.close()
