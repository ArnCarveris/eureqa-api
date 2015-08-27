# [connection](doc_connection.md)::send\_data\_set #

**Sends a data set over the network to the Eureqa server**

```
bool send_data_set(const eureqa::data_set& data);
```

**data**<br>
The data set to transfer<br>
<br>
<h2>Comments</h2>
Returns true if the data set was transferred successfully to the server. Use <a href='doc_connection_last_result.md'>connection::last_result</a> to view the response from the Eureqa server.<br>
<br>
The Eureqa server needs to have received a data set prior to calling the <a href='doc_connection_start_search.md'>connection::start_search</a> method to being a search.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;iostream&gt;<br>
void main()<br>
{<br>
    // load data and connect to a server<br>
    eureqa::data_set data("my_data_set.txt");<br>
    eureqa::connection conn("127.0.0.1");<br>
<br>
    // send data to the server<br>
    std::cout &lt;&lt; "sending data set to the server..." &lt;&lt; std::endl;<br>
<br>
    if (!conn.send_data_set(data))<br>
    {<br>
        std::cout &lt;&lt; "unable to transfer data set over the network" &lt;&lt; std::endl;<br>
    }<br>
    else if (!conn.last_result())<br>
    {<br>
        std::cout &lt;&lt; "data set transfered successfully, but ";<br>
        std::cout &lt;&lt; "the server responded with an error message:" &lt;&lt; std::endl;<br>
        std::cout &lt;&lt; conn.last_result() &lt;&lt; std::endl;<br>
    }<br>
    else<br>
    {<br>
        std::cout &lt;&lt; "data set transfered successfully, and ";<br>
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
</li><li><a href='doc_connection_send_data_location.md'>connection::send_data_location method</a>
</li><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_data_set.md'>data_set class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>