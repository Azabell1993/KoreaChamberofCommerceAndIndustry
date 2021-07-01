#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include <sys/types.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <math.h>
#include <ctype.h>

//POSIX
#include <cpio.h>
#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <pthread.h>
#include <pwd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <tar.h>
#include <termios.h>
#include <utime.h>

int linux_conio(void)
{
	struct termios oldt, newt;
	int ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;

	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr ( STDIN_FILENO, TCSANOW, &newt );

	ch = getchar();

	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

	return (ch);
}

#define min(m,n)  ((m)<(n) ? (m) : (n))
#define max(m,n)  ((m)>(n) ? (m) : (n))

#endif

