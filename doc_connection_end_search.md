# [connection](doc_connection.md)::end\_search #

**Tells the server to stop searching**

```
bool end_search();
```

## Comments ##
Returns true if the command was transferred successfully to the server. Use [connection::last\_result](doc_connection_last_result.md) to view the response from the Eureqa server.

This command is only valid if a search has been started using the [connection::start\_search](doc_connection_start_search.md) method.

The server also automatically ends the search if the connection is disconnected.

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
    conn.start_search();

    // pause the search
    if (!conn.end_search())
    {
        std::cout << "unable to send the stop command to the server" << std::endl;
    }
    else if (!conn.last_result())
    {
        std::cout << "stop command sent successfully, but ";
        std::cout << "the server responded with an error message:" << std::endl;
        std::cout << conn.last_result() << std::endl;
    }
    else
    {
        std::cout << "stop command sent successfully, and";
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
  * [connection::start\_search method](doc_connection_start_search.md)
  * [connection::pause\_search method](doc_connection_pause_search.md)
  * [connection::disconnect method](doc_connection_disconnect.md)
  * [connection class](doc_connection.md)
  * [eureqa namespace](doc_intro.md)