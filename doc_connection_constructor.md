# [connection](doc_connection.md)::(constructor) #

**Constructs a connection instance**

```
connection();
connection(std::string hostname, int port = eureqa::default_port_tcp);
connection(boost::asio::io_service& io_service);
```

**hostname**<br>
The server's ip4 address or DNS hostname<br>
<br>
<b>port</b><br>
The server's listen port<br>
<br>
<b>io_service</b><br>
The network I/O service object to handle core I/O<br>
<br>
<h2>Comments</h2>
The eureqa connection class wraps a <a href='http://www.boost.org/doc/libs/release/libs/asio/'>Boost Asio</a> tcp socket. This means you can specify your own io_service instance if needed. By default, a static io_service is used.<br>
<br>
The second constructor version attempts to connect to the provided server hostname and port. Use the <a href='doc_connection_is_connected.md'>connection::is_connected</a> method and <a href='doc_connection_last_result.md'>connection::last_result</a> method to test if the connection was successful.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
void main()<br>
{<br>
    // default constructor<br>
    eureqa::connection conn;<br>
    <br>
    // initializing constructor<br>
    eureqa::connection conn_2("my-eureqa-server.net");<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/connection.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_connection_destructor.md'>connection::(destructor)</a>
</li><li><a href='doc_connection_connect.md'>connection::connect method</a>
</li><li><a href='doc_connection_disconnect.md'>connection::disconnect method</a>
</li><li><a href='doc_connection_is_connected.md'>connection::is_connected method</a>
</li><li><a href='doc_connection.md'>connection class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>