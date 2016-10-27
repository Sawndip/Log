#include <Log/include/Log.h>

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

namespace Log
{

void configure( const std::string& aXmlFileName )
{
	log4cxx::xml::DOMConfigurator::configure( aXmlFileName );
}

}