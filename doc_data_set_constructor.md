# [data\_set](doc_data_set.md)::(constructor) #

**Constructs a data\_set instance**

```
data_set();
data_set(std::string path);
data_set(int rows, int cols);
```

**path**<br>
Path to an ascii data file to load<br>
<br>
<b>rows</b><br>
Number of data points in the data set<br>
<br>
<b>cols</b><br>
Number of variables in the data set<br>
<br>
<h2>Comments</h2>
The <code>data_set(int rows, int cols)</code> constructor allocates a the matrix member <code>X_</code> and initializes the vector member <code>X_symbols_</code> to <a href='doc_data_set_set_default_symbols.md'>default names</a> for each column.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
<br>
void main()<br>
{<br>
    // default constructor<br>
    eureqa::data_set data_1;<br>
    <br>
    // construct from a data file<br>
    eureqa::data_set data_2("my_data.txt");<br>
    <br>
    // copy constructor<br>
    eureqa::data_set data_3(data_2);<br>
    eureqa::data_set data_4 = data_2;<br>
<br>
    // initialize 100 data points of 2 variables<br>
    // variable names default to "x0" and "x1"<br>
    eureqa::data_set data_5(100,2);<br>
    <br>
    // set different variables names<br>
    data_5.X_labels_[0] = "x";<br>
    data_5.X_labels_[1] = "y";<br>
<br>
    // fill in some values<br>
    for (int i=0; i&lt;data_5.size(); ++i)<br>
    {<br>
        float x = (float)i/10.0;<br>
        data_5(i,0) = x;<br>
        data_5(i,1) = x/(1+x*x);<br>
    }<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/data_set.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_data_set_resize.md'>data_set::resize method</a>
</li><li><a href='doc_data_set.md'>eureqa::data_set class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>