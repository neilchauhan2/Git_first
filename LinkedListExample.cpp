/*
* This is a C++ Program to illustrate a linked list for beginners.
*
* Created by Richard Eigenmann for Hacktoberfest 2018
*
* In response to issue:
* https://github.com/neilchauhan2/Git_first/issues/2
*
* License: The MIT License
*
* Copyright 2018 Richard Eigenmann
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
* and associated documentation files (the "Software"), to deal in the Software without restriction, 
* including without limitation the rights to use, copy, modify, merge, publish, distribute, 
* sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or 
* substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/* 
* To compile this program on a Linux computer with gcc type:
* g++ -Wall LinkedListExample.cpp -o LinkedListExample
*
* And if you prefer clang:
* clang++ -Wall LinkedListExample.cpp -o LinkedListExample
*
* Note the -Wall has nothing to do with walls but means -w for warnings and all for all warnings!
*
* After compiling you receive an executable called LinkedListExample.
* To run this type:
* ./LinkedListExample
*
* Note the ./ is important because it means "run the executable from the current directory". If you 
* leave this off your computer may not know where to look for the executabel and may fail to run it.
*/


#include <iostream> // std::cout
#include <list> // std::list
#include <string> // std::string
#include <algorithm> // std::find

int main () {
	// Let's create a linked list of concert tour venues
	std::list<std::string> concertVenues {};

	// Add some venues to our European Tour
	concertVenues.push_back("Paris");
	concertVenues.push_back("London");
	concertVenues.push_back("Berlin");

	// print the list:
	std::cout << "Concert Venues:" << std::endl;
	for( auto venue : concertVenues ) {
		std::cout << venue << std::endl;
	}

	// Our agent was able to get us some Asian gigs!
	concertVenues.push_back("Tokyo");
	concertVenues.push_back("Beijing");

	// print the list:
	std::cout << std::endl << "After adding the Asian gigs the venues are:" << std::endl;
	for( auto venue : concertVenues ) {
		std::cout << venue << std::endl;
	}

	// Oh no, they double booked London and we got rejected!
	// std::find will start at the begin iterator and step through to the end iterator
	// looking for a match with the 3rd parameter. std::find returns an interator which 
	// either points at the first matching element or points to the end interator when 
	// it found nothing.
	auto it = std::find(concertVenues.begin(), concertVenues.end(), "London");
    if (it != concertVenues.end()) {
		// if the interator doesn't point to the end of the list we remove the venue 
        concertVenues.erase(it);
    }

	std::cout << std::endl << "After losing the London gig the venues are:" << std::endl;
	for( auto venue : concertVenues ) {
		std::cout << venue << std::endl;
	}

	// Some guys from Switzerland called and want us to play before heading out to Asia!
	auto it2 = std::find(concertVenues.begin(), concertVenues.end(), "Tokyo");
    if (it2 != concertVenues.end()) {
        concertVenues.insert(it2, "Zurich");
    }

	std::cout << std::endl << "We go to Zurich before heading out to Asia:" << std::endl;
	for( auto venue : concertVenues ) {
		std::cout << venue << std::endl;
	}

	// We've played our first concert:
	// pop_front removes the first element of the container.
	concertVenues.pop_front();

	// And they want us in London and give us a double gig!
	concertVenues.push_back("London");
	concertVenues.push_back("London");

	std::cout << std::endl << "After our first concert they want us so badly in London that we were given a double date!" << std::endl;

	// we can also use iterators to step through the list instead of using the range for loop: 1
	int count = 1;
	for ( std::list<std::string>::iterator  it = concertVenues.begin(); it != concertVenues.end(); ++it) {
		std::cout << count << ". " << *it << std::endl;
		++count;
	}
	std::cout << count-1 << " concerts left to play." << std::endl;
}


/*
Expected output:

Concert Venues:
Paris
London
Berlin

After adding the Asian gigs the venues are:
Paris
London
Berlin
Tokyo
Beijing

After losing the London gig the venues are:
Paris
Berlin
Tokyo
Beijing

We go to Zurich before heading out to Asia:
Paris
Berlin
Zurich
Tokyo
Beijing

After our first concert they want us so badly in London that we were given a double date!
1. Berlin
2. Zurich
3. Tokyo
4. Beijing
5. London
6. London
6 concerts left to play.
*/