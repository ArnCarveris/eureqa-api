# [solution\_frontier](doc_solution_frontier.md)::clear #

**Clears and resets the frontier**

```
void clear();
```

## Comments ##
Completely resets the frontier object to its initial empty state.

### Example ###
```
#include <eureqa/eureqa.h>
#include <iostream>
void main()
{
    // start a search
    eureqa::connection conn("127.0.0.1");
    conn.send_data_set(eureqa::data_set("my_data.txt"));
    conn.send_options(eureqa::search_options("z = f(x,y)"));
    conn.start_search();

    // get the solution frontier
    eureqa::solution_frontier solutions;
    conn.query_frontier(solutions);

    std::cout << "size: " << solutions.size() << std::endl;

    // remove the solution at index 2
    solutions.remove(2);

    std::cout << "size: " << solutions.size() << std::endl;

    // remove all solutions
    solutions.clear();

    std::cout << "size: " << solutions.size() << std::endl;
}
```
**example output:**
```
size: 5
size: 4
size: 0
```

### Requirements ###
  * **Header:** <eureqa/solution\_frontier.h>
  * **Namespace:** [eureqa](doc_intro.md)

# See Also #
  * [solution\_frontier::size member](doc_solution_frontier_size.md)
  * [solution\_frontier::remove member](doc_solution_frontier_remove.md)
  * [solution\_frontier class](doc_solution_frontier.md)
  * [eureqa namespace](doc_intro.md)