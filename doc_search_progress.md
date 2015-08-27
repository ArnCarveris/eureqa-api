# [eureqa](doc_intro.md)::search\_progress #

**Hold information from a Eureqa server on the progress of the current search.**

```
class search_progress;
```

## Comments ##

Use the [connection::query\_progress](doc_connection_query_progress.md) function to retrieve search progress from a connected Eureqa server.

See the individual member functions for examples on using the search\_progress class.

## Members ##

**public member functions:**
| [(constructor)](doc_search_progress_constructor.md) | constructs a search\_progress object |
|:----------------------------------------------------|:-------------------------------------|
| [is\_valid](doc_search_progress_is_valid.md)        | tests if fields are entered and in range|
| [summary](doc_search_progress_summary.md)           | returns a short text summary of the search progress|

**protected member functions:**
| [serialize](doc_search_progress_serialize.md) | boost serialization, used for sending search\_progress over the network; can also be used for saving/loading to files |
|:----------------------------------------------|:----------------------------------------------------------------------------------------------------------------------|

**public data members:**
| [solution\_info](doc_solution_info.md) | `solution_` |  a solution recently added server's [solution frontier](doc_solution_frontier.md) |
|:---------------------------------------|:------------|:----------------------------------------------------------------------------------|
| `float`                                | `generations_` |  total generations completed                                                      |
| `float`                                | `generations_per_sec_` |  generations speed                                                                |
| `float`                                | `evaluations_` |  total times any equation was evaluated                                           |
| `float`                                | `evaluations_per_sec_` |  evaluation speed                                                                 |
| `int`                                  | `total_population_size_` |  total number of individuals in the current population                            |

## Requirements ##
  * **Header:** `<eureqa/search_progress.h>`
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_progress](doc_connection_query_progress.md)
  * [eureqa namespace](doc_intro.md)