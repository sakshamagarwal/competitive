#include <iostream>
#include <cmath>
using namespace std;

#define lim 1000000000
#define lim_sqrt 31628
int main() {
	bool primes[lim_sqrt];
	int p_array[100000];
	for (int i = 0; i < lim_sqrt; ++i)
	{
		primes[i] = true;
	}
	primes[0] = false;
	primes[1] = false;
	for (int i = 2; i < lim_sqrt; ++i)
	{
		if (primes[i]) {
			int j = i*i;
			while (j<lim_sqrt) {
				primes[j] = false;
				j += i;
			}
		}
	}
	int j = 0;
	for (int i = 0; i < lim_sqrt; ++i)
	{
		if (primes[i]) {
			
			p_array[j++] = i;
		}
	}
	int p_array_size = j;
	
	int t;
	cin >> t;
	while (t--) {
		int m,n;
		cin >> m >> n;
		bool flag[n-m+1];
		
		for (int i = 0; i < n-m+1; ++i)
		{
			flag[i] = true;
		}
		j = 0;
		int b = (int)sqrt(n);
		while (p_array[j] <= b) {

			int a = m/p_array[j];
			a = a*p_array[j];
			if (m==p_array[j])
				a = m;
			else if (a==m)
				flag[0] = false;
			if (a==0)
				a+=p_array[j];
			
			
			while (a<n) {
				a += p_array[j];
				if (a < n+1)
					flag[a-m] = false;
			
			}
			
			j++;
		}
		
		if (m==1)
			flag[0] = false;
		for (int i = 0; i < n-m+1; ++i)
		{
			if (flag[i])
				cout << i+m << endl;
		}
		cout << endl;
	}
	
}