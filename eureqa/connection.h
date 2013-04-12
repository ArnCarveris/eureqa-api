#ifndef EUREQA_CONNECTION_H
#define EUREQA_CONNECTION_H

#include <boost/asio.hpp>

#include <string>
#include <vector>
#include <eureqa/data_set.h>
#include <eureqa/server_info.h>
#include <eureqa/search_progress.h>
#include <eureqa/search_options.h>
#include <eureqa/solution_frontier.h>

namespace eureqa
{
// default connection options
static const int default_port_tcp = 22112;
static const int default_port_multicast = 30002;

// response codes
static const int result_success = 0;
static const int result_error = 1;

// command codes
namespace commands
{
static const int send_data_set      = 101;
static const int send_data_location = 102;
static const int send_options       = 103;
static const int send_individuals   = 104;
static const int send_population    = 105;
static const int query_progress     = 201;
static const int query_server_info  = 202;
static const int query_individuals  = 203;
static const int query_frontier     = 204;
static const int query_population   = 205;
static const int start_search       = 301;
static const int pause_search       = 302;
static const int end_search         = 303;
static const int calc_solution_info = 401;
}

// info sent back from the server after non-query commands
struct command_result
{
public:
	int value_;
	std::string message_;
public:
	command_result() : value_(result_success) { }
	command_result(int value, std::string message) : value_(value), message_(message) { }
	int value() const { return value_; }
	std::string message() const { return message_; }
	operator const void*() const { return ((value_ == result_success)?this:0); }
};
inline
std::ostream& operator <<(std::ostream& os, const command_result& r) { return os << r.message(); }

// synchronous/blocking network interface with a eureqa server
class connection
{
protected:
	boost::asio::ip::tcp::socket socket_;
	command_result last_result_;
	
public:
	// default constructor
	connection();
	connection(std::string hostname, int port = default_port_tcp);
	connection(boost::asio::io_service& io_service);
	virtual ~connection() { disconnect(); }
	
	// basic connection information
	bool is_connected() const { return socket_.is_open(); }
	command_result last_result() const { return last_result_; }

	// opens a network connection to a eureqa server
	bool connect(std::string hostname, int port = default_port_tcp);
	void disconnect() { socket_.close(); }

	// send server the data set over the network
	// or tell it to load it from a network file
	bool send_data_set(const eureqa::data_set& data);
	bool send_data_location(std::string path);
	
	// send server the search options
	bool send_options(const eureqa::search_options& options);
	
	// send server individuals to insert into its population
	bool send_individuals(std::string text);
	bool send_individuals(eureqa::solution_info soln);
	bool send_individuals(const std::vector<eureqa::solution_info>& individuals);

	// send server a population
	bool send_population(const std::vector<eureqa::solution_info>& individuals);

	// query server for information on the search progress
	bool query_progress(eureqa::search_progress& progress);
	
	// query server for its system information
	bool query_server_info(eureqa::server_info& info);
	
	// query server for random individuals from its population
	bool query_individuals(eureqa::solution_info& soln);
	bool query_individuals(std::vector<eureqa::solution_info>& individuals, int count);

	// query server for the current population
	bool query_population(std::vector<eureqa::solution_info>& individuals);
	
	// query the servers local solution frontier
	bool query_frontier(eureqa::solution_frontier& front);
	
	// tell server to start/pause/end searching
	bool start_search();
	bool pause_search();
	bool end_search();
	
	// calculate the solution info on the server
	bool calc_solution_info(eureqa::solution_info& soln);
	bool calc_solution_info(std::vector<eureqa::solution_info>& individuals);
	
	// returns are a short description of the connection
	std::string summary() const;
	std::string remote_address() const;
	int remote_port() const;
	
//protected:
	bool connect_socket(std::string hostname, int port);

	template<typename T> bool write_fixed(const T& val);
	template<typename T> bool write_command_fixed(int cmd, const T& val);
	bool write_command(int cmd);
	bool write_command_packet(int cmd, const void* buf, int num_bytes);
	bool write_command_packet(int cmd, const std::string& s);
	
	template<typename T> bool read_fixed(T& val);
	bool read_packet(std::vector<char>& buf);
	bool read_packet(std::string& s);
	bool read_response();
	
};

void handle_nan_inf(std::istream& is);
void handle_nan_inf(std::ostream& os);

} // namespace eureqa

#endif //EUREQA_CONNECTION_H
