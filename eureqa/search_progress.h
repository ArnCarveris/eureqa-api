#ifndef EUREQA_SEARCH_PROGRESS_H
#define EUREQA_SEARCH_PROGRESS_H

#include <string>
#include <eureqa/solution_frontier.h>

namespace eureqa
{
struct search_progress
{
public:
	solution_info solution_; // a solution recently added server's solution frontier
	float generations_; // total generations completed
	float generations_per_sec_; // generations speed
	float evaluations_; // total times any equation was evaluated
	float evaluations_per_sec_; // evaluation speed
	int total_population_size_; // total number of individuals in the current population
	
public:
	// default constructor 
	search_progress();
	
	// tests if fields are entered and in range
	bool is_valid() const;
	
	// returns a short text summary of the search progress
	std::string summary() const;
	
protected:
	// boost serialization, used for sending over it the network
	// can also be used for saving/loading the data set
	friend class boost::serialization::access;
	template<class TArchive> void serialize(TArchive& ar, const unsigned int version);
};

} // namespace eureqa

#endif // EUREQA_SEARCH_PROGRESS_H
