# [search\_options](doc_search_options.md)::is\_valid #

**Tests if the search options are filled and have values within valid ranges**

```
bool is_valid() const;
```

## Comments ##
The search options are valid if all members have values within valid ranges. For example, probablities such as `solution_mutation_probability_` must be a real number within 0 to 1.

### Example ###
```
#include <eureqa/eureqa.h>
#include <cassert>
void main()
{
    // default constructor
    eureqa::search_options options("z = f(x,y)");
    assert(options.is_valid());
    options.solution_population_size = -44; // invalid: negative population size
    assert(!options.is_valid());
}
```

### Requirements ###
  * **Header:** <eureqa/search\_options.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [search\_options::set\_default\_options method](doc_search_options_set_default_options.md)
  * [search\_options::set\_default\_building\_blocks method](doc_search_options_set_default_building_blocks.md)
  * [eureqa::search\_options class](doc_search_options.md)
  * [eureqa namespace](doc_intro.md)