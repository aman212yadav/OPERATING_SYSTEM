#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cout<<"Number of process: ";
cin>>n;
pair<int,int> arr[n];
cout<<"Enter arrival and burst time for each process in arrival order\n";
queue< pair<int,int> > q;
for(int i=0;i<n;i++)
    {cin>>arr[i].first>>arr[i].second;
     q.push(arr[i]);
    }
int tsf=0,cmp[n]={},turn[n]={},counter=0;
while(!q.empty()){
     pair<int,int> p=q.front();
     q.pop();
     if(p.first > tsf)
     cmp[counter]+=p.first+p.second;
     else{
       cmp[counter]+=tsf+p.second;
     }
     tsf=cmp[counter];
     counter++;
}
int turnaroundtime=0,waitingtime=0;
for(int i=0;i<n;i++){
 int turnaround=cmp[i]-arr[i].first;
 int waiting=turnaround-arr[i].second;
  cout<<"process : "<<i+1<<" , turn around time : "<<turnaround<<" , waiting time : "<< waiting<<"\n";
  turnaroundtime+=turnaround;
  waitingtime+=waiting;
}
cout<<" average turn around time "<<turnaroundtime/n<<" , "<<" average waiting time "<<waitingtime/n<<"\n";
}
