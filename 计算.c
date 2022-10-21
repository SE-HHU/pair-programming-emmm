#include<stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<string.h>
#include<time.h>
#define N 100

FILE* fpQ;     /*题目储存文件*/
FILE* fpA;     /*答案储存文件*/
FILE* fpG;     /*答题情况储存文件*/


char GetOp()     /*随机生成运算符*/
{
	char op[4] = { '+','-','*','/' };
	int i = rand() % 4;
	return op[i];
}


int Random()     /*生成1-100随机数用于运算*/
{
	int b;
	b = rand() % 100 + 1;
	return b;
}


int gcd(int x, int y)     /*辗转相除法求最大公约数*/
{
	if (x % y == 0)
		return y;
	else
		return gcd(y, x % y);
}


void Question(int count, int k)
{
	int num_1, num_2, num_3, maxn, x, y;     /*x,y分别为算式写成分数形式后的分子分母，用于进一步化简*/
	char op1, op2;
	num_1 = Random();
	num_2 = Random();
	num_3 = Random();
	op1 = GetOp();
	op2 = GetOp();
	
	if (k == 0)     /*生成两个运算数的式子*/
	{
		fprintf(fpQ, "题目%d, %d %c %d = \n", count, num_1, op1, num_2);
		fprintf(fpA, "题目%d, %d %c %d = ", count, num_1, op1, num_2);
		switch (op1)
		{
		case '+':
			fprintf(fpA, "%d\n", num_1 + num_2);
			break;
		case '-':
			fprintf(fpA, "%d\n", num_1 - num_2);
			break;
		case '*':
			fprintf(fpA, "%d\n", num_1 * num_2);
			break;
		case '/':
			maxn = gcd(num_1, num_2);
			if ((num_1 >= num_2) && (maxn == num_2))
				fprintf(fpA, "%d\n", num_1 / num_2);
			else
			{
				fprintf(fpA, "%d/%d\n", num_1 / maxn, num_2 / maxn);
			}
			break;
		}		
	}
	else     /*生成三个运算数的式子*/
	{
		fprintf(fpQ, "题目%d, %d %c %d %c %d = \n", count, num_1, op1, num_2, op2, num_3);
		fprintf(fpA, "题目%d, %d %c %d %c %d = ", count, num_1, op1, num_2, op2, num_3);
		if (op1 == '+')
		{
			switch (op2)
			{
			case '+':
				fprintf(fpA, "%d\n", num_1 + num_2 + num_3);
				break;
			case '-':
				fprintf(fpA, "%d\n", num_1 + num_2 - num_3);
				break;
			case '*':
				fprintf(fpA, "%d\n", num_1 + num_2 * num_3);
				break;
			case '/':
				if ((num_2 >= num_3) && (gcd(num_2, num_3) == num_3))
					fprintf(fpA, "%d\n", num_1 + num_2 / num_3);
				else
				{
					x = num_1 * num_3 + num_2;
					y = num_3;
					maxn = gcd(x, y);
					fprintf(fpA, "%d/%d\n", x / maxn, y / maxn);
				}
				break;
			}
		}
		else
			if (op1 == '-')
			{
				switch (op2)
				{
				case '+':
					fprintf(fpA, "%d\n", num_1 - num_2 + num_3);
					break;
				case '-':
					fprintf(fpA, "%d\n", num_1 - num_2 - num_3);
					break;
				case '*':
					fprintf(fpA, "%d\n", num_1 - num_2 * num_3);
					break;
				case '/':
					if ((num_2 >= num_3) && (gcd(num_2, num_3) == num_3))
						fprintf(fpA, "%d\n", num_1 - num_2 / num_3);
					else
					{
						x = num_1 * num_3 - num_2;
						y = num_3;
						maxn = gcd(x, y);
						fprintf(fpA, "%d/%d\n", x / maxn, y / maxn);
					}
					break;
				}
			}
			else
				if (op1 == '*')
				{
					switch (op2)
					{
					case '+':
						fprintf(fpA, "%d\n", num_1 * num_2 + num_3);
						break;
					case '-':
						fprintf(fpA, "%d\n", num_1 * num_2 - num_3);
						break;
					case '*':
						fprintf(fpA, "%d\n", num_1 * num_2 * num_3);
						break;
					case '/':
						if ((num_1 * num_2 >= num_3) && (gcd(num_1 * num_2, num_3) == num_3))
							fprintf(fpA, "%d\n", num_1 * num_2 / num_3);
						else
						{
							x = num_1 * num_2;
							y = num_3;
							maxn = gcd(x, y);
							fprintf(fpA, "%d/%d\n", x / maxn, y / maxn);
						}
						break;
					}
				}
				else
				{
					switch (op2)
					{
					case '+':
						if ((num_1 >= num_2) && (gcd(num_1, num_2) == num_2))
							fprintf(fpA, "%d\n", num_1 / num_2 + num_3);
						else
						{
							x = num_1 + num_2 * num_3;
							y = num_2;
							maxn = gcd(x, y);
							fprintf(fpA, "%d/%d\n", x / maxn, y / maxn);
						}
						break;
					case '-':
						if ((num_1 >= num_2) && (gcd(num_1, num_2) == num_2))
							fprintf(fpA, "%d\n", num_1 / num_2 - num_3);
						else
						{
							x = num_1 - num_2 * num_3;
							y = num_2;
							maxn = gcd(x, y);
							fprintf(fpA, "%d/%d\n", x / maxn, y / maxn);
						}
						break;
					case '*':
						if ((num_1 >= num_2) && (gcd(num_1, num_2) == num_2))
							fprintf(fpA, "%d\n", num_1 / num_2 * num_3);
						else
						{
							x = num_1 * num_3;
							y = num_2;
							maxn = gcd(x, y);
							fprintf(fpA, "%d/%d\n", x / maxn, y / maxn);
						}
						break;
					case '/':
						if ((num_1 >= num_2 * num_3) && (gcd(num_1, num_2 * num_3) == num_2 * num_3))
							fprintf(fpA, "%d\n", num_1 / num_2 / num_3);
						else
						{
							x = num_1;
							y = num_2 * num_3;
							maxn = gcd(x, y);
							fprintf(fpA, "%d/%d\n", x / maxn, y / maxn);
						}
						break;
					}
				}
	}
}

int match_results()
{
	char exercise[N];
	char answer[N];
	int wr[N * 2], right[N * 2];
	int i = 0, correct = 0, wrong = 0;
	fpQ = fopen("Exercises.txt", "r");
	fpA = fopen("Answers.txt", "r");
	fpG = fopen("Grade.txt", "w");
	if ((fpQ == NULL) || (fpA == NULL))
	{
		puts("ERROR WITH DOCUMENT!!!");
		exit(0);
	}
	while ((fgets(exercise, N, fpQ) != NULL) && (fgets(answer, N, fpA) != NULL))
	{
		i++;
		if (!strcmp(exercise, answer))
		{
			right[correct] = i;
			correct++;
		}
		else {
			wr[wrong] = i;
			wrong++;
		}
	}
	fclose(fpQ);
	fclose(fpA);
	fprintf(fpG, "Correct:%d", correct);
	if (correct > 0) {
		fprintf(fpG, "(");
		int j;
		for (j = 0; j < correct; j++) {
			fprintf(fpG, "%d", right[j]);
			if (j < correct - 1) {
				fprintf(fpG, ",");
			}
		}
		fprintf(fpG, ")");
	}
	fprintf(fpG, "\n");
	fprintf(fpG, "Wrong:%d", wrong);
	if (wrong > 0) {
		fprintf(fpG, "(");
		int j;
		for (j = 0; j < wrong; j++) {
			fprintf(fpG, "%d", wr[j]);
			if (j < wrong - 1) {
				fprintf(fpG, ",");
			}
		}
		fprintf(fpG, ")");
	}
	fprintf(fpG, "\n");
	fclose(fpQ);
	fclose(fpA);
	fclose(fpG);
	return 0;
}


int main()
{
	srand((unsigned int)time(NULL));
	int i = 0;
	int k;
	int count = 0, n;
	int number;
	
	printf("题目生成请输入1，答案对比输入2\n");
	scanf("%d", &number);
	switch (number)
	{
	case 1:
		fpQ = fopen("Exercises.txt", "w");
		fpA = fopen("Answers.txt", "w");
		printf("请输入需要生成的题目个数：\n");
		scanf("%d", &n);
		while (count < n)
		{
			k = rand() % 2;
			count += 1;
			Question(count, k);
		}
		fclose(fpQ);
		fclose(fpA);
		break;
	case 2:
		match_results();
		break;
	}	
	return 0;
}
