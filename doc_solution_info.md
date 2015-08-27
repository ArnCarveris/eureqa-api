# [eureqa](doc_intro.md)::solution\_info #

**Holds information about an individual solution**

```
class solution_info;
```

## Comments ##

The solution\_info objects are used in various classes to store solutions (such as [solution\_frontier](doc_solution_frontier.md) and [search\_progress](doc_search_progress.md) classes), and in several functions for sending and receiving solutions (such as [connection::send\_individuals](doc_connection_send_individuals.md) and [connection::query\_individuals](doc_connection_query_individuals.md) functions) to and from a Eureqa server.

See individual member functions for examples on using the solution\_info class.

## Members ##

**public member functions:**
| [(constructor)](doc_solution_info_constructor.md) | constructs a solution\_info object |
|:--------------------------------------------------|:-----------------------------------|
| [dominates](doc_solution_info_dominates.md)       | tests if a solution dominates another in both fitness and complexity |
| [matches](doc_solution_info_matches.md)           | tests if a solution matches another in terms of fitness and complexity |

**protected member functions:**
| [serialize](doc_solution_info_serialize.md) | boost serialization, used for sending solution\_info over the network; can also be used for saving/loading to files |
|:--------------------------------------------|:--------------------------------------------------------------------------------------------------------------------|

**public data members:**
| `std::string` | `text_` | text representation of the solution |
|:--------------|:--------|:------------------------------------|
| `float`       | `score_` | a score value used to rank solutions |
| `float`       | `fitness_` | fitness value of the solution       |
| `float`       | `complexity_` | complexity of the solution          |
| `unsigned int` | `age_`  | genotypic age of the solution       |

## Requirements ##
  * **Header:** <eureqa/solution\_info.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::send\_individuals](doc_connection_send_individuals.md)
  * [connection::query\_individuals](doc_connection_query_individuals.md)
  * [search\_progress class](doc_search_progress.md)
  * [solution\_frontier class](doc_solution_frontier.md)
  * [eureqa namespace](doc_intro.md)