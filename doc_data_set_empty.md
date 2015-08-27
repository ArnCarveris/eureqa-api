# [data\_set](doc_data_set.md)::empty #

**Tests if the data set is empty**

```
bool empty() const;
```

## Comments ##
Returns true if there are zero data points in the data set.

### Example ###
```
#include <eureqa/eureqa.h>
#include <cassert>
void main()
{
    eureqa::data_set data_1;
    assert(data_1.empty());
    
    eureqa::data_set data_2("my_data.txt");
    assert(!data_2.empty());

    data_2.clear();
    assert(data_2.empty());
}
```

### Requirements ###
  * **Header:** <eureqa/data\_set.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [data\_set::clear method](doc_data_set_clear.md)
  * [data\_set::size method](doc_data_set_size.md)
  * [data\_set class](doc_data_set.md)
  * [eureqa namespace](doc_intro.md)