# minimal\_client #

## Comments ##
The minimal\_client attempts to connect to a Eureqa Server running on the local machine and perform a search with very little error checking. It is meant to be used as a source code example.

See the [basic\_client](doc_basic_client.md) example for an example with appropriate error checking.

## Source code ##
See the [minimal\_client](http://code.google.com/p/eureqa-api/source/browse/trunk#trunk/examples/minimal_client) project directory.

#### Compile with Visual Studio ####

  * Open the provided [minimal\_client.sln](http://code.google.com/p/eureqa-api/source/browse/trunk#trunk/examples/minimal_client) or [minimal\_client.vcproj](http://code.google.com/p/eureqa-api/source/browse/trunk#trunk/examples/minimal_client) in the project directory in Visual Studio 2008 or later.

  * Select the _Build > Build Solution_ menu item to build the program.

  * Start a Eureqa server running in a background window (e.g. running "c:\_your\_path\_to_\eureqa-api\server\windows\eureqa\_server.exe").

  * Run the program in Visual Studio by selecting the _Debug > Start Debugging_ menu item or hitting the _F5_ key.

### Compile with `make` and `g++` ###

  * Modify the provided [Makefile](http://code.google.com/p/eureqa-api/source/browse/trunk/examples/minimal_client/Makefile) in project's directory for your system.

  * Type `make` at the command line in the project directory to build the project.

  * Start a Eureqa server running in the background, (e.g. typing `./eureqa_server &` in the "/_your\_path\_to_/eureqa-api/server/linux/" directory).

  * Run the program by entering `./minimal_client` at the command line.

## Expected Program Output ##
```
Data: 100 data points, 3 variables
Options: "y = f(x)", 8 building-block types, Absolute Error fitness
Connection: Connected to 127.0.0.1
Server: duop, Eureqa 0.79 (win32), 2 CPU cores
0 generations, 932 evaluations
Size:   Fitness:        Equation:
-----   --------        ---------
1       1.23185 f(x) = -1.07667

567 generations, 1.41821e+007 evaluations
1101 generations, 2.82219e+007 evaluations
1668 generations, 4.30322e+007 evaluations
Size:   Fitness:        Equation:
-----   --------        ---------
3       0.938139        f(x) = cos(x)
1       1.231850        f(x) = -1.07667
```
...
```
13963 generations, 3.23017e+008 evaluations
Size:   Fitness:        Equation:
-----   --------        ---------
13      0.223740        f(x) = x*sin(2*x) - sin(2*x)
21      0.216538        f(x) = 1.95545*x*cos(x)*sin(x) - 2.14445*cos(x)*sin(x)
9       0.713277        f(x) = 1.07867*x*sin(2*x)
11      0.713220        f(x) = 2*x*cos(x)*sin(x)
5       0.898780        f(x) = cos(-1.25332*x)
3       0.938139        f(x) = cos(x)
1       1.098610        f(x) = -0.551342
```

## See Also ##
  * [basic\_client example](doc_basic_client.md)
  * [eureqa namespace](doc_intro.md)