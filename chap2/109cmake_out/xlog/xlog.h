// xlog.h

#ifndef XLOG_H__
#define XLOG_H__

#ifndef _WIN32
	#define XCPP_API
#else
	#ifdef xlog_STATIC // 静态库
		#define XCPP_API
	#else //动态库
		#ifdef xlog_EXPORTS
			#define XCPP_API __declspec(dllexport)
		#else 
			#define XCPP_API __declspec(dllimport)
		#endif
	#endif
#endif

class XCPP_API XLog
{
public:
	XLog();
};
#endif
