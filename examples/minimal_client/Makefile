# Eureqa API example project
#

EUREQA_INCLUDE_PATH = ../../
BOOST_INCLUDE_PATH = /path_to_boost/boost_1_42_0/
BOOST_LIBRARY_PATH = /path_to_boost/boost_1_42_0/stage/lib/

minimal_client: minimal_client.o
	g++ minimal_client.o \
	$(BOOST_LIBRARY_PATH)libboost_system.a \
	$(BOOST_LIBRARY_PATH)libboost_serialization.a \
	-o minimal_client 

minimal_client.o: minimal_client.cpp
	g++ minimal_client.cpp \
	-I$(BOOST_INCLUDE_PATH) \
	-I$(EUREQA_INCLUDE_PATH) \
	-c -o minimal_client.o
