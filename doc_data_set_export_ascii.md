# [data\_set](doc_data_set.md)::export\_ascii #

**Exports the data set to a plain data file or file stream**

```
void export_ascii(std::string path);
void export_ascii(std::ostream& os);
```

**path**<br>
path to a text file to import data from<br>
<br>
<b>os</b><br>
an output file stream to export data to<br>
<br>
<h2>Comments</h2>
Returns true on success. By default, the exported file uses a Eureqa one-line header, starting with a comment character "<code>%</code>". This format can be imported into Matlab, Excel, and similar programs.<br>
<br>
<b>Eureqa header file example:</b><br>
<pre><code>% r t w | x y z |<br>
0 1 2 1.23 2.15 3.35<br>
0 2 2 2.25 7.66 5.31<br>
1 1 1 4.13 4.55 3.36<br>
1 2 1 5.23 2.47 7.31<br>
1 3 1 6.23 1.35 0.32<br>
</code></pre>

<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
void main()<br>
{<br>
    // create a data set<br>
    eureqa::data_set data(100,2);<br>
    for (int i=0; i&lt;data.size(); ++i)<br>
    {<br>
        for (int j=0; j&lt;data.num_vars(); ++j)<br>
        {<br>
            data(i,j) = 10*i + j;<br>
        }<br>
    }<br>
<br>
    // export it to a text file<br>
    data.export_ascii("my_data.txt");<br>
    <br>
    // import it later<br>
    data.import_ascii("my_data.txt");<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/data_set.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_data_set_export_ascii.md'>data_set::export_ascii method</a>
</li><li><a href='doc_data_set_serialize.md'>data_set::serialize method</a>
</li><li><a href='doc_data_set.md'>data_set class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>