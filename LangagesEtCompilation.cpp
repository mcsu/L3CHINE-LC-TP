// LangagesEtCompilation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"



/********************************************/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "conio.h"
#include <string.h>

/*******************************************/

int count = 0;              /*�ֽ�Ĳ���ʽ�ĸ���Le Nombre des CSS*/
int number;               /*�����ս���ͷ��ս��������Le Nombre des tous les Ter et Non-Ter*/
char start;               /*��ʼ����Le signe de debut*/
char termin[50];          /*�ս����*/
char non_ter[50];         /*���ս����*/
char v[50];               /*���з���*/
char left[50];            /*��*/
char right[50][50];       /*�Ҳ�*/
char first[50][50], follow[50][50];       /*������ʽ�Ҳ���FIRST���󲿵�FOLLOW����*/
char first1[50][50];      /*���е������ŵ�FIRST����*/
char select[50][50];      /*����������ʽ��SELECT����*/
char f[50], F[50];         /*��¼�����ŵ�FIRST��FOLLOW�Ƿ������*/
char empty[20];           /*��¼��ֱ���Ƴ�^�ķ���*/
char TEMP[50];            /*��FOLLOWʱ���ĳһ���Ŵ���FIRST����*/
int validity = 1;           /*��ʾ�����ķ��Ƿ���Ч*/
int ll = 1;                 /*��ʾ�����ķ��Ƿ�ΪLL(1)�ķ�*/
int M[20][20];            /*������*/
char choose;              /*�û�����ʱʹ��*/
char empt[20];            /*��_emp()ʱʹ��*/
char fo[20];              /*��FOLLOW����ʱʹ��*/


char vn[50], vt[50];
char s;
char p[50][50];
int i, j, k;


						  /*******************************************
						  �ж�һ���ַ��Ƿ���ָ���ַ�����
						  ********************************************/
int in(char c, char *p)
{
	int i;
	if (strlen(p) == 0)
		return(0);
	for (i = 0;; i++)
	{
		if (p[i] == c)
			return(1);       /*���ڣ�����*/
		if (i == strlen(p))
			return(0);       /*�����ڣ�����*/
	}
}
int w = 0;
/*******************************************
�ļ���ȡ
********************************************/
void Lecture(char* FileName)
{
	FILE *fp;  // �ļ�ָ�� 
	if ((fp = fopen(FileName, "rt+")) == NULL) {
		printf("\nERROR��\n");
		getch();
		exit(1);
	}
	else
	{
		printf("\nsucc��s ��\n");

	}
	
	
	do{
		fscanf(fp, "%s\n", p[w]);   //��ȡһ��
		printf("%s\n", p[w]); //���
		vn[w] = p[w][0];
		w++;
	} while (!feof(fp));
	vn[w + 1] = '\0';
	fclose(fp);
}


/*******************************************
�õ�һ�����Ƿ��ս���ķ���
********************************************/
char c()
{
	char c = 'A';
	while (in(c, non_ter) == 1)
		c++;
	return(c);
}
/*******************************************
�ֽ⺬����ݹ�Ĳ���ʽ
********************************************/
void recur(char *point)
{                     /*�����Ĳ���ʽ��point[]��*/
	int j, m = 0, n = 3, k;
	char temp[20], ch;
	ch = c();           /*�õ�һ�����ս��*/
	k = strlen(non_ter);
	non_ter[k] = ch;
	non_ter[k + 1] = '\0';
	for (j = 0; j <= strlen(point) - 1; j++)
	{
		if (point[n] == point[0])
		{                          /*�����|������׷��ź�����ͬ*/
			for (j = n + 1; j <= strlen(point) - 1; j++)
			{
				while (point[j] != '|'&&point[j] != '\0')
					temp[m++] = point[j++];
				left[count] = ch;
				memcpy(right[count], temp, m);
				right[count][m] = ch;
				right[count][m + 1] = '\0';
				m = 0;
				count++;
				if (point[j] == '|')
				{
					n = j + 1;
					break;
				}
			}
		}
		else
		{                          /*�����|������׷��ź��󲿲�ͬ*/
			left[count] = ch;
			right[count][0] = '^';
			right[count][1] = '\0';
			count++;
			for (j = n; j <= strlen(point) - 1; j++)
			{
				if (point[j] != '|')
					temp[m++] = point[j];
				else
				{
					left[count] = point[0];
					memcpy(right[count], temp, m);
					right[count][m] = ch;
					right[count][m + 1] = '\0';
					printf(" count=%d ", count);
					m = 0;
					count++;
				}
			}
			left[count] = point[0];
			memcpy(right[count], temp, m);
			right[count][m] = ch;
			right[count][m + 1] = '\0';
			count++;
			m = 0;
		}
	}
}
/*******************************************
�ֽⲻ������ݹ�Ĳ���ʽ
********************************************/
void non_re(char *point)
{
	int m = 0, j;
	char temp[20];
	for (j = 3; j <= strlen(point) - 1; j++)
	{
		if (point[j] != '|')
			temp[m++] = point[j];
		else
		{
			left[count] = point[0];
			memcpy(right[count], temp, m);
			right[count][m] = '\0';
			m = 0;
			count++;
		}
	}
	left[count] = point[0];
	memcpy(right[count], temp, m);
	right[count][m] = '\0';
	count++;
	m = 0;
}
/*******************************************
����һ���ķ�
********************************************/

char grammer(char *t, char *n, char *left, char right[50][50])
{
	i = strlen(vn);
	memcpy(n, vn, i);
	n[i] = '\0';
	printf("Veuillez taper le String des terminaux ��");
	scanf("%s", vt);
	getchar();
	i = strlen(vt);
	memcpy(t, vt, i);
	t[i] = '\0';
	printf("Veuillez taper Axiome ��");
	scanf("%c", &s);
	getchar();
	i = w;
	for (j = 0; j <= i - 1; j++)
		if (p[j][1] != '-' || p[j][2] != '>')
		{
			printf("\ninput error!");
			validity = 0;
			return('\0');
		}            /*����������*/
	for (k = 0; k <= i - 1; k++)
	{                        /*�ֽ�����ĸ�����ʽ*/
		if (p[k][3] == p[k][0])
			recur(p[k]);
		else
			non_re(p[k]);
	}
	return(s);
}
/*******************************************
���������Ż���Ŵ�������һ���Ŵ�
********************************************/
void merge(char *d, char *s, int type)
{                 /*d��Ŀ����Ŵ���s��Դ����type����Դ���еġ�^ ��һ������Ŀ����
				  type����Դ���еġ�^ ��������Ŀ��*/
	int i, j;
	for (i = 0; i <= strlen(s) - 1; i++)
	{
		if (type == 2 && s[i] == '^')
			;
		else
		{
			for (j = 0;; j++)
			{
				if (j<strlen(d) && s[i] == d[j])
					break;
				if (j == strlen(d))
				{
					d[j] = s[i];
					d[j + 1] = '\0';
					break;
				}
			}
		}
	}
}
/*******************************************
��������ֱ���Ƴ�^�ķ���
********************************************/
void emp(char c)
{                   /*���������ɡ�^ ���Ƴ��ķ���*/
	char temp[10];
	int i;
	for (i = 0; i <= count - 1; i++)
	{
		if (right[i][0] == c&&strlen(right[i]) == 1)
		{
			temp[0] = left[i];
			temp[1] = '\0';
			merge(empty, temp, 1);
			emp(left[i]);
		}
	}
}
/*******************************************
��ĳһ�����ܷ��Ƴ���^ ��
********************************************/
int _emp(char c)
{                  /*�����Ƴ������أ����򣬷���*/
	int i, j, k, result = 1, mark = 0;
	char temp[20];
	temp[0] = c;
	temp[1] = '\0';
	merge(empt, temp, 1);
	if (in(c, empty) == 1)
		return(1);
	for (i = 0;; i++)
	{
		if (i == count)
			return(0);
		if (left[i] == c)         /*��һ����Ϊc�Ĳ���ʽ*/
		{
			j = strlen(right[i]);    /*jΪ�Ҳ��ĳ���*/
			if (j == 1 && in(right[i][0], empty) == 1)
				return(1);
			else if (j == 1 && in(right[i][0], termin) == 1)
				return(0);
			else
			{
				for (k = 0; k <= j - 1; k++)
					if (in(right[i][k], empt) == 1)
						mark = 1;
				if (mark == 1)
					continue;
				else
				{
					for (k = 0; k <= j - 1; k++)
					{
						result *= _emp(right[i][k]);
						temp[0] = right[i][k];
						temp[1] = '\0';
						merge(empt, temp, 1);
					}
				}
			}
			if (result == 0 && i<count)
				continue;
			else if (result == 1 && i<count)
				return(1);
		}
	}
}
/*******************************************
�ж϶�����ķ��Ƿ���ȷ
********************************************/
int judge()
{
	int i, j;
	for (i = 0; i <= count - 1; i++)
	{
		if (in(left[i], non_ter) == 0)
		{                    /*���󲿲��ڷ��ս���У�����*/
			printf("\nerror1!");
			validity = 0;
			return(0);
		}
		for (j = 0; j <= strlen(right[i]) - 1; j++)
		{
			if (in(right[i][j], non_ter) == 0 && in(right[i][j], termin) == 0 && right[i][j] != '^')
			{               /*���Ҳ�ĳһ���Ų��ڷ��ս�����ս�����Ҳ�Ϊ��^ ��������*/
				printf("\nerror2!");
				validity = 0;
				return(0);
			}
		}
	}
	return(1);
}
/*******************************************
�󵥸����ŵ�FIRST
********************************************/
void first2(int i)
{                     /*iΪ������������������е����*/
	char c, temp[20];
	int j, k, m;
	c = v[i];
	char ch = '^';
	emp(ch);
	if (in(c, termin) == 1)       /*��Ϊ�ս��*/
	{
		first1[i][0] = c;
		first1[i][1] = '\0';
	}
	else if (in(c, non_ter) == 1)       /*��Ϊ���ս��*/
	{
		for (j = 0; j <= count - 1; j++)
		{
			if (left[j] == c)
			{
				if (in(right[j][0], termin) == 1 || right[j][0] == '^')
				{
					temp[0] = right[j][0];
					temp[1] = '\0';
					merge(first1[i], temp, 1);
				}
				else if (in(right[j][0], non_ter) == 1)
				{
					if (right[j][0] == c)
						continue;
					for (k = 0;; k++)
						if (v[k] == right[j][0])
							break;
					if (f[k] == '0')
					{
						first2(k);
						f[k] = '1';
					}
					merge(first1[i], first1[k], 2);
					for (k = 0; k <= strlen(right[j]) - 1; k++)
					{
						empt[0] = '\0';
						if (_emp(right[j][k]) == 1 && k<strlen(right[j]) - 1)
						{
							for (m = 0;; m++)
								if (v[m] == right[j][k + 1])
									break;
							if (f[m] == '0')
							{
								first2(m);
								f[m] = '1';
							}
							merge(first1[i], first1[m], 2);
						}
						else if (_emp(right[j][k]) == 1 && k == strlen(right[j]) - 1)
						{
							temp[0] = '^';
							temp[1] = '\0';
							merge(first1[i], temp, 1);
						}
						else
							break;
					}
				}
			}
		}
	}
	f[i] = '1';
}
/*******************************************
�������ʽ�Ҳ���FIRST
********************************************/
void FIRST(int i, char *p)
{
	int length;
	int j, k, m;
	char temp[20];
	length = strlen(p);
	if (length == 1)                  /*����Ҳ�Ϊ��������*/
	{
		if (p[0] == '^')
		{
			if (i >= 0)
			{
				first[i][0] = '^';
				first[i][1] = '\0';
			}
			else
			{
				TEMP[0] = '^';
				TEMP[1] = '\0';
			}
		}
		else
		{
			for (j = 0;; j++)
				if (v[j] == p[0])
					break;
			if (i >= 0)
			{
				memcpy(first[i], first1[j], strlen(first1[j]));
				first[i][strlen(first1[j])] = '\0';
			}
			else
			{
				memcpy(TEMP, first1[j], strlen(first1[j]));
				TEMP[strlen(first1[j])] = '\0';
			}
		}
	}
	else                      /*����Ҳ�Ϊ���Ŵ�*/
	{
		for (j = 0;; j++)
			if (v[j] == p[0])
				break;
		if (i >= 0)
			merge(first[i], first1[j], 2);
		else
			merge(TEMP, first1[j], 2);
		for (k = 0; k <= length - 1; k++)
		{
			empt[0] = '\0';
			if (_emp(p[k]) == 1 && k<length - 1)
			{
				for (m = 0;; m++)
					if (v[m] == right[i][k + 1])
						break;
				if (i >= 0)
					merge(first[i], first1[m], 2);
				else
					merge(TEMP, first1[m], 2);
			}
			else if (_emp(p[k]) == 1 && k == length - 1)
			{

				temp[0] = '^';
				temp[1] = '\0';
				if (i >= 0)
					merge(first[i], temp, 1);
				else
					merge(TEMP, temp, 1);
			}
			else if (_emp(p[k]) == 0)
				break;
		}
	}
}
/*******************************************
�������ʽ�󲿵�FOLLOW
********************************************/
void FOLLOW(int i)
{
	int j, k, m, n, result = 1;
	char c, temp[20];
	c = non_ter[i];             /*cΪ����ķ��ս��*/
	temp[0] = c;
	temp[1] = '\0';
	merge(fo, temp, 1);
	if (c == start)
	{                         /*��Ϊ��ʼ����*/
		temp[0] = '#';
		temp[1] = '\0';
		merge(follow[i], temp, 1);
	}
	for (j = 0; j <= count - 1; j++)
	{
		if (in(c, right[j]) == 1)     /*��һ���Ҳ�����c�Ĳ���ʽ*/
		{
			for (k = 0;; k++)
				if (right[j][k] == c)
					break;       /*kΪc�ڸò���ʽ�Ҳ������*/
			for (m = 0;; m++)
				if (v[m] == left[j])
					break;        /*mΪ����ʽ�󲿷��ս�������з����е����*/
			if (k == strlen(right[j]) - 1)
			{              /*���c�ڲ���ʽ�Ҳ������*/
				if (in(v[m], fo) == 1)
				{
					merge(follow[i], follow[m], 1);
					continue;
				}
				if (F[m] == '0')
				{
					FOLLOW(m);
					F[m] = '1';
				}
				merge(follow[i], follow[m], 1);
			}
			else
			{              /*���c���ڲ���ʽ�Ҳ������*/
				for (n = k + 1; n <= strlen(right[j]) - 1; n++)
				{
					empt[0] = '\0';
					result *= _emp(right[j][n]);
				}
				if (result == 1)
				{         /*����Ҳ�c����ķ��Ŵ����Ƴ�^*/
					if (in(v[m], fo) == 1)
					{           /*����ѭ���ݹ�*/
						merge(follow[i], follow[m], 1);
						continue;
					}
					if (F[m] == '0')
					{
						FOLLOW(m);
						F[m] = '1';
					}
					merge(follow[i], follow[m], 1);
				}
				for (n = k + 1; n <= strlen(right[j]) - 1; n++)
					temp[n - k - 1] = right[j][n];
				temp[strlen(right[j]) - k - 1] = '\0';
				FIRST(-1, temp);
				merge(follow[i], TEMP, 2);
			}
		}
	}
	F[i] = '1';
}

/*******************************************
�ж϶����ķ��Ƿ�Ϊһ��LL(1)�ķ�
********************************************/
int ll1()
{
	int i, j, length, result = 1;
	char temp[50];
	for (j = 0; j <= 49; j++)
	{	                           /*��ʼ��*/
		first[j][0] = '\0';
		follow[j][0] = '\0';
		first1[j][0] = '\0';
		select[j][0] = '\0';
		TEMP[j] = '\0';
		temp[j] = '\0';
		f[j] = '0';
		F[j] = '0';
	}
	for (j = 0; j <= strlen(v) - 1; j++)
		first2(j);                /*�󵥸����ŵ�FIRST����*/
	printf("\nfirst1:");
	for (j = 0; j <= strlen(v) - 1; j++)
		printf("%c:%s  ", v[j], first1[j]);
	//printf("\nempty:%s", empty);
	//printf("\n:::\n_emp:");
	//for (j = 0; j <= strlen(v) - 1; j++)
		//printf("%d  ", _emp(v[j]));
	for (i = 0; i <= count - 1; i++)
		FIRST(i, right[i]);          /*��FIRST*/
	printf("\n");
	for (j = 0; j <= strlen(non_ter) - 1; j++)
	{                               /*��FOLLOW*/
		if (fo[j] == 0)
		{
			fo[0] = '\0';
			FOLLOW(j);
		}
	}
	printf("\nfirst:");
	for (i = 0; i <= count - 1; i++)
		printf("%s ", first[i]);
	printf("\nfollow:");
	for (i = 0; i <= strlen(non_ter) - 1; i++)
		printf("%s ", follow[i]);
	for (i = 0; i <= count - 1; i++)
	{                          /*��ÿһ����ʽ��SELECT����*/
		memcpy(select[i], first[i], strlen(first[i]));
		select[i][strlen(first[i])] = '\0';
		for (j = 0; j <= strlen(right[i]) - 1; j++)
			result *= _emp(right[i][j]);
		if (strlen(right[i]) == 1 && right[i][0] == '^')
			result = 1;
		if (result == 1)
		{
			for (j = 0;; j++)
				if (v[j] == left[i])
					break;
			merge(select[i], follow[j], 1);
		}
	}
	/*printf("\nselect:");
	for (i = 0; i <= count - 1; i++)
		printf("%s ", select[i]);*/
	memcpy(temp, select[0], strlen(select[0]));
	temp[strlen(select[0])] = '\0';
	for (i = 1; i <= count - 1; i++)
	{                 /*�ж������ķ��Ƿ�ΪLL(1)�ķ�*/
		length = strlen(temp);
		if (left[i] == left[i - 1])
		{
			merge(temp, select[i], 1);
			if (strlen(temp)<length + strlen(select[i]))
				return(0);
		}
		else
		{
			temp[0] = '\0';
			memcpy(temp, select[i], strlen(select[i]));
			temp[strlen(select[i])] = '\0';
		}
	}
	return(1);
}

/*******************************************
���������M
********************************************/
void MM()
{
	int i, j, k, m;
	for (i = 0; i <= 19; i++)
		for (j = 0; j <= 19; j++)
			M[i][j] = -1;
	i = strlen(termin);
	termin[i] = '#';     /*��#�����ս������*/
	termin[i + 1] = '\0';
	for (i = 0; i <= count - 1; i++)
	{
		for (m = 0;; m++)
			if (non_ter[m] == left[i])
				break;      /*mΪ����ʽ�󲿷��ս�������*/
		for (j = 0; j <= strlen(select[i]) - 1; j++)
		{
			if (in(select[i][j], termin) == 1)
			{
				for (k = 0;; k++)
					if (termin[k] == select[i][j])
						break;        /*kΪ����ʽ�Ҳ��ս�������*/
				M[m][k] = i;
			}
		}
	}
}

/*******************************************
�ܿ��㷨
********************************************/
void syntax()
{
	int i, j, k, m, n, p, q;
	char ch;
	char S[50], str[50];
	printf("Veuillez taper un STRING��");
	scanf("%s", str);
	getchar();
	i = strlen(str);
	str[i] = '#';
	str[i + 1] = '\0';
	S[0] = '#';
	S[1] = start;
	S[2] = '\0';
	j = 0;
	ch = str[j];
	while (1)
	{
		if (in(S[strlen(S) - 1], termin) == 1)
		{
			if (S[strlen(S) - 1] != ch)
			{
				printf("\nFaut��");
				return;
			}
			else if (S[strlen(S) - 1] == '#')
			{
				printf("\nvrai.");
				return;
			}
			else
			{
				S[strlen(S) - 1] = '\0';
				j++;
				ch = str[j];
			}
		}
		else
		{
			for (i = 0;; i++)
				if (non_ter[i] == S[strlen(S) - 1])
					break;
			for (k = 0;; k++)
			{
				if (termin[k] == ch)
					break;
				if (k == strlen(termin))
				{
					printf("\nL'erreur de  le lexical��");
					return;
				}
			}
			if (M[i][k] == -1)
			{
				printf("\nL'erreur de la grammaire��");
				return;
			}
			else
			{
				m = M[i][k];
				if (right[m][0] == '^')
					S[strlen(S) - 1] = '\0';
				else
				{
					p = strlen(S) - 1;
					q = p;
					for (n = strlen(right[m]) - 1; n >= 0; n--)
						S[p++] = right[m][n];
					S[q + strlen(right[m])] = '\0';
				}
			}
		}
		printf("\nS:%s str:", S);
		for (p = j; p <= strlen(str) - 1; p++)
			printf("%c", str[p]);
		printf(" ");
	}
}

/*******************************************
һ���û����ú���
********************************************/
void menu()
{
	syntax();
	printf("\nContinuer ��(y or n):");
	scanf("%c", &choose);
	getchar();
	while (choose == 'y')
	{
		menu();
	}
}
void leftRight()
{
	printf("Les grammaire sans la r��cursivit�� �� gauche");
	for (int i = count-1; i >= 0; i--)
	{
		printf("\n%c->%s",left[i],right[i]);
	}
}


/*******************************************
������
********************************************/
void main()
{
	char filename[] = {""};
	printf("Veuillez taper le nom du fichier\n");
	scanf("%s",filename);
	Lecture(filename);
	
	int i, j;
	start = grammer(termin, non_ter, left, right);             
	printf("count=%d", count);
	printf("\nstart:%c\n", start);
	leftRight();
	strcpy(v, non_ter);
	strcat(v, termin);
	printf("\nv:%s", v);
	printf("\nnon_ter:%s", non_ter);
	printf("\ntermin:%s", termin);
	//printf("\nright:");
	//for (i = 0; i <= count - 1; i++)
	//	printf("%s   ", right[i]);
	//printf("\nleft:");
	//for (i = 0; i <= count - 1; i++)
	//	printf("%c   ", left[i]);
	if (validity == 1)
		validity = judge();
	printf("\nvalidity=%d", validity);
	if (validity == 1)
	{
		printf("\nLa grammaire succ��s");
		ll = ll1();
		printf("\nll=%d", ll);
		if (ll == 0)
			printf("\nC'est pas un LL1 grammaire��");
		else
		{
			MM();
			printf("\n");
			for (i = 0; i <= 19; i++)
				for (j = 0; j <= 19; j++)
					if (M[i][j] >= 0)
						printf("M[%d][%d]=%d ", i, j, M[i][j]);
			printf("\n");
			menu();
		}
	}
	
	getch();
}

