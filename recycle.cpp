#include <iostream>
#include <vector>

using namespace std;

void splitInt(vector<int> &out, string str, char delim = ' '){
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

int main(){
	string str;
	getline(cin, str, '\n');
	vector<int> str_splited;
	splitInt(str_splited, str, ' ');
}