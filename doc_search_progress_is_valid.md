# [search\_progress](doc_search_progress.md)::is\_valid #

**Tests if the search progress members are filled and have values within valid ranges**

```
bool is_valid() const;
```

## Comments ##
The search progress is valid if all members have values within valid ranges. For example, the number of generations must be non-negative.

### Example ###
```
#include <eureqa/eureqa.h>
#include <cassert>
void main()
{
    eureqa::search_progress progress;
    progress.evaluations_ = -10;
    assert(!progress.is_valid());
}
```

### Requirements ###
  * **Header:** <eureqa/search\_progress.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::query\_progress method](doc_connection_query_progress.md)
  * [search\_progress class](doc_search_progress.md)
  * [eureqa namespace](doc_intro.md)