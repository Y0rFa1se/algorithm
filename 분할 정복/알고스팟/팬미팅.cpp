#include <iostream>
#include <vector>

using namespace std;

void reverseVector(vector<int> &vec, vector<int> &out, int len_of_vector){
	out = {};

	for (int i: vec){
		out.insert(out.begin(), i);
	}
}
void stringToVector(string &str, vector<int> &out){
	out = {};
	for (char i: str){
		if (i == 'M'){
			out.push_back(1);
		}else{
			out.push_back(0);
		}
	}
}
void putZero(vector<int> &vec, int number_of_zero){
	for (int i = 0; i < number_of_zero; i++){
		vec.insert(vec.begin(), 0);
	}
}



void vectorAdd(vector<int> &a, vector<int> &b, vector<int> &out, int len_of_vector, int a_start, int b_start){
	out = {};

	for (int i = 0; i < len_of_vector; i++){
		out.push_back(a[a_start + i] + b[b_start + i]);
	}
}
void vectorSubtract(vector<int> &a, vector<int> &b, vector<int> &out, int len_of_vector){
	out = {};
	for (int i = 0; i < len_of_vector; i++){
		out.push_back(a[i] - b[i]);
	}
}
void multiply(vector<int> &a, vector<int> &b, vector<int> &out, int len_of_vector, int start){
	int sum;
	for (int i = 0; i < len_of_vector; i++){
		sum = 0;
		for (int j = 0; j <= i; j++){
			sum += a[start + j] * b[start + i - j];
		}
		out.push_back(sum);
	}
	for (int i = len_of_vector - 2; i >= 0; i--){
		sum = 0;
		for (int j = 0; j <= i; j++){
			sum += a[start + len_of_vector - j - 1] * b[start + len_of_vector - (i - j) - 1];
		}
		out.push_back(sum);
	}
}

vector<int> karatsuba(vector<int> &a, vector<int> &b, int len_of_vector, int start, int end){
	vector<int> ret = {};
	if (len_of_vector <= 50){
		multiply(a, b, ret, len_of_vector, start);
		return ret;
	}

	int half_of_len = len_of_vector / 2;

	vector<int> z0, z1, z2;
	z0 = karatsuba(a, b, half_of_len, start, half_of_len - 1);
	z2 =  karatsuba(a, b, half_of_len, half_of_len, end);

	vector<int> z_temp1, z_temp2;
	vectorAdd(a, a, z_temp1, half_of_len, 0, half_of_len);
	vectorAdd(b, b, z_temp2, half_of_len, 0, half_of_len);
	z1 = karatsuba(z_temp1, z_temp2, half_of_len, 0, half_of_len - 1);

	vectorSubtract(z1, z0, z_temp1, half_of_len);
	vectorSubtract(z_temp1, z2, z1, half_of_len);

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

	vectorAdd(z0, z1, z_temp1, (2 * len_of_vector) - 1, 0, 0);
	vectorAdd(z_temp1, z2, ret, (2 * len_of_vector) - 1, 0, 0);

	return ret;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;

	vector<int> members, _fans, fans;
	int len_of_members, len_of_fans;
	string _;

	vector<int> ret;

	int n;

	for (int i = 0; i < c; i++){
		cin >> _;
		stringToVector(_, members);
		cin >> _;
		stringToVector(_, _fans);

		len_of_members = members.size();
		len_of_fans = _fans.size();
		
		reverseVector(_fans, fans, len_of_fans);

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

		ret = karatsuba(members, fans, cnt, 0, cnt - 1);

		cnt = 0;
		for (int j = len_of_members - 1; j < len_of_fans; j++){
			if (ret[n - j - 1] == 0){
				cnt += 1;
			}
		}

		cout << cnt << "\n";
	}
}