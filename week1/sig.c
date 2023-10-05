#include <stdio.h>
#include <signal.h>

int main() {
	int procNum;
	printf("シグナルを送信するプロセス番号\n > ");
	scanf("%d", &procNum);

	while (1) {
		char input;
		printf("シグナルを送信します\n > ");
		scanf("%c", &input);
		kill(procNum, SIGUSR1);
		printf("シグナルを送信しました\n");
	}
}
