#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
	int i = 0;
	char ch;
	printf("\ncmdline args count=%d", argc);

	/* First argument is executable name only */
	char *fileName = argv[1];
	char* cryptCommand = argv[2];

	printf("\nexe name=%s", argv[0]);
	printf("\n filename %s", fileName);
	printf("\n encryption %s", cryptCommand);
	printf("\n");

	//file pointer
	FILE* fp, * fpt;
	if (strcmp(cryptCommand, "enc") == 0)
	{



		//open the file to be encrypted
		fp = fopen(fileName, "r");
		//check the return of fopen
		if (fp == NULL)
		{
			printf("Error in opening the file...");
			exit(1);
		}


		//also open another file for writing
		fpt = fopen("temp.txt", "w");
		if (fpt == NULL)
		{
			printf("Error in creating of the file %s", fileName + '.crp');
			//close the file
			fclose(fp);
			exit(2);
		}
		while (1)
		{
			ch = fgetc(fp);
			if (ch == EOF)
			{
				break;
			}
			else {
				ch = ch + 100;
				fputc(ch, fpt);
			}
		}
		fclose(fp);
		fclose(fpt);

		//open the file for writing
		fp = fopen(fileName, "w");
		if (fp == NULL)
		{
			printf(" File does not exists or error in opening..!!");
			exit(3);
		}

		//open the temp file for reading
		fpt = fopen("temp.txt", "r");
		if (fpt == NULL)
		{
			printf(" File does not exists or error in opening..!!");
			fclose(fp);
			exit(4);
		}

		while (1)
		{
			ch = fgetc(fpt);
			if (ch == EOF)
			{
				break;
			}
			else
			{
				fputc(ch, fp);
			}
		}

		printf(" File %s successfully encrypted ..!!\n\n", fileName);
		fclose(fp);
		fclose(fpt);
		remove("temp.txt");
	}
	return 0;
}