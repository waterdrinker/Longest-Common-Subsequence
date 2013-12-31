#ifndef STRING_MATCH
#define STRING_MATCH

#define MATCH 0
#define INSERT 1
#define DELETE 2

#define MAXINT 100

typedef struct {
	int cost;
	int parent;
}cell;

void	row_init		     (int i);
void	column_init		     (int i);
int		match			     (char c, char d);
int		indel			     (char c);
int		string_compare	     (char *s, char *t);
void	print_lcs		     (char *s, int i, int j);

#endif