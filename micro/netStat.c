#include <stdio.h>

void display(char *a, char *b, int offset) {
	int i, j = offset;
	for (i = offset; a[i] != '\n'; i++) {
		if (a[i] == ' ') {
			printf("  ->  [ ");
			while (b[j] != '\n') {
				if (b[j] == ' ') {
					printf(" ]\n");
					j++;
					break;
				}
				else
					printf("%c", b[j]);
				j++;
			}
		}
		else
			printf("%c", a[i]);
	}
	printf("  ->  [ ");
	while (b[j] != '\n')
		printf("%c", b[j++]);
	printf(" ]");
}
void main() {
	char *cmd = "cat /proc/net/netstat";
	char tcp[2500] = " ";
	char tcpn[2500] = " ";
	char ip[2500] = " ";
	char ipn[2500] = " ";
	FILE *fp;
	int i, j;
	if ((fp = popen(cmd, "r")) == NULL)
	{
		printf("Error opening pipe!\n");
		return;
	}

	fgets(tcp, 2500, fp);
	fgets(tcpn, 2500, fp);
	printf("\n\n\n***********************");
	printf("\nExternal TCP Statictics");
	printf("\n***********************\n");
	display(tcp, tcpn, 8);

	fgets(ip, 2000, fp);
	fgets(ipn, 2000, fp);

	printf("\n\n\n*********************");
	printf("\nGeneral IP Statictics");
	printf("\n***********************\n");
	display(ip, ipn, 7);

	printf("\n\n\n");
	pclose(fp);
	return;
}
