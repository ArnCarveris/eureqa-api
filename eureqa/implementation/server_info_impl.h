#ifndef EUREQA_SERVER_INFO_IMPL_H
#define EUREQA_SERVER_INFO_IMPL_H

#include "eureqa/server_info.h"

namespace eureqa
{

/*---------------------------------------------------------
	Implementation:
*--------------------------------------------------------*/
EUREQA_INLINE
server_info::server_info() :
	hostname_(""),
	operating_system_(""),
	eureqa_version_(0),
	cpu_cores_(0)
{ }

EUREQA_INLINE
bool server_info::is_valid() const
{
	return (hostname_.length() > 0)
		&& (operating_system_.length() > 0)
		&& (eureqa_version_ > 0)
		&& (cpu_cores_ > 0)
		;
}


EUREQA_INLINE
std::string server_info::summary() const
{
	std::ostringstream os;
	if (!is_valid()) { os << "Invalid! "; }
	os << hostname_;
	os << ", Eureqa " << eureqa_version_;
	os << " (" << operating_system_ << ")";
	os << ", " << cpu_cores_ << " CPU core" << (cpu_cores_==1?"":"s");
	return os.str();
}

template<typename TArchive>
EUREQA_INLINE
void server_info::serialize(TArchive& ar, const unsigned int /*version*/) 
{
	ar & BOOST_SERIALIZATION_NVP( hostname_ );
	ar & BOOST_SERIALIZATION_NVP( operating_system_ );
	ar & BOOST_SERIALIZATION_NVP( eureqa_version_ );
	ar & BOOST_SERIALIZATION_NVP( cpu_cores_ );
}

}

#endif
