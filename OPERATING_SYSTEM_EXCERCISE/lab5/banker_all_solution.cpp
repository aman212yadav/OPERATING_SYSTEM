#include<bits/stdc++.h>
using namespace std;
bool isPossible(int need[100][100],int available[],int process_id,int num_of_resources){
    for(int j=0;j<num_of_resources;j++)
         if(need[process_id][j]>available[j])
            return false;
    return true;
}
void add(int all[100][100],int available[],int process_id,int num_of_resources){

 for(int i=0;i<num_of_resources;i++)
     available[i]+=all[process_id][i];
}
void sub(int all[100][100],int available[],int process_id,int num_of_resources){
 for(int i=0;i<num_of_resources;i++)
     available[i]-=all[process_id][i];
}
void banker_algorithm(vector< vector<int> > &solution,int need[][100],int all[][100],int available[],int vis[],int num_of_process,int num_of_resources,int co){
     if(co>num_of_process){
        vector<int> vec(vis,vis+num_of_process);
        solution.push_back(vec);
        return;
     }
    for(int i=0;i<num_of_process;i++){
        if(!vis[i] && isPossible(need,available,i,num_of_resources)){
            vis[i]=co;
            add(all,available,i,num_of_resources);
            banker_algorithm(solution,need,all,available,vis,num_of_process,num_of_resources,co+1);
            sub(all,available,i,num_of_resources);
            vis[i]=0;
        }
    }
}
int main(){
int num_of_process,num_of_resources;
cout<<"Enter number of resources: ";
cin>>num_of_resources;
cout<<"Enter number of process: ";
cin>>num_of_process;
cout<<" Enter allocation matrix \n";
int all[num_of_process][100];
for(int i=0;i<num_of_process;i++){
        for(int j=0;j<num_of_resources;j++)
               cin>>all[i][j];
}
cout<<"Enter max matrix \n";
int res[100][100];
for(int i=0;i<num_of_process;i++){
    for(int j=0;j<num_of_resources;j++)
         cin>>res[i][j];
}
cout<<"Enter enter available resources \n";
int available[num_of_resources];
for(int i=0;i<num_of_resources;i++){
    cin>>available[i];
}
int need[100][100];
for(int i=0;i<num_of_process;i++){                 // need matrix calculation
    for(int j=0;j<num_of_resources;j++)
        need[i][j]=res[i][j]-all[i][j];
}
cout<<"Need matrix is \n";
for(int i=0;i<num_of_process;i++){
    for(int j=0;j<num_of_resources;j++)
         cout<<need[i][j]<<" ";
    cout<<"\n";
}
vector< vector<int> > solution;
int vis[num_of_process]={0},co=1;
banker_algorithm(solution,need,all,available,vis,num_of_process,num_of_resources,co);
for(auto k : solution){
   for(auto j: k ){
    cout<<j<<" ";
   }
   cout<<"\n";

}

}
/*
0 1 1 0
1 2 3 1
1 3 6 5
0 6 3 2
0 0 1 4

0 2 1 0
1 6 5 2
2 3 6 6
0 6 5 2
0 6 5 6

1 5 2 0
*/
