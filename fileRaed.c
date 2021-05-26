#include <stdio.h>

/*以字符串形式读取文件*/
int main()
{
	FILE* fp = NULL;
	char buff[255];

	fp = fopen("ReadTest.txt", "r");
	fscanf(fp, "%s", buff);					  //遇到第一个空格停止读取；
	printf("1: %s\n", buff);

	fgets(buff, 255, (FILE*)fp);			//连续读取 读取一行数据，直到行尾停止；
	printf("2: %s\n", buff);
											              //读取到的字符串会在末尾自动添加 '\0'；
	fgets(buff, 255, (FILE*)fp);
	printf("3: %s\n", buff);
	fclose(fp);

}
