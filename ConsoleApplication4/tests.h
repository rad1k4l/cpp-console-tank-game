#pragma once
#include "pch.h"
#include "conio.h"
#include "defines.h"
#include "tank.h"
#include "pages.h"
#include <thread>
#include "border.h"
using namespace std;

void gunTest() {
	
	/*
		enemy.sh.update();
		tank enemy;
		enemy.shoot();

	*/

	_tank.shoot();

	return;
}




void thread1() {
	
	loop{
	while (_tank.position.blocked) { Sleep(2); }

		_tank.dynamic.select(1)->right();
		Sleep(100);
	}
}


void thread2() {

	loop{
	while (_tank.position.blocked) { Sleep(2); }

		_tank.dynamic.select(0)->right();
		Sleep(100);
	}
}

void dynamicTankWithThreadTest() {
	_tank.dynamic.create(2);

	_tank.dynamic.get(0)[d_color] = blue;
	_tank.dynamic.get(0)[d_x] = 10;
	_tank.dynamic.get(0)[d_y] = 10;

	_tank.dynamic.get(1)[d_x] = 15;
	_tank.dynamic.get(1)[d_y] = 10;
	_tank.dynamic.get(1)[d_color] = green;

	thread th(thread1);

	thread2();

	th.join();
}



void dynamicTankTest() {
	_tank.dynamic.create(2);

	_tank.dynamic.get(0)[d_color] = blue;
	_tank.dynamic.get(0)[d_x] = 10;
	_tank.dynamic.get(0)[d_y] = 10;

	_tank.dynamic.get(1)[d_x] = 15;
	_tank.dynamic.get(1)[d_y] = 10;
	_tank.dynamic.get(1)[d_color] = green;
	
	loop{
		_tank.dynamic.select(1)->down();
		Sleep(100);

		_tank.dynamic.select(0)->right();
		Sleep(100);

	}
}

void tankTest() {
 
	tank introTank2;

	introTank2.position._color = green;

	int key;
	loop{
	Sleep(100);
	if (_kbhit()) {
		key = _getch();

		switch (key)
		{

		case 72:
			introTank2.position.up();
			break;

		case 75:
			introTank2.position.left();

			break;

		case  80:
			introTank2.position.down();

			break;
		case 77:
			introTank2.position.right();
			break;
		case 224:
			break;
		case 'q':
			introTank2.shoot();
			break;
		
		}
	}
	introTank2.sh.update();

				cursor.position.set(16, 10);
				print "Screen size : ";

	}
}