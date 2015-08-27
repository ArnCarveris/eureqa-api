# [data\_set](doc_data_set.md)::swap #

**Exchanges the contents of two data sets**

```
void swap(eureqa::data_set& other);

template<>
void std::swap(eureqa::data_set& a, eureqa::data_set& b);
```

## Comments ##
The two data sets may be different sizes.

The standard algorithm [std::swap](http://www.cplusplus.com/reference/algorithm/swap/) is also specialized for this class.

### Example ###
```
#include <eureqa/eureqa.h>
#include <algorithm>
void main()
{
    eureqa::data_set data_1("my_data.txt");
    eureqa::data_set data_2("my_other_data.txt");
    data_1.swap(data_2);
    std::swap(data_1, data_2);
}
```

### Requirements ###
  * **Header:** <eureqa/data\_set.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [std::swap function](http://www.cplusplus.com/reference/algorithm/swap/)
  * [data\_set class](doc_data_set.md)
  * [eureqa namespace](doc_intro.md)