# Eureqa API Documentation #
## Namespaces ##
| [eureqa](doc_intro.md) | The `eureqa` namespace encapsulates all Eureqa API classes and methods |
|:-----------------------|:-----------------------------------------------------------------------|

## Classes ##

| [eureqa::connection](doc_connection.md) | Connects to and controls a Eureqa server |
|:----------------------------------------|:-----------------------------------------|
| [eureqa::data\_set](doc_data_set.md)    | Holds data values and symbol labels used in a Eureqa search |
| [eureqa::search\_options](doc_search_options.md) | Holds settings and search options used in a Eureqa search |
| [eureqa::search\_progress](doc_search_progress.md) | Holds progress information about a search on a Eureqa server |
| [eureqa::server\_info](doc_server_info.md) | Holds system information about a Eureqa server |
| [eureqa::solution\_info](doc_solution_info.md) | Holds information about a solution in a Eureqa search|
| [eureqa::solution\_frontier](doc_solution_frontier.md) | Tracks the highest fit solutions for different solution complexities |

## Example Projects ##
|[minimal\_client](doc_minimal_client.md) | The simplest possible complete program using the Eureqa API |
|:----------------------------------------|:------------------------------------------------------------|
| [basic\_client](doc_basic_client.md)    | The `minimal_client` with basic error checking and diagnostics |

## Style and Naming Conventions ##
The Eureqa API uses style and naming conventions that closely resemble those found in the Boost C++ Libraries and the C++ Standard Template Library. This choice was made so that the Eureqa API code looks nice next to Boost and STL code. In particular:

  * Class names use lower case, and use underscores
  * Method names use lower case, and use underscores
  * Member variable names contain a trailing underscore