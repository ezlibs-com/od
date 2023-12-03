/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * Main.cpp - _explain_
 *
 * Copyright (C) 2011 ezlibs.com, All Rights Reserved.
 *
 * $Id: Main.cpp 5884 2012-05-16 09:17:46Z WuJunjie $
 *
 *  Explain:
 *     -
 *      һ�����main (c++ ��)
 *     -
 *
 *  Update:
 *     2012-05-16 09:17:46   WuJunjie  Create
 */
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <syslog.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "SimpleThread.h"
#include "LocalConsole.h"

#include "Solar.h"
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

int daemon_init(void);
void signal_proc(int signo);

/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
int main(int argc, char * argv[])
{
    // ��ӡ��Ϣ
    printf("main(%d,", argc);
    for(int i = 0; i < argc; i++)
    {
        printf(" %s", argv[i]);
    }
    printf(")\n");
    
#if 0 // ����Щ������⣬ Ҳ�ޱ�Ҫ���ݲ���Ϊdaemon
    char *pRunMode = argc>1?argv[1]:(char *)"-s";

    if (strcmp(pRunMode, "-d")==0)
    {
        if(daemon_init() == -1)
        {
            printf("can't fork self \n");
            exit(0);
        }
    }
#endif

    signal(SIGPIPE, signal_proc);

    signal(SIGTERM, signal_proc);
    signal(SIGKILL, signal_proc);
    signal(SIGQUIT, signal_proc);
    signal(SIGINT, signal_proc);
	
    // ��ʼ��
    g_Solar.Initialize(argc, argv);
    // just exa
    //g_SimpleThread.Start();
    g_LocalConsole.Start();

    // ���ĵ��ã�
    // ���һЩ����ά��������֮��
    g_Solar.Done();

    return 0;
}

int daemon_init(void)
{
    /* Our process ID and Session ID */
    pid_t pid, sid;

    /* Fork off the parent process */
    pid = fork();
    if (pid < 0)
    {
        return(-1);
    }
    /* If we got a good PID, then
       we can exit the parent process. */
    if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }

    /* Change the file mode mask */
    umask(0);

    /* Open any logs here */

    /* Create a new SID for the child process */
    sid = setsid();
    if (sid < 0)
    {
        /* Log the failure */

        //exit(EXIT_FAILURE);
        return(-1);
    }

    /* Change the current working directory */
    //        if ((chdir("/")) < 0) {
    //                /* Log the failure */
    //                exit(EXIT_FAILURE);
    //        }

    /* Close out the standard file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    return(0);
}

void signal_proc(int signo)
{
    if(signo == SIGTERM 	\
    	|| signo == SIGKILL \
    	|| signo == SIGQUIT \
    	|| signo == SIGINT   \
    	)
    {
        g_Solar.haveException(signo, (char *)"on exit signal");
        g_Solar.Term();
        exit(0);
    }
    else if(signo == SIGPIPE)
    {
        g_Solar.haveException(signo, (char *)"on signal:SIGPIPE");
    }
}

