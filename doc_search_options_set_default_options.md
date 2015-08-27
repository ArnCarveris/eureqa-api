# [search\_options](doc_search_options.md)::set\_default\_options #

**Returns a short descriptive string about the search options**

```
void set_default_options();
```

## Comments ##
Sets the default search options, except for the search relationship which must be set manually. Default options are also set by the [constructor](doc_search_options_constructor.md).

### Example ###
```
#include <eureqa/eureqa.h>
#include <cassert>
void main()
{
    // constructor initializes default options
    eureqa::search_options options;
    
    // set custom options
    options.search_relationship_ = "z = f(x,y)"
    options.normalize_fitness_by_ = 10.0;
    options.fitness_metric_ = eureqa::fitness_types::correlation;
    options.solution_population_size_ = 100;
    options.predictor_population_size_ = 10;
    options.trainer_population_size_ = 10;
    options.solution_crossover_probability_ = 0.5;
    options.solution_mutation_probability_ = 0.01;
    options.predictor_crossover_probability_ = 0.5;
    options.predictor_mutation_probability_ = 0.2;
    options.implicit_derivative_dependencies_ = "";
    
    // set custom building-block list
    options.building_blocks_.clear();
    options.building_blocks_.push_back("1.23");	// constants
    options.building_blocks_.push_back("a"); // variables
    options.building_blocks_.push_back("a+b"); // adds
    options.building_blocks_.push_back("a-b"); // subtracts
    options.building_blocks_.push_back("a*b"); // multiplies
    options.building_blocks_.push_back("a/b"); // divides
    options.building_blocks_.push_back("sin(a)"); // sines
    options.building_blocks_.push_back("cos(a)"); // cosines

    // check that values are within range
    assert(options.is_valid());

    // reset to the default options
    options.set_default_options();
}
```

### Requirements ###
  * **Header:** <eureqa/search\_options.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [Eureqa Building-blocks](doc_building_blocks.md)
  * [search\_options::(constructor)](doc_search_options_constructor.md)
  * [search\_options::set\_default\_building\_blocks method](doc_search_options_set_default_building_blocks.md)
  * [search\_options class](doc_search_options.md)
  * [eureqa namespace](doc_intro.md)