#include <stdlib.h>
#include <stdio.h>

#include "ugui_sim.h"
#include "ugui.h"
#include "ugui_button.h"
#include "ugui_checkbox.h"
#include "ugui_textbox.h"
#include "ugui_image.h"
#include "ugui_progress.h"

// Simulator Variables
#define WIDTH               296
#define HEIGHT              152
#define SCREEN_MULTIPLIER   1
#define SCREEN_MARGIN       0
#define WINDOW_BACK_COLOR   0x00
#define MAX_OBJS 15

#define INITIAL_MARGIN  3
#define BTN_WIDTH       100
#define BTN_HEIGHT      30
#define CHB_WIDTH       100
#define CHB_HEIGHT      14

#define OBJ_Y(i)        BTN_HEIGHT*i+(INITIAL_MARGIN*(i+1))

UG_GUI ugui;
UG_WINDOW wnd;
UG_TEXTBOX txt0;
UG_TEXTBOX txt1;
UG_TEXTBOX txt2;
UG_PROGRESS pgb0;
UG_OBJECT objs[MAX_OBJS];


void GUI_Setup(UG_DEVICE *device)
{
	//Setup UGUI
	UG_Init(&ugui, device);

	UG_FillScreen(C_BLACK);

	//Setup Window
	UG_WindowCreate(&wnd, objs, MAX_OBJS, 0);
	UG_WindowSetTitleTextFont(&wnd, &FONT_6X8);
	UG_WindowSetTitleText(&wnd, "ePaper GUI");

	UG_TextboxCreate(&wnd, &txt1, TXB_ID_1, UGUI_POS(INITIAL_MARGIN, OBJ_Y(0), 280, 30));
	UG_TextboxSetAlignment(&wnd, TXB_ID_1, ALIGN_CENTER);
	UG_TextboxSetFont(&wnd, TXB_ID_1, &FONT_12X20);
	UG_TextboxSetText(&wnd, TXB_ID_1, "Hi little GUI!");

	UG_TextboxCreate(&wnd, &txt2, TXB_ID_2, UGUI_POS(INITIAL_MARGIN, OBJ_Y(1), 280, 45));
	UG_TextboxSetAlignment(&wnd, TXB_ID_1, ALIGN_CENTER);
	UG_TextboxSetFont(&wnd, TXB_ID_2, &FONT_22X36);
	UG_TextboxSetText(&wnd, TXB_ID_2, "Hi STM32!");

	// Progress Bar
	UG_ProgressCreate(&wnd, &pgb0, PGB_ID_0, UGUI_POS(INITIAL_MARGIN, OBJ_Y(2)+25, 280, 20));
	UG_ProgressSetProgress(&wnd, PGB_ID_0, 0);

	UG_WindowShow(&wnd);
}

void GUI_Process()
{
	static UG_U8 tick = 0;
	static UG_U8 page = 0;

	UG_ProgressSetProgress(&wnd, PGB_ID_0, tick * 20);

	if(tick >= 5)
	{
		page++;
		tick = 0;
	}
	else
	{
		tick++;
	}

	if(page == 1)
	{
		UG_TextboxSetText(&wnd, TXB_ID_1, "ePaper with STM32");
		UG_TextboxSetFont(&wnd, TXB_ID_2, &FONT_12X20);
		UG_TextboxSetText(&wnd, TXB_ID_2, "github.com/Estylos");
	}
	else if(page == 2)
	{
		UG_TextboxSetText(&wnd, TXB_ID_1, "ePaper from");
		UG_TextboxSetText(&wnd, TXB_ID_2, "Pervasive Displays");
	}
	else if(page == 3)
	{
		UG_TextboxSetText(&wnd, TXB_ID_1, "with custom driver");
		UG_TextboxSetText(&wnd, TXB_ID_2, "and the UGUI library");
	}
	else if(page == 4)
	{
		UG_TextboxSetText(&wnd, TXB_ID_1, "github.com/Estylos");
		UG_TextboxSetFont(&wnd, TXB_ID_2, &FONT_22X36);
		UG_TextboxSetText(&wnd, TXB_ID_2, ":)");
		page = 0;
	}

	UG_Update();
}
