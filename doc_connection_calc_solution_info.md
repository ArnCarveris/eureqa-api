# [connection](doc_connection.md)::calc\_solution\_info #

**Calculates the statistics and members of solution\_info objects on the server based on the text representation of the solution**

```
bool calc_solution_info(eureqa::solution_info& soln);

bool calc_solution_info(std::vector<eureqa::solution_info>& individuals);
```

**soln**<br>
A single solution to fill<br>
<br>
<b>individuals</b><br>
A buffer of individuals to fill<br>
<br>
<h2>Comments</h2>
Returns true if the request was transferred successfully to the server.<br>
<br>
Use this method to fill in the member values and statistics for a <a href='doc_solution_info.md'>eureqa::solution_info</a> object using only the text representation of the solution.<br>
<br>
The server receives the <a href='doc_solution_info.md'>eureqa::solution_info</a> object(s) and fills in the member variables for each based on the <code>text_</code> member.<br>
<br>
This method can be called at anytime after the search has been started successfully using the <a href='doc_connection_start_search.md'>connection::start_search</a> method.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;iostream&gt;<br>
void main()<br>
{<br>
    // connect to a server and start a search<br>
    eureqa::data_set data("my_data.txt");<br>
    eureqa::search_options("y = f(x)");<br>
    eureqa::connection conn("127.0.0.1");<br>
    conn.send_data_set(data);<br>
    conn.send_options(options);<br>
    conn.send_start();<br>
    <br>
    // create a solution object<br>
    eureqa::solution_info soln("1.3*x + sin(2.2*y)");<br>
    <br>
    // send to the server to fill-in<br>
    conn.calc_solution_info(soln);<br>
<br>
    // print the calculated values<br>
    std::cout &lt;&lt; soln.text_ &lt;&lt; std::endl;<br>
    std::cout &lt;&lt; soln.score_ &lt;&lt; std::endl;<br>
    std::cout &lt;&lt; soln.fitness_ &lt;&lt; std::endl;<br>
    std::cout &lt;&lt; soln.complexity_ &lt;&lt; std::endl;<br>
    std::cout &lt;&lt; soln.age_ &lt;&lt; std::endl;<br>
}<br>
</code></pre>
<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/connection.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_solution_info.md'>solution_info class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>