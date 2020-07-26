#pragma once

#define print std::cout << 
#define  _  <<
#define br  "\n"

#define tank_char (char)219

#define tank_shoot (char)x;

#define loop while(true)

#define pause system("pause");


enum this_page {
	_menu = 0,
	_game = 1,
	settings = 2
}this_page;



enum tank_position {
	pos_up = 0,
	pos_right = 1,
	pos_down = 2,
	pos_left = 3,

}
tank_position;

enum dynamic_tank {
	d_x = 0,
	d_y = 1,
	d_type = 2,
	d_died = 3,
	d_color = 4
};

enum shoot
{
	sh_x = 0,
	sh_y = 1,
	sh_pos = 2,
	sh_type = 3,

	sh_green = 4,
	sh_red = 5,
};

enum border {
	b_x = 0,
	b_y = 1,
	b_max = 0,
	b_min = 1
};
