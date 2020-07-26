#pragma once
#include "pch.h"
#include "defines.h"
/*


0 => x = 0  min / 1 max
	 y = 0  min / 1 max

1 => x = 0]  min | 1] max
	 y = 0]  min | 1] max

2 =>  x => [
	  y	    max = 9
			min = 2
		]
**/
struct bord {
	int*** data;
	int num = 0; // number of border rules
	bool initialized = false;

	void add(int min_x, int min_y, int max_x, int max_y) {
		if (!initialized) {
			init(min_x, min_y, max_x, max_y);
			return;
		}


		int*** tmp_data;

		tmp_data = new  int** [1]; // cont
		tmp_data[num + 1] = new int* [2]; // ->  x / y 
		tmp_data[0][b_x] = new int[2]{}; // max /min  -> x
		tmp_data[0][b_y] = new int[2]{}; // max /min  -> y

		for (int i = 0; i < num; i++)
		{
			tmp_data[i][b_x][b_min] = data[i][b_x][b_min];
			tmp_data[i][b_y][b_min] = data[i][b_y][b_min];

			tmp_data[i][b_x][b_max] = data[i][b_x][b_max];
			tmp_data[i][b_y][b_max] = data[i][b_y][b_max];
		}

		tmp_data[num][b_x] = new int[2]{}; // max /min  -> x
		tmp_data[num][b_y] = new int[2]{}; // max /min  -> y


		tmp_data[num][b_x][b_min] = min_x;
		tmp_data[num][b_y][b_min] = min_y;

		tmp_data[num][b_x][b_max] = max_x;
		tmp_data[num][b_y][b_max] = max_y;
		destroy();

		data = tmp_data;
		++num;

	}

	void init(int min_x, int min_y, int max_x, int max_y) {
		data = new  int** [1]; // cont
		data[0] = new int* [2]; // ->  x / y 
		data[0][0] = new int[2]{}; // max /min  -> x
		data[0][1] = new int[2]{}; // max /min  -> y

		data[0][b_x][b_min] = min_x;
		data[0][b_y][b_min] = min_y;

		data[0][b_x][b_max] = max_x;
		data[0][b_y][b_max] = max_y;
		initialized = true;
	}

	void destroy() {

		for (int i = 0; i < num; i++)
		{
			delete[] data[i][b_x];
			delete[] data[i][b_y];
			delete[] data[i];
		}
		delete[] data;

	}

	bool check(int x, int y) {
		if (!initialized) return true;

		int max_y, max_x, min_x, min_y;
		for (int i = 0; i < num; i++) {

			max_x = data[i][b_x][b_max];
			max_y = data[i][b_y][b_max];

			min_x = data[i][b_x][b_min];
			min_y = data[i][b_y][b_min];

			if (max_x == min_x) {
				if (y > min_y && y < max_y) {
					return true;
				}
				else {
					return false;
				}
			}
			else if (max_y == min_y) {
				if (x > min_x && x < max_x) {
					return true;
				}
				else {
					return false;
				}
			}
			return false;
		}
	}


}rule;