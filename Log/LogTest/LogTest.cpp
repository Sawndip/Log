// LogTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Log\include\Log.h>

LOG_INIT( "LOG.TEST" );

int _tmain(int argc, _TCHAR* argv[])
{
	wchar_t* error = nullptr;
	const wchar_t* softwareName = L"SPO2";

	bool retVal = Log::createLogFolder( softwareName, error );
	Log::configure( "d:\\drol\\Personal\\SwProjects\\Log\\configurationFile\\logConfig.xml" );

	LOG_INFO("LogInfo");
	LOG_ERROR("LogError");
	LOG_WARN("LogWarn");

	return 0;
}

