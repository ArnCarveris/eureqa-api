# [connection](doc_connection.md)::query\_progress #

**Queries the server for information about the search progress**

```
bool query_progress(eureqa::search_progress& progress);
```

**progress**<br>
The progress object to fill in<br>
<br>
<h2>Comments</h2>
Returns true if the request was transferred successfully to the server.<br>
<br>
The Eureqa server maintains a history of the solutions that it has added to its local <a href='doc_solution_frontier.md'>frontier of best solutions</a>. Querying the progress also pops a solution from this list which goes into the <a href='doc_search_progress.md'>eureqa::search_progress</a> object. Clients should reconstruct their own <a href='doc_solution_frontier.md'>solution_frontier</a> object by adding each solution received in the search progress queries to it.<br>
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
    // track the progress and the best solutions<br>
    eureqa::search_progress progress;<br>
    eureqa::solution_frontier best_solutions;<br>
<br>
    // monitor the progress of the search<br>
    while (!conn.query_progress(progress))<br>
    {<br>
        // print the search progress<br>
        std::cout &lt;&lt; progress.summary() &lt;&lt; std::endl;<br>
<br>
        // filter out the best solutions sent from the server<br>
        if (best_solutions.add(progress.solution_))<br>
        {<br>
            std::cout &lt;&lt; "new best solution found!" &lt;&lt; std::endl;<br>
            std::cout &lt;&lt; best_solutions.to_string() &lt;&lt; std::endl;<br>
        }<br>
    }<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/connection.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_search_progress.md'>search_progress class</a>
</li><li><a href='doc_solution_frontier.md'>solution_frontier class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>