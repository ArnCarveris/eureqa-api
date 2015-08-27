# [data\_set](doc_data_set.md)::resize #

**Changes the number of data points and variables in the data set**

```
void resize(int rows, int cols);
```

## Comments ##
The resize method resizes all member variables as needed. If the resize adds any additional columns, the method calls [data\_set::set\_default\_symbols](doc_data_set_set_default_symbols.md) to reset the column names.

### Example ###
```
#include <eureqa/eureqa.h>
void main()
{
    eureqa::data_set data;
    data.resize(100,2);
    data.resize(1000,4);
}
```

### Requirements ###
  * **Header:** <eureqa/data\_set.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [data\_set::(constructor)](doc_data_set_constructor.md)
  * [data\_set::size method](doc_data_set_size.md)
  * [data\_set::num\_vars method](doc_data_set_num_vars.md)
  * [data\_set::operator() method](doc_data_set_operator_pp.md)
  * [data\_set class](doc_data_set.md)
  * [eureqa namespace](doc_intro.md)