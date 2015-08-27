# Getting Started on Linux or Mac #

## **1)** Setup the Boost C++ Libraries ##
The Eureqa API and examples use four binary libraries from Boost: **asio**, **system**, **thread**, and **date\_time**. Be sure to install these binaries while installing Boost.

Follow the [Getting Started Guide](http://www.boost.org/doc/libs/1_42_0/more/getting_started/unix-variants.html#get-boost) at the [Boost website](http://www.boost.org)

This guide assumes you've unpacked boost in "/_your\_path\_to_/boost\_1\_42\_0/" and compiled the Boost libraries to "/_your\_path\_to_/boost\_1\_42\_0/stage/lib" (the default from using "`bjam ... stage`"), where "/_your\_path\_to_" should be replaced with your correct boost root directory.

## **2)** Setup the Eureqa API Files ##

  1. [Download the latest Eureqa API archive](http://code.google.com/p/eureqa-api/downloads)
  1. Unzip this archive to a folder on your computer
    * this guide refers to "/_your\_path\_to_/eureqa/" where "/_your\_path\_to_" is meant to be replaced by the path you unarchived to

## **3)** Compiling Your First Eureqa API Program ##

  1. Browse to "/_your\_path\_to_/eureqa/eureqa\_1\_01\_0/examples/linux"
  1. Pick an example project, such as "basic\_client"
  1. Open the "Makefile" in your favorite editor, such as `emacs Makefile`
  1. Edit the "`EUREQA_INCLUDE_PATH`" to your Eureqa base path, such as"/_your\_path\_to_/eureqa/eureqa\_1\_01\_0/"
  1. Edit the "`BOOST_INCLUDE_PATH`" to your Boost path, such as "/_your\_path\_to_/boost\_1\_42\_0/"
  1. Edit the "`BOOST_LIBRARY_PATH`" to your Boost library path, such as "/_your\_path\_to_/boost\_1\_42\_0/stage/lib"
  1. Compile the example program using make

In order to start performing searches, the client programs need a Eureqa server to connect to. The Eureqa Server executable can be found at "/_your\_path\_to_/eureqa\_api\_1\_01\_0/server/linux/eureqa\_server" (check the [Eureqa Website](http://ccsl.mae.cornell.edu/eureqa_download) for the latest version). Try running one in the background on your local computer before running the example project.


## **4)** Next Steps ##
You're now ready to start developing your own Eureqa client program. Try following the instructions to compile the [basic\_client](doc_basic_client.md) example project. You can use one of the example projects as a base for your project by copying it to a new directory.

You can learn more about the Eureqa API by browsing the [source header files](http://code.google.com/p/eureqa-api/source/browse/trunk#trunk/eureqa) and browsing the [Eureqa API Documentation](doc_intro.md).