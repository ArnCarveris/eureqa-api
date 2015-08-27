# [connection](doc_connection.md)::query\_individuals #

**Queries a number of solutions from the servers population**

```
bool query_individuals(eureqa::solution_info& soln);

bool query_individuals(std::vector<eureqa::solution_info>& individuals, int count);
```

**soln**<br>
A single solution to fill<br>
<br>
<b>individuals</b><br>
A buffer of individuals to fill<br>
<br>
<b>count</b><br>
The number of solutions to sample<br>
<br>
<h2>Comments</h2>
Returns true if the request was transferred successfully to the server.<br>
<br>
The server sends back an array of <a href='doc_solution_info.md'>eureqa::solution_info</a> objects sampled from its population.<br>
<br>
The query_individuals method can be called at anytime after the search has been started using the <a href='doc_connection_start_search.md'>connection::start_search</a> method.<br>
<br>
Use the <a href='doc_connection_send_individuals.md'>connection::send_individuals</a> method to send solutions to the server instead.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;iostream&gt;<br>
void main()<br>
{<br>
    // load data set and init options<br>
    eureqa::data_set data("my_data.txt");<br>
    eureqa::search_options("y = f(x)");<br>
<br>
    // connect to a server and start a search<br>
    eureqa::connection conn("127.0.0.1");<br>
    conn.send_data_set(data);<br>
    conn.send_options(options);<br>
    conn.send_start();<br>
    <br>
    // vector to receive solutions in<br>
    std::vector&lt;eureqa::solution_info&gt; individuals;<br>
<br>
    // query 17 individuals<br>
    if (!query_individuals(individuals, 17))<br>
    {<br>
        std::cout &lt;&lt; "unable to receive individuals from the server" &lt;&lt; std::endl;<br>
    }<br>
}<br>
</code></pre>
<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/connection.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_connection_send_individuals.md'>connection::send_individuals method</a>
</li><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_solution_info.md'>solution_info class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>