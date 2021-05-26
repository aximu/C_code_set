#include <stdio.h>

/*以字符串形式读取文件*/
int main0()
{
	FILE* fp = NULL;
	char buff[255];

	fp = fopen("ReadTest.txt", "r");
    if (fp == NULL)
    {
        return -1;
    }
	fscanf(fp, "%s", buff);					//遇到第一个空格停止读取；
	printf("1: %s\n", buff);

	fgets(buff, 255, (FILE*)fp);			//连续读取 读取一行数据，直到行尾停止；
	printf("2: %s\n", buff);
											//读取到的字符串会在末尾自动添加 '\0'；
	fgets(buff, 255, (FILE*)fp);
	printf("3: %s\n", buff);
	fclose(fp);

}

/*
	fgets()局限性:只能读取单行，遇到换行符就结束；
	fread():可读取多行内容；块读取
*/

/*fread() 和 fwrite() 一般用于二进制文件的输入输出*/
#include <stdio.h>
void main(void)
{
    FILE* stream = NULL;
    char buff[30];
    int i, numread, numwritten;
    // 以文本方式打开文件
    if ((stream = fopen("fread.out", "w+t")) != NULL)  // 如果读取无误
    {
        for (i = 0; i < 25; i++)
            buff[i] = (char)('z' - i);
        numwritten = fwrite(buff, sizeof(char), 25, stream);
        printf("Wrote %d items\n", numwritten);
        fclose(stream);
    }
    else
    {
        printf("Problem opening the file\n");
    }

    if ((stream = fopen("fread.out", "r+t")) != NULL)  // 文件读取
    {
        numread = fread(buff, sizeof(char), 25, stream);
        printf("Number of items read = %d\n", numread);
        printf("Contents of buffer = %.25s\n", buff);
        fclose(stream);
    }
    else
    {
        printf("File could not be opened\n");
    }
}
