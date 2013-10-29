#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for(int nn=0;nn<N;nn++) {
		int n, m;
		long long X, Y, Z;
		cin >>n>>m>>X>>Y>>Z;
		vector<int> A(m);
		for(int i=0;i<m;i++) cin >> A[i];
		vector<int> a(n);
		for(int i=0;i<n;i++) {
			long long tmp;
			int ti=i%m;
			a[i]=A[ti];
			tmp=A[ti];
			A[ti]=(tmp*X+Y*(i+1))%Z;
		}
		vector<int> va(n);
		int sum=0;
		for(int i=0;i<n;i++) {
			va[i]=1;
			for(int j=0;j<n;j++) 
				if(a[j]<a[i]) va[i]+=va[j];
			sum+=va[i];
		}
		cout << sum<<endl;
	}
}
