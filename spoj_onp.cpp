#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t,n;
	string line;
	stack <char> S;
	cin >> t;
	while (t--) {
		cin >> line;
		for (int i = 0; i < line.length(); ++i)
		{
			if (line[i]>='a'&&line[i]<='z')
				cout << line[i];
			else if (line[i]=='+'||line[i]=='-'||line[i]=='*'||line[i]=='/'||line[i]=='^')
				S.push(line[i]);
			else if (line[i]==')') {
				cout << S.top();
				S.pop();
			}
		}
		cout << endl;
	}
}