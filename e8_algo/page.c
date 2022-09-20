#include <stdio.h>
#include <stdlib.h>

int *pages, *frames;
int np, nf, ch;
int miss = 0, hit = 0;

void display(int type, int pg) {
	printf("Page = %d\t", pg);
	for(int i = 0; i < nf; i++) {
		if(frames[i] == -1)
			printf("x ");
		else
			printf("%d ", frames[i]);
	}
	if(type == 1)
		printf("\t[HIT]\n");
	else
		printf("\t[MISS]\n");
}

int isIn(int pg) {
	for(int i = 0; i < nf; i++) 
		if(frames[i] == pg)
			return 1;
	return 0;
}

void insF(int pg) {
	int i;
	for(i = 0; i < nf; i++) {
		if(frames[i] == -1) {
			frames[i] = pg;
			return;
		}
	}
	for(i = 0; i < nf - 1; i++)
		frames[i] = frames[i + 1];
	
	frames[nf - 1] = pg;
}
	

void fcfs() {
	int i, j, pg;
	for(i = 0; i < np; i++) {
		pg = pages[i];
		if(isIn(pg) == 1) {
			hit++;
			display(1, pg);
		}
		else {
			miss++;
			insF(pg);
			display(0, pg);
		}
	}
}

void insL(int pg, int pos) {
	int i, j;
	int maxR = -1, maxP = -1, r;
	
	for(i = 0; i < nf; i++) {
		if(frames[i] == -1) {
			frames[i] = pg;
			return;
		}
	}
	
	for(i = 0; i < nf; i++) {
		r = 0;
		for(j = pos - 1; j > -1; j--) {
			r++;
			if(pages[j] == frames[i])
				break;
		}
		if(r > maxR) {
			maxR = r;
			maxP = i;
		}
	}
	frames[maxP] = pg;
}

void lru() {
	int i, j, pg;
	int minR, minP;
	for(i = 0; i < np; i++) {
		pg = pages[i];
		if(isIn(pg) == 1) {
			hit++;
			display(1, pg);
		}
		else {
			miss++;
			insL(pg, i); 
			display(0, pg);
		}
	}
}

void insLFU(int pg, int pos) {
	int i, j;
	int minR = 100, minP = 100, r;
	
	for(i = 0; i < nf; i++) {
		if(frames[i] == -1) {
			frames[i] = pg;
			return;
		}
	}
	
	for(i = 0; i < nf; i++) {
		r = 0;
		for(j = 0; j < pos; j++) {
			if(pages[j] == frames[i]) {
				r++;
			}
		}
		if(r < minR) {
			minR = r;
			minP = i;
		}
	}
	for(i = minP; i < nf - 1; i++)
		frames[i] = frames[i + 1];
	frames[nf - 1] = pg;
}

void lfu() {
	int i, j, pg;
	int minR, minP;
	for(i = 0; i < np; i++) {
		pg = pages[i];
		if(isIn(pg) == 1) {
			hit++;
			display(1, pg);
		}
		else {
			miss++;
			insLFU(pg, i); 
			display(0, pg);
		}
	}
}


void insO(int pg, int pos) {
	int i, j;
	int maxR = -1, maxP = -1, r;
	
	for(i = 0; i < nf; i++) {
		if(frames[i] == -1) {
			frames[i] = pg;
			return;
		}
	}
	
	for(i = 0; i < nf; i++) {
		r = 0;
		for(j = pos + 1; j < np; j++) {
			r++;
			if(pages[j] == frames[i])
				break;
		}
		if(r > maxR) {
			maxR = r;
			maxP = i;
		}
	}
	frames[maxP] = pg;
}

void opt() {
	int i, j, pg;
	int minR, minP;
	for(i = 0; i < np; i++) {
		pg = pages[i];
		if(isIn(pg) == 1) {
			hit++;
			display(1, pg);
		}
		else {
			miss++;
			insO(pg, i); 
			display(0, pg);
		}
	}
}
		

void main() {
	int i;
	printf("--- Page Replacement Algorithm ---\n");
	printf("1. FCFS\t2. LRU\t3. LFU\t4. Optimal\n");	
	printf("Choose Algorithm: ");
	scanf("%d", &ch);
	
	printf("Number of Frames: ");
	scanf("%d", &nf);
	frames = malloc(nf * sizeof(int));
	for(i = 0; i < nf; i++)
		frames[i] = -1;
	
	printf("Number of Pages : ");
	scanf("%d", &np);
	pages = malloc(np * sizeof(int));
	printf("Page Requests: "); 
	for(i = 0; i < np; i++) 
		scanf("%d", &pages[i]);
	printf("\n");
	
	switch(ch) {
		case 1: fcfs(); break;
		case 2: lru(); break;
		case 3: lfu(); break;
		case 4: opt(); break;
		
	}
	
	printf("\nTotal Page Faults: %d\n", miss);
	printf("Total Page Hit(s): %d\n\n", hit);
} 

/* Output

*************************
FCFS Algorithm

--- Page Replacement Algorithm ---
1. FCFS	2. LRU	3. Optimal
Choose Algorithm: 1
Number of Frames: 3
Number of Pages : 7
Page Requests: 1 3 0 3 5 6 3

Page = 1	1 x x 	[MISS]
Page = 3	1 3 x 	[MISS]
Page = 0	1 3 0 	[MISS]
Page = 3	1 3 0 	[HIT]
Page = 5	3 0 5 	[MISS]
Page = 6	0 5 6 	[MISS]
Page = 3	5 6 3 	[MISS]

Total Page Faults: 6
Total Page Hit(s): 1

*************************
#########################
*************************
LRU

--- Page Replacement Algorithm ---
1. FCFS	2. LRU	3. LFU	4. Optimal
Choose Algorithm: 2
Number of Frames: 4
Number of Pages : 14
Page Requests: 7 0 1 2 0 3 0 4 2 3 0 3 2 3

Page = 7	7 x x x 	[MISS]
Page = 0	7 0 x x 	[MISS]
Page = 1	7 0 1 x 	[MISS]
Page = 2	7 0 1 2 	[MISS]
Page = 0	7 0 1 2 	[HIT]
Page = 3	3 0 1 2 	[MISS]
Page = 0	3 0 1 2 	[HIT]
Page = 4	3 0 4 2 	[MISS]
Page = 2	3 0 4 2 	[HIT]
Page = 3	3 0 4 2 	[HIT]
Page = 0	3 0 4 2 	[HIT]
Page = 3	3 0 4 2 	[HIT]
Page = 2	3 0 4 2 	[HIT]
Page = 3	3 0 4 2 	[HIT]

Total Page Faults: 6
Total Page Hit(s): 8


*************************
#########################
*************************
LFU

--- Page Replacement Algorithm ---
1. FCFS	2. LRU	3. LFU	4. Optimal
Choose Algorithm: 3
Number of Frames: 3
Number of Pages : 7
Page Requests: 1 2 3 4 2 1 5

Page = 1	1 x x 	[MISS]
Page = 2	1 2 x 	[MISS]
Page = 3	1 2 3 	[MISS]
Page = 4	4 2 3 	[MISS]
Page = 2	4 2 3 	[HIT]
Page = 1	4 1 3 	[MISS]
Page = 5	4 5 3 	[MISS]

Total Page Faults: 6
Total Page Hit(s): 1

*************************
#########################
*************************
Optimal Algorithm

--- Page Replacement Algorithm ---
1. FCFS	2. LRU	3. LFU	4. Optimal
Choose Algorithm: 4
Number of Frames: 3
Number of Pages : 20
Page Requests: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

Page = 7	7 x x 	[MISS]
Page = 0	7 0 x 	[MISS]
Page = 1	7 0 1 	[MISS]
Page = 2	2 0 1 	[MISS]
Page = 0	2 0 1 	[HIT]
Page = 3	2 0 3 	[MISS]
Page = 0	2 0 3 	[HIT]
Page = 4	2 4 3 	[MISS]
Page = 2	2 4 3 	[HIT]
Page = 3	2 4 3 	[HIT]
Page = 0	2 0 3 	[MISS]
Page = 3	2 0 3 	[HIT]
Page = 2	2 0 3 	[HIT]
Page = 1	2 0 1 	[MISS]
Page = 2	2 0 1 	[HIT]
Page = 0	2 0 1 	[HIT]
Page = 1	2 0 1 	[HIT]
Page = 7	7 0 1 	[MISS]
Page = 0	7 0 1 	[HIT]
Page = 1	7 0 1 	[HIT]

Total Page Faults: 9
Total Page Hit(s): 11
*************************

*/
	
	
		
	
