# basic\_client #

## Comments ##

The basic\_client attempts to connect to a Eureqa Server running on the local machine and perform a search. It is an extension of the [minimal\_client example](doc_minimal_client.md), with informational messages and proper error checking. It is meant to be used as a source code example.

## Source code ##
See the [basic\_client](http://code.google.com/p/eureqa-api/source/browse/trunk#trunk/examples/basic_client) project directory.

#### Compile with Visual Studio ####

  * Open the provided [basic\_client.sln](http://code.google.com/p/eureqa-api/source/browse/trunk#trunk/examples/basic_client) or [basic\_client.vcproj](http://code.google.com/p/eureqa-api/source/browse/trunk#trunk/examples/basic_client) in the project directory in Visual Studio 2008 or later.

  * Select the _Build > Build Solution_ menu item to build the program.

  * Start a Eureqa server running in a background window (e.g. running "c:\_your\_path\_to_\eureqa-api\server\windows\eureqa\_server.exe").

  * Run the program in Visual Studio by selecting the _Debug > Start Debugging_ menu item or hitting the _F5_ key.

### Compile with `make` and `g++` ###

  * Modify the provided [Makefile](http://code.google.com/p/eureqa-api/source/browse/trunk/examples/basic_client/Makefile) in project's directory for your system.

  * Type `make` at the command line in the project directory to build the project.

  * Start a Eureqa server running in the background, (e.g. typing `./eureqa_server &` in the "/_your\_path\_to_/eureqa-api/server/linux/" directory).

  * Run the program by entering `./basic_client` at the command line.

## Expected Program Output ##
```
> Importing data set from a text file
Data set imported successfully
100 data points, 3 variables

> Setting the search options
"y = f(x)", 8 building-block types, Absolute Error fitness

> Connecting to a eureqa server at 127.0.0.1
Connected to server successfully, and the server sent back a success message:
Connected successully

> Querying the server systems information
Recieved server information successfully:
duop, Eureqa 0.79 (win32), 2 CPU cores

> Sending the data set to the server
Data set transferred successfully, and the server sent back a success message:
Received data set successfully

> Sending search options to the server
Search options transferred successfully, and the server sent back a success mess
age:
Received options successfully

> Telling server to start searching
Start command sent successfully, and the server sent back a success message:
Search started successfully

> Monitoring the search progress
> 0 generations, 932 evaluations

New solution found:
f(x) = 0.169233 + (x/x)/0.763474 - 0.763474

Size:   Fitness:        Equation:
-----   --------        ---------
9       1.53639 f(x) = 0.169233 + (x/x)/0.763474 - 0.763474


> 675 generations, 1.48219e+007 evaluations

New solution found:
f(x) = 0.909297

Size:   Fitness:        Equation:
-----   --------        ---------
1       1.65628 f(x) = 0.909297
9       1.53639 f(x) = 0.169233 + (x/x)/0.763474 - 0.763474
```
...
```
> 4654 generations, 1.05299e+008 evaluations

New solution found:
f(x) = 0.954553*x*cos(1.43534 - 2*x)

Size:   Fitness:        Equation:
-----   --------        ---------
13      0.22374 f(x) = x*sin(2*x) - sin(2*x)
7       0.71322 f(x) = x*sin(2*x)
11      0.695899        f(x) = 0.954553*x*cos(1.43534 - 2*x)
5       0.840779        f(x) = cos(x) - 0.456527
3       0.938139        f(x) = cos(x)
```

## See Also ##
  * [minimal\_client example](doc_minimal_client.md)
  * [eureqa namespace](doc_intro.md)