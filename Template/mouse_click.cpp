#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <time.h>


#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
using namespace std;

int main() {


    POINT p;
    GetCursorPos(&p);
    cout << p.x << " " << p.y << '\n';
    bool ok = 0;
    while(true){
        ok ^= 1;
        mouse_event(MOUSEEVENTF_LEFTDOWN , 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        if(ok == 0)
            _sleep(2000);
        else
            _sleep(8000);

    }



}






