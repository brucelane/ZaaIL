#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "include/IL/il.h"

int* tBuffer;
int offset_x = 0;
int offset_y = 0;
int offset_z = 0;
int width = 0;
int height = 0;
int depth = 0;

int* getPixels(int offset_x, int offset_y, int offset_z, int width, int height, int depth) 
{

	int bytes_read;
	int full_width;
	int full_height;
	int full_depth;
	int bpp;
	int bpc;
	int i;
	char r, g, b, a;
	unsigned int byte;
	ILubyte * bytes;
 
	// Get the values from the library
	bpp = ilGetInteger(IL_IMAGE_BPP);
	bpc = ilGetInteger(IL_IMAGE_BPC);
	full_width = ilGetInteger(IL_IMAGE_WIDTH);
	full_height = ilGetInteger(IL_IMAGE_HEIGHT);
	full_depth = ilGetInteger(IL_IMAGE_DEPTH);
 
	// Check the given values
	if (offset_x + width > full_width)
		width = (full_width - offset_x);
	if (offset_y + height > full_height)
		height = (full_height - offset_y);
	if (offset_z + depth > full_depth)
		depth = (full_depth - offset_z);
 
	// Now get the information from the library
	bytes_read = width * height * depth * 4 * bpc;
	tBuffer = (int*)malloc( bytes_read );
	bytes = (ILubyte*)malloc(bytes_read);
	ilCopyPixels(offset_x, offset_y, offset_z, width, height, depth, IL_RGBA, IL_UNSIGNED_BYTE, bytes);
 
	// Switch RGBA to ARGB
	for (i=0; i < bytes_read; i+=4)
	{
		r = bytes[i];
		g = bytes[i+1];
		b = bytes[i+2];
		a = bytes[i+3];
 
		bytes[i] = a;
		bytes[i+1] = r;
		bytes[i+2] = g;
		bytes[i+3] = b;
	}
 
	// Copy the pixels into the bytes array
	AS3_SetS(tBuffer, "position", NULL);// was data
	AS3_ByteArray_writeBytes(tBuffer, bytes, bytes_read);
 
	// Free up the memory
	free(bytes);
 	return tBuffer;//&(tBuffer[0]);//return the pointer to the screen buffer

}