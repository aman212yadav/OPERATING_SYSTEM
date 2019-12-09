#include<bits/stdc++.h>
using namespace std;
struct node{
int a,b,idx;
};
int main(){
int n;
cout<<"Number of process: ";
cin>>n;
pair<int,int>  arr[n];
queue< node > q;
cout<<"Enter arrival and burst time for each process in arrival order\n";
for(int i=0;i<n;i++){
   cin>>arr[i].first>>arr[i].second;
    q.push({arr[i].first,arr[i].second,i});
}
int tsf=0, prev=0,switc=0,quant,cmp[n]={};
cout<<"Enter quant size : ";
cin>>quant;
while(!q.empty()){
    node p=q.front();
    if(prev!=p.idx){
     switc++;
    }
    prev=p.idx;
    q.pop();
    if(p.a > tsf){
    tsf=p.a;
    }
    if(p.b <= quant){
       cmp[p.idx]=p.b+tsf;
    }else{
       cmp[p.idx]=quant+tsf;
       q.push({p.a,p.b-quant,p.idx});
    }
    tsf=cmp[p.idx];
}
cout<<"No of context switches: "<<switc<<"\n";
float turnaroundtime=0,waitingtime=0;
for(int i=0;i<n;i++){

int turnaround=cmp[i]-arr[i].first;
 int waiting=turnaround-arr[i].second;
  cout<<"process : "<<i+1<<" , turn around time : "<<turnaround<<" , waiting time : "<< waiting<<"\n";
  turnaroundtime+=turnaround;
  waitingtime+=waiting;
}
cout<<" average turn around time "<<turnaroundtime/n<<" , "<<" average waiting time "<<waitingtime/n<<"\n";

}
