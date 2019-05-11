//给定4-20个木棍长度，判断是否能不能围成一个正方形

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> vec, int index, int *used, int one_stick, int length, int seq, bool &ok) {
	if (seq == 3) {
		ok = true;
		return;
	}
	else {
		for (int i = index; i < vec.size() && !ok; i++) {
			if (used[i] == 1)
				continue;
			if (one_stick + vec[i] < length) {
				used[i] = 1;
				dfs(vec, i + 1, used, one_stick + vec[i], length, seq, ok);
				used[i] = 0;
			}
			else if (one_stick + vec[i] == length) {
				used[i] = 1;
				dfs(vec, 0, used, 0, length, seq + 1, ok);
				used[i] = 0;
			}
		}
	}
	return;
}
int main() {
	int n = 0;
	cin >> n;
	while (n--) {
		int sticks;
		cin >> sticks;
		vector <int> vec;
		int num = 0;
		while (sticks--) {
			cin >> num;
			vec.push_back(num);
		}
		int sum = 0;
		for (int i = 0; i < vec.size(); i++) {
			sum += vec[i];
		}
		if (sum % 4 != 0) {
			cout << "no" << endl;
			continue;
		}
		int length = sum / 4;
		int used[25];
		for (int i = 0; i < 25; i++)
			used[i] = 0;
		bool ok = false;
		dfs(vec, 0, used, 0, length, 0, ok);

		if (ok)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	//system("pause");
	return 0;
}
