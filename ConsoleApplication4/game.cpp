#pragma once

#include "pch.h"
#include <iostream>
#include <string>
#include "time.h"
#include "core.h"
#include "console.h"
#include "windows.h"
#include <thread>
#include "conio.h"
#include "defines.h"
//#include "pages.h"
#include "tank.h"
#include "tests.h"

using namespace std;

struct conf {

	short bots;

	bool netGame = true;

	struct network {
		
		string ip;
	
		short port;

	}network;

} conf;

void gotoxy(int x , int y) {

	cursor.position.set(x , y);
}

int main (){
	ShowCursor(FALSE);
	
	//tankTest();
	//dynamicTankTest();
	dynamicTankWithThreadTest();

	_tank.dynamic.deleteAll();
	
	return 0;
}