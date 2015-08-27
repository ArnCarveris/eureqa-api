# [data\_set](doc_data_set.md)::operator() #

**Returns the number of variables in the data set**

```
float& operator ()(int i, int j);
const float& operator ()(int i, int j) const;
```

**i**<br>
The row number<br>
<br>
<b>j</b><br>
The column number<br>
<br>
<h2>Comments</h2>
Row and column numbers are zero indexed, meaning the very first cell is (0, 0) and the very last cell is (<i>rows</i> - 1, <i>cols</i> - 1).<br>
<br>
Data values are stored in <a href='http://en.wikipedia.org/wiki/Row-major'>row-major order</a>, meaning it is most efficient computationally to loop over columns for each row, rather than all rows of a particular column.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
void main()<br>
{<br>
    // create an uninitialized 100 data point by 2 variable data set<br>
    eureqa::data_set data(100,2);<br>
   <br>
    // loop over each data point<br>
    for (int i=0; i&lt;data.size(); ++i)<br>
    {<br>
        // loop over each variable in the data point<br>
        for (int j=0; j&lt;data.num_vars(); ++j)<br>
        {<br>
            // assign a data value<br>
            data(i,j) = 10*i + j;<br>
            <br>
            // print the data value<br>
            std::cout &lt;&lt; data(i,j) &lt;&lt; "\t";<br>
        }<br>
        std::cout &lt;&lt; std::endl;<br>
    }<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/data_set.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_data_set_size.md'>data_set::size method</a>
</li><li><a href='doc_data_set_num_vars.md'>data_set::num_vars method</a>
</li><li><a href='doc_data_set.md'>data_set class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>