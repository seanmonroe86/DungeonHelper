//=============================================================================
// DungeonHelper.cpp
//
// Main function of Dungeon Helper
//

//=============================================================================
// Includes
//
#include <string>
#include <iostream>
#include "DungeonHelper.h"

//=============================================================================
// Menu option enum values
//
enum MENUSELECTION_e
{
	eMINSELECTION,
	eEXITGAME,
	eNEWGAME,
	eLOADGAME,
	eSANDBOXGAME,
	eMAXSELECTION
};

//=============================================================================
// Function prototypes
//
STATUS	ShowMenu(void);
STATUS	ShowMainMenuReselection(void);
STATUS	QuerySelection(MENUSELECTION_e* peMenuSelection);
STATUS	GetMenuSelection(MENUSELECTION_e* peMenuSelection);
STATUS	GetAndActOnSelection(MENUSELECTION_e* peMenuSelection);

//=============================================================================
// main()
//
// Show the menu and query for a selection. Keep going until the user exits.
//
// Args:
//		nNumArgs		= number of arguments passed
//		apszArgs		= array of argument strings
//
// Returns:
//		STATUS			= SUCCESS or ERROR_UNSPECIFIED
//
STATUS main(int nNumArgs, char* apszArgs[])
{
	STATUS			nStatus;
	MENUSELECTION_e eMenuSelection;

	do
	{
		nStatus = GetAndActOnSelection(&eMenuSelection);
		if (ERROR_BADGAME == nStatus)
		{
			ERROR("Bad game %d", nStatus);
		}
		else if (ERROR_UNSPECIFIED == nStatus)
		{
			ERROR("Bad selection %d", nStatus);
			return nStatus;
		}
	}
	while (eEXITGAME != eMenuSelection);

    return nStatus;
}

//=============================================================================
// GetAndActOnSelection()
//
// Get a selection and run a switch on the value.
//
// Args:
//		peMenuSelection	= pointer to menu selection to be populated
//
// Returns:
//		STATUS			= SUCCESS or ERROR_UNSPECIFIED
//
STATUS GetAndActOnSelection(MENUSELECTION_e* peMenuSelection)
{
	STATUS nStatus = SUCCESS;

	if (SUCCESS != GetMenuSelection(peMenuSelection))
	{
		return ERROR_UNSPECIFIED;
	}

	switch (*peMenuSelection)
	{
		case eEXITGAME:
		{
			nStatus = SUCCESS;
			break;
		}

		case eNEWGAME:
		{
			//nStatus = NewGame();
			break;
		}

		case eLOADGAME:
		{
			//nStatus = LoadGame();
			break;
		}

		case eSANDBOXGAME:
		{
			//nStatus = Sandbox();
			break;
		}

		default:
		{
			nStatus = ERROR_BADSWITCH;
		}
	}

	return nStatus;
}

//=============================================================================
// GetMenuSelection()
//
// Show the menu and query for a selection. Keep going until the user exits.
//
// Args:
//		peMenuSelection	= pointer to menu selection to be populated
//
// Returns:
//		STATUS			= SUCCESS or ERROR_UNSPECIFIED
//
STATUS GetMenuSelection(MENUSELECTION_e* peMenuSelection)
{
	if (SUCCESS != ShowMenu())
	{
		ERROR("Bad ShowMenu()");
		return ERROR_UNSPECIFIED;
	}

	if (SUCCESS != QuerySelection(peMenuSelection))
	{
		ERROR("Bad QuerySelection()");
		return ERROR_UNSPECIFIED;
	}

	return SUCCESS;
}

//=============================================================================
// ShowMenu()
//
// Show the menu.
//
// Args:
//		None.
//
// Returns:
//		STATUS			= SUCCESS or ERROR_UNSPECIFIED
//
STATUS ShowMenu(void)
{
	std::string strOutput = "                           \n"
		"===============================================\n"
		"= Dungeon Helper                              =\n"
		"===============================================\n"
		"                                               \n"
		"Main Menu                                      \n"
		"                                               \n"
		"1) Exit                                        \n"
		"2) Load Game                                   \n"
		"3) Save Game                                   \n"
		"4) Sandbox                                     \n"
		"                                               \n"
		"Selection: ";

	std::cout << strOutput;

	return SUCCESS;
}

//=============================================================================
// QuerySelection()
//
// Show the menu and query for a selection. Keep going until the user exits.
//
// Args:
//		peMenuSelection	= pointer to menu selection to be populated
//
// Returns:
//		STATUS			= SUCCESS or ERROR_UNSPECIFIED
//
STATUS QuerySelection(MENUSELECTION_e* peMenuSelection)
{
	char	pszUserInput[BUFFER_SIZE]	= {0};
	int		nFirstChar					= 1;
	bool	fFirstQuery					= true;
	bool	fIsSingleChar				= false;
	bool	fIsInRange					= false;

	do
	{
		//=====================================================================
		// If it isn't the first time around, there was an error
		//
		if (!fFirstQuery)
		{
			ShowMainMenuReselection();
		}

		std::cin.getline(pszUserInput, sizeof(pszUserInput));
		nFirstChar = pszUserInput[0] - '0';

		//=====================================================================
		// Entry has to be a single character within the menu range
		//
		fIsSingleChar	= ('\0' == pszUserInput[1]);
		fIsInRange		= (eMINSELECTION < nFirstChar)
					   && (nFirstChar < eMAXSELECTION);

		fFirstQuery = false;
	}
	while (!fIsSingleChar || !fIsInRange);

	*peMenuSelection = static_cast<MENUSELECTION_e>(nFirstChar);
	
	return SUCCESS;
}

//=============================================================================
// ShowMainMenuReselection()
//
// Show an error message for a bad menu selection.
//
// Args:
//		None.
//
// Returns:
//		STATUS			= SUCCESS or ERROR_UNSPECIFIED
//
STATUS ShowMainMenuReselection(void)
{
	std::string strOutput = "             \n"
		"Erroneous input. Make a selection: ";

	std::cout << strOutput;

	return SUCCESS;
}
