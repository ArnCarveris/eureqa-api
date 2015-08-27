# [connection](doc_connection.md)::last\_result #

**Returns the last result response received from the server**

```
command_result last_result() const
```

## Comments ##
Returns a [eureqa::command\_result](doc_command_result.md) object which contains a result value and text description of the result.

The returned [eureqa::command\_result](doc_command_result.md) is convertible to a boolean, which allows it to be tested in a conditional as if it were a bool success value.

Results are sent back from the server after non-query server commands (commands where the server doesn't send back other data or information), for example the [connection::send\_data](doc_connection_send_data.md) method or the [connection::send\_options](doc_connection_send_options.md) method.

### Example ###
```
#include <eureqa/eureqa.h>
#include <iostream>
void main()
{
    // connect
    eureqa::connection conn("localhost");
    
    // send options
    eureqa::search_options options("z = f(x,y)");
    
    // check result
    if (!conn.send_options(options))
    {
        std::cout << "failed to send options to the server" << std::endl;
    }
    else if (!conn.last_result())
    {
        std::cout << "the server responded with an error message:" << std::endl;
        std::cout << conn.last_result() << std::endl;
    }
    else
    {
        std::cout << "the server responded with a success message:" << std::endl;
        std::cout << conn.last_result() << std::endl;
    }
}
```

### Requirements ###
  * **Header:** <eureqa/connection.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [command\_result class](doc_command_result.md)
  * [connection class](doc_connection.md)
  * [eureqa namespace](doc_intro.md)
