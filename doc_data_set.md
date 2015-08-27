# [eureqa](doc_intro.md)::data\_set #

**Loads and stores data used by the Eureqa Server**

```
class data_set;
```

## Comments ##

The data\_set class is a container class for holding numeric data and symbol names of a data set. The main data members are a matrix `X_` of number values and a vector `X_symbols_` of variable names. Other members are optional (can be left empty) such as a vector `w_` of weight values.

The data\_set class can import and export data to and from plain ascii files. The data set can also be loaded and saved in various other formats [using a Boost Serialization archive](doc_data_set_serialize.md).

Use the [connection::send\_data\_set](doc_connection_send_data_set.md) or [connection::send\_data\_location](doc_connection_send_data_location.md) functions to load a data set onto a Eureqa server.

See the individual member functions for examples on using the data\_set class.

## Members ##

**public member functions:**
| [(constructor)](doc_data_set_constructor.md) | constructs a data\_set object |
|:---------------------------------------------|:------------------------------|
| [is\_valid](doc_data_set_is_valid.md)        | test if the data set is sized and filled in correctly |
| [set\_default\_symbols](doc_data_set_set_default_symbols.md) | sets symbols as `{ x1, x2, x3, ... }` |
| [size](doc_data_set_size.md)                 | returns number of data points in the data set |
| [num\_vars](doc_data_set_num_vars.md)        | returns number of variables in the data set |
| [operator()](doc_data_set_operator_pp.md)    | access value of a data point, e.g. `data(i,j) = 1.32;` |
| [clear](doc_data_set_clear.md)               | empties and resets the data set |
| [swap](doc_data_set_swap.md)                 | swap content with another data\_set |
| [resize](doc_data_set_resize.md)             | resize the data set           |
| [empty](doc_data_set_empty.md)               | tests if the data set is empty |
| [import\_ascii](doc_data_set_import_ascii.md) | imports plain ascii text files |
| [export\_ascii](doc_data_set_export_ascii.md) | exports plain ascii text files |
| [summary](doc_data_set_summary.md)           | returns a short text summary of the data set |

**protected member functions:**
| [serialize](doc_data_set_serialize.md) | boost serialization, used for sending data sets over the network. can also be used for saving/loading the data set |
|:---------------------------------------|:-------------------------------------------------------------------------------------------------------------------|

**public data members:**
| [std::vector](http://www.cplusplus.com/reference/stl/vector/)`<int>` | `r_` | series identifier (optional) |
|:---------------------------------------------------------------------|:-----|:-----------------------------|
| [std::vector](http://www.cplusplus.com/reference/stl/vector/)`<float>` | `t_` | time ordering values (optional) |
| [std::vector](http://www.cplusplus.com/reference/stl/vector/)`<float>` | `w_` | weight values (optional)     |
| [boost::numeric::ublas::matrix](http://www.boost.org/doc/libs/1_42_0/libs/numeric/ublas/doc/matrix.htm#matrix)`<float>` | `X_` | data values                  |
| [boost::numeric::ublas::matrix](http://www.boost.org/doc/libs/1_42_0/libs/numeric/ublas/doc/matrix.htm#matrix)`<float>` | `Y_` | special values (reserved)    |
| [std::vector](http://www.cplusplus.com/reference/stl/vector/)`<`[std::string](http://www.cplusplus.com/reference/string/)`>` | `X_symbols_` | symbols for data values      |
| [std::vector](http://www.cplusplus.com/reference/stl/vector/)`<`[std::string](http://www.cplusplus.com/reference/string/)`>` | `Y_symbols_` | symbols for special values (reserved) |

## Requirements ##
  * **Header:** `<eureqa/data_set.h>`
  * **Namespace:** [eureqa](doc_intro.md)

## See Also ##
  * [connection::send\_data\_set](doc_connection_send_data_set.md)
  * [connection::send\_data\_location](doc_connection_send_data_location.md)
  * [eureqa namespace](doc_intro.md)