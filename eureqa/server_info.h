#ifndef EUREQA_SERVER_INFO_H
#define EUREQA_SERVER_INFO_H

#include <string>

namespace eureqa
{
// structure for receiving system information about the server
class server_info
{
public:
	std::string hostname_;
	std::string operating_system_;
	double eureqa_version_;
	int cpu_cores_;
	
public:
	// default constructor
	server_info();
	
	// test if info is entered and in range
	bool is_valid() const;
	
	// returns a short text summary of the server info
	std::string summary() const;
	
protected:
	// boost serialization, used for sending over it the network
	// can also be used for saving/loading the data set
	friend class boost::serialization::access;
	template<class TArchive> void serialize(TArchive& ar, const unsigned int /*version*/);
};

} // namespace eureqa

#endif // EUREQA_SERVER_INFO_H
