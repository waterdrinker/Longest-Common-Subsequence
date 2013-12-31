#include "longest_common_subsequence.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

cell m[MAXINT][MAXINT];

void row_init(int i)
{
	m[0][i].cost = 0;
}

void column_init(int i)
{
	m[i][0].cost = 0;
}

int match(char c, char d)
{
	if(c==d) return 0;
	else return 1;
}

int indel(char c)
{
	return 1;
}

int string_compare(char *s, char *t)
{
	int i,j,k;
	for (i = 0; i< MAXINT; i++)
	{
		row_init(i);
		column_init(i);
	}
	for (i=1; i <= strlen(s) ;i++)
	{
		for (j=1; j <= strlen(t) ;j++)
		{
			if (s[i] == t[j])
			{
				m[i][j].parent = MATCH;
				m[i][j].cost = m[i-1][j-1].cost + 1;
			}
			else
			{
				if  (m[i-1][j].cost < m[i][j-1].cost)
				{
					m[i][j].cost = m[i][j-1].cost;
					m[i][j].parent = INSERT;
				}	
				else
				{
					m[i][j].cost = m[i-1][j].cost;
					m[i][j].parent = DELETE;
				}
			}
		}
	}
	print_lcs(s, i-1, j-1);
	return (m[i-1][j-1].cost);
}

void print_lcs(char *s, int i, int j)
{
	if(i==0||j==0) return;
	if (m[i][j].parent == MATCH)
	{
		print_lcs(s, i-1, j-1);
		printf("%c ", s[i-1]);
	}
	else if (m[i][j].parent == INSERT)
		print_lcs(s, i, j-1);
	else if(m[i][j].parent == DELETE)
		print_lcs(s, i-1, j);
}
