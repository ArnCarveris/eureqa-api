# [data\_set](doc_data_set.md)::import\_ascii #

**Attempts to import data from a text file or file stream**

```
bool import_ascii(std::string path);
bool import_ascii(std::string path, std::string& error_msg);

bool import_ascii(std::istream& is);
bool import_ascii(std::istream& is, std::string& error_msg);
```

**path**<br>
path to a text file to import data from<br>
<br>
<b>error_msg</b><br>
optional string to receive error messages from the import<br>
<br>
<b>is</b><br>
an input file stream to import data from<br>
<br>
<h2>Comments</h2>
Returns true on success. On failure, the method fills the error_msg string with a description of the failure.<br>
<br>
This method can import three types of text formats: no header text files, plain header text files, and eureqa header files. Values and symbols can be delimited by repeated white space. Lines can also be commented either entirely or after the last column using the "<code>%</code>" character (except on the first line, the comment symbol is always skipped and ignored).<br>
<br>
<b>No header text file example:</b><br>
If first line is all numeric values, assumes column symbols "x0", "x1", and "x2"<br>
<pre><code>1.23 2.15 3.35<br>
2.25 7.66 5.31<br>
4.13 4.55 3.36<br>
5.23 2.47 7.31<br>
6.23 1.35 0.32<br>
</code></pre>

<b>Plain header file example:</b><br>
Interprets non-numeric values on the first line as a one-line header of symbols<br>
<pre><code>x y z<br>
1.23 2.15 3.35<br>
2.25 7.66 5.31<br>
4.13 4.55 3.36<br>
5.23 2.47 7.31<br>
6.23 1.35 0.32<br>
</code></pre>

<b>Eureqa header file example:</b><br>
If the first line contains two "<code>|</code>" delimiters, interprets a one-line Eureqa header that contains series identifiers, time ordering, and weight vectors.<br>
<pre><code>% r t w | x y z |<br>
0 1 2 1.23 2.15 3.35<br>
0 2 2 2.25 7.66 5.31<br>
1 1 1 4.13 4.55 3.36<br>
1 2 1 5.23 2.47 7.31<br>
1 3 1 6.23 1.35 0.32<br>
</code></pre>


<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;iostream&gt;<br>
#include &lt;fstream&gt;<br>
void main()<br>
{<br>
    eureqa::data_set data;<br>
    std::string error;<br>
<br>
    // create an ascii data text file<br>
    {<br>
        std::ofstream file("my_data.txt");<br>
        file &lt;&lt; "x y z" &lt;&lt; std::endl;<br>
        file &lt;&lt; "1.1 1.2 1.3" &lt;&lt; std::endl;<br>
        file &lt;&lt; "2.1 2.2 2.3" &lt;&lt; std::endl;<br>
        file &lt;&lt; "3.1 3.2 3.3" &lt;&lt; std::endl;<br>
        file &lt;&lt; "4.1 4.2 4.3" &lt;&lt; std::endl;<br>
    }<br>
<br>
    // import the ascii data<br>
    if (!data.import_ascii("my_data.txt", error))<br>
    {<br>
        std::cout &lt;&lt; "Error loading data set: &lt;&lt; std::endl;<br>
        std::cout &lt;&lt; error &lt;&lt; std::endl;<br>
    }<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/data_set.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_data_set_constructor.md'>data_set::(constructor)</a>
</li><li><a href='doc_data_export_ascii.md'>data_set::export_ascii method</a>
</li><li><a href='doc_data_set_serialize.md'>data_set::serialize method</a>
</li><li><a href='doc_data_set.md'>data_set class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>