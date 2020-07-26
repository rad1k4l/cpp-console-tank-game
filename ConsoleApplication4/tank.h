#pragma once

#include "pch.h"
#include <iostream>
#include "defines.h"
#include "console.h"
#include "border.h"
using namespace std;
bool cursor_blocked = true;

struct tank {


	int* tanks;
	int tip;
	bool blocked = false;


	struct _position {

		int x = 0;
		int y = 0;

		int type;
		int _color;
		bool blocked = false;

		void block() {
			blocked = true;
		}

		void unblock() {
			blocked = false;
		}

		void up() {
			block();
			del();
			cursor.color.set(_color);
			if ((int)type == (int)0)
				y--;
			cursor.position.set(x, y);

			print " " _ tank_char;

			cursor.position.down();
			print tank_char _ tank_char _ tank_char;

			cursor.position.down();
			print tank_char _ " " _ tank_char;
			cursor.color.reset();
			type = 0;
			unblock();
		}

		void down() {
			block();
			del();

			cursor.color.set(_color);
			if (type == 2)
				y++;
			cursor.position.set(x, y);

			print  tank_char _ " " _  tank_char;

			cursor.position.down();
			print tank_char _ tank_char _ tank_char;

			cursor.position.down();
			print " " _ tank_char;
			cursor.color.reset();
			type = 2;
			unblock();
		}

		void left() {
			block();
			del();

			cursor.color.set(_color);
			if (type == 3)
				x--;
			cursor.position.set(x, y);


			print " " _ tank_char _ tank_char;

			cursor.position.down();
			print tank_char _ tank_char _ " ";

			cursor.position.down();
			print " " _ tank_char _ tank_char;
			cursor.color.reset();
			type = 3;
			unblock();
		}

		void right() {

			block();
			del();
			cursor.color.set(_color);
			if (type == 1)
				x++;
			cursor.position.set(x++, y);
			print tank_char _ tank_char;

			cursor.position.down()->right();
			print tank_char _ tank_char;

			cursor.position.down()->left();
			print tank_char _ tank_char;
			cursor.color.reset();
			type = 1;
			unblock();
		}

		void del() {
			int a = x;
			int b = y;

			switch (type)
			{
			case pos_up:
				b = y + 1;
				break;
			case pos_right:
				a = x - 1;
				break;
			case pos_down:
				b = y - 1;
				break;
			case pos_left:
				a = x + 1;
				break;

			}

			cursor.position.set(a, b);
			print "   ";
			cursor.position.down();
			print "   ";
			cursor.position.down();
			print "   ";
		}

	}position;

	struct dynamic {
		int _id;
		int** tanks;
		int num;

		void create(int numberOfTanks)
		{
			num = numberOfTanks;

			tanks = new int* [numberOfTanks];

			for (int i = 0; i < numberOfTanks; i++) {
				tanks[i] = new int[4]{};
			}

		}

		dynamic* select(int tankId) {

			_id = tankId;
			_tank.position.x = tanks[tankId][d_x];
			_tank.position.y = tanks[tankId][d_y];
			_tank.position.type = tanks[tankId][d_type];
			_tank.position._color = tanks[tankId][d_color];

			return this;
		}
		void up() {
			tanks[_id][d_type] = 0;
			tanks[_id][d_y]--;

			_tank.position.up();
		}
		void right() {
			tanks[_id][d_type] = 1;
			tanks[_id][d_x]++;
			_tank.position.right();
		}
		void left() {
			tanks[_id][d_type] = 3;
			tanks[_id][d_x]--;
			_tank.position.left();

		}
		void down() {
			tanks[_id][d_type] = 2;
			tanks[_id][d_y]++;
			_tank.position.down();
		}
		void del() {
			_tank.position.del();
		}

		int* get(int tankId) {
			return tanks[tankId];
		}

		void deleteAll() {

			for (int i = 0; i < num; i++) {
				delete[] tanks[i];

			}
			delete[] tanks;
		}


		void destroy() {
			for (int i = 0; i < num; i++) {
				delete[] tanks[i];
			}
			delete[] tanks;
		}
	}dynamic;



	void shoot() {
		this->sh.x = this->position.x;
		this->sh.y = this->position.y;
		this->sh.gunColor = this->position._color;
		this->sh.pos = this->position.type;
		int a = 3;
		sh.create();

	}


	struct gun {

		int** shoots;
		int x;
		int y;
		int pos;
		int gunColor;
		int border[2][2];

		bool initialized = false;

		int num = 0;

		const int params = 3;

		void update()
		{
			border[b_x][b_max];
			border[b_y][b_min];
			border[b_x][b_min];
			border[b_y][b_max];

			if (initialized) {
				for (int id = 0; id < num; id++)
				{
					up(id);
				}


			}
		}
		void create()
		{
			if (initialized)
				add();
			else
				init();

			return;
		}

		void init()
		{
			num = 1;
			initialized = true;
			shoots = new int* [1];
			shoots[0] = new int[params] {};
			shoots[0][sh_x] = _getx(x, pos);
			shoots[0][sh_y] = _gety(y, pos);
			shoots[0][sh_pos] = pos;
		}

		int _getx(int x, int pos) {
			switch (pos)
			{
			case pos_up:
				++x; // y--
				break;
			case pos_right:
				x += 3; // y++
				break;
			case pos_down:
				++x; // y += 3
				break;
			case pos_left:
				--x; // y++ 
				break;
			}
			return x;
		}

		int _gety(int y, int pos) {

			switch (pos) {
			case pos_up:
				y--;
				break;
			case pos_right:
				y++;
				break;
			case pos_down:
				y += 3;
				break;
			case pos_left:
				y++;
				break;
			}
			return y;
		}

		void up(int id)
		{
			clean(id);
			int& x = shoots[id][sh_x];
			int& y = shoots[id][sh_y];
			int pos = shoots[id][sh_pos];
			switch (pos)
			{
			case pos_up:
				--y;
				break;
			case pos_right:
				++x;
				break;
			case pos_down:
				++y;
				break;
			case pos_left:
				--x;
				break;
			}


			if (rule.check(x, y)) {
				cursor.position.set(x, y);
				cursor.color.set(red);
				print "x";

			}

			//EOM
			cursor.color.reset();
		}


		void add()
		{

			int** newArr = new int* [num + 1];

			for (int i = 0; i < num; i++)
			{
				newArr[i] = new int[params];

				for (int k = 0; k < params; k++)
				{
					newArr[i][k] = shoots[i][k];
				}
			}

			newArr[num] = new int[params];
			newArr[num][sh_x] = _getx(x, pos);
			newArr[num][sh_y] = _gety(y, pos);
			newArr[num][sh_pos] = pos;

			destroy();
			++num;
			shoots = newArr;
			initialized = true;
		}

		void clean(int id) {

			int& x = shoots[id][sh_x], & y = shoots[id][sh_y];
			cursor.position.set(x, y);
			print " ";
			return;
		}

		void die(int id)
		{
			clean(id);
			if (num == 1)
			{
				delete[] shoots[0];
				delete[] shoots;
				initialized = false;
				return;
			}

			int** newArr = new int* [num - 1];

			for (int i = 0; i < num - 1; i++)
			{
				newArr[i] = new int[params] {};

				for (int k = 0; k < params; k++)
				{
					if (i != id) {
						newArr[i][k] = shoots[i][k];
					}
				}
			}
			destroy();
			shoots = newArr;
		}

		void kill()
		{

			for (int i = 0; i < num; i++)
			{
				delete[] shoots[i];
			}

			delete[] shoots;
		}

		void destroy()
		{
			if (!initialized) return;

			for (int i = 0; i < num; i++)
			{
				delete[] shoots[i];
			}
			delete[] shoots;
			initialized = false;
		}
	}sh;

}_tank;



