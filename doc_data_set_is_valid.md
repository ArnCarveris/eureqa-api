# [data\_set](doc_data_set.md)::is\_valid #

**Tests if the data set is sized and filled in correctly**

```
bool is_valid() const;
```

## Comments ##
A data set is valid if it has a text symbol for each column, and optional data members are either zero length or have values for each data point.

A data set with zero data points or zero variables is also invalid.

### Example ###
```
#include <eureqa/eureqa.h>
#include <cassert>
void main()
{
    eureqa::data_set data(100,2);
    data.X_symbols_.resize(1); 
    assert(!data.is_valid()); 
}
```

### Requirements ###
  * **Header:** <eureqa/data\_set.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [data\_set class](doc_data_set.md)
  * [eureqa namespace](doc_intro.md)