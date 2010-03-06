# Eureqa API example project
#

EUREQA_INCLUDE_PATH = ../../
BOOST_INCLUDE_PATH = /path_to_boost/boost_1_42_0/
BOOST_LIBRARY_PATH = /path_to_boost/boost_1_42_0/stage/lib/

basic_client: basic_client.o
	g++ basic_client.o \
	$(BOOST_LIBRARY_PATH)libboost_system.a \
	$(BOOST_LIBRARY_PATH)libboost_serialization.a \
	$(BOOST_LIBRARY_PATH)libboost_date_time.a \
	$(BOOST_LIBRARY_PATH)libboost_thread.a \
	-lpthread \
	-o basic_client 

basic_client.o: basic_client.cpp
	g++ basic_client.cpp \
	-I$(BOOST_INCLUDE_PATH) \
	-I$(EUREQA_INCLUDE_PATH) \
	-c -o basic_client.o
