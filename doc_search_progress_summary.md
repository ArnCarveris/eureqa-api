# [search\_progress](doc_search_progress.md)::summary #

**Returns a short descriptive string about the search progress**

```
std::string summary() const;
```

## Comments ##
The returned string includes a note if [search\_progress::is\_valid](doc_search_progress_is_valid.md) returns false, along with other basic information about the progress such as the number of generations.

### Example ###
```
#include <eureqa/eureqa.h>
#include <iostream>
void main()
{
    // start a saerch
    eureqa::data_set data("my_data.txt");
    eureqa::search_options options("z = f(x,y)");
    eureqa::connection conn("127.0.0.1");
    conn.send_data(data);
    conn.send_options(options);
    conn.start_search();

    // get the progress
    eureqa::search_progress progress;
    conn.query_progress(progress);

    // print the progress summary
    std::cout << progress.summary() << std::endl;
}
```
**Prints:** `133 generations, 1.55e+006 evaluations`

### Requirements ###
  * **Header:** <eureqa/search\_progress.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_progress method](doc_connection_query_progress.md)
  * [search\_progress class](doc_search_progress.md)
  * [eureqa namespace](doc_intro.md)