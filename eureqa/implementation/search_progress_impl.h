#ifndef EUREQA_SEARCH_PROGRESS_IMPL_H
#define EUREQA_SEARCH_PROGRESS_IMPL_H

#include <string>
#include <eureqa/search_progress.h>

namespace eureqa
{

/*---------------------------------------------------------
	Implementation:
*--------------------------------------------------------*/
EUREQA_INLINE
search_progress::search_progress() :
	generations_(0),
	generations_per_sec_(0),
	evaluations_(0),
	evaluations_per_sec_(0),
	total_population_size_(0)
{ }

EUREQA_INLINE
bool search_progress::is_valid() const
{
	return (generations_ >= 0)
		&& (generations_per_sec_ >= 0)
		&& (evaluations_ >= 0)
		&& (evaluations_per_sec_ >= 0)
		&& (total_population_size_ >= 0)
		;
}

EUREQA_INLINE 
std::string search_progress::summary() const
{
	std::ostringstream os;
	if (!is_valid()) { os << "Invalid! "; }
	os << generations_ << " generations";
	//os << " (" << generations_per_sec_ << " per sec)";
	os << ", " << evaluations_ << " evaluations";
	//os << " (" << evaluations_per_sec_ << " per sec)";
	return os.str();
}

template<typename TArchive>
EUREQA_INLINE
void search_progress::serialize(TArchive& ar, const unsigned int /*version*/) 
{
	ar & BOOST_SERIALIZATION_NVP( solution_ );
	ar & BOOST_SERIALIZATION_NVP( generations_ );
	ar & BOOST_SERIALIZATION_NVP( generations_per_sec_ );
	ar & BOOST_SERIALIZATION_NVP( evaluations_ );
	ar & BOOST_SERIALIZATION_NVP( evaluations_per_sec_ );
	ar & BOOST_SERIALIZATION_NVP( total_population_size_ );
}

} 

#endif
