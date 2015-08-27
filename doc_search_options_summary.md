# [search\_options](doc_search_options.md)::summary #

**Returns a short descriptive string about the search options**

```
std::string summary() const;
```

## Comments ##
The returned string includes a note if [search\_options::is\_valid](doc_search_options_is_valid.md) returns false, along with other basic information about the options such as the search relationship.

### Example ###
```
#include <eureqa/eureqa.h>
#include <iostream>
void main()
{
    eureqa::search_options options("z = f(x,y)");
    std::cout << data.summary() << std::endl;
}
```
**Prints:** `"z = f(x,y)", 8 building-block types, Mean Squared Error fitness`

### Requirements ###
  * **Header:** <eureqa/search\_options.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [search\_options class](doc_search_options.md)
  * [eureqa namespace](doc_intro.md)