#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sigNum);

int main() {
	printf("プロセス番号 %d で実行しています\n", getpid());

	if (signal(SIGUSR1, sig_handler) == SIG_ERR) {
		perror("signalの値が不正なため、signal_handlerを登録できませんでした");
		exit(1);
	}
	printf("シグナルを登録しました。\n");

	while (1) {
		printf("z\n");
		sleep(1);
	}
}

void sig_handler(int sigNum) {
	printf("次のシグナル番号のシグナルを受信しました: %d\n", sigNum);
	if (sigNum < 0) {
		printf("処理を終了します\n");
		exit(1);
	}
		
}
