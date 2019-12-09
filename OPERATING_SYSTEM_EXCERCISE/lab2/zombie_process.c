#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
  int pid=fork();
  if(pid==0){
    printf("In Child process \n");
    exit(0);
  }else{
     int childId=wait(0);
     sleep(10);
     printf("In Parent process \n pid of zombie process(child) %d",childId);
  }
}
