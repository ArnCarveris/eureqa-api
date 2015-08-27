# [data\_set](doc_data_set.md)::clear #

**Empties and resets all members of the data set**

```
void clear();
```

## Comments ##
The resulting data set has size of zero data points and zero variables.

### Example ###
```
#include <eureqa/eureqa.h>
#include <cassert>
void main()
{
    eureqa::data_set data(100,2);
    assert(!data.empty());
    data.clear();
    assert(data.empty());
}
```

### Requirements ###
  * **Header:** <eureqa/data\_set.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [data\_set::resize method](doc_data_set_resize.md)
  * [data\_set::empty method](doc_data_set_empty.md)
  * [data\_set class](doc_data_set.md)
  * [eureqa namespace](doc_intro.md)