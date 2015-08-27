# [search\_options](doc_search_options.md)::set\_default\_building\_blocks #

**Returns a short descriptive string about the search options**

```
void set_default_building_blocks();
```

## Comments ##
Sets the default building-blocks. Default building-blocks are also set by the [constructor](doc_search_options_constructor.md) and the [search\_options::set\_default\_options](doc_search_options_set_default_options.md) method.

See [Eureqa Building-blocks](doc_building_blocks.md) for a list of valid building-block types and more information on specifying building-blocks.

### Example ###
```
#include <eureqa/eureqa.h>
void main()
{
    // constructor initializes default options
    eureqa::search_options options;
    
    // set custom building-block list
    options.building_blocks_.clear();
    options.building_blocks_.push_back("1.23");	// constants
    options.building_blocks_.push_back("a"); // variables
    options.building_blocks_.push_back("a+b"); // adds
    options.building_blocks_.push_back("a-b"); // subtracts
    options.building_blocks_.push_back("a*b"); // multiplies
    options.building_blocks_.push_back("a/b"); // divides
    options.building_blocks_.push_back("sin(a)"); // sines
    options.building_blocks_.push_back("cos(a)"); // cosines

    // reset to the default building-blocks
    options.set_default_building_blocks();
}
```

### Requirements ###
  * **Header:** <eureqa/search\_options.h>
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [Eureqa Building-blocks](doc_building_blocks.md)
  * [search\_options::(constructor)](doc_search_options_constructor.md)
  * [search\_options::set\_default\_options method](doc_search_options_set_default_options.md)
  * [search\_options class](doc_search_options.md)
  * [eureqa namespace](doc_intro.md)