#include <iostream>
#include <vector>

using namespace std;

void splitInt(vector<int> &out, string str, char delim = ' '){
	out = {};
	string temp;
	for (int i = 0; i < str.size(); i++){
		if (str[i] == delim){
			out.push_back(stoi(temp));
			temp = "";
			continue;
		}
		else{
			temp.push_back(str[i]);
		}
	}
	out.push_back(stoi(temp));
}
vector<int> sliceVector(vector<int> &vec, int start_ind, int end_ind){
	return vector<int>(vec.begin() + start_ind, vec.begin() + end_ind);
}

int passThrough(vector<int> &fences, int size, int loc){
	return 0;
}

int maxFence(vector<int> fences, int size){
	if (size == 1){
		return fences[0];
	}
	else{
		vector<int> left_side, right_side;
		left_side = vector<int>();
		right_side = vector<int>();

	}
}

int main(){
	vector<int> vec = {1, 2, 3, 4};

	for (int i: sliceVector(vec, 0, 0)){
		cout << i << " ";
	}
}