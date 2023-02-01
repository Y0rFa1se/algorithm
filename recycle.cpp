#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> split(string str, char delim){
	vector<int> ret;

	stringstream strTemp(str);
	string temp;

	while (getline(strTemp, temp, delim)){ //ss를 입력받아 temp에 입력, delimiter를 받으면 중지
		ret.push_back(stoi(temp));
	}
	
	return ret;
}

int main(){
	
}