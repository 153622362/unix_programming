/*play_again0.c
 * 过程:完成功能->关闭规范输入即时响应(关闭规范标准输入)->忽略非法键(关闭回显)->超时响应(关闭阻塞)->Ctrl-c鲁莽杀信号解决
 *purpose: ask if user wants anthoer transaction
 *method: ask a question, wait for yes/no answer
 *returns: 0=>yes ,1=>no
 *better:eliminate need to press return
 */

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#define ASK "Do you want another transaction"
#define TRIES 3
#define SLEEPTIME 1
#define BEEP putchar('\a')


int main()
{
	int response;
	void ctrl_c_handler(int);
	tty_mode(0);
	set_cr_noecho_mode();
	set_nodelay_mode();
	signal( SIGINT, ctrl_c_handler );
	signal( SIGQUIT, SIG_IGN );
	response = get_response(ASK, TRIES); /*get some answer*/
	tty_mode(1);
	return response;
}

int get_response(char *question, int maxtries)
/*
 *purpose:ask a question and wait for a y/n answer
 *method:use getchar and ignore no y/n answers
 *returns: 0=>yes, 1=>no
 */
{
	int input;
	printf("%s (y/n)",question);
	fflush(stdout);
	while(1){
	sleep(SLEEPTIME);
	input = tolower(get_ok_char());
	if(  input == 'y')
		return 0;
	if(  input == 'n')
		return 1;
	if( maxtries-- == 0 )
		return 2;
	BEEP;
	}

}

get_ok_char()
{
    int c;
    while( ( c = getchar()) != EOF && strchr("yYnN", c) == NULL );
    return c;
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

set_nodelay_mode()
{
	int termflags;
	termflags = fcntl(0, F_GETFL);
	termflags |= O_NDELAY;
	fcntl(0, F_SETFL, termflags);
}

tty_mode(int how)
{
	static struct termios original_mode;
	static int original_flags;
	if( how == 0 ){
	    tcgetattr(0, &original_mode);
	    original_flags = fcntl(0, F_GETFL);
	}else{
	    tcsetattr(0, TCSANOW, &original_mode);
	    fcntl(0, F_SETFL,original_flags);
	}
}

void ctrl_c_handler(int signum)
{
	tty_mode(1);
	exit(EXIT_SUCCESS);

}
