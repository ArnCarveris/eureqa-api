# [solution\_frontier](doc_solution_frontier.md)::(constructor) #

**Constructs a solution\_frontier instance**

```
solution_frontier();
```

## Comments ##
The constructor initializes an empty solution frontier.

### Example ###
```
#include <eureqa/eureqa.h>

void main()
{
    // default constructor
    eureqa::solution_frontier best;
    
    // copy constructor
    eureqa::solution_frontier best_2(best);
    eureqa::solution_frontier best_3 = best;
}
```

### Requirements ###
  * **Header:** <eureqa/solution\_frontier.h>
  * **Namespace:** [eureqa](doc_intro.md)

# See Also #
  * [search\_progress class](doc_search_progress.md)
  * [solution\_frontier class](doc_solution_frontier.md)
  * [solution\_info class](doc_solution_info.md)
  * [eureqa namespace](doc_intro.md)