# [connection](doc_connection.md)::send\_data\_location #

**Tells the Eureqa server to load a data set from a file**

```
bool send_data_location(std::string path);
```

**path**<br>
path to a data file<br>
<br>
<h2>Comments</h2>
Returns true if the command was transferred successfully to the server. Use <a href='doc_connection_last_result.md'>connection::last_result</a> to view the response from the Eureqa server.<br>
<br>
The Eureqa server needs to have received or loaded a data set prior to calling the <a href='doc_connection_start_search.md'>connection::start_search</a> method to being a search.<br>
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
    if (!conn.send_data_location("my_data.txt"))<br>
    {<br>
        std::cout &lt;&lt; "unable to send the data location to the server" &lt;&lt; std::endl;<br>
    }<br>
    else if (!conn.last_result())<br>
    {<br>
        std::cout &lt;&lt; "data set path was sent successfully, but ";<br>
        std::cout &lt;&lt; "the server responded with an error message:" &lt;&lt; std::endl;<br>
        std::cout &lt;&lt; conn.last_result() &lt;&lt; std::endl;<br>
    }<br>
    else<br>
    {<br>
        std::cout &lt;&lt; "data set path was sent successfully, and ";<br>
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
</li><li><a href='doc_connection_send_data_set.md'>connection::send_data_set method</a>
</li><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_data_set.md'>data_set class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>