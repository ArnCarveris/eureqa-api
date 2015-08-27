# [search\_options](doc_search_options.md)::(constructor) #

**Constructs a search\_options instance**

```
search_options();
search_options(std::string search_relationship);
```

**search\_relationship**<br>
The relationship for the search to analyze, e.g. "y = f(x)"<br>
<br>
<h2>Comments</h2>
The constructor initializes all options to default values, except for the <code>search_relationship_</code> member variable. This value must be assigned manually or by using the second version of the constructor.<br>
<br>
<h3>Example</h3>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
<br>
void main()<br>
{<br>
    // default constructor<br>
    eureqa::search_options options;<br>
    <br>
    // copy constructor<br>
    eureqa::search_options options_2(options);<br>
    eureqa::search_options options_3 = options;<br>
<br>
    // initializing constructor<br>
    eureqa::search_options options_4("z = f(x,y)");<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/search_options.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h2>See Also</h2>
<ul><li><a href='doc_search_options_set_default_options.md'>search_options::set_default_options method</a>
</li><li><a href='doc_search_options_set_default_building_blocks.md'>search_options::set_default_building_blocks method</a>
</li><li><a href='doc_search_options.md'>eureqa::search_options class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>