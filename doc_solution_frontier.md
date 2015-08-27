# [eureqa](doc_intro.md)::solution\_frontier #

**Filters out the best solutions and maintains a frontier of non-dominated solutions**

```
class solution_frontier;
```

## Comments ##

The solution\_frontier class maintains a list of solutions that have the highest fitness for their complexity. Specifically, the class maintains a two-dimensional [Pareto Frontier](http://en.wikipedia.org/wiki/Pareto_frontier#Pareto_frontier) of non-dominated solutions. Calling the [add](doc_solution_frontier_add.md) member function automatically updates the frontier as new solutions are returned by the server.

A solution frontier can be filled by successively adding solutions returned from a Eureqa server in a [search\_progress](doc_search_progress.md) object after calling [connection::query\_progress](doc_connection_query_progress.md), or by calling the [connection::query\_frontier](doc_connection_query_frontier.md) function to retrieve a copy of the server's local solution frontier.

See the individual member functions for examples on using the connection class.

## Members ##

**public member functions:**
| [(constructor)](doc_solution_frontier_constructor.md) | constructs a solution\_frontier object |
|:------------------------------------------------------|:---------------------------------------|
| [add](doc_solution_frontier_add.md)                   | adds solution to the pareto front if non-dominated, and removes any existing solutions dominated by the solution |
| [test](doc_solution_frontier_test.md)                 | tests if a solution is non-dominated and not already on the current frontier |
| [to\_string](doc_solution_frontier_to_string.md)      | returns a text display of the frontier |
| [size](doc_solution_frontier_size.md)                 | returns the number of solutions on the frontier |
| [operator](doc_solution_frontier_operator_bb.md)`[]`  | accesses a solution on the frontier    |
| [clear](doc_solution_frontier_clear.md)               | clears and resets the frontier         |
| [remove](doc_solution_frontier_remove.md)             | removes a solution from the frontier   |

**protected member functions:**
| [serialize](doc_solution_frontier_serialize.md) | boost serialization, used for sending solution\_frontier over the network; can also be used for saving/loading to files |
|:------------------------------------------------|:------------------------------------------------------------------------------------------------------------------------|

**protected data members:**
| `std::vector<`[solution\_info](doc_solution_info.md)`>` | `front_` | set of the highest fit solutions for different complexities, ordered from most complex to least |
|:--------------------------------------------------------|:---------|:------------------------------------------------------------------------------------------------|

## Requirements ##
  * **Header:** `<eureqa/solution_frontier.h>`
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_frontier method](doc_connection_query_frontier.md)
  * [connection::query\_progress method](doc_connection_query_progress.md)
  * [solution\_info class](doc_solution_info.md)
  * [eureqa namespace](doc_intro.md)