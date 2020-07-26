#pragma once
#include "pch.h"
#include <iostream>
#include <windows.h>
#include "colors.h"

struct cursor
{


	int h = 5;
	struct position
	{
		int x = 0;
		int y = 0;
		COORD coord;
		HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);

		bool _x(int x)
		{


			this->x = x;
			this->coord.X = x;

			return true;
		}

		bool _y(int y)
		{
			this->y = y;
			this->coord.Y = y;

			coord.Y = this->y;

			return true;
		}

		position* set(int x, int  y)
		{


			this->_x(x);
			this->_y(y);

			SetConsoleCursorPosition(this->handler, this->coord);

			return this;
		}

		position* up(int num = 1) {
			int up = this->y - num;
			if (up >= 0)
			{
				this->set(this->x, up);
			}
			return this;
		}

		position* left(int num = 1) {

			int left = this->x - num;

			if (left >= 0)
			{
				this->set(left, this->y);
			}
			return this;
		}

		position* down(int num = 1) {

			int down = this->y + num;

			if (down >= 0)
			{
				this->set(this->x, down);
			}
			return this;
		}

		position* right(int num = 1) {
			int right = this->x + num;

			if (right >= 0)
			{
				this->set(right, this->y);
			}
			return this;
		}
		position* reset() {
			this->set(0, 0);

			return this;
		}


	} position;

	struct size {

		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int columnsx() {

			int columns;

			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
			columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

			return columns;
		}
		int rowsy() {

			int  rows;

			system("cls");
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
			rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;


			return rows;
		}

	}size;

	struct _color
	{
		bool set(int color)
		{
			HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handler, color);
			return true;
		}
		bool reset() {

			this->set(white);

			return true;

		}

	} color;


}cursor;



