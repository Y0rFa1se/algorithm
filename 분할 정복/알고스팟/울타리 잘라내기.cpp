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
	int left_ind, right_ind;
	left_ind = loc - 1;
	right_ind = loc;
	int h = min(fences[left_ind], fences[right_ind]);
	int max_rectangle = 0;

	while (true){
		if (left_ind != 0 && fences[left_ind - 1] >= h){
			left_ind -= 1;
		}
		else if (right_ind != size - 1 && fences[right_ind + 1] >= h){
			right_ind += 1;
		}
		else{
			max_rectangle = max(h * (right_ind - left_ind + 1), max_rectangle);

			if (right_ind == size - 1){
				if (left_ind == 0){
					return max_rectangle;
				}

				else{
					left_ind -= 1;
					h = fences[left_ind];
				}
			}
			else if (left_ind == 0){
				right_ind += 1;
				h = fences[right_ind];
			}
			else{
				if (fences[right_ind + 1] > fences[left_ind - 1]){
					right_ind += 1;
					h = fences[right_ind];
				}
				else{
					left_ind -= 1;
					h = fences[left_ind];
				}
			}
		}
	}
}

int maxFence(vector<int> fences, int size){
	if (size == 1){
		return fences[0];
	}
	else{
		int half = size / 2;
		vector<int> left_side, right_side;
		left_side = sliceVector(fences, 0, half);
		right_side = sliceVector(fences, half, size);

		int left_max, right_max, middle_max;
		left_max = maxFence(left_side, half);
		right_max = maxFence(right_side, size - half);
		middle_max = passThrough(fences, size, half);

		return max(max(right_max, left_max), middle_max);
	}
}

int main(){
	int n;
	cin >> n;
	
	cin.ignore();

	string inp;
	vector<int> fences;

	for (int i = 0; i < n; i++){
		int size;
		cin >> size;
		cin.ignore();

		getline(cin, inp, '\n');
		splitInt(fences, inp, ' ');

		cout << maxFence(fences, size) << endl;
	}
}