# [server\_info](doc_server_info.md)::is\_valid #

**Tests if the server\_info members are filled and have values within valid ranges**

```
bool is_valid() const;
```

## Comments ##
The server info is valid if all members have values within valid ranges. For example, the server version number and the number of CPU cores must be positive values.

### Example ###
```
#include <eureqa/eureqa.h>
#include <cassert>
void main()
{
    eureqa::server_info server;
    progress.cpu_cores_ = -1;
    assert(!server.is_valid());
}
```

### Requirements ###
  * **Header:** <eureqa/server\_info.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_server\_info method](doc_connection_query_server_info.md)
  * [server\_info class](doc_server_info.md)
  * [eureqa namespace](doc_intro.md)