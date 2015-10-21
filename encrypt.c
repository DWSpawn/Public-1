#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* InputC(char str[], int n);
void FileInput(char* av[], int ac);
void NowInput();

int main(int argc, char* argv[]) {
	if (argc > 1) {
		FileInput(argv, argc);
	} else {
		NowInput();
	}
	printf("<退出！>\n");
	return EXIT_SUCCESS;
}

char*  InputC(char str[], int n) {
	char *_str=str;
	int i = 0;
	for (; i < n; i++) {
		if ((_str[i] >= 'a' && _str[i] < 'z') || (_str[i] >= 'A' && _str[i] < 'Z')) {
			_str[i] += 1;
		} else if (_str[i] == 'z') {
			_str[i]= 'a';
		} else if (_str[i] == 'Z') {
			_str[i] = 'A';
		}
	}
	return str;
}





void FileInput(char* av[], int ac) {
	int i = 1;
	FILE *fp, *op;
	char a[128];
	char filename[81];
	for (; i < ac; i++) {
		if ((fp = fopen(av[i], "r")) == NULL) {
			strcpy(filename, av[i]);
			printf("STR: %s-->%s\n", av[i], InputC(filename, (int)strlen(av[i])));
		} else {
			strcpy(filename, av[i]);
			strcat(filename, ".jm");
			if ((op = fopen(filename, "a")) == NULL) {
				printf("创建文件失败！\n");
				continue;
			}
			while (fgets(a, 128, fp)) {
				fputs(InputC(a, (int)strlen(a)), op);
//				printf("%s",a);
			}
			printf("FILE: %s-->%s\n", av[i], filename);
			fclose(op);
			fclose(fp);
		}

	}
}

void NowInput() {
	char str[81];
	while (1) {
		printf("输入要加密的字符串(\"exit\"退出）：\n");
		scanf("%s",str);
		if (strcmp(str, "exit\0") == 0) {
			return;
		}
		printf("-->%s\n", InputC(str, (int)strlen(str)));
	}
}


