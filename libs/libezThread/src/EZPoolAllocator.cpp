/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * EZPoolAllocator.cpp - _explain_
 *
 * Copyright (C) 2011 ezlibs.com, All Rights Reserved.
 *
 * $Id: pool_allocator.cpp 5884 2012-05-16 09:10:18Z WuJunjie $
 *
 *  Explain:
	1, �ο�"The C++ Programming Laguage (Special Edition)", by Bjarne Stroustrup 

	2, ֻ֧��list����, ��Ϊlist����ÿ��ֻ������ͷ�һ��һ�ֹ��Ľڵ�. ����deque, ��Ԫ�ع��С��
	4Kʱ, ��Ĭ�ϵ�������Ծ��൱���ڴ��, ���ڵ���4Kʱ, �������������͵Ĺ��, һ����Ԫ��ָ��, һ��
	����ĸ������ò��÷�������, ��һ����Ԫ��, ��ʱ�ſ��Կ����ڴ��.  ��vectorʹ�óع���ʵ��ûʲô��
	��, ���ڴ�������Ҳ�Ѿ������˶�̬���������, �����ͼʵ���ڴ��, ���������ش���.

	3, ����'Chunk'ʵ��, Chunk��СĬ��ֵ��1024��Ԫ�صĴ�С, ����ͨ���ӿ�setchunksize������, 
	����ڳ�ʼ����ʱ��ֻ����һ��.

	4, �ݲ�֧���ڴ��ͷ�, ����������ڴ�ֻ������, �������.

	5, �̰߳�ȫ, ������߳̿��Թ���һ��ͬ���͵��ڴ��.

	6, ��Allocator���Ե�����ʹ��, ���ܴﵽ�ڴ�ع����Ŀ��, �������ڹ̶���С���ݰ��ڴ�Ĺ���.
 *
 *  Update:
 *     2011-10-13 22:00:11   Create
 */


#include "EZPoolAllocator.h"
#ifdef EZLIBS_NAMESPACE
namespace ezlibs {
#endif

CEZPool::CEZPool(unsigned int sz)
:esize(sz < sizeof(Link) ? sizeof(Link) : sz),
ecount(ecount_default)
{
	head = 0;
	chunks = 0;
}

//free all chunks
CEZPool::~CEZPool()
{
	Chunk* n = chunks;
	while(n)
	{
		Chunk *p = n;
		n = n->next;
		delete p; //the data memory of 'chunk' will also be freed
	}
}

//allocate new 'chunk' and its space, organize it as a linked list of element of size 'esize'
void CEZPool::grow()
{
	//ez_trace("CEZPool::grow %d bytes\n", esize * ecount + sizeof(Chunk));

	void *buff = new char[esize * ecount + sizeof(Chunk)];
	Chunk *n = new (buff) Chunk;
	n->mem = reinterpret_cast<char*>(n + 1);
	n->next = chunks;
	chunks = n;

	char *start = n->mem;
	char *last = &start[(ecount - 1) * esize];
	for (char *p = start; p < last; p += esize)
	{
		reinterpret_cast<Link*>(p)->next = reinterpret_cast<Link*>(p + esize);
	}
	reinterpret_cast<Link*>(last)->next = 0;
	head = reinterpret_cast<Link*>(start);
}

//if you want to change the defaut element count in a 'chunk',
//you the best call the function when initializing and only once
void CEZPool::setec(unsigned int n)
{
	mutex.Lock();
	ecount = n;
	mutex.Unlock();
}

unsigned int CEZPool::getec()
{
	return ecount;
}
#ifdef EZLIBS_NAMESPACE
}// namespace ezlibs
#endif
