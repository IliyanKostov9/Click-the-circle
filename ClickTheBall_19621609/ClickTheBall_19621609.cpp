// ClickTheBall_19621609.cpp : Defines the entry point for the application.
//

//Iliyan Kostov
// Specialty: SIT
// Group : 4
// Course : 2


#include "stdafx.h"
#include "ClickTheBall_19621609.h"
#include<Windows.h>
#include<time.h>
#include<wingdi.h>
#include<WinUser.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX_LOADSTRING 100
#define TIMER 1



// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	ClickTheBall(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CLICKTHEBALL_19621609, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLICKTHEBALL_19621609));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLICKTHEBALL_19621609));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_CLICKTHEBALL_19621609);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_CLICKTHEBALL:
			DialogBox(hInst,MAKEINTRESOURCE(IDD_CLICKTHEBALL),hWnd,ClickTheBall);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

			



	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}







static HWND hEdit;
int t=0;
int hits=0;

static int rand_left,rand_top,rand_right,rand_down;
static RECT rt;

// Message handler for ClickTheBall box.
INT_PTR CALLBACK ClickTheBall(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	
	POINT point;

	HDC hdc;
	PAINTSTRUCT ps;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
		label:
			case WM_INITDIALOG:
			
				SetTimer(hDlg,TIMER,1000,NULL);
				
				
		SendMessage(hDlg,WM_CREATE,(LPARAM)hEdit,TRUE);
		
		return (INT_PTR)TRUE;
		break;

	case WM_CREATE:

		hEdit = CreateWindow("STATIC",
 NULL
, WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_LEFT | 	ES_MULTILINE | ES_AUTOVSCROLL,
 0, 0,
 500,190,
 hDlg,
 NULL,
 hInst,
 NULL); 


			ShowWindow(hEdit,SW_SHOW);


			return (INT_PTR)TRUE;
		break;

		case WM_SETFOCUS:
			SetFocus(hEdit);
			return 0;

		case WM_SIZE:
			MoveWindow(hEdit,0,0,LOWORD(lParam),HIWORD(lParam),TRUE);
			return 0;

			
			
		case WM_TIMER:



			switch(wParam) {

			
			
		

		case TIMER:



			
			
			srand (time(NULL));

			
			rand_left=rand()%450;
			rand_top=rand()%130;

			rand_right=rand()%60+(rand_left+10);
			rand_down=rand()%60+(rand_top+10);

			
			SetDlgItemInt(hDlg,IDEC_SECONDS,++t,NULL);
			SetDlgItemInt(hDlg,IDEC_HIT,hits,NULL);
			 	
			
			
			 RedrawWindow(hDlg,&rt,NULL,RDW_ERASE | RDW_INVALIDATE  | RDW_INTERNALPAINT | RDW_ERASENOW);


	
			return 0;
			 
				
			}
			
			break;

			

		

			case WM_LBUTTONDOWN:
		

			{
				GetCursorPos(&point);
				ScreenToClient(hEdit,&point);
			
				
				if ( (point.x >= rand_left && point.y>= rand_top) &&  (point.x <=rand_right && point.y <= rand_down)  ) {
				
				++hits;
	
				}
	
			}

			


				

				break;
		
		case WM_PAINT:
			
			hdc=BeginPaint(hEdit,&ps);
		
			{
					GetClientRect(hEdit,&rt);
			
				HPEN hPen=CreatePen(PS_SOLID,1,RGB(0,0,0));

				SelectObject(hdc,hPen);
				HBRUSH hbr=CreateSolidBrush(RGB(255,0,0));
				SelectObject(hdc,hbr);
					
				Ellipse(hdc,rand_left,rand_top,rand_right,rand_down);
				
			
				
			}
		
			EndPaint(hEdit,&ps);
		
		
			break;

		

	

	


	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
