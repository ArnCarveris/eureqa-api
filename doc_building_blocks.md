# Eureqa Building-blocks #

**The building blocks define the allowed operations that can appear in solution equations.**

| **name** | **example** |
|:---------|:------------|
| constant | `"1.34"`    |
| data variable | `"x"`       |
| addition | `"x+y"`     |
| subtraction | `"x-y"`     |
| multiplication | `"x*y"`     |
| division | `"x/y"`     |
| power    | `"x^y"`     |
| power to constant | `"powc(x, 1.5)"` |
| exponential | `"exp(x)"`  |
| logarithm | `"log(x)"`  |
| sine     | `"sin(x)"`  |
| cosine   | `"cos(x)"`  |
| absolute value | `"abs(x)"`  |
| tangent  | `"tan(x)"`  |
| time delay | `"delay(x, 12.3)"` |
| time delay of a variable | `"delay_var(x, 12.3)"` |
| simple moving average | `"sma(x, 12.3)"` |
| time integral | `"integral(x)"` |
| two-input arctangent | `"atan2(x,y)"` |
| minimum of two | `"min(x,y)"` |
| maximum of two | `"max(x,y)"` |
| square root | `"sqrt(x)"` |
| gamma function | `"gamma(x)"` |
| gaussian function | `"gauss(x)"` |
| logistic function | `"logistic(x)"` |
| hill function, power 2 | `"hill2(x)"` |
| step function | `"step(x)"` |
| sign function | `"sign(x)"` |
| arcsine  | `"asin(x)"` |
| arccosine | `"acos(x)"` |
| arctangent | `"atan(x)"` |
| hyperbolic sine | `"sinh(x)"` |
| hyperbolic cosine | `"cosh(x)"` |
| hyperbolic tangent | `"tanh(x)"` |
| inverse hyperbolic sine | `"asinh(x)"` |
| inverse hyperbolic cosine | `"acosh(x)"` |
| inverse hyperbolic tangent | `"atanh(x)"` |

**special building blocks:<sup>*</sup>**
| **name** | **example** |
|:---------|:------------|
| equals   | `"y = f(x)"` |
| search formula | `"y = f(x)"` |
| derivative<sup>**</sup> | `"D(y,t) = f(x,y)"` |

<sup>*</sup>special building blocks may only be used when specifying the [search relationship](doc_search_options.md).

<sup>**</sup>the current version of the Eureqa server does calculate derivatives; instead, the client program should calculate derivatives and add their values as a new variable.

## Comments ##
When specifying the building blocks in the [search\_options](doc_search_options.md), the variable names and numeric values of constants are ignored. Only the operator used (e.g. addition from the express `"a+b"`) is used. Future versions of Eureqa may support custom building blocks however, that use fixed variables or parameters inside building blocks.

### Example ###
```
#include <eureqa/eureqa.h>
void main()
{
    // options structure for sending to the server later
    eureqa::search_options options;
    
    // pick specific equation building blocks for the search
    options.building_blocks_.clear();
    options.building_blocks_.push_back("1.23");
    options.building_blocks_.push_back("x");
    options.building_blocks_.push_back("x+y");
    options.building_blocks_.push_back("x-y");
    options.building_blocks_.push_back("x*y");
    options.building_blocks_.push_back("atanh(x)");
    options.building_blocks_.push_back("logistic(x)");
    
    // search for a formula f that satisfies:
    options.search_relationship_ = "y/10 = f(t,z) + 2";
}
```

## See Also ##
  * [search\_options::set\_default\_building\_blocks method](doc_search_options_set_default_building_blocks.md)
  * [search\_options class](doc_search_options.md)
  * [eureqa namespace](doc_intro.md)