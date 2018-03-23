#include "../include/tetris.h"

void			init_all_pieces(t_board *b)
{
		int		i;
		int		j;
		int		k;
		int		h;

		int		p[7][4][4][4] = {
	//J
		{
		   {{0,0,1,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,0,0,0}},

		   {{0,1,0,0},
			{0,1,1,1},
			{0,0,0,0},
			{0,0,0,0}},
		
		   {{0,0,1,1},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,0,0}},

			{{0,0,0,0},
			{0,1,1,1},
			{0,0,0,1},
			{0,0,0,0}}
		},
	//I
		{
			{{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0}},

			{{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}},
		
			{{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0}},

			{{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}}
		},
	//S
		{
			{{0,0,0,0},
			{0,0,1,1},
			{0,1,1,0},
			{0,0,0,0}},
	
			{{0,0,0,0},
			{0,0,1,0},
			{0,0,1,1},
			{0,0,0,1}},
		
			{{0,0,0,0},
			{0,0,0,0},
			{0,0,1,1},
			{0,1,1,0}},

			{{0,0,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,0,1,0}}
		},
	//Z
		{
		   {{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0},
			{0,0,0,0}},
	   
			{{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}},

			{{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,0,0}},
		
			{{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}},
		},
	//T
		{
			{{0,0,0,0},
			{0,1,1,1},
			{0,0,1,0},
			{0,0,0,0}},

			{{0,0,0,1},
			{0,0,1,1},
			{0,0,0,1},
			{0,0,0,0}},
		
			{{0,0,0,0},
			{0,0,1,0},
			{0,1,1,1},
			{0,0,0,0}},

			{{0,1,0,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,0,0}}
		},
	//L
		{
			{{0,0,1,0},
			{0,0,1,0},
			{0,0,1,1},
			{0,0,0,0}},

			{{0,0,0,0},
			{0,1,1,1},
			{0,1,0,0},
			{0,0,0,0}},
		
			{{0,1,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,0,0}},

			{{0,0,0,1},
			{0,1,1,1},
			{0,0,0,0},
			{0,0,0,0}}
		},
	//0
		{
			{{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}},

			{{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}},
		
			{{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}},

			{{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}}
		}
	};
	i = -1;
	while (++i < 7)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				h = -1;
				while (++h < 4)
					b->arr_piece[i][j][k][h] = p[i][j][k][h];
			}
		}
	}
}
