#include <stdio.h>
#define MAP_SIZE 30

typedef struct Dot {
	int x = 0, y = 0;
};

void dot_init(Dot *dot, int x, int y) {
	dot->x = x;
	dot->y = y;	
}

int map[MAP_SIZE][MAP_SIZE] = { 0, };

void brh(Dot *one, Dot *two) {
	Dot result;
	result.x = one->x;
	result.y = one->y;
	
	int W, H, H1, H2, F;
	W = two->x - one->x;
	H = two->y - one->y;
	H1 = 2 * H;
	H2  = 2 * (H - W);
	F = (H1) - W;
	printf("F : %d\n", F);
	
	for(int x = one->x; x <= two->x; x++) {
		map[result.y][x] = 1;
		printf("(%d, %d)\n", x, result.y);
		if( F < 0 ) {
			F += H1;
		} else {
			result.y += 1;
			F += H2;
		}
		
	}
	
}

void view_map() {
	for(int i = MAP_SIZE - 1; i >= 0; i--) {
		for(int j = 0; j < MAP_SIZE; j++) {
			if( map[i][j] == 1 ) {
				printf("■");
			} else {
				printf("□");
			}
		}
		printf("\n"); 
	}
}

int main() {
	Dot one, two;
	dot_init(&one, 1, 1);
	dot_init(&two, 8, 3);
	
	brh(&one, &two);
	view_map();
	return 0;
}
