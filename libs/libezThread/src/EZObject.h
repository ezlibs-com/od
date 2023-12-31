/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * Object.h - _explain_
 *
 * Copyright (C) 2011 ezlibs.com, All Rights Reserved.
 *
 * $Id: Object.h 5884 2012-05-16 09:14:37Z WuJunjie $
 *
 *  Explain:
 *     -explain-
 *
 *  Update:
 *     2012-05-16 09:09:51   Create
 */
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

#ifndef __EZOBJECT_H__
#define __EZOBJECT_H__
#ifdef EZLIBS_NAMESPACE
namespace ezlibs {
#endif

class CEZObject {
public:
	CEZObject(){};
	virtual ~CEZObject(){};
};

/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
///////////////// 单件模式 -- 非线程安全模式，一般在程序初始化的时候调用一下也不会出现问题
#define PATTERN_SINGLETON_NOTSAFE_DECLARE(classname)	\
static classname * instance();

#define PATTERN_SINGLETON_NOTSAFE_IMPLEMENT(classname)	\
classname * classname::instance()		\
{												\
	static classname * _instance = NULL;		\
	if( NULL == _instance)						\
	{											\
		_instance = new classname;				\
	}											\
	return _instance;							\
}												

// 饿汉模式：即无论是否调用该类的实例，在程序开始时就会产生一个该类的实例
// 性能较高，故而默认使用此模式
#define PATTERN_SINGLETON_DECLARE(classname)	\
static classname * instance();                  \
static classname* _instance;

#define PATTERN_SINGLETON_IMPLEMENT(classname)	\
classname * classname::instance()		        \
{                                               \
	return _instance;							\
}												\
classname* classname::_instance = new classname;
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/


/////////////////////////////////////////////////////
///////////////// 内存池模式，内联实现
#define USE_POOL_ALLOCATOR(classname)				\
static void * operator new(size_t size)				\
{													\
	static	pool_allocator<classname> a;			\
	if (size != sizeof(classname))					\
		return ::operator new(size);				\
	return a.allocate(1);							\
}													\
static void operator delete(void *p, size_t size)	\
{													\
	static	pool_allocator<classname> a;			\
	if (p == 0) return;								\
	if (size != sizeof(classname)) {				\
		::operator delete(p);						\
		return;                        				\
	}												\
	a.deallocate((classname *) p, size);			\
}													\
static void setAllocatorChunk(size_t n)				\
{													\
	static	pool_allocator<classname> a;			\
	a.setchunksize(n);								\
}													\
/////////////////////////////////////////////////////

// Join two variables
#define MACRO_JOIN( X, Y ) MACRO_DO_JOIN( X, Y )
#define MACRO_DO_JOIN( X, Y ) MACRO_DO_JOIN2(X,Y)
#define MACRO_DO_JOIN2( X, Y ) X##Y

// Useful objects & functions
template<class T>
struct strless{
	inline bool operator()(const T& x, const T& y) const
	{
		return (strcmp(x ,y) < 0);
	}
};
#ifdef EZLIBS_NAMESPACE
}// namespace ezlibs
#endif

#endif// __EZOBJECT_H__
