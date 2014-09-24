#include "ZaaIL.c"
#include <stdlib.h>
#include "AS3/AS3.h"

// Mark the functions declaration with a GCC attribute specifying the
// AS3 signature we want it to have in the generated SWC. The functions will
// be located in the Zaa.IL namespace.

void ilGetPixels()  __attribute__((used,
	annotate("as3sig:public function ilGetPixels(offset_x0:int,offset_y0:int,offset_z0:int,width0:int,height0:int,depth0:int):uint"),
	annotate("as3package:Zaa.IL")));

void ilGetPixels()
{
	int* result;
	//copy the AS3 resolution variables offset_x0,offset_y0,width0,height0,depth0
	// (parameters of the swc function ilGetPixels) 
	// to C variables offset_x, offset_y, offset_z, width, height, depth in ZaaIL.c
	AS3_GetScalarFromVar(offset_x,offset_x0);
	AS3_GetScalarFromVar(offset_y,offset_y0);
	AS3_GetScalarFromVar(offset_z,offset_z0);
	AS3_GetScalarFromVar(width,width0);
	AS3_GetScalarFromVar(height,height0);
	AS3_GetScalarFromVar(depth,depth0);
	//get the pointer of the screen buffer
	result = getPixels(offset_x, offset_y, offset_z, width, height, depth);
	// return the result (using an AS3 return rather than a C/C++ return)
	AS3_Return(result);
}