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

im = Image.open("atascii.png")

width = im.size[0]
height = im.size[1]
n = (width / 8) * (height / 8)

px = list(im.getdata())

file = open("font.c", "w")

cx = 0
cy = 0
for i in range(0, n):
	c = "// ascii " + str(i) + "\n"
	
	for l in range(0, 8):
		c += "0b"
		c += "0" + str(GetPixel(px, (cx * 8) + 0, (cy * 8) + l, width))
		c += "0" + str(GetPixel(px, (cx * 8) + 1, (cy * 8) + l, width))
		c += "0" + str(GetPixel(px, (cx * 8) + 2, (cy * 8) + l, width))
		c += "0" + str(GetPixel(px, (cx * 8) + 3, (cy * 8) + l, width))
		c += ", 0b"
		c += "0" + str(GetPixel(px, (cx * 8) + 4, (cy * 8) + l, width))
		c += "0" + str(GetPixel(px, (cx * 8) + 5, (cy * 8) + l, width))
		c += "0" + str(GetPixel(px, (cx * 8) + 6, (cy * 8) + l, width))
		c += "0" + str(GetPixel(px, (cx * 8) + 7, (cy * 8) + l, width))
		c += ",\n"
		'''c += str(GetPixel(px, (cx * 8) + 0, (cy * 8) + l, width))
		c += str(GetPixel(px, (cx * 8) + 1, (cy * 8) + l, width))
		c += str(GetPixel(px, (cx * 8) + 2, (cy * 8) + l, width))
		c += str(GetPixel(px, (cx * 8) + 3, (cy * 8) + l, width))
		c += str(GetPixel(px, (cx * 8) + 4, (cy * 8) + l, width))
		c += str(GetPixel(px, (cx * 8) + 5, (cy * 8) + l, width))
		c += str(GetPixel(px, (cx * 8) + 6, (cy * 8) + l, width))
		c += str(GetPixel(px, (cx * 8) + 7, (cy * 8) + l, width))
		c += "\r\n"'''
		
	file.write(c)
		
	cx += 1
	if cx >= (width / 8):
		cy += 1
		cx = 0
		
file.close()