#pragma once

#include <Log/include/Export.h>
#include <Log/include/Logger.h>

#include <mutex>

#include <mutex>

#define LOG_INIT( aLoggerName ) \
			static auto logger = []() { \
				static std::mutex mMutex; \
				std::lock_guard< std::mutex > mLock( mMutex ); \
				static Log::MLogger* mLogger = new Log::MLogger( aLoggerName ); \
				return mLogger; \
			}

#define LOG_LEVEL( aLevel, aMsg ) { \
		logger()->log##aLevel( aMsg, __FILE__, __FUNCSIG__, __LINE__ ); \
	}


#define LOG_INFO(msg)				LOG_LEVEL( Info, msg )
#define LOG_WARN(msg)				LOG_LEVEL( Warning, msg )
#define LOG_ERROR(msg)				LOG_LEVEL( Error, msg )

namespace Log
{
Log_API void    configure( const std::string& aXmlFileName );
};
