# [solution\_info](doc_solution_info.md)::serialize #

**Allows the solution\_info class to be stored or retrieved in an archive**

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
The version number of the search_options class<br>
<br>
<h2>Comments</h2>
Serialization is the process of reversibly constructing and destructing arbitrary data structures into a sequence of bytes.<br>
<br>
This member makes the class compatible with the <a href='http://www.boost.org/doc/libs/release/libs/serialization'>Boost Serialization library</a>. Boost Serialization supports several different <a href='http://www.boost.org/doc/libs/1_42_0/libs/serialization/doc/archives.html#archive_models'>archive formats</a>, such as binary, plain text, and XML.<br>
<br>
<br>
<h3>Examples</h3>
See example in <a href='doc_data_set_serialize.md'>data_set::serialize</a>.<br>
<br>
<h3>Requirements</h3>
<ul><li><b>Header:</b> <eureqa/solution_frontier.h><br>
</li><li><b>Namespace:</b> <a href='doc_intro.md'>eureqa</a></li></ul>

<h1>See Also</h1>
<ul><li><a href='http://www.boost.org/doc/libs/release/libs/serialization'>Boost Serialization library</a>
</li><li><a href='doc_connection_query_individuals.md'>connection::query_individuals method</a>
</li><li><a href='doc_connection_query_progress.md'>connection::query_progress method</a>
</li><li><a href='doc_solution_frontier_add.md'>solution_frontier::add method</a>
</li><li><a href='doc_solution_frontier_test.md'>solution_frontier::test method</a>
</li><li><a href='doc_search_progress.md'>search_progress class</a>
</li><li><a href='doc_solution_frontier.md'>solution_frontier class</a>
</li><li><a href='doc_solution_info.md'>solution_info class</a>
</li><li><a href='doc_intro.md'>eureqa namespace</a>