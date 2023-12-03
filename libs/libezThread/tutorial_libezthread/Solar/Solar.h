/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * Solar.h - _explain_
 *
 * Copyright (C) 2011 ezlibs.com, All Rights Reserved.
 *
 * $Id: Solar.h 5884 2012-05-16 09:17:46Z WuJunjie $
 *
 *  Explain:
 *     -
 *      һ��������
 *     -
 *
 *  Update:
 *     2012-05-16 09:17:46   WuJunjie  Create
 */
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
#ifndef __Solar_H__
#define __Solar_H__

#include "EZThread.h"
#include "EZTimer.h"

#ifndef _VERSION
#define _VERSION "1.0.0"
#endif//_VERSION
#ifndef _COPY_RIGHT_STRING
#define _COPY_RIGHT_STRING "@(#) Copyright (c) 2013 ezlibs.com.  All rights reserved"
#endif//_COPY_RIGHT_STRING

#ifndef _CONFIG_FILENAME_MAIN
#define _CONFIG_FILENAME_MAIN "cfg-uniTrans.cfg"
#endif
#ifndef _CONFIG_FILENAME_MAIN_DUPLICATE
#define _CONFIG_FILENAME_MAIN_DUPLICATE "cfg-uniTrans.cfg.duplicate"
#endif
#ifndef _LOG_FILENAME
#define _LOG_FILENAME "log-uniTrans.log"
#endif

class CSolar : public CEZObject
{
public:
    PATTERN_SINGLETON_DECLARE(CSolar);

    CSolar();
    ~CSolar();

    void Initialize(int argc, char * argv[]);

    void Done();
    
    // kill(1)
    void Term();

    int Reboot();
    int Shutdown();

    int Restart();
    int Restore();

    void haveException(int ExcNo=0, char *pMsg = NULL);
    void Cleanup(int iMode=0);
    void TimerProcMaintain();

    const std::string &GetVersion();
    const char *GetCopyRights();
    unsigned int GetRunPeriod();
    time_t GetStartTime();

private:
    /*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
    // ����

    /*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

    int InitializeLogs();

    void ShowVersion();

    CEZTimer          m_TimerMaintain;          //����ܶ�ʱ��

    // �汾�ַ���
    std::string m_strVer;
    // ����ʱ��
    unsigned int m_iRunPeriod;

    time_t m_ttStartTime;


    CEZMutex m_mutexMark;
};

#define g_Solar (*CSolar::instance())

#endif //__Solar_H__
