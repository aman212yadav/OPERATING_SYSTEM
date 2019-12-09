#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
 int pid=fork();
 if(pid==0){
    sleep(5);
    printf("In child process (orphan)\n");
 }else{
    printf("In parent process\n");
    exit(0);
 }

}
