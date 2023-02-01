#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> split(string str, char delim = ' '){
	vector<int> ret;

	stringstream strTemp(str);
	string temp;

	while (getline(strTemp, temp, delim)){ //strTemp를 입력받아 temp에 입력, delimiter를 받으면 중지
		ret.push_back(stoi(temp));
	}
	
	return ret;
}

vector<vector<int>> switches{
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

vector<int> putSwitch(vector<int> clock, int numberOfSwitch){
	vector<int> ret = clock;
	for (int pushed: switches[numberOfSwitch]){
		ret[pushed] += 3;
		if (ret[pushed] == 15){
			ret[pushed] = 3;
		}
	}
}

int main(){
	int c;
	cin >> c;

	for (int i = 0; i < c; ++i){
		vector<int> clocks;
		string _;
		cin >> _;
		clocks = split(_);

		for (int i: putSwitch(clocks, 3)){
			cout << i;
		}
	}
}