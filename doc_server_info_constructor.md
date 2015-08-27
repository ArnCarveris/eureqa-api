# [server\_info](doc_server_info.md)::(constructor) #

**Constructs a server\_info instance**

```
server_info();
```

## Comments ##
The constructor initializes all members to default values

### Example ###
```
#include <eureqa/eureqa.h>

void main()
{
    // default constructor
    eureqa::server_info server;
    
    // copy constructor
    eureqa::server_info info_2(info);
    eureqa::server_info info_3 = info;
}
```

### Requirements ###
  * **Header:** <eureqa/server\_info.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_server\_info method](doc_connection_query_server_info.md)
  * [server\_info class](doc_server_info.md)
  * [eureqa namespace](doc_intro.md)