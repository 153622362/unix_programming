/*more01.c -version 0.1 of more
 * read and print 24 lines then pause for a few special commands
 */
#include <stdio.h>
#include <stdlib.h>
#define PAGELEN 24
#define LINELEN 512
void do_more(FILE *);
int see_more();
int main(int ac, char *av[])
{
    FILE *fp;
    if( ac ==1 )
       do_more(stdin);
    else
      while (--ac)
      if ( (fp = fopen( *++av, "r") ))
      {
        do_more( fp );
        fclose( fp );
      }
      else
        exit(EXIT_SUCCESS);
       return 0;
}

void do_more( FILE *fp)
{
   char line[LINELEN];
   int num_of_lines = 0;
   int see_more(),reply;
   FILE *fp_tty;
   fp_tty = fopen( "/dev/tty", "r");
   if( fp_tty == NULL )
	exit(EXIT_SUCCESS);
   while ( fgets( line, LINELEN, fp) ) { /* more input */
	if( num_of_lines == PAGELEN ) { /* full screen? */
		reply = see_more();	/* y:ask user */
		if ( reply == 0 )	/* n:done */
		   break;
		num_of_lines -= reply;  /* reset count */
	}
	if ( fputs( line, stdout ) == EOF) /*show line */
	    exit(1);			/*or die*/
	num_of_lines++;			/* count it*/
    }
}

int see_more(FILE *cmd)
{
    int c;
    printf("\033[7m more? \033[m");
    while ( (c = getc(cmd)) != EOF )
    {
	if ( c == 'q')
	    return 0;
	if ( c == ' ' )
	    return PAGELEN;
	if ( c == '\n' )
	    return 1;
    }

	return 0 ;
}
