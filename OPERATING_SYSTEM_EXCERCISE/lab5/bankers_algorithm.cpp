#include<bits/stdc++.h>
using namespace std;
void getFreeResources(int res[],int available[],int nr,int np,int p[][100]){
      for(int i=0;i<nr;i++){
      int total=0;
      for(int j=0;j<np;j++)
        total+=p[j][i];
      available[i]=res[i]-total;

      }


}
bool possible(int available[],int nr,int pos,int p[][100]){
  for(int i=0;i<nr;i++)
     if(p[pos][i]>available[i])
      return false;
      return true;

}
void add(int av[],int nr,int pos,int p[][100]){
for(int i=0;i<nr;i++)
   av[i]+=p[pos][i];
}
void bankers(int available[],int nr,int np,int p[][100],int need[][100]){

       int co=0;
       bool vis[np];
       for(int i=0;i<np;i++)
       vis[i]=false;
       while(true){
          bool flag=true;
          for(int i=0;i<np;i++){
             if(!vis[i] && possible(available,nr,i,need)){
                flag=false;
                co++;
                cout<<"resources allocated to process no "<<i<<endl;
                vis[i]=1;
                add(available,nr,i,p);
             }

          }
          if(co==np){
          return ;}else if(flag){
          cout<<"deadlock occured\n";
          return;
          }

       }



}
void getNeedMatrix(int need[][100],int ma[][100],int p[][100],int np,int nr){
  for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++)
       need[i][j]=ma[i][j]-p[i][j];
  }

}
int main(){
int nr,np;
cout<<"enter number of resources: ";
cin>>nr;

cout<<"enter number of process : ";
cin>>np;
int p[np][100];
cout<<"enter allocated resources : ";
for(int i=0;i<np;i++){
 for(int j=0;j<nr;j++)
    cin>>p[i][j];
}
cout<<"enter max resources required  ";
int ma[np][100];
for(int i=0;i<np;i++){
 for(int j=0;j<nr;j++)
    cin>>ma[i][j];
}
int need[np][100];
getNeedMatrix(need,ma,p,np,nr);


int available[nr];
cout<<"enter currently available res : ";
for(int i=0;i<nr;i++)
cin>>available[i];
//getFreeResources(res,available,nr,np,p);
for(int i=0;i<nr;i++)
cout<<available[i]<<" ";
cout<<endl;
bankers(available,nr,np,p,need);



}
