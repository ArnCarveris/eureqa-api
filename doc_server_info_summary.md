# [server\_info](doc_server_info.md)::summary #

**Returns a short descriptive string about the server info**

```
std::string summary() const;
```

## Comments ##
The returned string includes a note if [server\_info::is\_valid](doc_server_info_is_valid.md) method returns false, along with other basic information about the server such as the number of CPU cores.

### Example ###
```
#include <eureqa/eureqa.h>
#include <iostream>
void main()
{
    // connect to a server
    eureqa::connection conn("127.0.0.1");

    // get the progress
    eureqa::server_info server;
    conn.query_server_info(server);

    // print the server info summary
    std::cout << server.summary() << std::endl;
}
```
**Prints:** `127.0.0.1, Eureqa 0.78 (linux), 4 CPU cores`

### Requirements ###
  * **Header:** <eureqa/server\_info.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_server\_info method](doc_connection_query_server_info.md)
  * [server\_info class](doc_server_info.md)
  * [eureqa namespace](doc_intro.md)