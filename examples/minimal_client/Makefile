# Eureqa API example project
#

#------------------------------------------
# Edit the following paths for your system:
#------------------------------------------
EUREQA_INCLUDE_PATH ?= ../../
BOOST_INCLUDE_PATH  ?= /EDIT_THIS_PATH/boost_1_42_0/
BOOST_LIBRARY_PATH  ?= /EDIT_THIS_PATH/boost_1_42_0/stage/lib/


#------------------------------------------
# Edit the following if you want to use a specific build of boost
# 
# For example: building boost 1.52 on Ubuntu 64 with gcc yields
# libraries named libboost_system-gcc46-mt-1_52.a. In this caseL
# BOOST_TAIL=-gcc46-mt-1_52
#------------------------------------------
BOOST_TAIL?=

minimal_client: minimal_client.o
	g++ minimal_client.o \
	$(BOOST_LIBRARY_PATH)libboost_system$(BOOST_TAIL).a \
	$(BOOST_LIBRARY_PATH)libboost_serialization$(BOOST_TAIL).a \
	$(BOOST_LIBRARY_PATH)libboost_date_time$(BOOST_TAIL).a \
	$(BOOST_LIBRARY_PATH)libboost_thread$(BOOST_TAIL).a \
	-lpthread \
	-o minimal_client 

minimal_client.o: minimal_client.cpp
	g++ minimal_client.cpp \
	-I$(BOOST_INCLUDE_PATH) \
	-I$(EUREQA_INCLUDE_PATH) \
	-c -o minimal_client.o

clean: 
	rm -f minimal_client minimal_client.o
