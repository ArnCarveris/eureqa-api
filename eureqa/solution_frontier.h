#ifndef EUREQA_SOLUTION_FRONTIER_H
#define EUREQA_SOLUTION_FRONTIER_H

#include <boost/asio.hpp>
#include <cmath>

namespace boost
{
namespace serialization
{
class access;
}
}


namespace eureqa
{
// information about a solution
class solution_info
{
public:
	std::string text_; // text representation of the solution
	float score_; // score, related to fitness, for ranking solutions
	float fitness_; // fitness value of the solution
	float complexity_; // complexity of the solution
	unsigned int age_; // genotypic age of the solution

public:
	// constructor
	solution_info(std::string text = "") : text_(text), score_(-1e30f), fitness_(-1e30f), complexity_(0), age_(0) { }

	// tests if the solution dominates another solution in fitness and complexity
	bool dominates(const solution_info& s) const;
	bool matches(const solution_info& s) const;

protected:
	// boost serialization, used for sending over it the network
	// can also be used for saving/loading the data set
	friend class boost::serialization::access;
	template<class TArchive> void serialize(TArchive& ar, const unsigned int /*version*/);
};
inline
std::ostream& operator <<(std::ostream& os, const solution_info& r) { return os << r.text_; }


// predicate for sorting
struct by_descending_fitness;
struct by_descending_score;

// container for tracking the best solutions
class solution_frontier
{
protected:
	// set of the highest fit solutions for differnt complexities
	// ordered from most complex to least
	std::vector<solution_info> front_;

public:
	// adds solution to the pareto front if non-dominated
	// and removes any existing dominated by the solution
	bool add(const solution_info& soln);

	// tests if a solution is non-dominated and not already on the current frontier
	bool test(solution_info soln) const;

	// returns a text display of the frontier
	std::string to_string() const;

	// basic container functions
	int size() const { return (int)front_.size(); }
	solution_info& operator [](int i) { return front_[i]; }
	const solution_info& operator [](int i) const { return front_[i]; }
	void clear() { front_.clear(); }
	void remove(int i) { front_.erase(front_.begin()+i); }

protected:
	// boost serialization, used for sending over it the network
	// can also be used for saving/loading the data set
	friend class boost::serialization::access;
	template<class TArchive> void serialize(TArchive& ar, const unsigned int /*version*/);
};

} // namespace eureqa

#endif // EUREQA_SOLUTION_FRONTIER_H
