# [connection](doc_connection.md)::is\_connected #

**Tests if the connection is currently connected**

```
bool is_connected() const;
```

## Comments ##
Returns true if the connection is currently open.

### Example ###
```
#include <eureqa/eureqa.h>
#include <iostream>
void main()
{
    // attempt to connect to a server
    eureqa::connection conn("my-eureqa-server.net");
    
    // test if connected
    if (!conn.is_connected())
    {
        std::cout << "not connected" << std::endl;
    }
}
```

### Requirements ###
  * **Header:** <eureqa/connection.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::(constructor)](doc_connection_constructor.md)
  * [connection::connect method](doc_connection_connect.md)
  * [connection::disconnect method](doc_connection_disconnect.md)
  * [connection class](doc_connection.md)
  * [eureqa namespace](doc_intro.md)