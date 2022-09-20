#include <stdio.h>

// to ignore first two columns
int ignore = 2, ig;

// display each word
// every number is also a word
void display(char *word) {
	int isEmpty = 1, i;
	// check if string empty
	for(i = 0; word[i] != '\0'; i++)
		if(word[i] != ' ')
			isEmpty = 0;
	// only print non-empty string and columns from 3
	if(isEmpty == 0 && ig++ >= ignore)
		printf(" %-5s ", word);
}

void line(char *a) {
	ig = 0;
	char word[20];
	int i, j = 0;
	// split line and print
	for(i = 0; a[i] != '\n'; i++) {
		if(a[i] != ' ')
			word[j++] = a[i];
		else {
			word[j] = '\0';
			display(word);
			j = 0;
		}
	}
	printf("\n");
}

void main() {
	char *cmd = "cat /proc/diskstats";
	char dis[500] = " ";
	FILE *fp;
	int i, j;

	if ((fp = popen(cmd, "r")) == NULL) {
		printf("Error opening pipe!\n");
		return;
	}
	
	printf("--- Disk Statictics ---");
	// table header. Might change if you run from lab system.
	// In wsl its 17 columns!!
	// Values will automatically change, only header needs to be changed.
	// col<2 space>col format with (col length 5 charatcter)
	printf("\n BLOCK  MAJOR  MINOR  R COM  R MER  SEC R  RTIME  W COM  W MER  SEC W  WTIME  PROGR  IOTIM  WEIGH  D COM  D MER  SEC D\n");
	while(fgets(dis, 500, fp) > 0)
		line(dis);
		
	pclose(fp);
	printf("\n");
}
