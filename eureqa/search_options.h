#ifndef EUREQA_SEARCH_INFO_H
#define EUREQA_SEARCH_INFO_H

#include <string>
#include <vector>

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

}
#endif // EUREQA_SEARCH_INFO_H
