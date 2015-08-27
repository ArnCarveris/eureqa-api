# [eureqa](doc_intro.md)::connection #

**Serves as the primary interface for connecting to and controlling a Eureqa Server**

```
class connection;
```

## Comments ##

The connection object opens a tcp connection to a running Eureqa server. The connection class provides member functions for controlling the connected server such as specifying the data set to use and starting the search. A program may have several instances of connection object to multiple servers.

See the individual member functions for examples on using the connection class.

## Members ##

**public member functions:**
| [(constructor)](doc_connection_constructor.md) | constructs a connection object |
|:-----------------------------------------------|:-------------------------------|
| [(destructor)](doc_connection_destructor.md)   | destructs a connection object  |
| [is\_connected](doc_connection_is_connected.md) | tests if the server is connected |
| [last\_result](doc_connection_last_result.md)  | returns the [last response](doc_command_result.md) from the server after a non-query command |
| [connect](doc_connection_connect.md)           | opens a network connection to a Eureqa server |
| [disconnect](doc_connection_disconnect.md)     | closes the connection          |
| [send\_data\_set](doc_connection_send_data_set.md) | transfers a [data\_set](doc_data_set.md) over the network to the server |
| [send\_data\_location](doc_connection_send_data_location.md) | tells the server to load a [data\_set](doc_data_set.md) locally from a file |
| [send\_options](doc_connection_send_options.md) | sends server the [search options](doc_search_options.md) |
| [send\_individuals](doc_connection_send_individuals.md) | sends server individuals to insert into its population |
| [query\_progress](doc_connection_query_progress.md) | queries server for information on the [search progress](doc_search_progress.md) |
| [query\_server\_info](doc_connection_query_server_info.md) | queries server for its [system information](doc_server_info.md) |
| [query\_individuals](doc_connection_query_individuals.md) | queries server for random individuals from its population |
| [query\_frontier](doc_connection_query_frontier.md) | queries the server's local [solution frontier](doc_solution_frontier.md) |
| [start\_search](doc_connection_start_search.md) | tells server to start searching |
| [pause\_search](doc_connection_pause_search.md) | tells server to pause searching |
| [end\_search](doc_connection_end_search.md)    | tells server to end searching  |
| [calc\_solution\_info](doc_connection_calc_solution_info.md) | calculates the statistics of a solution on the server |
| [summary](doc_connection_summary.md)           | returns are a short description of the connection |
| [remote\_address](doc_connection_remote_address.md) | returns the server's address string |
| [remote\_port](doc_connection_remote_port.md)  | returns the server's port number |

**protected member functions:**
| [connect\_socket](doc_connection_connect_socket.md) | resolves the hostname and connects the network socket |
|:----------------------------------------------------|:------------------------------------------------------|
| [write\_fixed](doc_connection_write_fixed.md)       | writes a fixed size object or primitive to the socket |
| [write\_command\_fixed](doc_connection_write_command_fixed.md) | writes a command type and a fixed size object or primitive to the socket |
| [write\_command](doc_connection_write_command.md)   | writes a command type to the socket                   |
| [write\_command\_packet](doc_connection_write_command_packet.md) | writes a command type and variable length object or string to the socket |
| [read\_fixed](doc_connection_read_fixed.md)         | reads a fixed size object or primitive from the socket |
| [read\_packet](doc_connection_read_packet.md)       | reads a variable length object or string from the socket|
| [read\_response](doc_connection_read_response.md)   | reads a result response from the server               |

**protected data members:**
| `boost::asio::ip::tcp::socket` | `socket_` | the network socket |
|:-------------------------------|:----------|:-------------------|
| `command_result`               | `last_result_` | stored response by the server from the last non-query command |

## Requirements ##
  * **Header:** <eureqa/connection.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [Boost Asio library](http://www.boost.org/doc/libs/release/libs/asio/)
  * [command\_result class](doc_command_result.md)
  * [eureqa namespace](doc_intro.md)