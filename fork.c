#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>

int child(){//child process
	printf("Child pid: %d\n",getpid());
	srand(time(NULL));
	int t = rand()%15 + 5;
	sleep(t);
	printf("Child terminated\n");
	return t;
}

int main(){
	printf("Parent pid: %d\n\n",getpid());
	int p1,status,w;
	p1 = fork();
	if (p1){//parent
		w = wait(&status);
		printf("From parent -- Child pid: %d, Time: %d\n\n",p1,WEXITSTATUS(status));
		int p2 = fork();
		if(p2) {//parent
			w = wait(&status);
			printf("From parent -- Child pid: %d, Time: %d\n\n",p2,WEXITSTATUS(status));
			printf("Parent terminated\n");
			return 0;
		}else{//child2
			return child();
		}	
	}else{//child1
		return child();
	}
	return 0;
}
