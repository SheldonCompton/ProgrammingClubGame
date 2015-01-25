#include <windows.h>
#include <xinput.h>
static bool running;

static BITMAPINFO bitmapinfo;
static void *BitMapMemory;
static int ClientWidth;
static int ClientHeight;
void RenderWeirdGradient(int XOffset, int YOffset){

	//drawing loop
	int Width = ClientWidth;
	int Height = ClientHeight;
	int Pitch = Width*4;
	unsigned char* Row = (unsigned char*)BitMapMemory;
	
	for(int Y = 0;Y<Height;Y++){
		unsigned char *Pixel= (unsigned char*)Row;
		for(int X = 0;X<Width;X++){
			
			*Pixel = (unsigned char)X+XOffset; 
			++Pixel;
			*Pixel = 0;
			++Pixel;
			*Pixel =(unsigned char)Y+YOffset;
			++Pixel;
			*Pixel = 0;
			++Pixel;
						
		}
		Row+=Pitch;
	}
	
}

void ResizeDIBsection(int Width,int Height){
	ClientWidth = Width;
	ClientHeight = Height;
	if(&BitMapMemory){
			VirtualFree(BitMapMemory,0,MEM_RELEASE);
	}
	
	bitmapinfo.bmiHeader.biSize=sizeof(bitmapinfo.bmiHeader);
	bitmapinfo.bmiHeader.biWidth=ClientWidth;
	bitmapinfo.bmiHeader.biHeight=-ClientHeight;
	bitmapinfo.bmiHeader.biPlanes=1;
	bitmapinfo.bmiHeader.biBitCount=32;
	bitmapinfo.bmiHeader.biCompression=BI_RGB;
	
		
	int BitMapMemorySize = (ClientWidth*ClientHeight)*4;
	BitMapMemory = VirtualAlloc(0,BitMapMemorySize,MEM_COMMIT,PAGE_READWRITE);
	RenderWeirdGradient(0,0);
	
}
void win32UpdateWindow(HDC DeviceContext,int XOffset,int YOffset){
	int FullWidth = ClientWidth;
	int FullHeight = ClientHeight;
	StretchDIBits(DeviceContext,
	0,0,FullWidth,FullHeight,
	0,0,FullWidth,FullHeight,
	/*X,Y,Width,Height,
	X,Y,Width,Height,*/
	BitMapMemory,
	&bitmapinfo,
	DIB_RGB_COLORS,
    SRCCOPY);
	RenderWeirdGradient(XOffset,YOffset);
}

LRESULT CALLBACK WindowCallBack(
  HWND WinHandle,
  UINT uMsg,
  WPARAM wParam,
  LPARAM lParam
  ){
	  LRESULT Result = 0;
	  switch(uMsg){
		  case WM_KEYDOWN:
			if(wParam == VK_ESCAPE){
				running = false;
			}
		  break;
		  case WM_ACTIVATEAPP:
		  
		  break;
		  case WM_DESTROY:
			running = false;
		  break;
		  case WM_SIZE:
		  {
			RECT clientrec;
			GetClientRect(WinHandle,&clientrec);
			int Width = clientrec.right - clientrec.left;
			int Height = clientrec.bottom - clientrec.top;
			ResizeDIBsection(Width,Height);
			
		  }
			break;
		  case WM_CLOSE:
			running = false;
		  break;
		case WM_PAINT:
		{
			PAINTSTRUCT paint;
			RECT drawrec;
			HDC DeviceContext =	BeginPaint(WinHandle,&paint);
			int X = paint.rcPaint.left;
			int Y = paint.rcPaint.top;
			int Height = paint.rcPaint.bottom - paint.rcPaint.top;
			int Width = paint.rcPaint.right - paint.rcPaint.left;
			GetClientRect(WinHandle,&drawrec);
			win32UpdateWindow(DeviceContext,0,0);
			EndPaint(WinHandle,&paint);
		}
		  break;
		  default:
		  Result = DefWindowProc(WinHandle,uMsg,wParam,lParam);
		  break;
	}
	return Result;
  }

int CALLBACK WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR lpCmdLine,
  int nCmdShow
)
{
	WNDCLASS WindowClass = {};
	
	WindowClass.style=(CS_HREDRAW|CS_VREDRAW);
	WindowClass.lpfnWndProc = WindowCallBack;
	WindowClass.hInstance=hInstance;
	//WindowClass.hIcon;
	WindowClass.lpszClassName="Handmade Hero";
	
	RegisterClass(&WindowClass);
	
	HWND WinHandle = CreateWindowEx(
	0,
    WindowClass.lpszClassName,
    "First Handmade Window",
    (WS_OVERLAPPEDWINDOW|WS_VISIBLE),
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    0,
    0,
    hInstance=WindowClass.hInstance,
    0
	);
	MSG msg;
	
	if(WinHandle){
		running = true;
		int XOffset;
		int YOffset;
		char temp = 0;
		while(running){
			while(PeekMessage(&msg,0,0,0,PM_REMOVE)){
				TranslateMessage(&msg);DispatchMessage(&msg);
				if(msg.message == WM_CLOSE){
					running = false;
				}
			}
			XINPUT_STATE gamePadState;
			if(XInputGetState(0,&gamePadState)==ERROR_SUCCESS){
				//32767
				if(gamePadState.Gamepad.sThumbLX>10000){
					XOffset+=3;
				}
				else if(gamePadState.Gamepad.sThumbLX<-10000){
					XOffset-=3;
				}
				if(gamePadState.Gamepad.sThumbLY>10000){
					YOffset-=3;
				}
				else if(gamePadState.Gamepad.sThumbLY<-10000){
					YOffset+=3;
				}
			}
			else{
				//no controller available
			}
			HDC DeviceContext;
			DeviceContext = GetDC(WinHandle);
			win32UpdateWindow(DeviceContext,XOffset,YOffset);
			ReleaseDC(WinHandle,DeviceContext);
		}
	}
	else{
		//oops
	}
		
	return(0);
}


