#include <algorithm> // find_if()
#include <cctype> //isspace()
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �μ��� ������ ���� true, �׷��� �������� false
static bool space(char c) {
	return isspace(c);
}

// �μ��� ������ ���� false, �׷��� ���� ���� true
static bool not_space(char c) {
	return !isspace(c);
}

static vector<string> split(const string& str) {
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector<string> ret;

	// for(iter i = str.begin(); i != str.end(); i++)
	while (i != str.end()) {
		cout << "String begin pos: " << 
			distance(str.begin(), i) << endl;

		// ���� ������ ����
		i = find_if(i, str.end(), not_space);

		// ���� �ܾ��� ���� ã��
		// while �ݺ��� �� �׻� ���ο� �ݺ��� j�� ����
		// ���� i ��ġ���� ù ��° �پ�� ���� ã��
		iter j = find_if(i, str.end(), space);
		cout << "j pos: " << distance(str.begin(), j) << endl;

		// [i, j) ������ ���ڸ� ����
		if (i != str.end()) {
			ret.push_back(string(i, j));

			// i �ݺ��� ��ġ�� j �ݺ����� ��ġ�� �����ϱ�
			i = j;
			cout << " i �̵� pos: " <<
				distance(str.begin(), j) << endl;
		}
	}
	return ret;
}
int main() {
	string s;

	// ���ڿ��� �� �྿ �Է¹޾� ����
	while (getline(cin, s)) {
		vector<string> v = split(s);

		// ���� v�� ������ �ܾ ���� ���
		for (vector<string>::size_type i = 0;
			i != v.size(); i++) {
			cout << v[i] << endl;
		}
	}
}