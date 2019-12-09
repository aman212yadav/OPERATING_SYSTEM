#include <bits/stdc++.h>
using namespace std;

bool search(int key, vector<int>& fr)
{
	for (int i = 0; i < fr.size(); i++)
		if (fr[i] == key)
			return true;
	return false;
}
int predict(int pg[], vector<int>& fr, int pn, int index)
{
	int res = -1, farthest = index;
	for (int i = 0; i < fr.size(); i++) {
		int j;
		for (j = index; j < pn; j++) {
			if (fr[i] == pg[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}
		if (j == pn)
			return i;
	}
	return (res == -1) ? 0 : res;
}

int pageFaults(int pg[], int pn, int fn=3)
{
	vector<int> fr;
	int hit = 0;
	for (int i = 0; i < pn; i++) {
		if (search(pg[i], fr)) {
			hit++;
			continue;
		}
		if (fr.size() < fn)
			fr.push_back(pg[i]);
		else {
			int j = predict(pg, fr, pn, i + 1);
			fr[j] = pg[i];
		}
	}	return pn-hit;
}
int main()
{
	int n,sz;
	cout<<"Enter number of pages : ";
	cin>>n;
	int pages[n];
	for(int i=0;i<n;i++)
         cin>>pages[i];
     cin>>sz;
    cout<<pageFaults(pages,n,sz);
	return 0;
}
