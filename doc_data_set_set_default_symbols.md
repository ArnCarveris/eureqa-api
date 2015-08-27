# [data\_set](doc_data_set.md)::set\_default\_symbols #

**Resizes the variable name vector and sets default names**

```
bool set_default_symbols() const;
```

## Comments ##
The default names are the symbol "x" followed by the column number, e.g. "x0", "x1", "x3, etc.

### Example ###
```
#include <eureqa/eureqa.h>
void main()
{
    eureqa::data_set data("lame_symbols.txt");
    data.set_default_symbols(); // ignore the lame symbols
}
```

### Requirements ###
  * **Header:** <eureqa/data\_set.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [data\_set class](doc_data_set.md)
  * [eureqa namespace](doc_intro.md)