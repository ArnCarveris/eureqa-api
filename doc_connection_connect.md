# [connection](doc_connection.md)::connect #

**Attempts to make a connection to a Eureqa Server**

```
bool connect(std::string hostname, int port = eureqa::default_port_tcp);
```

**hostname**<br>
The hostname or ip address string of the server<br>
<br>
<b>port</b><br>
The listening port of the server<br>
<br>
<h2>Comments</h2>
Returns true if the connection is made successfully.<br>
<br>
The server sends back a <a href='doc_command_result.md'>eureqa::command_result</a> object if the connection is made successfully. You can view the response with the <a href='doc_connection_last_result.md'>connection::last_result</a> method.<br>
<br>
A connection can also be made in the <a href='doc_connection_constructor.md'>connection::(constructor)</a>.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;iostream&gt;<br>
void main()<br>
{<br>
    // the connection object<br>
    eureqa::connection conn;<br>
<br>
    // connect and test result<br>
    std::cout &lt;&lt; "attempting to connect..." &lt;&lt; std::endl;<br>
<br>
    if (!conn.connect("localhost"))<br>
    {<br>
        std::cout &lt;&lt; "unable to connect to the server" &lt;&lt; std::endl;<br>
    }<br>
    else if (!conn.last_result())<br>
    {<br>
        std::cout &lt;&lt; "connection made successfully, but ";<br>
        std::cout &lt;&lt; "the server sent back an error message:" &lt;&lt; std::endl;<br>
        std::cout &lt;&lt; conn.last_result() &lt;&lt; std::endl;<br>
    }<br>
    else<br>
    {<br>
        std::cout &lt;&lt; "connection made successfully, and ";<br>
        std::cout &lt;&lt; "the server sent back a success message:" &lt;&lt; std::endl;<br>
        std::cout &lt;&lt; conn.last_result() &lt;&lt; std::endl;<br>
    }<br>
    <br>
    // disconnect<br>
    std::cout &lt;&lt; "disconnecting..." &lt;&lt; std::endl;<br>
    conn.disconnect();<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/connection.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_connection_last_result.md'>connection::last_result method</a>
</li><li><a href='doc_connection_disconnect.md'>connection::disconnect method</a>
</li><li><a href='doc_connection_constructor.md'>connection::(constructor)</a>
</li><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a></li></ul>
