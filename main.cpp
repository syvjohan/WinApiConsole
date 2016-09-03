#include <windows.h>
#include <cassert> //Remove later

#include "Keyboard.h"

#define internal static
#define global_variable static


global_variable bool running;


//Text
global_variable int textOffsetX = 10;
global_variable int textOffsetY = 20;

global_variable HDC deviceContext;
global_variable RECT window;

struct axisBox {
	float x;
	float y;
	float w;
	float h;
};

#define MAX_TEXT_SIZE 128
struct String {
	char data[MAX_TEXT_SIZE];
	int length;
	axisBox box;
};

global_variable int    nextTextPositionY;

global_variable String welcomeText;
global_variable String commandText;
global_variable String input;

internal void
Draw(HWND window) {
	//Window
	PAINTSTRUCT paint;
	deviceContext = BeginPaint( window, &paint );
	int x         = paint.rcPaint.left;
	int y         = paint.rcPaint.top;
	int width     = paint.rcPaint.right - paint.rcPaint.left;
	int hight     = paint.rcPaint.bottom - paint.rcPaint.top;

	//Text in window
	SetBkMode( deviceContext, TRANSPARENT );
	BOOL text = TextOut( deviceContext, welcomeText.box.x, welcomeText.box.y, welcomeText.data, welcomeText.length );
	assert( text );

	text = TextOut( deviceContext, commandText.box.x, commandText.box.y, commandText.data, commandText.length );
	assert( text );

	EndPaint( window, &paint );
}

internal void 
Update() {
	//Text: input
	input.length = 0;
	input.data[0] = '\0';
	input.box.x = window.right + textOffsetX;
	input.box.y = nextTextPositionY;
	//nextTextPositionY += textOffsetY;
}

internal void
Init() {
	//Start position
	nextTextPositionY = window.top;

	//Text: welcome
	const char *welcome =  "Terminal is ready to go!";	
	welcomeText.length  =  lstrlen( welcome );
	lstrcpy( welcomeText.data, welcome );	
	welcomeText.box.x   =  window.right + textOffsetX;
	welcomeText.box.y   =  nextTextPositionY;
	nextTextPositionY   += textOffsetY;

	//Text: command
	const char *cmd    =  "Master Command Me: ";
	commandText.length =  lstrlen( cmd );
	lstrcpy( commandText.data, cmd );
	commandText.box.x  =  window.right + textOffsetX;
	commandText.box.y  =  nextTextPositionY;
	nextTextPositionY  += textOffsetY;
}

LRESULT CALLBACK
MainWindowCallback( HWND window, UINT message, WPARAM wParam, LPARAM lParam ) {
	Update();
	LRESULT result = 0;

	switch ( message ) {
		case WM_SIZE:
		{
			OutputDebugStringA( "WM_SIZE\n" );
			break;
		}

		case WM_DESTROY:
		{
			OutputDebugStringA( "WM_DESTROY\n" );
			running = false;
			break;
		}

		case WM_CLOSE:
		{
			OutputDebugStringA( "WM_CLOSE\n" );
			running = false;
			break;
		}

		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
		case WM_KEYDOWN:
		case WM_KEYUP:
		{
			KeyboardVKInput( wParam );
			break;
		}

		case WM_CHAR:
		{
			input.data[++input.length] = KeyboardCharInput( wParam );
			break;
		}

		case WM_PAINT:
		{
			Draw(window);
			OutputDebugStringA( "WM_PAINT\n" );
			break;
		}

		default:
		{
			OutputDebugStringA( "WM_DEFAULT\n" );
			return DefWindowProc( window, message, wParam, lParam );
			break;
		}

	}
	return( result );
}

int CALLBACK
WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {
	Init();
	running                   = false;

	//Window
	HBRUSH windowBrush        = CreateSolidBrush( RGB( 0, 0, 255 ) );
	WNDCLASSA windowClass     = {};
	windowClass.style         = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc   = MainWindowCallback;
	windowClass.hInstance     = hInstance;
	windowClass.lpszClassName = "console";
	windowClass.hbrBackground = windowBrush;


	if ( RegisterClass( &windowClass ) ) {
		HWND window = CreateWindowEx( 0, windowClass.lpszClassName,	"console",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,	CW_USEDEFAULT,
			CW_USEDEFAULT, 0, 0, hInstance,	0 );

		if ( window ) {
			deviceContext = GetDC( window );

			running = true;
			while ( running ) {

				MSG message;
				while ( PeekMessage( &message, 0, 0, 0, PM_REMOVE ) ) {
					if ( message.message == WM_QUIT ) {
						running = false;
						break;
					}

					TranslateMessage( &message );
					DispatchMessageA( &message );
					Update();
				}
			}
		}

	}

	return 0;
}
//NOTE flytta allting till Draw och se till att meddelandena skickas korrekt.