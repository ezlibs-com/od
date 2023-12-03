/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * api_ezthread.h - _explain_
 *
 * Copyright (C) 2011 ezlibs.com, All Rights Reserved.
 *
 * $Id: api_ezthread.h 5884 2014-08-26 04:50:52Z WuJunjie $
 *
 *  Explain:
 *     -explain-
 *
 *  Update:
 *     2014-08-26 04:50:52  Create
 */
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/


#ifndef __api_ezthread_H__
#define __api_ezthread_H__


#ifdef __cplusplus
extern "C"
{
#endif

	/// \defgroup SystemAPI API System
	/// ϵͳʱ�����ã��ػ���������ϵͳ��Դ״����������API��
	/// @{

	/// �õ�ϵͳ�ĺ�����������ε���֮��ļ��ʱ����ǵõ��ļ����Ĳ�ֵ��
	///
	/// \param ��
	/// \return ��ǰ������
	/// \note һ������£�49.7���õ������������ʹ�õ��ĵط�Ҫ���������
	unsigned int SystemGetMSCount(void);
	unsigned long long process_counter_ms();
	unsigned long long process_counter_sec();

	/// ����ǰ�̣߳�ʱ�䵽���ٻ��ѡ�
	///
	/// \param [in] dwMilliSeconds �����ʱ�䡣
	void SystemSleep(unsigned int dwMilliSeconds);

	/// @} end of group

#ifdef __cplusplus
}
#endif

#endif //__api_ezthread_H__

