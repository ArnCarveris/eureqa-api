#ifndef EUREQA_CONNECTION_IMPL_H
#define EUREQA_CONNECTION_IMPL_H

#include <eureqa/connection.h>

#include <boost/array.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/math/special_functions/nonfinite_num_facets.hpp>
#include <boost/archive/codecvt_null.hpp>

namespace eureqa
{
static boost::asio::io_service default_io_service;


/*---------------------------------------------------------------------------
    implementions:
*--------------------------------------------------------------------------*/

EUREQA_INLINE void handle_nan_inf(std::istream& is)
{
    std::locale default_locale(std::locale::classic(), new boost::archive::codecvt_null<char>);
    std::locale my_locale(default_locale, new boost::math::nonfinite_num_get<char>);
    is.imbue(my_locale);
}
EUREQA_INLINE void handle_nan_inf(std::ostream& os)
{
    std::locale default_locale(std::locale::classic(), new boost::archive::codecvt_null<char>);
    std::locale my_locale(default_locale, new boost::math::nonfinite_num_put<char>);
    os.imbue(my_locale);
}

EUREQA_INLINE
connection::connection()
{
    create_socket(default_io_service);
}

EUREQA_INLINE
connection::connection(std::string hostname, int port)
{
    create_socket(default_io_service);
    connect(hostname, port);
}

EUREQA_INLINE
connection::connection(boost::asio::io_service& io_service)
{
    create_socket(io_service);
}

EUREQA_INLINE
bool connection::connect(std::string hostname, int port)
{
    if (!connect_socket(hostname, port)) { return false; }
    if (!read_response()) { return false; }
    return true;
}

EUREQA_INLINE
void connection::disconnect()
{
    boost::system::error_code ec;
    boost::asio::io_service& io_service = socket_->get_io_service();

    // attempt graceful shutdown of the connection before forcing the dtor
    if (socket_->is_open())
    {
        socket_->shutdown(socket_->shutdown_both, ec);
        //socket_->close();
    }
    create_socket(io_service);
}

EUREQA_INLINE
bool connection::send_data_set(const eureqa::data_set& data)
{
    // serialize the data set
    std::ostringstream ss;
    handle_nan_inf(ss);
    boost::archive::xml_oarchive ar(ss, boost::archive::no_codecvt);
    ar & boost::serialization::make_nvp("data_set", data );

    // send a command-code, packet size, and data packet
    if (!write_command_packet(commands::send_data_set, ss.str())) { return false; }
    if (!read_response()) { return false; }
    return true;
}

EUREQA_INLINE
bool connection::send_data_location(std::string path)
{
    if (!write_command_packet(commands::send_data_location, path)) { return false; }
    if (!read_response()) { return false; }
    return true;
}

EUREQA_INLINE
bool connection::send_options(const eureqa::search_options& options)
{
    // serialize the data set
    std::ostringstream ss;
    handle_nan_inf(ss);
    boost::archive::xml_oarchive ar(ss, boost::archive::no_codecvt);
    ar << boost::serialization::make_nvp("search_options", options );

    // send a command-code, packet size, and data packet
    if (!write_command_packet(commands::send_options, ss.str())) { return false; }
    if (!read_response()) { return false; }
    return true;
}

EUREQA_INLINE
bool connection::send_individuals(std::string text)
{
    return send_individuals(eureqa::solution_info(text));
}

EUREQA_INLINE
bool connection::send_individuals(eureqa::solution_info soln)
{
    std::vector<eureqa::solution_info> individuals(1, soln);
    return send_individuals(individuals);
}

EUREQA_INLINE
bool connection::send_individuals(const std::vector<solution_info>& individuals)
{
    // serialize the data set
    std::ostringstream ss;
    handle_nan_inf(ss);
    boost::archive::xml_oarchive ar(ss, boost::archive::no_codecvt);
    ar << boost::serialization::make_nvp("vector_solution_info", individuals );

    // send a command-code, packet size, and data packet
    if (!write_command_packet(commands::send_individuals, ss.str())) { return false; }
    if (!read_response()) { return false; }
    return true;
}

EUREQA_INLINE
bool connection::send_population(const std::vector<eureqa::solution_info>& individuals)
{
    // serialize the data set
    std::ostringstream ss;
    handle_nan_inf(ss);
    boost::archive::xml_oarchive ar(ss, boost::archive::no_codecvt);
    ar << boost::serialization::make_nvp("vector_solution_info", individuals );

    // send a command-code, packet size, and data packet
    if (!write_command_packet(commands::send_population, ss.str())) { return false; }
    if (!read_response()) { return false; }
    return true;
}

EUREQA_INLINE
bool connection::query_progress(eureqa::search_progress& progress)
{
    // request progress
    if (!write_command(commands::query_progress)) { return false; }

    // read packet
    std::string s;
    if (!read_packet(s)) { return false; }

    // serialize store
    std::istringstream ss(s);
    handle_nan_inf(ss);
    boost::archive::xml_iarchive ar(ss, boost::archive::no_codecvt);
    ar >> boost::serialization::make_nvp("search_progress", progress );
    return true;
}

EUREQA_INLINE
bool connection::query_server_info(eureqa::server_info& info)
{
    // request progress
    if (!write_command(commands::query_server_info)) { return false; }

    // read packet
    std::string s;
    if (!read_packet(s)) { return false; }

    // serialize store
    std::istringstream ss(s);
    handle_nan_inf(ss);
    boost::archive::xml_iarchive ar(ss, boost::archive::no_codecvt);
    ar >> boost::serialization::make_nvp("server_info", info );
    return true;
}

EUREQA_INLINE
bool connection::query_individuals(eureqa::solution_info& soln)
{
    std::vector<eureqa::solution_info> individuals;
    if (!query_individuals(individuals, 1)) { return false; }
    if (individuals.size() != 1) { return false; }
    soln = individuals[0];
    return true;
}

EUREQA_INLINE
bool connection::query_individuals(std::vector<solution_info>& individuals, int count)
{
    // request individuals
    if (!write_command_fixed(commands::query_individuals, count)) { return false; }

    // read packet
    std::string s;
    if (!read_packet(s)) { return false; }

    // serialize
    std::istringstream ss(s);
    handle_nan_inf(ss);
    boost::archive::xml_iarchive ar(ss, boost::archive::no_codecvt);
    ar >> boost::serialization::make_nvp("vector_solution_info", individuals );
    return true;
}

EUREQA_INLINE
bool connection::query_population(std::vector<eureqa::solution_info>& individuals)
{
    // request individuals
    if (!this->write_command(commands::query_population)) { return false; }

    // read packet
    std::string s;
    if (!read_packet(s)) { return false; }

    // serialize
    std::istringstream ss(s);
    handle_nan_inf(ss);
    boost::archive::xml_iarchive ar(ss, boost::archive::no_codecvt);
    ar >> boost::serialization::make_nvp("vector_solution_info", individuals );
    return true;
}

EUREQA_INLINE
bool connection::query_frontier(eureqa::solution_frontier& frontier)
{
    // request frontier
    if (!write_command(commands::query_frontier)) { return false; }

    // read packet
    std::string packet;
    if (!read_packet(packet)) { return false; }

    // serialize store
    std::istringstream is(packet);
    handle_nan_inf(is);
    boost::archive::xml_iarchive ar(is, boost::archive::no_codecvt);
    ar >> boost::serialization::make_nvp("solution_frontier", frontier);
    return true;
}

EUREQA_INLINE
bool connection::start_search()
{
    if (!write_command(commands::start_search)) { return false; }
    if (!read_response()) { return false; }
    return true;
}

EUREQA_INLINE
bool connection::pause_search()
{
    if (!write_command(commands::pause_search)) { return false; }
    if (!read_response()) { return false; }
    return true;
}

EUREQA_INLINE
bool connection::end_search()
{
    if (!write_command(commands::end_search)) { return false; }
    if (!read_response()) { return false; }
    return true;
}

EUREQA_INLINE
bool connection::calc_solution_info(eureqa::solution_info& ind)
{
    std::vector<eureqa::solution_info> individuals(1, ind);
    if (!calc_solution_info(individuals)) { return false; }
    if (individuals.size() != 1) { return false; }
    ind = individuals[0];
    return true;
}

EUREQA_INLINE
bool connection::calc_solution_info(std::vector<eureqa::solution_info>& individuals)
{
    // serialize the data set
    std::ostringstream os;
    handle_nan_inf(os);
    boost::archive::xml_oarchive ar(os, boost::archive::no_codecvt);
    ar << boost::serialization::make_nvp("vector_solution_info", individuals);

    // send a command-code, packet size, and data packet
    if (!write_command_packet(commands::calc_solution_info, os.str())) { return false; }

    // read packet
    std::string packet;
    if (!read_packet(packet)) { return false; }

    // serialize
    std::istringstream is(packet);
    handle_nan_inf(is);
    boost::archive::xml_iarchive ar2(is, boost::archive::no_codecvt);
    ar2 >> boost::serialization::make_nvp("vector_solution_info", individuals);
    return true;
}

EUREQA_INLINE
bool connection::evaluate_expression(std::string const& expression, std::vector<double>& outputs)
{
    std::vector<std::pair<int,int> > series_and_rows; // empty means evaluate all series and rows
    return evaluate_expression(expression, series_and_rows, outputs);
}

EUREQA_INLINE
bool connection::evaluate_expression(std::string const& expression, int row, double& output)
{
    return evaluate_expression(expression, row, 0, output);
}

EUREQA_INLINE
bool connection::evaluate_expression(std::string const& expression, int row, int series, double& output)
{
    std::vector<std::pair<int,int> > series_and_rows(1); // do a single series and row
    series_and_rows[0].first  = series;
    series_and_rows[0].second = row;
    std::vector<double> outputs;
    if (evaluate_expression(expression, series_and_rows, outputs) && outputs.size())
    {
        output = outputs[0];
        return true;
    }
    return false;
}

EUREQA_INLINE
bool connection::evaluate_expression(std::string const& expression, std::vector<std::pair<int,int> > const& series_and_rows, std::vector<double>& outputs)
{
    // serialize the data set
    std::ostringstream os;
    handle_nan_inf(os);
    boost::archive::xml_oarchive ar(os, boost::archive::no_codecvt);
    ar << boost::serialization::make_nvp("expression", expression);
    ar << boost::serialization::make_nvp("series_and_rows", series_and_rows);

    // send a command-code, packet size, and data packet
    if (!write_command_packet(commands::evaluate_expression, os.str())) { return false; }

    // read packet
    std::string packet;
    if (!read_packet(packet)) { return false; }

    // serialize
    std::istringstream is(packet);
    handle_nan_inf(is);
    boost::archive::xml_iarchive ar2(is, boost::archive::no_codecvt);
    ar2 >> boost::serialization::make_nvp("outputs", outputs);
    return true;
}

EUREQA_INLINE
std::string connection::remote_address() const
{
    boost::system::error_code error;
    return socket_->remote_endpoint(error).address().to_string();
}
EUREQA_INLINE
int connection::remote_port() const
{
    boost::system::error_code error;
    return socket_->remote_endpoint(error).port();
}

EUREQA_INLINE
std::string connection::summary() const
{
    std::ostringstream os;
    if (!is_connected())
    {
        os << "Disconnected";
    }
    else
    {
        os << "Connected to " << remote_address();
    }
    return os.str();
}

EUREQA_INLINE
bool connection::connect_socket(std::string hostname, int port)
{
    try
    {
        // resolve hostname into a tcp end point
        boost::asio::ip::tcp::resolver resolver(socket_->get_io_service());
        boost::asio::ip::tcp::resolver::query query(hostname, boost::lexical_cast<std::string>(port));
        boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        boost::asio::ip::tcp::resolver::iterator end;

        // create and connect a socket
        boost::system::error_code error = boost::asio::error::host_not_found;
        while (error && endpoint_iterator != end)
        {
            create_socket(socket_->get_io_service());
            socket_->connect(*endpoint_iterator++, error);
        }

        if (error) { create_socket(socket_->get_io_service()); }
        return !error;
    }
    catch (std::exception&) { return false; }
}

template<typename T>
EUREQA_INLINE
bool connection::write_fixed(const T& val)
{
    // write a primitive or fixed-sized object
    boost::system::error_code error;
    boost::asio::write(get_socket(), boost::asio::buffer(&val,sizeof(T)), boost::asio::transfer_all(), error);
    if (error) { disconnect(); }
    return !error;
}

template<typename T>
EUREQA_INLINE
bool connection::write_command_fixed(int cmd, const T& val)
{
    // write a packet: a size/data pair
    boost::system::error_code error;
    boost::array<boost::asio::const_buffer, 2> packet = {{ boost::asio::buffer(&cmd,sizeof(int)), boost::asio::buffer(&val,sizeof(T)) }};
    boost::asio::write(get_socket(), packet, boost::asio::transfer_all(), error);
    if (error) { disconnect(); }
    return !error;
}

EUREQA_INLINE
bool connection::write_command(int cmd)
{
    return write_fixed(cmd);
}

EUREQA_INLINE
bool connection::write_command_packet(int cmd, const void* buf, int num_bytes)
{
    // write a packet: a size/data pair
    boost::system::error_code error;
    boost::array<boost::asio::const_buffer, 3> packet = {{ boost::asio::buffer(&cmd,sizeof(int)), boost::asio::buffer(&num_bytes,sizeof(int)), boost::asio::buffer(buf,num_bytes) }};
    boost::asio::write(get_socket(), packet, boost::asio::transfer_all(), error);
    if (error) { disconnect(); }
    return !error;
}

EUREQA_INLINE
bool connection::write_command_packet(int cmd, const std::string& s)
{
    // wraps the std::vector<char> version
    return write_command_packet(cmd, s.c_str(), s.length());
}

EUREQA_INLINE
bool connection::read_packet(std::vector<char>& buf)
{
    // read size of packet
    int num_bytes = 0;
    boost::system::error_code error_header;
    boost::asio::read(get_socket(), boost::asio::buffer(&num_bytes,sizeof(int)), boost::asio::transfer_all(), error_header);
    if (error_header) { disconnect(); }
    if (error_header || num_bytes < 0) { return false; }

    // read data
    buf.resize(num_bytes);
    boost::system::error_code error_data;
    if (num_bytes > 0) { boost::asio::read(get_socket(), boost::asio::buffer(&buf[0],num_bytes), boost::asio::transfer_all(), error_data); }
    if (error_data) { disconnect(); }
    return !error_header && !error_data;
}

EUREQA_INLINE
bool connection::read_packet(std::string& s)
{
    // wraps the std::vector<char> version
    std::vector<char> buf;
    if (!read_packet(buf)) { return false; }
    s.assign(&buf[0], buf.size());
    return true;
}

template<typename T>
EUREQA_INLINE
bool connection::read_fixed(T& val)
{
    // read a primitive or fixed-sized object
    boost::system::error_code error;
    boost::asio::read(get_socket(), boost::asio::buffer(&val,sizeof(T)), boost::asio::transfer_all(), error);
    if (error) { disconnect(); }
    return !error;
}

EUREQA_INLINE
bool connection::read_response()
{
    if (!read_fixed(last_result_.value_)) { return false; }
    if (!read_packet(last_result_.message_)) { return false; }
    return true;
}

EUREQA_INLINE
void connection::create_socket(boost::asio::io_service& io_service)
{
    socket_.reset(new boost::asio::ip::tcp::socket(io_service));
}

} // namespace eureqa


#endif
