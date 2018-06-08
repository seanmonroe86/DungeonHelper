//=============================================================================
// DungeonHelper.h
//
// Common defines, values, typedefs, etc for the Dungeon Helper project.
//
#ifndef DUNGEONHELPER_H_
#define DUNGEONHELPER_H_

//=============================================================================
// Project-wide includes
//
#include <stdio.h>

//=============================================================================
// Defines
//
#define SUCCESS				0x00
#define ERROR_UNSPECIFIED	0x01

#define	ERROR_BADGAME		0x10
#define	ERROR_BADSELECTION	0x11
#define	ERROR_BADSWITCH		0x12

#define BUFFER_SIZE			128

#define ERROR(...)			printf("\n\nERROR: " __VA_ARGS__)

//=============================================================================
// Typedefs
//
typedef int STATUS;



#endif // DUNGEONHELPER_H_
