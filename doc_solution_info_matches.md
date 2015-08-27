# [solution\_info](doc_solution_info.md)::matches #

**Tests if the solution has equal fitness and complexity**

```
bool matches(const solution_info& s) const;
```

**s**<br>
Another solution_info instance<br>
<br>
<h2>Comments</h2>
Returns true of the solution has <i>both</i> equal fitness and equal complexity to another solution.<br>
<br>
Used in conjunction with the <a href='doc_solution_info_dominates.md'>solution_info::dominates</a> method to test if a new solution belongs on the <a href='doc_solution_frontier.md'>solution frontier</a> and doesn't already exist.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;iostream&gt;<br>
void main()<br>
{<br>
    eureqa::solution_info a, b;<br>
<br>
    // ...<br>
<br>
    if (a.matches(b))<br>
    {<br>
        std::cout &lt;&lt; a &lt;&lt; " matches " &lt;&lt; b &lt;&lt; " in performance." &lt;&lt; std::endl;<br>
    }<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/solution_frontier.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_solution_info_dominates.md'>solution_info::dominates method</a>
</li><li><a href='doc_connection_query_individuals.md'>connection::query_individuals method</a>
</li><li><a href='doc_connection_query_progress.md'>connection::query_progress method</a>
</li><li><a href='doc_solution_frontier_add.md'>solution_frontier::add method</a>
</li><li><a href='doc_solution_frontier_test.md'>solution_frontier::test method</a>
</li><li><a href='doc_search_progress.md'>search_progress class</a>
</li><li><a href='doc_solution_frontier.md'>solution_frontier class</a>
</li><li><a href='doc_solution_info.md'>solution_info class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>