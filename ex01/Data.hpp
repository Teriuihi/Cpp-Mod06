#ifndef DATA_HPP
#define DATA_HPP


class Data {
public:
	Data(int randomData);
	Data(Data const &data);
	Data& operator=(Data const &);
	Data();
	int getRandomData() const;
	~Data();
private:
	int randomData;
};


#endif
