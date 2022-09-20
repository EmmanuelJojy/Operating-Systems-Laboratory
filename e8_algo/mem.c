#include <stdio.h>
#include <stdlib.h>

int *mem, *req;
int np, nr;

void display(int r, int flag, int pos) {
	int i;
	if(flag == 1)
		printf("Request %d Allocated @ [%d]\tCurrent Partition: ", r, pos);
	else
		printf("Request %d Not - Allocated\tCurrent Partition: ", r);
	
	for(i = 0; i < np; i++)
			printf("%d ", mem[i]);
	printf("\n");
}

void f() {
	int i, j, flag;
	for(i = 0; i < nr; i++) {
		flag = 0;
		for(j = 0; j < np; j++) {
			if(req[i] <= mem[j]) {
				mem[j] -= req[i];
				flag = 1;
				break;
			}
		}
		display(req[i], flag, j);
	}
} 

void w() {
	int i, j, flag = 0;
	int max;
	for(i = 0; i < nr; i++) {
		max = 0;
		flag = 0;
		for(j = 0; j < np; j++) {
			if(mem[max] < mem[j])
				max = j;
		}
		if(req[i] <= mem[max]) {
			mem[max] -= req[i];
			flag = 1;
		}
		display(req[i], flag, max);		
	}
}	

void b() {
	int i, j, flag = 0;
	int max;
	for(i = 0; i < nr; i++) {
		max = 0;
		flag = 0;
		for(j = 0; j < np; j++) {
			if(mem[max] < mem[j])
				max = j;
		}
		for(j = 0; j < np; j++) {
			if(mem[max] > mem[j] && req[i] <= mem[j])
				max = j;
		}
		if(req[i] <= mem[max]) {
			mem[max] -= req[i];
			flag = 1;
		}
		display(req[i], flag, max);		
	}
}
	
	
void main() {
	int ch, i;
	printf("--- Memory Allocation ---");
	printf("\n1. First Fit\t2. Worst Fit\t3. Best Fit\n");
	printf("Choose Algorithm: ");
	scanf("%d", &ch);
	
	printf("\nNumber of Partitions: ");
	scanf("%d", &np);
	mem = malloc(np * sizeof(int));
	printf("Enter all Partitions: ");
	for(i = 0; i < np; i++) 
		scanf("%d", &mem[i]);
	
	printf("\nNumber of Request(s): ");
	scanf("%d", &nr);
	req = malloc(nr * sizeof(int));
	printf("Enter all Request(s): ");
	for(i = 0; i < nr; i++) 
		scanf("%d", &req[i]);
	printf("\n");
	
	switch(ch) {
		case 1: f(); break;
		case 2: w(); break;
		case 3: b(); break;
	}
	
	printf("\n");
	
	free(mem);
	free(req);
}

/*

Output
*********************
1. First Fit

--- Memory Allocation ---
1. First Fit	2. Worst Fit	3. Best Fit
Choose Algorithm: 1

Number of Partitions: 5
Enter all Partitions: 100 500 200 300 600

Number of Request(s): 4
Enter all Request(s): 212 417 112 426

Request 212 Allocated @ [1]	Current Partition: 100 288 200 300 600 
Request 417 Allocated @ [4]	Current Partition: 100 288 200 300 183 
Request 112 Allocated @ [1]	Current Partition: 100 176 200 300 183 
Request 426 Not - Allocated	Current Partition: 100 176 200 300 183 

*********************
2. Best Fit

--- Memory Allocation ---
1. First Fit	2. Worst Fit	3. Best Fit
Choose Algorithm: 2

Number of Partitions: 5
Enter all Partitions: 100 500 200 300 600

Number of Request(s): 4
Enter all Request(s): 212 417 112 426

Request 212 Allocated @ [4]	Current Partition: 100 500 200 300 388 
Request 417 Allocated @ [1]	Current Partition: 100 83 200 300 388 
Request 112 Allocated @ [4]	Current Partition: 100 83 200 300 276 
Request 426 Not - Allocated	Current Partition: 100 83 200 300 276 

*********************
3. Best Fit

--- Memory Allocation ---
1. First Fit	2. Worst Fit	3. Best Fit
Choose Algorithm: 3

Number of Partitions: 5
Enter all Partitions: 100 500 200 300 600

Number of Request(s): 4
Enter all Request(s): 212 417 112 426

Request 212 Allocated @ [3]	Current Partition: 100 500 200 88 600 
Request 417 Allocated @ [1]	Current Partition: 100 83 200 88 600 
Request 112 Allocated @ [2]	Current Partition: 100 83 88 88 600 
Request 426 Allocated @ [4]	Current Partition: 100 83 88 88 174 

*********************

*/
