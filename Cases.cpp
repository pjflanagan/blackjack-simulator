#ifndef CASES_CPP
#define CASES_CPP

#include <string>
#include <map>

class Cases {
	public: 
	Cases(){
		//				A	2	3	4	5	6	7	8	9	10
		cases["sum4"] = {'H','H','H','H','H','H','H','H','H','H'};
		cases["sum5"] = {'H','H','H','H','H','H','H','H','H','H'};
		cases["sum6"] = {'H','H','H','H','H','H','H','H','H','H'};
		cases["sum7"] = {'H','H','H','H','H','H','H','H','H','H'};
		cases["sum8"] = {'H','H','H','H','H','H','H','H','H','H'};
		cases["sum9"] = {'H','H','D','D','D','D','H','H','H','H'};
		cases["sum10"] = {'H','D','D','D','D','D','D','D','D','H'};
		cases["sum11"] = {'H','D','D','D','D','D','D','D','D','D'};
		cases["sum12"] = {'H','H','H','S','S','S','H','H','H','H'};
		cases["sum13"] = {'H','S','S','S','S','S','H','H','H','H'};
		cases["sum14"] = {'H','S','S','S','S','S','H','H','H','H'};
		cases["sum15"] = {'H','S','S','S','S','S','H','H','H','H'};
		cases["sum16"] = {'H','S','S','S','S','S','H','H','H','H'};
		cases["sum17"] = {'S','S','S','S','S','S','S','S','S','S'};
		cases["sum18"] = {'S','S','S','S','S','S','S','S','S','S'};
		cases["sum19"] = {'S','S','S','S','S','S','S','S','S','S'};
		cases["sum20"] = {'S','S','S','S','S','S','S','S','S','S'};
		cases["sum21"] = {'S','S','S','S','S','S','S','S','S','S'};
		cases["ace2"] = {'H','H','H','H','D','D','H','H','H','H'};
		cases["ace3"] = {'H','H','H','H','D','D','H','H','H','H'};
		cases["ace4"] = {'H','H','H','D','D','D','H','H','H','H'};
		cases["ace5"] = {'H','H','H','D','D','D','H','H','H','H'};
		cases["ace6"] = {'H','H','D','D','D','D','H','H','H','H'};
		cases["ace7"] = {'H','S','D','D','D','D','S','S','H','H'};
		cases["ace8"] = {'S','S','S','S','S','S','S','S','S','S'};
		cases["ace9"] = {'S','S','S','S','S','S','S','S','S','S'};
		cases["ace10"] = {'B','B','B','B','B','B','B','B','B','B'};
		cases["pair1"] = {'P','P','P','P','P','P','P','P','P','P'};
		cases["pair2"] = {'H','P','P','P','P','P','P','H','H','H'};
		cases["pair3"] = {'H','P','P','P','P','P','P','H','H','H'};
		cases["pair4"] = {'H','H','H','H','P','P','H','H','H','H'};
		cases["pair5"] = {'H','D','D','D','D','D','D','D','D','H'};
		cases["pair6"] = {'H','P','P','P','P','P','H','H','H','H'};
		cases["pair7"] = {'H','P','P','P','P','P','P','H','H','H'};
		cases["pair8"] = {'P','P','P','P','P','P','P','P','P','P'};
		cases["pair9"] = {'S','P','P','P','P','P','S','P','P','S'};
		cases["pair10"] = {'S','S','S','S','S','S','S','S','S','S'};
	}

	char action(std::string type, int upcard){
		return cases[type][upcard-1];
	}

	private:
	std::map<std::string, std::vector<char> > cases;
};

#endif