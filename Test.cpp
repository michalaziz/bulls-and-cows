/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main()
{

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0)
	{

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "1234"), "4,0") // 4 bull, 0 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "4321"), "0,4") // 0 bull, 4 pgia
				;

		testcase.setname("Play with dummy choosers and guessers")
				.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)		 // guesser wins in one turn.
				.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)	// guesser loses by running out of turns
				.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101) // guesser loses technically by making an illegal guess (too long).
				.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)	 // chooser loses technically by choosing an illegal number (too long).
				;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i = 0; i < 100; ++i)
		{
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 100, true); // smarty should always win in at most 100 turns!
		}

		//MY TESTS//

		//ConstantChooser and SmartGuesser
		ConstantChooser cconst{"687"};
		SmartGuesser s;

		testcase.setname("Play with smart guesser and constant chooser");
		for (uint i = 0; i < 100; i++)
		{

			testcase.CHECK_EQUAL(play(cconst, s, 3, 100) <= 100, true); //check if smart guesser won in maximum 100 turns
		}
		testcase
				.CHECK_EQUAL(play(cconst, s, 3, 0) == 1, true)	//no turns
				.CHECK_EQUAL(play(cconst, s, 4, 10) == 0, true);//chooser lose technically

		//ConstantChooser and ConstantChooser
		ConstantGuesser gconst{"687"};
		testcase.setname("Play with constant guesser and constant chooser");
		testcase
				.CHECK_EQUAL(play(cconst, gconst, 3, 100) ,1) //the strings are equal guesser win on the first turn
				.CHECK_EQUAL(play(cconst, gconst, 1, 10) ,0)	//technically win to guesser
				.CHECK_EQUAL(play(cconst, gconst, 3, 0) ,1);	//technically wining to chooser guesser pass the maxturn
		for (int i = 0; i < 90; i++)
		{
			testcase
					.CHECK_EQUAL(play(cconst, gconst, 3, 90) == 1, true); //both are const so guesser always win in the first turn
		}
		gconst = {"675"};
		for (int i = 0; i < 90; i++)
		{
			testcase
					.CHECK_EQUAL(play(cconst, gconst, 3, 90) <= 91, true); //both are const so guesser never win
		}
		gconst = {"67"};
		testcase.CHECK_EQUAL(play(cconst, gconst, 3, 90) ,91); //technical win to chooser

		//random chooser and smart guesser
		testcase.setname("Play with smart guesser and random chooser");
		RandomChooser crandom;
		for (uint i = 0; i < 100; ++i)
		{
			testcase.CHECK_EQUAL(play(crandom, s, 2, 100) <= 100, true); // smartguesser s should always win in at most 100 turns!
		}

		testcase.setname("check calculateBullAndPgia");
		testcase
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "6789"), "0,0")								 //0 bul,0 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1236", "3457"), "0,1")								 //0 bul,1 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1236", "4512"), "0,2")								 //0 bul,2 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "4325"), "0,3")						 //0 bul,3 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "4321"), "0,4")				 //0 bul,4 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "1567"), "1,0")								 //1 bul,0 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "1562"), "1,1")								 //1 bul,1 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "1325"), "1,2")								 //1 bul,2 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("12346", "13254"), "1,3")					 //1 bul,3 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("12345", "13254"), "1,4")				 //1 bul,4 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "1256"), "2,0")								 //2 bul,0 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "1245"), "2,1")								 //2 bul,1 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "1243"), "2,2")						 //2 bul,2 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("12345", "12534"), "2,3")				 //2 bul,3 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("123456", "124365"), "2,4")		 //2 bul,4 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "1235"), "3,0")								 //3 bul,0 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("12346", "12354"), "3,1")							 //3 bul,1 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("12345", "12354"), "3,2")						 //3 bul,2 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("123456", "123645"), "3,3")			 //3 bul,3 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234567", "1236475"), "3,4")	 //3 bul,4 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234", "1234"), "4,0")								 //4 bul,0 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("123456", "123467"), "4,1")						 //4 bul,1 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("123456", "123465"), "4,2")				 //4 bul,2 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("1234567", "1234756"), "4,3")		 //4 bul,3 pgia
				.CHECK_OUTPUT(calculateBullAndPgia("12345678", "12346785"), "4,4"); //4 bul,4 pgia
				

		grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: " << grade << endl;
	return 0;
}