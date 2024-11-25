//the goal is to create a bar graph repersenting the population rounded to the nearest thousanth. 
//We collected data from the people.txt file and used this program to turn it into a bar graph


#include <iostream> 
#include <fstream>
#include <vector> 
#include <string> 


//this allows for the actual display of the chart accounting for the "year:*" placement and what each should mean
void display_bar_chart(const std::vector<int>& years, const std::vector<int>& populations) { 
	for (size_t i = 0; i < years.size(); ++i) { 
		std::cout << years[i] << ": ";
	     for (int j = 0; j < populations[i] / 1000; ++j) {
		    std::cout << "*"; } std::cout << std::endl; 
	} 
} 

//this imports the nessecary file with the nessecary numbers 
int main() {
	std::ifstream infile("People.txt");

	//this is incase of a file misplacement or no file found 
	if (!infile) {
		std::cerr << "The file 'People.txt' was not found. Please make sure the file exists in the same directory as this program." << std::endl;
		return 1;
	}

	//here we set the years we want displayed in the graph 
	std::vector<int> years = { 1900, 1920, 1940, 1960, 1980, 2000 };
	std::vector<int> populations; int population; while (infile >> population) {
		populations.push_back(population);
	}

	//this accounts for if the file does not include the proper information for population data 

	infile.close();
	if (populations.size() != years.size() || populations.empty()) {
		std::cerr << "Invalid data in 'People.txt'. Please ensure it contains valid population figures." << std::endl;
		return 1;
	}


	display_bar_chart(years, populations);
	return 0;
}
