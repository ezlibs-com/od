/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * api_thread.h - _explain_
 *
 * Copyright (C) 2011 ezlibs.com, All Rights Reserved.
 *
 * $Id: api_thread.h 5884 2012-05-16 09:15:42Z WuJunjie $
 *
 *  Explain:
 *     -�߳�API����װ�˲�ͬ����ϵͳ���߳̽ӿڡ�-
 *
 *  Update:
 *     2012-05-16 09:09:51   Create
 */
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

#ifndef __THREAD_API_H__
#define __THREAD_API_H__

#include "typedef_ezthread.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup ThreadAPI API Thread
/// �߳�API����װ�˲�ͬ����ϵͳ���̶߳���
///	\n ��������ͼ:
/// \code
///    ===========================
///                |
///           ThreadCreate
///                |------------+
///        ThreadShareSocket    |
///           ThreadGetID       |
///                |------------+
///           ThreadExit
///          ThreadDestory
///                |
///    ===========================
/// \endcode
/// @{


/// �����̡߳�
/// 
/// \param [out] phThread �̴߳����ɹ�ʱ���������߳̾����
/// \param [in] pStartAddress �̺߳����ĵ�ַ��
/// \param [in] pParameter �̺߳����Ĳ�����
/// \param [in] nPriority �߳����ȼ���ȡֵ0-127��ֵԽС��ʾ���ȼ�Խ�ߣ��ᱻת��
///        �ɶ�Ӧ����ϵͳ�����ȼ���
/// \param [in] dwStatckSize Ϊ�߳�ָ���Ķ�ջ��С���������0����С�ڱ����ֵ��
///        ��ʹ��ȱʡֵ��
/// \param [in] pName �߳������ַ�����
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int ThreadCreate(EZTHREAD__HANDLE *phThread,
				 void(*pStartAddress)(void *p),
				 void *pParameter,
				 int nPriority,
				 unsigned int dwStatckSize,
				 const char*pName);


/// �����̡߳���ָ�����߳��˳�ǰ�����������̡߳�
/// 
/// \param [in] hThread ָ���������̵߳ľ����
/// \retval 0  ���ٳɹ�
/// \retval <0 ����ʧ��
int ThreadDestory(EZTHREAD__HANDLE hThread);


/// ����̵߳Ĺ����׽��֡�ĳЩ����ϵͳ��ͬ���̲߳���ʹ��ͬһ���׽��֣���Ҫ����ת����
/// �������ʹ��ͬһ���׽��֣���ֱ�ӷ��ش������������
/// 
/// \param [in] hThread ָ��Ҫʹ���׽��ֵ��߳̾����
/// \param [in] nSocket �������߳��д������׽��ֵ���������
/// \return �������׽���������
int ThreadShareSocket(EZTHREAD__HANDLE hThread, int nSocket);


/// �˳������̡߳�
void ThreadExit(void);


/// ���ص����̵߳�ID��
/// 
/// \return �߳�ID
int ThreadGetID(void);

#define TSK_DEF_STACK_SIZE		16384

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif //__THREAD_API_H__

