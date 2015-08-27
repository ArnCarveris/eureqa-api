# [solution\_frontier](doc_solution_frontier.md)::operator`[]` #

**Accesses a solution on the frontier**

```
solution_info& operator [](int i);

const solution_info& operator [](int i) const;
```

**i**<br>
Zero-based index of a solution on the frontier<br>
<br>
<h2>Comments</h2>
Returns a reference to a <a href='doc_solution_info.md'>solution_info</a> object on the frontier. Use the <a href='doc_solution_frontier_size.md'>solution_frontier::size</a> method to determine the size of the frontier.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;iostream&gt;<br>
void main()<br>
{<br>
    // start a search<br>
    eureqa::connection conn("127.0.0.1");<br>
    conn.send_data_set(eureqa::data_set("my_data.txt"));<br>
    conn.send_options(eureqa::search_options("z = f(x,y)"));<br>
    conn.start_search();<br>
<br>
    // get the solution frontier<br>
    eureqa::solution_frontier solutions;<br>
    conn.query_frontier(solutions);<br>
<br>
    std::cout &lt;&lt; solutions.size() &lt;&lt; " solutions on the frontier:" &lt;&lt; std::endl;<br>
<br>
    // loop over the frontier<br>
    for (int i=0; i&lt;solutions.size(); ++i)<br>
    {<br>
        std::cout &lt;&lt; "solution #" &lt;&lt; i &lt;&lt; ": " &lt;&lt; solutions[i] &lt;&lt; std::endl;<br>
    }<br>
}<br>
</code></pre>
<b>example output:</b>
<pre><code>4 solutions on the frontier:<br>
solution #0: f(x,y) = 1.45*sin(x)<br>
solution #1: f(x,y) = 1.44*sin(x) + 1.03*y<br>
solution #2: f(x,y) = 1.75*sin(x - y) + 4.41*cos(y)<br>
solution #3: f(x,y) = cos(x)/(3.45 + y*y) + 1.33*sin(x)<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/solution_frontier.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h1>See Also</h1>
<ul><li><a href='doc_solution_frontier_size.md'>solution_frontier::size member</a>
</li><li><a href='doc_solution_frontier.md'>solution_frontier class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>