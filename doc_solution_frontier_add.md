# [solution\_frontier](doc_solution_frontier.md)::add #

**Adds a new solution to the frontier**

```
bool add(const solution_info& soln);
```

**soln**<br>
The new solution to test and add to the frontier<br>
<br>
<h2>Comments</h2>
Returns true if the new solution was added the the solution frontier <a href='http://en.wikipedia.org/wiki/Pareto_frontier#Pareto_frontier'>Pareto front</a>; false if the solution was dominated by an existing solution.<br>
<br>
A solution is dominated based on the <a href='doc_solution_info_dominates.md'>solution_info::dominates</a> member function. The add function also returns false if the solution <a href='doc_solution_info_matches.md'>matches</a> an existing solution.<br>
<br>
Use the <a href='doc_solution_frontier_test.md'>solution_frontier::test</a> method to test if a solution would be added to the frontier, without actually adding it.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;iostream&gt;<br>
#include &lt;cassert&gt;<br>
void main()<br>
{<br>
    // connect to a server<br>
    eureqa::connection conn("127.0.0.1");<br>
    conn.send_data_set(eureqa::data_set("my_data.txt"));<br>
    conn.send_options(eureqa::search_options("z = f(x,y)"));<br>
    <br>
    // fill-in some solutions<br>
    eureqa::solution_info soln_1("1.3*x + y/(1+x)");<br>
    eureqa::solution_info soln_2("1.3*x + y/(1+x) + 4.2*cos(x-y)");<br>
    eureqa::solution_info soln_3("1.3*x + 2.4*x + 4.2*cos(y)");<br>
    conn.calc_solution_info(soln_1);<br>
    conn.calc_solution_info(soln_2);<br>
    conn.calc_solution_info(soln_2);<br>
<br>
     // filter the solutions on a frontier<br>
    eureqa::solution_frontier solutions;<br>
    <br>
   // add solutions to the frontier<br>
    solutions.add(soln_1);<br>
    solutions.add(soln_2);<br>
    solutions.add(soln_3);<br>
<br>
    // display the frontier<br>
    std::cout &lt;&lt; solutions.to_string();<br>
}<br>
</code></pre>
<b>prints:</b>
<pre><code>Size:   Fitness:        Equation:<br>
-----   --------        ---------<br>
9       1.656280        f(x,y) = 1.3*x + y/(1+x)<br>
12      1.423152        f(x,y) = 1.3*x + 2.4*x + 4.2*cos(y)<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/solution_frontier.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h1>See Also</h1>
<ul><li><a href='doc_solution_frontier_test.md'>solution_frontier::test method</a>
</li><li><a href='doc_solution_frontier.md'>solution_frontier class</a>
</li><li><a href='doc_solution_info.md'>solution_info class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>