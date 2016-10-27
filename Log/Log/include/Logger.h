#pragma once

#include <Log/include/Export.h>

#include <string>

namespace Log
{

class Log_API MLogger
{
public:
	MLogger( const char* aCategory );
	~MLogger();

	void  logInfo( const std::string& aMsg, const char* aFile, const char* aFunction, int aLine );
	void  logWarning( const std::string& aMsg, const char* aFile, const char* aFunction, int aLine );
	void  logError( const std::string& aMsg, const char* aFile, const char* aFunction, int aLine );

private:

	enum LogLevel
	{
		Trace,
		Debug,
		Info,
		Warning,
		Error,
		Fatal
	};

	void* mLoggerPtr;

	template< MLogger::LogLevel aLevel >
	void log( const std::string& aMsg, const char* aFile, const char* aFunction, int aLine );

};

}