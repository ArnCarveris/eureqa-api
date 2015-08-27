# [connection](doc_connection.md)::send\_individuals #

**Sends the server individuals to insert into its population**

```
bool send_individuals(std::string text);
bool send_individuals(eureqa::solution_info soln);
bool send_individuals(const std::vector<eureqa::solution_info>& individuals);
```

**text**<br>
text representation of a solution to send<br>
<br>
<b>soln</b><br>
a single solution to send<br>
<br>
<b>individuals</b><br>
a vector of individuals to send<br>
<br>
<h2>Comments</h2>
Returns true if the individual(s) were transferred successfully to the server. Use <a href='doc_connection_last_result.md'>connection::last_result</a> to view the response from the Eureqa server.<br>
<br>
Individuals can only be sent to the server after a search has been started by a call to the <a href='doc_connection_start_search.md'>connection::start_search</a> method.<br>
<br>
Use the <a href='doc_connection_query_individuals.md'>connection::query_individuals</a> method to retrieve solutions from the server instead.<br>
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
    // make a vector of solutions to send<br>
    std::vector&lt;eureqa::solution_info&gt; individuals;<br>
    individuals.push_back(eureqa::solution_info("sin(x) + 2*cos(x)"));<br>
    individuals.push_back(eureqa::solution_info("1/(1+x*x) - 2.34"));<br>
<br>
    // send the solutions to the server<br>
    if (!conn.send_individuals(individuals))<br>
    {<br>
        std::cout &lt;&lt; "unable to transfer the individuals to the server" &lt;&lt; std::endl;<br>
    }<br>
    else if (!conn.last_result())<br>
    {<br>
        std::cout &lt;&lt; "individuals transfer successfully, but ";<br>
        std::cout &lt;&lt; "the server responded with an error message:" &lt;&lt; std::endl;<br>
        std::cout &lt;&lt; conn.last_result() &lt;&lt; std::endl;<br>
    }<br>
    else<br>
    {<br>
        std::cout &lt;&lt; "individuals transfer successfully, and";<br>
        std::cout &lt;&lt; "the server responded with an success message:" &lt;&lt; std::endl;<br>
        std::cout &lt;&lt; conn.last_result() &lt;&lt; std::endl;<br>
    }<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/connection.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_connection_query_individuals.md'>connection::query_individuals method</a>
</li><li><a href='doc_connection_last_result.md'>connection::last_result method</a>
</li><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_solution_info.md'>solution_info class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>