# Eureqa API example project
#

#------------------------------------------
# Edit the following paths for your system:
#------------------------------------------
EUREQA_INCLUDE_PATH = ../../
BOOST_INCLUDE_PATH = /path_to_boost/boost_1_42_0/
BOOST_LIBRARY_PATH = /path_to_boost/boost_1_42_0/stage/lib/

minimal_client: minimal_client.o
	
	g++ minimal_client.o \
	$(BOOST_LIBRARY_PATH)libboost_system.a \
	$(BOOST_LIBRARY_PATH)libboost_serialization.a \
	$(BOOST_LIBRARY_PATH)libboost_date_time.a \
	$(BOOST_LIBRARY_PATH)libboost_thread.a \
	-lpthread \
	-o minimal_client 

minimal_client.o: minimal_client.cpp
	
	g++ minimal_client.cpp \
	-I$(BOOST_INCLUDE_PATH) \
	-I$(EUREQA_INCLUDE_PATH) \
	-c -o minimal_client.o
