#ifndef EUREQA_SEARCH_INFO_H
#define EUREQA_SEARCH_INFO_H

#include <string>
#include <vector>
#include <boost/serialization/vector.hpp>

namespace eureqa
{
// identifiers for the fitness metrics
namespace fitness_types
{
const static int absolute_error       =  0;
const static int squared_error        =  1;
const static int r_squared_error      =  2;
const static int correlation          =  3;
const static int maximum_error        =  4;
const static int logarithmic_error    =  5;
const static int median_error         =  6;
const static int iqr_absolute_error   =  7;
const static int minimize_difference  =  8;
const static int hybrid_correlation   =  9;
const static int implicit_error       = 10;
const static int streak_error         = 11;
const static int excursion_error      = 12;
const static int excursion_fine_error = 13;
const static int aic_squared_error    = 14;
const static int aic_absolute_error   = 15;
const static int count                = 16;

// depreciated/unsupported fitness metrics
const static int root_squared_error   = squared_error;
const static int explog_error         = logarithmic_error;
const static int akaike_information   = aic_absolute_error;
const static int bayesian_information = aic_absolute_error;
const static int slope_error          = absolute_error;
const static int stats_error          = absolute_error;

std::string str(int type);
}

// structure for sending search options to the server
class search_options
{
public:
	std::string search_relationship_;
	std::vector<std::string> building_blocks_;
	float normalize_fitness_by_;
	int fitness_metric_;
	int solution_population_size_;
	int predictor_population_size_;
	int trainer_population_size_;
	float solution_crossover_probability_;
	float solution_mutation_probability_;
	float predictor_crossover_probability_;
	float predictor_mutation_probability_;
	std::string implicit_derivative_dependencies_;

	int max_delays_per_variable_;
	float max_history_fraction_;
	int min_implicit_variables_used_;

	
public:
	// default constructor sets default options
	search_options(std::string search_relationship = "0=f(0)");
	
	// test if the options are entered and in range
	bool is_valid() const;
	
	// sets default search options
	void set_default_options() { (*this) = search_options(); }
	void set_default_building_blocks();
	
	// returns a short text summary of the search options
	std::string summary() const;
	
protected:
	// boost serialization, used for sending over it the network
	// can also be used for saving/loading the data set
	template<class TArchive> void serialize(TArchive& ar, const unsigned int version);
	friend class boost::serialization::access;
};

/*---------------------------------------------------------
	Implementation:
*--------------------------------------------------------*/
namespace fitness_types
{
inline 
std::string str(int type)
{
	switch(type)
	{
	case absolute_error:       return "Absolute Error";
	case squared_error:        return "Squared Error";
	case r_squared_error:      return "R^2 Goodness of Fit";
	case correlation:          return "Correlation Coefficient";
	case maximum_error:        return "Maximum Error";
	case logarithmic_error:    return "Logarithmic Error";
	case median_error:         return "Median Error";
	case iqr_absolute_error:   return "Inter-quartile Absolute Error";
	case minimize_difference:  return "Minimize the Difference";
	case hybrid_correlation:   return "Hybrid Correlation Absolute Error";
	case implicit_error:       return "Implicit Derivative Error";
	case streak_error:         return "Streak Error";
	case excursion_error:      return "Excursion Error";
	case excursion_fine_error: return "Fine Excursion Error";
	case aic_squared_error:    return "Squared Error AIC";
	case aic_absolute_error:   return "Absolute Error AIC";
	default:                   return "Unknown?";
	}
}
}

inline
search_options::search_options(std::string search_relationship) :
	search_relationship_(search_relationship),
	normalize_fitness_by_(1),
	fitness_metric_(fitness_types::absolute_error),
	solution_population_size_(64),
	predictor_population_size_(8),
	trainer_population_size_(8),
	solution_crossover_probability_(0.7f),
	solution_mutation_probability_(0.03f),
	predictor_crossover_probability_(0.5f),
	predictor_mutation_probability_(0.06f),
	implicit_derivative_dependencies_(""),
	max_delays_per_variable_(0),
	max_history_fraction_(0.5f),
	min_implicit_variables_used_(2)
{
	set_default_building_blocks();
}

inline
bool search_options::is_valid() const
{
	return (search_relationship_.length() > 0)
		&& (fitness_metric_ >= 0 && fitness_metric_ < fitness_types::count)
		&& (building_blocks_.size() > 0)
		&& (solution_population_size_ >= 5) 
		&& (predictor_population_size_ >= 5)
		&& (trainer_population_size_ >= 1)
		&& (solution_crossover_probability_ >= 0 && solution_crossover_probability_ <= 1)
		&& (solution_mutation_probability_ >= 0 && solution_mutation_probability_ <= 1)
		&& (predictor_crossover_probability_ >= 0 && predictor_crossover_probability_ <= 1)
		&& (predictor_mutation_probability_ >= 0 && predictor_mutation_probability_ <= 1)
		&& (fitness_metric_ != fitness_types::implicit_error || implicit_derivative_dependencies_.length() > 0)
		&& (max_delays_per_variable_ >= 0)
		&& (max_history_fraction_ >= 0 && max_history_fraction_ <= 1)
		&& (min_implicit_variables_used_ >= 0)
		;
}

inline
void search_options::set_default_building_blocks()
{
	building_blocks_.clear();
	building_blocks_.push_back("1.23");    // constants
	building_blocks_.push_back("a"); // variables
	building_blocks_.push_back("a+b"); // adds
	building_blocks_.push_back("a-b"); // subtracts
	building_blocks_.push_back("a*b"); // multiplies
	building_blocks_.push_back("a/b"); // divides
	building_blocks_.push_back("sin(a)"); // sines
	building_blocks_.push_back("cos(a)"); // cosines
}

inline 
std::string search_options::summary() const
{
	std::ostringstream os;
	if (!is_valid()) { os << "Invalid! "; }
	os << "\"" << search_relationship_ << "\"";
	os << ", " << building_blocks_.size() << " building-block types";
	os << ", " << fitness_types::str(fitness_metric_) << " fitness";
	return os.str();
}

template<typename TArchive>
inline
void search_options::serialize(TArchive& ar, const unsigned int version) 
{
	if (TArchive::is_loading::value)
	{
		// set default options in case the version does not set all members
		set_default_options();
	}

	ar & BOOST_SERIALIZATION_NVP( search_relationship_ );
	ar & BOOST_SERIALIZATION_NVP( building_blocks_ );
	ar & BOOST_SERIALIZATION_NVP( normalize_fitness_by_ );
	ar & BOOST_SERIALIZATION_NVP( fitness_metric_ );
	ar & BOOST_SERIALIZATION_NVP( solution_population_size_ );
	ar & BOOST_SERIALIZATION_NVP( predictor_population_size_ );
	ar & BOOST_SERIALIZATION_NVP( trainer_population_size_ );
	ar & BOOST_SERIALIZATION_NVP( solution_crossover_probability_ );
	ar & BOOST_SERIALIZATION_NVP( solution_mutation_probability_ );
	ar & BOOST_SERIALIZATION_NVP( predictor_crossover_probability_ );
	ar & BOOST_SERIALIZATION_NVP( predictor_mutation_probability_ );
	ar & BOOST_SERIALIZATION_NVP( implicit_derivative_dependencies_ );

	// support serving to older Eureqa clients
	if (version >= 1)
	{
		ar & BOOST_SERIALIZATION_NVP( max_delays_per_variable_ );
		ar & BOOST_SERIALIZATION_NVP( max_history_fraction_ );
		ar & BOOST_SERIALIZATION_NVP( min_implicit_variables_used_ );
	}
}


} // namespace eureqa

// serialization version
BOOST_CLASS_VERSION(eureqa::search_options, 1)

#endif // EUREQA_SEARCH_INFO_H
