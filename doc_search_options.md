# [eureqa](doc_intro.md)::search\_options #

**Stores all options for performing a search on a Eureqa Server**

```
class search_options;
```

## Comments ##

Most search options are specified by modifying the public member variables directly.

The search options are sent to a Eureqa server by calling the [connection::send\_options](doc_connection_send_options.md) function.

See the individual member functions for examples on using the search\_options class.

## Members ##

**public member functions:**
| [(constructor)](doc_search_options_constructor.md) | constructs a search\_options object and initializes default options |
|:---------------------------------------------------|:--------------------------------------------------------------------|
| [is\_valid](doc_search_options_is_valid.md)        | test if the options are entered and in range                        |
| [set\_default\_options](doc_search_options_set_default_options.md) | sets default search options                                         |
| [set\_default\_building\_blocks](doc_search_options_set_default_building_blocks.md) | sets default search [building blocks](doc_building_blocks.md)       |
| [summary](doc_search_options_summary.md)           | returns a short text summary of the search options                  |

**protected member functions:**
| [serialize](doc_search_options_serialize.md) | boost serialization, used for sending search\_options over the network; can also be used for saving/loading to files |
|:---------------------------------------------|:---------------------------------------------------------------------------------------------------------------------|

**public data members:**
| `std::string` | `search_relationship_` | The relationship for the search to analyze; e.g. `"y = f(x)"` searches for an `"f(x)"` to model `"y"` |
|:--------------|:-----------------------|:------------------------------------------------------------------------------------------------------|
| `std::vector<std::string>` | `building_blocks_`     | an set of expressions representing individual [building-blocks](doc_building_blocks.md), e.g. { `"1.32"`, `"x"`, `"x+y"`, `"x-y"`, `"x*y"` } (does _not_ need to match variable name of the data set) |
| `float`       | `normalize_fitness_by_` | value used to normalize fitness values, _fitness_ = (_the fitness\_metric_)/(_this value_)            |
| `int`         | `fitness_metric_`      | specifies one of the [fitness error metrics](doc_fitness_types.md)                                    |
| `int`         | `solution_population_size_` | target size of a the solution population per core                                                     |
| `int`         | `predictor_population_size_` | target size of the predictor population per core                                                      |
| `int`         | `trainer_population_size_` | target size of the trainer population per core                                                        |
| `float`       | `solution_crossover_probability_` | probability `[0,1]` that solutions are crossed                                                        |
| `float`       | `solution_mutation_probability_` | probability `[0,1]` that solutions are mutated per gene                                               |
| `float`       | `predictor_crossover_probability_` | probability `[0,1]` that predictors are crossed                                                       |
| `float`       | `predictor_mutation_probability_` | probability `[0,1]` that predictors are mutated per gene                                              |
| `std::string` | `implicit_derivative_dependencies_` | string representing a dependency matrix needed for the implicit derivative fitness metric             |
| `int`         | `max_delays_per_variable_` | Deprecated feature, does not work in server version 0.99.9. Use the `max_history_fraction_` option instead |
| `float`       | `max_history_fraction_` | restricts the maximum amount of the data set (by the time variable) that can be used for history when evaluating time-delays. This is also effectively the maximum time-delay length allowed. |
| `int`         | ` min_implicit_variables_used_` | forces solutions to use this many variables when using the implicit derivative error metric           |


## Requirements ##
  * **Header:** `<eureqa/search_options.h>`
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [Eureqa Fitness Metrics](doc_fitness_types.md)
  * [Eureqa Building-blocks](doc_building_blocks.md)
  * [connection::send\_search\_options](doc_connection_send_options.md)
  * [eureqa namespace](doc_intro.md)