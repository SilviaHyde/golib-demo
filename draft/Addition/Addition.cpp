#include "WolframLibrary.h"
// #include "libgoutil.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int Addition(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	mint x,y;
	mint result;
	x = MArgument_getInteger(Args[0]);
	y = MArgument_getInteger(Args[1]);
	result = x+y;
	MArgument_setInteger(Res,result);
	return LIBRARY_NO_ERROR;
}

// EXTERN_C DLLEXPORT int MMinus(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
//   mint x,y;
//   mint result;
//   x = MArgument_getInteger(Args[0]);
//   y = MArgument_getInteger(Args[1]);
//   result = (mint)Minus((int)x, (int)y);
//   MArgument_setInteger(Res,result);
//   return LIBRARY_NO_ERROR;
// }