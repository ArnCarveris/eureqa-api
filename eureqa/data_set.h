#ifndef EUREQA_DATA_SET_H
#define EUREQA_DATA_SET_H

#include <string>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>

namespace eureqa
{

// main structure for holding data used by eureqa
class data_set
{
public:
	std::vector<int> r_; // series identifier (optional)
	std::vector<float> t_; // time ordering values (optional)
	std::vector<float> w_; // weight values (optional)
	boost::numeric::ublas::matrix<float> X_; // data values
	boost::numeric::ublas::matrix<float> Y_; // special values (reserved)
	std::vector<std::string> X_symbols_; // symbols for data values
	std::vector<std::string> Y_symbols_; // symbols for special values (reserved)
	
public:
	// constructors
	data_set() { }
	data_set(std::string path) { import_ascii(path); }
	data_set(int rows, int cols) : X_(rows,cols) { set_default_symbols(); }
	
	// test if the data set is sized and filled in correctly
	bool is_valid() const;
	
	// sets symbols as { x1, x2, x3, ... }
	void set_default_symbols();
	
	// basic container member functions
	int size()     const { return (int)X_.size1(); }
	int num_vars() const { return (int)X_.size2(); }
	int special_vars() const { return (int)Y_.size2(); }
		  float& operator ()(int i, int j)       { return X_(i,j); }
	const float& operator ()(int i, int j) const { return X_(i,j); }
	void clear() { data_set().swap(*this); }
	void swap(data_set& d);
	void resize(int rows, int cols);
	bool empty() const { return (size() == 0); }
	
	// imports plain ascii text files with single line header
	// can read a eureqa header, plain column header, or missing header
	// data can be delimited by whitespace or commas
	// lines can be commented using the '%' character
	bool import_ascii(std::string path);
	bool import_ascii(std::string path, std::string& error_msg);
	bool import_ascii(std::istream& is);
	bool import_ascii(std::istream& is, std::string& error_msg);
	void export_ascii(std::string path) { std::ofstream file(path.c_str()); export_ascii(file); }
	void export_ascii(std::ostream& os);
	
	// returns a short text summary of the data set
	std::string summary() const;
	
protected:
	// boost serialization, used for sending over it the network
	// can also be used for saving/loading the data set
	friend class boost::serialization::access;
	template<class TArchive> void serialize(TArchive& ar, const unsigned int version);
};


} // namespace eureqa

namespace std 
{
	// specialize the swap function
	template<>
	inline void swap(eureqa::data_set& a, eureqa::data_set& b) { a.swap(b); }
}

#endif // EUREQA_DATA_SET_H
