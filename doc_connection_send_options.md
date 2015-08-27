# [connection](doc_connection.md)::send\_options #

**sends the server the search options**

```
bool send_options(const eureqa::search_options& options);
```

**options**<br>
the search options<br>
<br>
<h2>Comments</h2>
Returns true if the options were transferred successfully to the server. Use <a href='doc_connection_last_result.md'>connection::last_result</a> to view the response from the Eureqa server.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;iostream&gt;<br>
void main()<br>
{<br>
    // connect<br>
    eureqa::connection conn("localhost");<br>
    <br>
    // send options<br>
    eureqa::search_options options("z = f(x,y)");<br>
    <br>
    // check result<br>
    if (!conn.send_options(options))<br>
    {<br>
        std::cout &lt;&lt; "failed to send options to the server" &lt;&lt; std::endl;<br>
    }<br>
    else if (!conn.last_result())<br>
    {<br>
        std::cout &lt;&lt; "the server responded with an error message:" &lt;&lt; std::endl;<br>
        std::cout &lt;&lt; conn.last_result() &lt;&lt; std::endl;<br>
    }<br>
    else<br>
    {<br>
        std::cout &lt;&lt; "the server responded with a success message:" &lt;&lt; std::endl;<br>
        std::cout &lt;&lt; conn.last_result() &lt;&lt; std::endl;<br>
    }<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/connection.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_connection_last_result.md'>connection::last_result method</a>
</li><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_search_options.md'>search_options class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>