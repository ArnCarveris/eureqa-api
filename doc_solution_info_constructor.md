# [solution\_info](doc_solution_info.md)::(constructor) #

**Constructs a solution\_info instance**

```
solution_info(std::string text = "")
```

**text**<br>
The text representation of the solution<br>
<br>
<h2>Comments</h2>
The constructor initializes all members to default values.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
<br>
void main()<br>
{<br>
    // default constructor<br>
    eureqa::solution_info soln;<br>
    <br>
    // copy constructor<br>
    eureqa::solution_info soln_2(soln);<br>
    eureqa::solution_info soln_3 = soln;<br>
<br>
    // initializing constructor<br>
    eureqa::solution_info soln_4("2*x*sin(x) + 1.3");<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/solution_frontier.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_connection_query_individuals.md'>connection::query_individuals method</a>
</li><li><a href='doc_connection_query_progress.md'>connection::query_progress method</a>
</li><li><a href='doc_search_progress.md'>search_progress class</a>
</li><li><a href='doc_solution_frontier.md'>solution_frontier class</a>
</li><li><a href='doc_solution_info.md'>solution_info class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>