#include "DungeonHelper.h"

enum MENUSELECTION_e
{
	eExit,
	eNew,
	eLoad,
	eSand
};

MENUSELECTION_e GetMenuSelection(void);

STATUS main()
{
	MENUSELECTION_e eMenuSelection = GetMenuSelection();
	
	switch (eMenuSelection)
	{
		case eExit:
		{
			break;
		}
		case eNew:
		{
			// NewGame();
			break;
		}
		case eLoad:
		{
			// LoadGame();
			break;
		}
		case eSand:
		{
			// Sandbox();
			break;
		}
		default:
		{
			return ERROR_UNSPECIFIED;
		}
	}

    return SUCCESS;
}

MENUSELECTION_e GetMenuSelection(void)
{
	// show main menu
		// exit
		// load game environment
		// new game environment
		// sandbox environment (nothing is saved)

	return eExit;
}
