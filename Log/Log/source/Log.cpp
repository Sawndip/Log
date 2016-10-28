#include <Log/include/Log.h>

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

#include <shlobj.h>
#include <iostream>

namespace Log
{

void configure( const char* aXmlFileName )
{
	log4cxx::xml::DOMConfigurator::configure( aXmlFileName );
}

bool createLogFolder( const wchar_t* aSoftwareName, wchar_t* aError )
{
	std::wstring logFolder;
	std::wstring swName( aSoftwareName );

	if ( ! getLogFolder( swName, logFolder, aError ) )
	{
		return false;
	}

	if ( ! CreateDirectory( logFolder.c_str(), nullptr ) )
	{
		int err = GetLastError();
		aError = L"Failed to create the log folder";
		std::wcerr << aError << std::endl;
		return false;
	}

	return true;
}

bool getLogFolder( const std::wstring& aSoftwareName, std::wstring& aLogFolder, wchar_t* aError )
{
	WCHAR commonApplicationDataFolder[ MAX_PATH + 1 ] = { 0 };
	if ( ! SUCCEEDED( SHGetFolderPath( 0, CSIDL_COMMON_APPDATA, 0, SHGFP_TYPE_CURRENT, commonApplicationDataFolder ) ) )
	{
		aError = L"Cannot get 'COMMON_APPDATA' folder location.";
		std::wcerr << aError << std::endl;
		return false;
	}
	
	aLogFolder = std::wstring( commonApplicationDataFolder ) + L"/" + aSoftwareName + L"/Log/";
	return true;
}

}