# [search\_progress](doc_search_progress.md)::(constructor) #

**Constructs a search\_progress instance**

```
search_progress();
```

## Comments ##
The constructor initializes all options to default values

### Example ###
```
#include <eureqa/eureqa.h>

void main()
{
    // default constructor
    eureqa::search_progress progress;
    
    // copy constructor
    eureqa::search_progress progress_2(progress);
    eureqa::search_progress progress_3 = progress;
}
```

### Requirements ###
  * **Header:** <eureqa/search\_progress.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_progress method](doc_connection_query_progress.md)
  * [search\_progress class](doc_search_progress.md)
  * [eureqa namespace](doc_intro.md)