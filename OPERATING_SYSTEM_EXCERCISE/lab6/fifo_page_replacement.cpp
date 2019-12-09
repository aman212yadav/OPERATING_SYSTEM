#include<bits/stdc++.h>
using namespace std;


// FIFO
int pageFaults(int pages[], int n, int capacity=3)
{

	unordered_set<int> s;
	queue<int> indexes;
	int page_faults = 0;
	for (int i=0; i<n; i++)
	{
		if (s.size() < capacity)
		{

			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);
				page_faults++;
				indexes.push(pages[i]);
			}
		}
		else
		{
			if (s.find(pages[i]) == s.end())
			{
				int val = indexes.front();
				indexes.pop();
				s.erase(val);
				s.insert(pages[i]);
				indexes.push(pages[i]);
				page_faults++;
			}
		}
	}

	return page_faults;
}

// Driver code
int main()
{
	int n,sz;
	cout<<"Enter number of pages : ";
	cin>>n;
	int pages[n];
	for(int i=0;i<n;i++)
         cin>>pages[i];
         cin>>sz;
    cout<<pageFaults(pages,n);
}
