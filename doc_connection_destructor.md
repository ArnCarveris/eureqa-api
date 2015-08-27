# [connection](doc_connection.md)::(destructor) #

**Destructs a connection instance**

```
virtual ~connection();
```

## Comments ##
The destructor automatically calls the [connection::disconnect](doc_connection_disconnect.md) method. The destructor declaration is virtual so that it may be derived from.

### Example ###
```
#include <eureqa/eureqa.h>
void main()
{
    // connect to a server
    {
        eureqa::connection conn("my-eureqa-server.net");
        // ...
    }
    // connection is disconnected at deconstruction
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