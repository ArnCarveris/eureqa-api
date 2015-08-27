# [connection](doc_connection.md)::disconnect #

**Closes the connection with the server**

```
void disconnect();
```

## Comments ##
The disconnect method is also called by the destructor.

### Example ###
```
#include <eureqa/eureqa.h>
void main()
{
    // connect
    eureqa::connection conn("localhost");
    
    // do some eureqa searches on the server
    // ...
    
    // disconnect
    conn.disconnect();
}
```

### Requirements ###
  * **Header:** <eureqa/connection.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::is\_connected method](doc_connection_is_connected.md)
  * [connection::connect method](doc_connection_connect.md)
  * [connection::(constructor)](doc_connection_constructor.md)
  * [connection::(destructor)](doc_connection_destructor.md)
  * [connection class](doc_connection.md)
  * [eureqa namespace](doc_intro.md)
