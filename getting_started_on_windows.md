# Getting Started on Microsoft Windows #

## **1)** Setup the Boost C++ Libraries ##
### Follow the Boost Getting Started Guide ###
The Eureqa API and examples use four binary libraries from Boost: **asio**, **system**, **thread**, and **date\_time**. Be sure to install these binaries while installing Boost.

The easiest way to setup Boost on Windows is to use the [Binary Installer for Visual C++](http://www.boostpro.com/download). Alternatively, you can follow the [Getting Started Guide](http://www.boost.org/doc/libs/1_42_0/more/getting_started/windows.html#get-boost) at the [Boost website](http://www.boost.org/) for a detailed guide and tutorial to setup the Boost libraries on Windows the normal way.

## **2)** Setup the Eureqa API files ##

  1. [Download the latest Eureqa API archive](http://code.google.com/p/eureqa-api/downloads)
  1. Unzip this archive to a folder on your computer
    * This guide will use "C:\_your\_path\_to_\eureqa\", where you are meant to replace "C:\_your\_path\_to_" with the path you extracted the files to.

## **3)** Configure Visual Studio ##

### Add paths to Visual Studio ###

  1. Launch Visual Studio and bring up the _Options_ window (in the menu: _Tools_ > _Options_)
  1. Go to the _Projects and Solutions_ > _VC++ Directories_ section.
  1. Select to show _Include files_
    * add a path to the Boost root directory: "C:\_your\_path\_to_\boost\_1\_42\_0\"
    * add a path to the Eureqa API root: "C:\_your\_path\_to_\eureqa\_1\_01\_0\"
  1. Select to show "Library files"
    * add a path to the Boost binaries directory: "C:\_your\_path\_to_\boost\_1\_42\_0\lib\"

### Or instead, add paths just to your project ###
  1. Open your project in Visual Studio
  1. Right-click on the project in the `Solution Explorer` pane, and select `Properties` in the resulting pop-up menu
  1. In _Configuration Properties_ > _C/C++_ > _General_ > _Additional Include Directories_:
    * Add the path to the Boost root directory, "C:\_your\_path\_to_\boost\_1\_42\_0\"
    * Add the path to the Eureqa root directory, "C:\_your\_path\_to_\eureqa\_1\_01\_0\"
  1. In _Configuration Properties_ > _Linker_ > _Additional Library Directories_:
    * Add the path to the Boost binaries, "C:\_your\_path\_to_\boost\_1\_42\_0\lib\"

## **4)** Compiling Your First Eureqa API Program ##

  1. Browse to "C:\_your\_path\_to_\eureqa\_1\_01\_0\examples\"
  1. Pick an example project, such as "basic\_client"
  1. Open the Visual Studio 2008 solution (.sln) file
  1. In Visual Studio, run _Debug_ > _Build_

In order to start performing searches, the client programs need a Eureqa Server to connect to. The Eureqa Server executable can be found at "C:\_your\_path\_to_\eureqa\_api\_1\_01\_0\server\windows\eureqa\_server.exe" (check the [Eureqa Website](http://ccsl.mae.cornell.edu/eureqa_download) for the latest version). Try running one in the background on your local computer before running the example project.

**Note:** If you get a flood of link errors when building, you are missing the compiled Boost binary files or did not add the correct library path; recheck the Boost installation. If you get errors about not being able to open header files, you did not add the correct include path to the Eureqa API or Boost root directories; recheck the Visual Studio configuration.

## **5)** Next Steps ##
You're now ready to start developing your own Eureqa client program. Try following the instructions to compile the [basic\_client](doc_basic_client.md) example project. You can use one of the example projects as a base for your project by copying it to a new directory.

You can learn more about the Eureqa API by browsing the [source header files](http://code.google.com/p/eureqa-api/source/browse/trunk#trunk/eureqa) and browsing the [Eureqa API Documentation](doc_intro.md).