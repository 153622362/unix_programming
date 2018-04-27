/*play_again0.c
 *purpose: ask if user wants anthoer transaction
 *method: ask a question, wait for yes/no answer
 *returns: 0=>yes ,1=>no
 *better:eliminate need to press return
 */

#include <stdio.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"

int get_response( char *);

int main()
{
	int response;
	tty_mode(0);
	set_cr_noecho_mode();
	response = get_response(QUESTION); /*get some answer*/
	tty_mode(1);
	return response;
}

int get_response(char *question)
/*
 *purpose:ask a question and wait for a y/n answer
 *method:use getchar and ignore no y/n answers
 *returns: 0=>yes, 1=>no
 */
{
	int input;
	printf("%s (y/n)",question);
	while(1){
	switch( input = getchar() ){
	case 'y':
	case 'Y': return 0;
	case 'n':
	case 'N': 
	case EOF: return 1;
		}
	}

}

set_cr_noecho_mode()
/*
 *purpose:put file descriptor 0 (i.e. stdin) into chr-by-chr mode
 *method:use bits in termios
 */
{
	struct termios ttystate;
	tcgetattr( 0, &ttystate);
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_lflag &= ~ECHO;
	ttystate.c_cc[VMIN] = 1;
	tcsetattr( 0, TCSANOW, &ttystate);
}

tty_mode(int how)
{
	static struct termios original_mode;
	if( how == 0)
		tcgetattr(0, &original_mode);
	else
		return tcsetattr(0, TCSANOW, &original_mode);
}
