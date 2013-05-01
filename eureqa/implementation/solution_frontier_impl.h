#ifndef EUREQA_SOLUTION_FRONTIER_IMPL_H
#define EUREQA_SOLUTION_FRONTIER_IMPL_H

#include <eureqa/solution_frontier.h>

namespace eureqa
{

/*---------------------------------------------------------
	Implementation:
*--------------------------------------------------------*/
struct by_descending_fitness
{
	bool operator ()(const solution_info& a, const solution_info& b) const
	{
		return (a.fitness_ > b.fitness_)
			|| (a.fitness_ == b.fitness_ && a.complexity_ < b.complexity_);
	}
};

struct by_descending_score
{
	bool operator ()(const solution_info& a, const solution_info& b) const
	{
		return (a.score_ > b.score_)
			|| (a.score_ == b.score_ && a.complexity_ < b.complexity_);
	}
};

EUREQA_INLINE
bool solution_info::dominates(const solution_info& s) const
{
	return (fitness_ <= s.fitness_ && complexity_ <  s.complexity_)
		|| (fitness_ <  s.fitness_ && complexity_ <= s.complexity_);
}

EUREQA_INLINE
bool solution_info::matches(const solution_info& s) const
{
	return (fitness_ == s.fitness_ && complexity_ == s.complexity_);
}

EUREQA_INLINE
bool solution_frontier::add(const solution_info& soln)
{
	// test if it belongs on the frontier
	if (!test(soln)) { return false; }

	// remove dominated
	for (int i=size()-1; i>=0; --i)
	{
		if (soln.dominates(front_[i])) { remove(i); }
	}

	// add and sort
	front_.push_back(soln);
	std::sort(front_.begin(), front_.end(), by_descending_score());
	return true;
}

EUREQA_INLINE
bool solution_frontier::test(solution_info soln) const
{
	for (int i=0; i<size(); ++i)
	{
		if (front_[i].dominates(soln) || front_[i].matches(soln)) { return false; }
	}
	return true;
}

EUREQA_INLINE
std::string solution_frontier::to_string() const
{
	std::ostringstream os;
	os << std::left << std::setw(6) << "Size:" << ' ' << std::left << std::setw(9) << "Fitness:" << ' ' << "Equation:\n";
	os << std::left << std::setw(6) << "-----" << ' ' << std::left << std::setw(9) << "--------" << ' ' << "---------\n";
	for (int i=0; i<size(); ++i)
	{
		os << std::left << std::setw(6) << front_[i].complexity_ << ' ';
		os << std::left << std::setw(9) << front_[i].fitness_ << ' ';
		os << front_[i].text_ << '\n';
	}
	return os.str();
}

template<class TArchive>
EUREQA_INLINE
void solution_info::serialize(TArchive& ar, const unsigned int /*version*/)
{
	ar & BOOST_SERIALIZATION_NVP( text_ );
	ar & BOOST_SERIALIZATION_NVP( score_ );
	ar & BOOST_SERIALIZATION_NVP( fitness_ );
	ar & BOOST_SERIALIZATION_NVP( complexity_ );
	ar & BOOST_SERIALIZATION_NVP( age_ );

	// use positive fitness convention (old versions are negative)
	if (TArchive::is_loading::value)
	{
		// TEMP: just force the absolute value for now
		if (fitness_ < 0) { fitness_ = -fitness_; }
	}
}

template<class TArchive>
EUREQA_INLINE
void solution_frontier::serialize(TArchive& ar, const unsigned int /*version*/)
{
	ar & BOOST_SERIALIZATION_NVP( front_ );
}

}

#endif /*EUREQA_SOLUTION_FRONTIER_IMPL_H*/
