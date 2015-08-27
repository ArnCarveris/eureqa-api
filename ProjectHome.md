# Overview #
The Eureqa API provides portable source code and examples for interacting with the [Eureqa servers](http://ccsl.mae.cornell.edu/eureqa) to perform custom equation searches.

[Getting Started](#Getting_Started.md) | [Function and Class Reference](doc_intro.md) | [Open Projects](open_projects.md)

# Introductory Example #
**The simplest possible complete C++ program using the Eureqa API:**
```
#include <eureqa/eureqa.h>
#include <iostream>

int main(int argc, char *argv[])
{
  // initialize data set and options
  eureqa::data_set data("my_data.txt");
  eureqa::search_options options("y = f(x)");

  // connect to a eureqa server
  eureqa::connection conn("127.0.0.1");
  conn.send_data_set(data);
  conn.send_options(options);
  conn.start_search();

  // display results
  eureqa::search_progress progress;
  eureqa::solution_frontier solutions;

  while (conn.query_progress(progress))
  {
    solutions.add(progress.solution_);
    std::cout << progress.summary() << std::endl;
    std::cout << solutions.to_string() << std::endl;
  }
  return 0;
}
```
<a href='Hidden comment: 
<wiki:gadget url="http://eureqa-api.googlecode.com/svn/trunk/examples/intro_example.xml" width="500" height="450" />
'></a>

# Getting Started #
The Eureqa API is a simple and portable header-only library for C++. It's only dependencies are from the well-known [Boost C++ Libraries](http://www.boost.org/). You can get started developing with the Eureqa API in three steps: (1) get Boost, (2) unzip the Eureqa API headers, (3) compile the example project.

**Detailed instructions are provided here:**
  * [Getting started on Microsoft Windows](getting_started_on_windows.md)
  * [Getting started on Linux or Mac](getting_started_on_unix_variants.md)

# Projects Using the Eureqa API #

  * [Eureqa Client for Mathematica](http://github.com/secelis/eureqa-mathematica-client#readme) by [Shane Celis](http://github.com/secelis)
  * [Eureqa Python](https://github.com/marcin-franc/eureqa_python/wiki) by [Marcin Franc](https://github.com/marcin-franc)
  * [Eureqa .NET](http://net.eureqa.ivi.eu.com/) by [Gábor Bakos](http://iiota2.blog.ivi.eu.com/)
  * [Eureqa in KNIME](http://eureqa.ivi.eu.com/) by [Gábor Bakos](http://iiota2.blog.ivi.eu.com/)
  * [Eureqa Matlab Interface](http://www.mathworks.com/matlabcentral/fileexchange/32225-interface-with-eureqa-featuring-symbolic-regression) by [Johannes Jenkner](http://www.mathworks.com/matlabcentral/fileexchange/authors/164793)
