# [connection](doc_connection.md)::start\_search #

**Tells the server to begin searching**

```
bool start_search();
```

## Comments ##
Returns true if the command was transferred successfully to the server. Use [connection::last\_result](doc_connection_last_result.md) to view the response from the Eureqa server.

Before calling start\_search, the server must have received a [search\_options](doc_search_options.md) object and a [data\_set](doc_data_set.md) object via the [connection::send\_options](doc_connection_send_options.md) method and [connection::send\_data\_set](doc_connection_send_data_set.md) or [connection::send\_data\_location](doc_connection_send_data_location.md) methods.

### Example ###
```
#include <eureqa/eureqa.h>
#include <iostream>
void main()
{
    // load data set and init options
    eureqa::data_set data("my_data.txt");
    eureqa::search_options("y = f(x)");

    // connect to a server and send options and data
    eureqa::connection conn("127.0.0.1");
    conn.send_data_set(data);
    conn.send_options(options);

    // start the search
    if (!conn.start_search())
    {
        std::cout << "unable to send the start command to the server" << std::endl;
    }
    else if (!conn.last_result())
    {
        std::cout << "start command sent successfully, but ";
        std::cout << "the server responded with an error message:" << std::endl;
        std::cout << conn.last_result() << std::endl;
    }
    else
    {
        std::cout << "start command sent successfully, and";
        std::cout << "the server responded with an success message:" << std::endl;
        std::cout << conn.last_result() << std::endl;
    }
}
```

### Requirements ###
  * **Header:** <eureqa/connection.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::last\_result method](doc_connection_last_result.md)
  * [connection::pause\_search method](doc_connection_pause_search.md)
  * [connection::end\_search method](doc_connection_end_search.md)
  * [connection class](doc_connection.md)
  * [eureqa namespace](doc_intro.md)