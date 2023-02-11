#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int cache[7][7];
int board[7][7];

int canJump(int x, int y){
	int &cach = cache[y][x];

    if (x >= 7 || y >= 7){
		return 0;
	}

	if (cach != -1){
		return cach;
	}

	if (x == 6 && y == 6){
		return 1;
	}

	int ret;
	ret = (canJump(x + board[y][x], y) || canJump(x, y + board[y][x]));
	cach = ret;
	return ret;
}

int main(){
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++){
            board[i][j] = 0;
        }
    }

	memset(cache, -1, sizeof(cache));

	string _;
	for (int i = 0; i < 7; i++){
		cin >> _;
		for (int j = 0; j < 7; j++){
			board[i][j] = int(_[j]) - 48;
		}
	}

	if (canJump(0, 0)){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}