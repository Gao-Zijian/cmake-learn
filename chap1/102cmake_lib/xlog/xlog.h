// xlog.h

#ifndef XLOG_H__
#define XLOG_H__

#ifndef _WIN32
	#define XCPP_API
#else
	#ifdef xlog_EXPORTS
		#define XCPP_API __declspec(dllexport)
	#else 
		#define XCPP_API __declspec(dllimport)
	#endif
#endif

class XCPP_API XLog
{
public:
	XLog();
};
#endif
