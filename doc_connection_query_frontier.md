# [connection](doc_connection.md)::query\_frontier #

**Query the local solution frontier of a Eureqa server**

```
bool query_frontier(eureqa::solution_frontier& front);
```

**front**<br>
The solution frontier object to fill in<br>
<br>
<h2>Comments</h2>
Returns true if the request was transferred successfully to the server.<br>
<br>
The server sends back a <a href='doc_solution_frontier.md'>eureqa::solution_frontier</a> object containing the set of non-dominated solutions currently found on the Eureqa server.<br>
<br>
This method can be called at anytime after the search has been started successfully using the <a href='doc_connection_start_search.md'>connection::start_search</a> method.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
void main()<br>
{<br>
    // connect to a server and start a search<br>
    eureqa::data_set data("my_data.txt");<br>
    eureqa::search_options options("z = f(x,y)");<br>
    eureqa::connection conn("127.0.0.1");<br>
    conn.send_data(data);<br>
    conn.send_options(options);<br>
    conn.start_search();<br>
<br>
    // read the server's solution frontier<br>
    eureqa::solution_frontier solutions;<br>
    conn.query_frontier(solutions);<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/connection.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_solution_frontier.md'>solution_frontier class</a>
</li><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>