#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* biggest(char *nb1, char* nb2)
{
	if (strlen(nb1) > strlen(nb2))
		return nb1;
	return nb2;
}

int opplus(char* nb1, char* nb2)
{
/*	char* ret;
	int inc1 = strlen(nb1);
	int inc2 = strlen(nb2);
	if (!(ret = malloc(sizeof(char) * (strlen(biggest(nb1, nb2)) + 1))))
		return NULL;*/
	return (atoi(nb1) + atoi(nb2));
}

int opminus(char* nb1, char* nb2)
{
	return (atoi(nb1) - atoi(nb2));
}

int optimes(char* nb1, char* nb2)
{
	return (atoi(nb1) * atoi(nb2));
}

int opdivide(char* nb1, char* nb2)
{
	return (atoi(nb1) / atoi(nb2));
}

int countOp(char* line)
{
	int cnt = 0;
	unsigned int i = 0;

	while (i < strlen(line))
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] >= '0' && line[i] <= '9')
		{
			while (line[i] >= '0' && line[i] <= '9')
				i++;
			cnt++;
		}
		else if (line[i] == '+' || line[i] == '*' || line[i] == '/' || line[i] == '-')
		{
			cnt++;
			i++;
		}
		else
			return (-1);
	}
	return (cnt);
}

int* countSizeOfOp(char *line)
{
	unsigned int i = 0;
	int cnt = 0;
	int* listSize;
	if (!(listSize = malloc(sizeof(int) * countOp(line) + 1)))
		return NULL;
	while (i < strlen(line))
	{
		listSize[cnt] = 0;
		if (line[i] == ' ')
			i++;
		else if (line[i] >= '0' && line[i] <= '9')
		{
			while (line[i] >= '0' && line[i] <= '9')
			{
				listSize[cnt]++;
				i++;
			}
			cnt++;
		}
		else if (line[i] == '+' || line[i] == '*' || line[i] == '/' || line[i] == '-')
		{
			listSize[cnt] = 1;
			cnt++;
			i++;
		}
		else
			return NULL;
	}
	return (listSize);
}

int parsAnd(char *line)
{
	unsigned int i = 0;
	unsigned int j = 0;
	char** tabOfContent;
	int* sizeOfOp;
	int nbrOfOp;

	if ((nbrOfOp = countOp(line)) == -1)
		return (-1);
	if ((sizeOfOp = countSizeOfOp(line)) == NULL)
		return (-1);
	if (!(tabOfContent = malloc(sizeof(char*) * (nbrOfOp + 10))))
		return (-2);
	while (i < strlen(line))
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] >= '0' && line[i] <= '9')
		{
			int k = 0;
			while (line[i] >= '0' && line[i] <= '9')
			{
				if (!(tabOfContent[j] = malloc(sizeof(char) * (sizeOfOp[j] + 1))))
					return (-2);
				tabOfContent[j][k] = line[i];
				printf("%c %c\n", line[i], tabOfContent[j][k]);
				k++;
				i++;
			}
			tabOfContent[j][i] = '\0';
			printf("j'arrive ici izi nombre %s\n", tabOfContent[j]);

			j++;
		}
		else if (line[i] == '+' || line[i] == '*' || line[i] == '/' || line[i] == '-')
		{
			if (!(tabOfContent[j] = malloc(sizeof(char) * 2)))
				return (-2);
			tabOfContent[j][0] = line[i];
			tabOfContent[j][1] = '\0';
			printf("j'arrive ici izi op\n%s\n", tabOfContent[j]);
			i++;
			j++;
		}
		else
			return (-1);
	}
	int w = 0;
	printf("j'arrive ici izi fin");
	while (w < 5)
	{
		printf("%s", tabOfContent[w]);
		w++;
	}
	return (0);
}


void main(int ac, char** av)
{
	parsAnd("123 + 12 - 6");
	/*int* hey = countSizeOfOp("123 + 12 - 6");
	printf("%d\n", hey[0]);
	printf("%d\n", hey[1]);
	printf("%d\n", hey[2]);
	printf("%d\n", hey[3]);
	printf("%d\n", hey[4]);
	int op = countOp("123 + 12 - 6");
	printf("%d\n", op);*/
}