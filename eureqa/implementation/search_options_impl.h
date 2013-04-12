#ifndef EUREQA_SEARCH_INFO_IMPL_H
#define EUREQA_SEARCH_INFO_IMPL_H

#include <boost/serialization/vector.hpp>
#include "eureqa/search_options.h"

namespace eureqa
{


/*---------------------------------------------------------
	Implementation:
*--------------------------------------------------------*/
namespace fitness_types
{
EUREQA_INLINE 
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

EUREQA_INLINE
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

EUREQA_INLINE
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

EUREQA_INLINE
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

EUREQA_INLINE 
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
EUREQA_INLINE
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



#endif
