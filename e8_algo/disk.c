#include <stdio.h>
#include <stdlib.h>

int *request;
int nr, st, max, seek = 0;

int mod(int x) {
	if(x < 0) 
		x *= -1;
	return x;
}

void sort() {
	int i, j;
	for(i = 0; i < nr; i++) {
		for(j =0 ; j < nr - i - 1; j++) {
			if(request[j] > request[j + 1]) {
				int temp = request[j];
				request[j] = request[j + 1];
				request[j + 1] = temp;
			}
		}
	}
}

void scan() {
	int i, last = st;
	int mid = -1;
	sort();
	printf("\nScheduler: ");
	for(i = 0 ; i < nr; i++) {
		if(request[i] < st) {
			mid = i;
			continue;
		}
		printf("%d ", request[i]);
	}
	for(i = mid; i > -1; i--)
		printf("%d ", request[i]);
	
	if (mid != -1)
		seek = mod(st - max) + mod(max - request[0]);
	else
		seek = mod(st - request[nr - 1]);
}

void cscan() {
	int i, last = st;
	int mid = -1;
	sort();	
	printf("\nScheduler: ");
	for(i = 0 ; i < nr; i++) {
		if(request[i] < st) {
			mid = i;
			continue;
		}
		printf("%d ", request[i]);
	}
	for(i = 0; i <= mid; i++)
		printf("%d ", request[i]);
	
	if (mid != -1)
		seek = mod(st - max) + max + request[mid];
	else
		seek = mod(st - request[nr - 1]);
}
		

void fcfs() {
	int i, last = st;;
	printf("\nScheduler: ");
	for(i = 0; i < nr; i++) {
		printf("%d ", request[i]);
		seek += mod(last - request[i]);
		last = request[i];
	}
}
		

void main() {
	int ch, i;
	
	printf("--- Disk Scheduling ---");
	printf("\n1. FCFS\t2. Scan\t3. C-Scan\n");
	printf("Scheduling Choice: ");
	scanf("%d", &ch);
	
	printf("Number of Request: ");
	scanf("%d", &nr);
	request = malloc(nr * sizeof(int));
	printf("Enter all Request: ");
	for(i = 0; i < nr; i++)
		scanf("%d", &request[i]);
	
	if(ch != 1) {
		printf("Enter Range (start 0): ");
		scanf("%d", &max);
	}
	
	printf("Initial Cylinder : ");
	scanf("%d", &st);
	
	switch(ch) {
		case 1: fcfs(); break;
		case 2: scan(); break;
		case 3: cscan(); break;
	}
	
	printf("\nSeek Time: %d\n\n", seek);
	free(request);
}

/*

Output:

*******************
1. FCFS

--- Disk Scheduling ---
1. FCFS	2. Scan	3. C-Scan
Scheduling Choice: 1
Number of Request: 7
Enter all Request: 82 170 43 140 24 16 190
Initial Cylinder : 50

Scheduler: 82 170 43 140 24 16 190 
Seek Time: 642

*******************


*******************
2. SCAN

--- Disk Scheduling ---
1. FCFS	2. Scan	3. C-Scan
Scheduling Choice: 2
Number of Request: 7
Enter all Request: 82 170 43 140 24 16 190
Enter Range (start 0): 199
Initial Cylinder : 50

Scheduler: 82 140 170 190 43 24 16 
Seek Time: 332

*******************


*******************
3. CSCAN

--- Disk Scheduling ---
1. FCFS	2. Scan	3. C-Scan
Scheduling Choice: 3
Number of Request: 7
Enter all Request: 82 170 43 140 24 16 190
Enter Range (start 0): 199
Initial Cylinder : 50

Scheduler: 82 140 170 190 16 24 43 
Seek Time: 391

*******************
	
*/
