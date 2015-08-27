# Fitness Metric Identifiers #

```
namespace fitness_types
{
// supported fitness metrics
const static int absolute_error       =  0;
const static int squared_error        =  1;
const static int root_squared_error   =  2;
const static int logarithmic_error    =  3;
const static int explog_error         =  4;
const static int correlation          =  5;
const static int minimize_difference  =  6;
const static int akaike_information   =  7;
const static int bayesian_information =  8;
const static int maximum_error        =  9;
const static int median_error         = 10;
const static int implicit_error       = 11;
const static int slope_error          = 12;
const static int count                = 13;

// translates a fitness_type integer value to a descriptive string
std::string str(int type);
}
```

## Comments ##
The value `fitness_types::count` is only used for enumerating/counting the fitness metrics. It is not a fitness metric itself.

### Example ###
```
#include <eureqa/eureqa.h>
void main()
{
    eureqa::search_options options;
    options.fitness_metric_ = eureqa::fitness_types::absolute_error;
    std::cout << eureqa::fitness_types::str(options.fitness_metric_) << end;
}
```

## See Also ##
  * [search\_options class](doc_search_options.md)
  * [eureqa namespace](doc_intro.md)