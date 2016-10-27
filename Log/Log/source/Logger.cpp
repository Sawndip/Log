#include "Log/include/Logger.h"

#include <log4cxx/logger.h>

#include <string>

using namespace log4cxx;

namespace Log
{

MLogger::MLogger( const char* aCategory )
{
	LoggerPtr* loggerPtr = new LoggerPtr;
	*loggerPtr = Logger::getLogger( aCategory );
	mLoggerPtr = loggerPtr;
}


MLogger::~MLogger()
{
	LoggerPtr* loggerPtr = ( LoggerPtr* )mLoggerPtr;
	delete loggerPtr;
}

void MLogger::logInfo( const std::string& aMsg, const char* aFile, const char* aFunction, int aLine )
{
	log< LogLevel::Info >( aMsg, aFile, aFunction, aLine );
}

void MLogger::logWarning( const std::string& aMsg, const char* aFile, const char* aFunction, int aLine )
{
	log< LogLevel::Warning >( aMsg, aFile, aFunction, aLine );
}

void MLogger::logError( const std::string& aMsg, const char* aFile, const char* aFunction, int aLine )
{
	log< LogLevel::Error >( aMsg, aFile, aFunction, aLine );
}

template< MLogger::LogLevel aLevel >
void MLogger::log( const std::string& aMsg, const char* aFile, const char* aFunction, int aLine )
{
	try
	{
		LoggerPtr&  logger = *( LoggerPtr* )mLoggerPtr;

		if( ( aLevel == Info && logger->isInfoEnabled() ) ||
			( aLevel == Warning && logger->isWarnEnabled() ) ||
			( aLevel == Error && logger->isErrorEnabled() ) )
		{
			//std::string currentUser, currentSession;
			//mcp::currentUser( &currentUser );
			//mcp::currentSession( &currentSession );
			//
			//MDC::put( L"user", currentUser.toStdWString() );
			//MDC::put( L"session", currentSession.toStdWString() );

			if( aLevel == Info )
				logger->forcedLog( Level::getInfo(), aMsg, spi::LocationInfo( aFile, aFunction, aLine ) );

			if( aLevel == Warning )
				logger->forcedLog( Level::getWarn(), aMsg, spi::LocationInfo( aFile, aFunction, aLine ) );

			if( aLevel == Error )
				logger->forcedLog( Level::getError(), aMsg, spi::LocationInfo( aFile, aFunction, aLine ) );

			//MDC::clear();
		}
	}
	catch( ... )
	{}

}

}