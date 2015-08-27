# [eureqa](doc_intro.md)::server\_info #

**Holds information about a Eureqa server**

```
class server_info;
```

## Comments ##

Use the [connection::query\_server\_info](doc_connection_query_server_info.md) function to retrieve information about a connected Eureqa server.

See the individual member functions for examples on using the server\_info class.

## Members ##

**public member functions:**
| [(constructor)](doc_server_info_constructor.md) | constructs a server\_info object |
|:------------------------------------------------|:---------------------------------|
| [is\_valid](doc_server_info_is_valid.md)        | test if info is entered and in range |
| [summary](doc_server_info_summary.md)           | returns a short text summary of the server info |

**protected member functions:**
| [serialize](doc_server_info_serialize.md) | boost serialization, used for sending server\_info over the network; can also be used for saving/loading to files |
|:------------------------------------------|:------------------------------------------------------------------------------------------------------------------|

**public data members:**
| `std::string` | `hostname_` | host computer name of the server |
|:--------------|:------------|:---------------------------------|
| `std::string` | `operating_system_` | operating system of the server   |
| `double`      | `eureqa_version_` | version of the server            |
| `int`         | `cpu_cores_` | number of CPU cores on server    |

## Requirements ##
  * **Header:** `<eureqa/server_info.h>`
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_server\_info](doc_connection_query_server_info.md)
  * [eureqa namespace](doc_intro.md)