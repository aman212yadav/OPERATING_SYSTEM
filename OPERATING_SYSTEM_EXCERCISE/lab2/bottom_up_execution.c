#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main(){
int pid1=fork();
int pid2=fork();
if(pid1>0 && pid2>0 ){    // parent process
   wait(0);
   wait(0);
   printf("Parent executed\n");
}
else if(pid1==0 && pid2 > 0){  // first child
   wait(0);
   sleep(2);
   printf("First child executed\n");
}
else if(pid1>0 && pid2==0){  //second child
    sleep(1);
    printf("Second child executed\n");
}else{                       //grand child
    printf("grand child executed\n");
}


}
