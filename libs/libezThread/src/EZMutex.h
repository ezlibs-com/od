/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * EZMutex.h - _explain_
 *
 * Copyright (C) 2011 ezlibs.com, All Rights Reserved.
 *
 * $Id: EZMutex.h 5884 2004-10-30 09:17:02Z WuJunjie $
 *
 *  Explain:
 *     -explain-
 *
 *  Update:
 *     2004-10-30 09:17:02  Create
 */
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/** \file EZMutex.h
 **	\date  2004-10-30
**/
#ifndef _EZMutex_H
#define _EZMutex_H

#ifndef _WIN32
#include <pthread.h>
#else
//#include "socket_include.h"
#include <windows.h>
#endif
//#include "IEZMutex.h"

#ifdef EZLIBS_NAMESPACE
namespace ezlibs {
#endif

/// ����������
enum mutex_type
{
	/// ���ٻ�����������ٽ����Ѿ���һ���̻߳�ȡ�������̻߳��߸��߳��ٴλ�ȡʱ��
	/// �����߳�ֱ�ӱ�����
	MUTEX_FAST = 0,

	/// �ݹ黥�������Ѿ���ȡ�ٽ������߳̿��Զ�λ�ȡ�������������ڲ�Ӧ�л�ȡ����
	/// ���������Ҫ��ȫ�ͷ��ٽ�����һ��Ҫ��֤��ȡ�������ͷŴ���һ�¡�
	MUTEX_RECURSIVE,
};

/** CEZMutex container class, used by CEZLock. 
	\ingroup threading */
class CEZMutex// : public ICMutex
{
public:
	CEZMutex(int nType = MUTEX_FAST);
	virtual ~CEZMutex();

	virtual void Lock() const;
	virtual void Unlock() const;

private:
#ifdef _WIN32
	HANDLE m_mutex;
#else
	mutable pthread_mutex_t m_mutex;
#endif
};


#ifdef EZLIBS_NAMESPACE
}
#endif
#endif // _EZMutex_H

