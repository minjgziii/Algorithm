#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;

	cin >> s;

	int count = 0;

	while (true) {
		int a = 0;

		if (s.find("c=") != string::npos) {
			int str = s.find("c=");
			s[str] = '0';
			s[str + 1] = '0';
			count++;
			a++;
		}
		if (s.find("c-") != string::npos) {
			int str = s.find("c-");
			s[str] = '0';
			s[str + 1] = '0';
			count++;
			a++;
		}
		while (true) {
			int b = 0;

			if (s.find("dz=") != string::npos) {
				int str = s.find("dz=");
				s[str] = '0';
				s[str + 1] = '0';
				s[str + 2] = '0';
				count++;
				a++;
				b++;
			}

			if (b == 0) {
				break;
			}
		}
		
		if (s.find("d-") != string::npos) {
			int str = s.find("d-");
			s[str] = '0';
			s[str + 1] = '0';
			count++;
		}
		if (s.find("lj") != string::npos) {
			int str = s.find("lj");
			s[str] = '0';
			s[str + 1] = '0';
			count++;
			a++;
		}
		if (s.find("nj") != string::npos) {
			int str = s.find("nj");
			s[str] = '0';
			s[str + 1] = '0';
			count++;
		}
		if (s.find("s=") != string::npos) {
			int str = s.find("s=");
			s[str] = '0';
			s[str + 1] = '0';
			count++;
			a++;
		}
		if (s.find("z=") != string::npos) {
			int str = s.find("z=");
			s[str] = '0';
			s[str + 1] = '0';
			count++;
			a++;
		}

		if (a == 0) {
			break;
		}
	}

	for (int i{ 0 }; i < s.length(); i++) {
		if (s[i] != '0' && s[i] != '-' && s[i] != '=') {
			count++;
		}
	}

	cout << count;

}