# [solution\_frontier](doc_solution_frontier.md)::test #

**Tests if a solution is non-dominated and not already on the current frontier**

```
bool test(solution_info soln) const;
```

**soln**<br>
The solution to test<br>
<br>
<h2>Comments</h2>
Returns true if the new solution would be added to the solution_frontier <a href='http://en.wikipedia.org/wiki/Pareto_frontier#Pareto_frontier'>Pareto front</a>; false if the solution was dominated by an existing solution.<br>
<br>
A solution is dominated based on the <a href='doc_solution_info_dominates.md'>solution_info::dominates</a> member function. The test function also returns false if a solution <a href='doc_solution_info_matches.md'>matches</a> an existing solution.<br>
<br>
Use the <a href='doc_solution_frontier_add.md'>solution_frontier::add</a> method to add a solution to the frontier and remove any solutions it dominates.<br>
<br>
<h3>Example</h3>
See example for the <a href='doc_solution_frontier_add.md'>solution_frontier::add</a> method.<br>
<br>
<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/solution_frontier.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h1>See Also</h1>
<ul><li><a href='doc_solution_frontier_add.md'>solution_frontier::add method</a>
</li><li><a href='doc_solution_frontier.md'>solution_frontier class</a>
</li><li><a href='doc_solution_info.md'>solution_info class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>