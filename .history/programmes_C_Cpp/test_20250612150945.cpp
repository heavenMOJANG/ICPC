#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Pi 3.1415926
long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam);
BOOL InitWindowsClass(HINSTANCE hInstance);
BOOL InitWindows(HINSTANCE hInstance, int nCmdShow);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG Message;
	if (!InitWindowsClass(hInstance))		return FALSE;
	if (!InitWindows(hInstance, nCmdShow))	return FALSE;
	while (GetMessage(&Message, 0, 0, 0))	
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}
long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam)
{
	HDC hDC;   					
	HPEN hPen;					
	PAINTSTRUCT PtStr; 		
	int n = 25;
	POINT points[25];
	double angel = 2 * Pi / n;
	for (int i = 0; i < n; i++)
	{
		points[i].x = static_cast<long>(320 + 180 * cos(i*angel));
		points[i].y = static_cast<long>(250 + 180 * sin(i*angel));
	}
	switch (iMessage)  			
	{
	case WM_PAINT:    		
		hDC = BeginPaint(hWnd, &PtStr);
		for (int i = 0; i < 25; i++)
		{
            hPen = (HPEN)GetStockObject(NULL_PEN); 
		    SelectObject(hDC, hPen);    	
			LineTo(hDC, points[i].x, points[i].y);  		
			DeleteObject(hPen); 		
			if (i == 0)
			{
				for (int j = 1; j < n; j++)
				{
					switch (j % 6)
					{
					case 1:
					case 2:
						hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); 
						break;
					case 3:
					case 4:
						hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0)); 
						break;
					case 5:
					case 0:
						hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255)); 
						break;
					}
					SelectObject(hDC, hPen);  	
					LineTo(hDC, points[j].x, points[j].y);
					MoveToEx(hDC, points[i].x, points[i].y, NULL);
					DeleteObject(hPen);    
				}
			}
			else
			{
				for (int j = i + 1; j < n; j++)
				{
					switch (j % 6)
					{
					case 1:
					case 2:
						hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
						break;
					case 3:
					case 4:
						hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
						break;
					case 5:
					case 0:
						hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255)); 
						break;
					}
					SelectObject(hDC, hPen);  	
					LineTo(hDC, points[j].x, points[j].y);
					MoveToEx(hDC, points[i].x, points[i].y, NULL);
					DeleteObject(hPen);    
					Sleep(50);
				}
			}
		}

		EndPaint(hWnd, &PtStr);  
		return 0;
	case WM_DESTROY: 
		PostQuitMessage(0);
		return 0;
	default:
		return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
}
BOOL InitWindows(HINSTANCE hInstance, int nCmdShow) 
{
	HWND hWnd;
	hWnd = CreateWindow("WinFill",  		 	 
		"                                                                         万花筒",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);			
	UpdateWindow(hWnd);
	return TRUE;
}
BOOL InitWindowsClass(HINSTANCE hInstance) 		
{
	WNDCLASS WndClass;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, "END");
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = "WinFill";
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	return RegisterClass(&WndClass);
}