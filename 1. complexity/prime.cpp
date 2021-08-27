#include <stdio.h>

// factorial: n! = 1 * 2 * 3 * 4 * ... * n
int main() {
	int n, i, num;
	printf("enter a number: ");
	scanf("%d", &n);
	for (num = 1; num <= n; num++) {
		for (i = 2; i < num; i++) {
			if (num % i == 0)
				break;
		}
		if (i == num)
			printf("%d, ", num);
	}
	return 0;
}

