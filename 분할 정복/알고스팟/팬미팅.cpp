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
void sliceVector(vector<int> &vec, vector<int> &out, int start_ind, int end_ind){
	out = vector<int>(vec.begin() + start_ind, vec.begin() + end_ind);
}


void vectorAdd(vector<int> &a, vector<int> &b, vector<int> &out, int len_of_vector){
	out = {};

	for (int i = 0; i < len_of_vector; i++){
		out.push_back(a[i] + b[i]);
	}
}
void vectorSubtract(vector<int> &a, vector<int> &b, vector<int> &out, int len_of_vector){
	out = {};

	for (int i = 0; i < len_of_vector; i++){
		out.push_back(a[i] - b[i]);
	}
}
vector<int> reverseVector(vector<int> &vec, int len_of_vector){
	vector<int> ret = {};

	for (int i: vec){
		ret.insert(ret.begin(), i);
	}

	return ret;
}
void stringToVector(string &str, vector<int> &out){
	out = {};
	for (char i: str){
		if (i == 'M'){
			out.push_back(1);
		}
		else{
			out.push_back(0);
		}
	}
}

void putZero(vector<int> &vec, int number_of_zero){
	for (int i = 0; i < number_of_zero; i++){
		vec.insert(vec.begin(), 0);
	}
}

vector<int> karatsuba(vector<int> &a, vector<int> &b, int len_of_vector){
	vector<int> ret = {};
	if (len_of_vector == 1){
		ret.push_back(a[0] * b[0]);
		return ret;
	}

	int return_vector_len = (2 * len_of_vector) - 1;

	vector<int> a_first_half, a_last_half, b_first_half, b_last_half;
	int half_of_len = len_of_vector / 2;
	sliceVector(a, a_first_half, 0, half_of_len);
	sliceVector(a, a_last_half, half_of_len, len_of_vector);
	sliceVector(b, b_first_half, 0, half_of_len);
	sliceVector(b, b_last_half, half_of_len, len_of_vector);

	vector<int> z0, z1, z2;
	z0 = karatsuba(a_first_half, b_first_half, half_of_len);
	z2 = karatsuba(a_last_half, b_last_half, half_of_len);
	vector<int> a_sum, b_sum;
	vectorAdd(a_first_half, a_last_half, a_sum, half_of_len);
	vectorAdd(b_first_half, b_last_half, b_sum, half_of_len);
	z1 = karatsuba(a_sum, b_sum, half_of_len);
	vector<int> z_temp;
	if (half_of_len != 1){
		vectorSubtract(z1, z0, z_temp, len_of_vector - 1);
		vectorSubtract(z_temp, z2, z1, len_of_vector - 1);
	}
	else{
		vectorSubtract(z1, z0, z_temp, 1);
		vectorSubtract(z_temp, z2, z1, 1);
	}

	if (len_of_vector == 2){
		ret.push_back(z0[0]);
		ret.push_back(z1[0]);
		ret.push_back(z2[0]);
	}
	else{
		for (int i = 0; i < half_of_len; i++){
			z0.push_back(0);
			z1.insert(z1.begin(), 0);
			z2.insert(z2.begin(), 0);
		}
		for (int i = 0; i < half_of_len; i++){
			z0.push_back(0);
			z1.push_back(0);
			z2.insert(z2.begin(), 0);
		}

		vector<int> temp;
		vectorAdd(z0, z1, temp, return_vector_len);
		vectorAdd(temp, z2, ret, return_vector_len);
	}

	return ret;
}

int main(){
	int c;
	cin >> c;

	vector<int> members, fans;
	int len_of_members, len_of_fans;
	string _;

	vector<int> ret;

	int n;

	for (int i = 0; i < c; i++){
		cin >> _;
		stringToVector(_, members);
		cin >> _;
		stringToVector(_, fans);

		len_of_members = members.size();
		len_of_fans = fans.size();
		
		fans = reverseVector(fans, len_of_fans);

		int cnt = 1;
		while (true){
			if (len_of_fans <= cnt){
				break;
			}
			cnt *= 2;
		}

		n = (2 * cnt) - 1;

		putZero(members, cnt - len_of_members);
		putZero(fans, cnt - len_of_fans);

		ret = karatsuba(members, fans, cnt);

		cnt = 0;
		for (int j = len_of_members - 1; j < len_of_fans; j++){
			if (ret[n - j - 1] == 0){
				cnt += 1;
			}
		}

		cout << cnt << endl;
	}
}