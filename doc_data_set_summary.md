# [data\_set](doc_data_set.md)::summary #

**Returns a short descriptive string about the data set**

```
std::string summary() const;
```

## Comments ##
The returned string includes a note if [data\_set::is\_valid](doc_data_set_is_valid.md) returns false, along with other basic information about the data set such as its size and number of variables.

### Example ###
```
#include <eureqa/eureqa.h>
#include <iostream>
void main()
{
    eureqa::data_set data(100,2);
    std::cout << data.summary() << std::endl;
}
```
**prints:** `100 data points, 2 variables`

### Requirements ###
  * **Header:** <eureqa/data\_set.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [data\_set class](doc_data_set.md)
  * [eureqa namespace](doc_intro.md)