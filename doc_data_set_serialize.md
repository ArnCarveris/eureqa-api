# [data\_set](doc_data_set.md)::serialize #

**Allows the data set to be stored or retrieved in an archive**

```
template<class TArchive> 
void serialize(TArchive& ar, const unsigned int version);
```

**TArchive**<br>
A template type for different archive classes<br>
<br>
<b>ar</b><br>
Reference to an input or output archive<br>
<br>
<b>version</b><br>
The version number of the data_set class<br>
<br>
<h2>Comments</h2>
Serialization is the process of reversibly constructing and destructing arbitrary data structures into a sequence of bytes.<br>
<br>
This member makes the data_set class compatible with the <a href='http://www.boost.org/doc/libs/release/libs/serialization'>Boost Serialization library</a>. The Boost Serialization supports several different <a href='http://www.boost.org/doc/libs/1_42_0/libs/serialization/doc/archives.html#archive_models'>archive formats</a>, such as binary, plain text, and XML.<br>
<br>
The numeric data members (vectors and matricies of numeric values), are always serialized as binary data values.<br>
<br>
<h3>Examples</h3>
<b>XML archive example:</b>
<pre><code>#include &lt;eureqa/eureqa.h&gt;<br>
#include &lt;boost/archive/xml_iarchive.hpp&gt;<br>
#include &lt;boost/archive/xml_oarchive.hpp&gt;<br>
void main()<br>
{<br>
    eureqa::data_set data;<br>
    <br>
    // load from xml file<br>
    {<br>
        // open input file<br>
        std::ifstream file("my_data.xml");<br>
        <br>
        // create input archive that interprets the xml file<br>
        boost::archive::xml_iarchive ar(file);<br>
<br>
        // read the data set from the xml archive<br>
        // make_nvp specifies the name-value-pair for xml tags<br>
        ar &gt;&gt; boost::serialization::make_nvp("data_set_tag", data);<br>
    }<br>
<br>
    // save to xml file<br>
    {<br>
        // open output file<br>
        std::ifstream file("my_data.xml");<br>
<br>
        // create output archive that writes xml to the file<br>
        boost::archive::xml_oarchive ar(file);<br>
<br>
        // add the data set to the xml archive<br>
        // make_nvp specifies the name-value-pair for xml tags<br>
        ar &lt;&lt; boost::serialization::make_nvp("data_set_tag", data);<br>
    }<br>
}<br>
</code></pre>

<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/data_set.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h1>See Also</h1>
<ul><li><a href='http://www.boost.org/doc/libs/release/libs/serialization'>Boost Serialization library</a>
</li><li><a href='doc_data_set_import_ascii.md'>data_set::import_ascii member</a>
</li><li><a href='doc_data_set_export_ascii.md'>data_set::export_ascii member</a>
</li><li><a href='doc_data_set.md'>data_set class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>