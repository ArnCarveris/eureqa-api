# [connection](doc_connection.md)::summary #

**Returns a short descriptive string about the connection**

```
std::string summary() const;
```

## Comments ##
Returns information on where the instance is connected to.

### Example ###
```
#include <eureqa/eureqa.h>
#include <iostream>
void main()
{
    // connect to a server
    eureqa::connection conn("127.0.0.1");

    // print the connection summary
    std::cout << conn.summary() << std::endl;
    
    // disconnect
    conn.disconnect();

    // print the connection summary
    std::cout << conn.summary() << std::endl;
}
```
**prints:**
```
Connected to 127.0.0.1
Disconnected
```

### Requirements ###
  * **Header:** <eureqa/server\_info.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_server\_info method](doc_connection_query_server_info.md)
  * [connection class](doc_connection.md)
  * [eureqa namespace](doc_intro.md)