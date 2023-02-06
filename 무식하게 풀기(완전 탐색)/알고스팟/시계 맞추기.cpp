#include <iostream>
#include <vector>

using namespace std;

void splitInt(vector<int> &out, string str, char delim = ' '){
	int ind = 0;
	string temp;
	for (int i = 0; i < str.size(); i++){
		if (str[i] == delim){
			out[ind] = stoi(temp);
			ind += 1;
			temp = "";
			continue;
		}
		else{
			temp.push_back(str[i]);
		}
	}
	out[ind] = stoi(temp);
}

vector<vector<int>> switches = {
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


void printClocks(vector<int> &clock){
	for (int i: clock){
		cout << i << " ";
	}
	cout << endl;
}

void pushSwitches(vector<int> &clock, int number_of_switch){
	for (int i: switches[number_of_switch]){
		if (clock[i] < 12){
			clock[i] += 3;
		}
		else{
			clock[i] = 3;
		}
	}
}

bool isClockPerfect(vector<int> &clock){
		bool isPerfect = true;
		for (int i = 0; i < clock.size(); i++){
			if (clock[i] != 12){
				isPerfect = false;
				break;
			}
		}

		return isPerfect;
	}

int _minSwitch(vector<int> clock, int number_of_switch, int cnt){
		if (isClockPerfect(clock)){
			return cnt;
		}
		else if (number_of_switch == 10){
			return 31;
		}
		else{
			int case1 = _minSwitch(clock, number_of_switch + 1, cnt);

			pushSwitches(clock, number_of_switch);
			cnt += 1;
			int case2 = _minSwitch(clock, number_of_switch + 1, cnt);

			pushSwitches(clock, number_of_switch);
			cnt += 1;
			int case3 = _minSwitch(clock, number_of_switch + 1, cnt);

			pushSwitches(clock, number_of_switch);
			cnt += 1;
			int case4 = _minSwitch(clock, number_of_switch + 1, cnt);

			int min_switch_times = case1;
			if (min_switch_times > case2){
				min_switch_times = case2;
			}
			if (min_switch_times > case3){
				min_switch_times = case3;
			}
			if (min_switch_times > case4){
				min_switch_times = case4;
			}

			return min_switch_times;
		}
	}

int minSwitch(vector<int> clock){
	int ret = _minSwitch(clock, 0, 0);
	if (ret == 31){
		return -1;
	}
	else{
		return ret;
	}
}

int main(){
	int n;
	cin >> n;
	
	cin.ignore();

	string inp;
	vector<int> clocks(16);

	for (int i = 0; i < n; i++){
		getline(cin, inp, '\n');
		splitInt(clocks, inp, ' ');

		cout << minSwitch(clocks) << endl;
	}
}