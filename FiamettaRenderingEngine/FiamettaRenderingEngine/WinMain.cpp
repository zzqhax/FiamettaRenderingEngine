#include<Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	switch (msg) {
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int		  nCmdShow)
{
	const auto pClassName = "FiamettaGenderingEngine";
	//register window class
	//wc is window class
	/*----------------------------------------------
	The WNDCLASSEX structure is similar to the WNDCLASS
	 structure. There are two differences. WNDCLASSEX
	 includes the cbSize member, which specifies the
	 size of the structure, and the hIconSm member, which
	 contains a handle to a small icon associated with the
	 window class.
	----------------------------------------------*/

	/*----------------------------------------------
	Syntax
	typedef struct tagWNDCLASSEXA {
		UINT      cbSize;
		UINT      style;
		WNDPROC   lpfnWndProc;
		int       cbClsExtra;
		int       cbWndExtra;
		HINSTANCE hInstance;
		HICON     hIcon;
		HCURSOR   hCursor;
		HBRUSH    hbrBackground;
		LPCSTR    lpszMenuName;
		LPCSTR    lpszClassName;
		HICON     hIconSm;
	} WNDCLASSEXA, *PWNDCLASSEXA, *NPWNDCLASSEXA, *LPWNDCLASSEXA;
	----------------------------------------------*/
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);			//The size, in bytes, of this structure. Set this member to . Be sure to set this member before calling the GetClassInfoEx function.sizeof(WNDCLASSEX)
	wc.style = CS_OWNDC;			//The class style(s). This member can be any combination of the Class Styles.
	wc.lpfnWndProc = DefWindowProc;	//A pointer to the window procedure. You must use the CallWindowProc function to call the window procedure.
	wc.cbClsExtra = 0;				//The number of extra bytes to allocate following the window-class structure. The system initializes the bytes to zero.
	wc.cbWndExtra = 0;				//The number of extra bytes to allocate following the window instance. The system initializes the bytes to zero. If an application uses WNDCLASSEX to register a dialog box created by using the CLASS directive in the resource file, it must set this member to DLGWINDOWEXTRA.
	wc.hInstance = hInstance;		//A handle to the instance that contains the window procedure for the class.
	wc.hIcon = nullptr;				//A handle to the class icon. This member must be a handle to an icon resource. If this member is NULL, the system provides a default icon.
	wc.hCursor = nullptr;			//A handle to the class cursor. This member must be a handle to a cursor resource. If this member is NULL, an application must explicitly set the cursor shape whenever the mouse moves into the application's window.
	wc.hbrBackground = nullptr;		//A handle to the class background brush. This member can be a handle to the brush to be used for painting the background, or it can be a color value. A color value must be one of the following standard system colors (the value 1 must be added to the chosen color). 
	wc.lpszMenuName = nullptr;		//Pointer to a null-terminated character string that specifies the resource name of the class menu, as the name appears in the resource file. If you use an integer to identify the menu, use the MAKEINTRESOURCE macro. If this member is NULL, windows belonging to this class have no default menu.
	wc.lpszClassName = pClassName;	//A pointer to a null-terminated string or is an atom. If this parameter is an atom, it must be a class atom created by a previous call to the RegisterClass or RegisterClassEx function. The atom must be in the low-order word of lpszClassName; the high-order word must be zero.If lpszClassName is a string, it specifies the window class name.The class name can be any name registered with RegisterClass or RegisterClassEx, or any of the predefined control - class names.		The maximum length for lpszClassName is 256. If lpszClassName is greater than the maximum length, the RegisterClassEx function will fail.
	wc.hIconSm = nullptr;			//A handle to a small icon that is associated with the window class. If this member is NULL, the system searches the icon resource specified by the hIcon member for an icon of the appropriate size to use as the small icon.
	RegisterClassEx(&wc);
	//create window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		"FiamettaGenderingEngine",
		WS_CAPTION | WS_MINIMIZE | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);
	//show the window
	ShowWindow(hWnd, SW_SHOW);
	
	MSG msg;
	BOOL gResult;
	while ( (gResult = GetMessage(&msg, nullptr, 0, 0) > 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1) {
		return -1;
	}
	else {
		return msg.wParam;
	}
}