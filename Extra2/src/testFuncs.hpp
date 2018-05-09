#ifndef TESTFUNCS_HPP
#define TESTFUNCS_HPP

#include <stdexcept>
#include "PFAString.hpp"

bool testDConstr()
{
	PFAString obj;
	return (obj.capacity() == 0 && obj.size() == 0);
}

bool testFillConstr(bool dProv)
{
	int cap = 5;

	if (dProv) {
		std::string PATTERN = "HI-DIDDLY-HO";
		PFAString obj(cap, PATTERN);

		if (obj.capacity() == cap && obj.size() == cap) {
			for (int i = 0; i < cap; ++i) {
				if (obj[i] != PATTERN) {
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
	} else {
		PFAString obj(cap);
		if (obj.capacity() == cap && obj.size() == cap) {
			for (int i = 0; i < cap; ++i) {
				if (obj[i] != "") {
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
	}
}

bool testCopConstr(bool blankCopy)
{
	PFAString one;

	if (blankCopy) {
		PFAString two = one;
		return two.size() == one.size() && two.capacity() == one.size();
	} else {
		one.push_back("THIS");
		one.push_back("IS");
		one.push_back("SPARTA");

		PFAString two = one;

		if (two.capacity() == 3 && two.size() == 3) {
			for (int i = 0; i < one.size(); ++i) {
				if (two[i] != one[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
}

bool testMovConstr(bool blankCopy)
{
	PFAString one;

	if (blankCopy) {
		PFAString two = std::move(one);
		return two.size() == one.size() && two.capacity() == one.size();
	} else {
		one.push_back("THIS");
		one.push_back("IS");
		one.push_back("SPARTA");

		PFAString two = std::move(one);

		return (two.size() == 3 
						&& two.capacity() == 4
						&& two[0] == "THIS"
						&& two[1] == "IS"
						&& two[2] == "SPARTA");
	}
}

bool testGetCap()
{
	int cap = 10;
	PFAString obj(cap);

	return (obj.capacity() == cap);
}

bool testGetSize()
{
	PFAString obj(3, "HUH");

	return (obj.size() == 3);
}

bool testPushBack(bool size)
{
	PFAString obj;
	if (!size) {
		obj.push_back("HUUH");
		return (obj[0] == "HUUH" && obj.size() == 1 && obj.capacity() == 1);
	} else {
		for (int i = 0; i < 9; ++i) {
			obj.push_back("HUUH_" + std::to_string(i + 1));
		}
		return ( obj[0] == "HUUH_1" &&
					obj[1] == "HUUH_2" &&
					obj[2] == "HUUH_3" &&
					obj[3] == "HUUH_4" &&
					obj[4] == "HUUH_5" &&
					obj[5] == "HUUH_6" &&
					obj[6] == "HUUH_7" &&
					obj[7] == "HUUH_8" &&
					obj[8] == "HUUH_9" && 
					obj.size() == 9 &&
					obj.capacity() == 16 );
	}
}

bool testPopBack(bool empty)
{
	if (empty) {
		PFAString obj;
		try {
			obj.pop_back();
		} catch(std::out_of_range &oor) {
			return true;
		}
		return false;
	} else {
		PFAString obj(3, "GANGNAM");
		obj.pop_back();
		return (obj.size() == 2);
	}
}

bool testResizeSmaller()
{
	PFAString obj(3, "HULLO");
	obj.resize(1);

	return (obj.size() == 1 && obj.capacity() == 3 && obj[0] == "HULLO");
}

bool testResizeLarger(std::string s = std::string())
{
	PFAString obj(3, "HULLO");
	obj.resize(5, s);

	for (int i = 0; i < 3; ++i) {
		if (obj[i] != "HULLO") {
			return false;
		}
	}
	for (int i = 3; i < 5; ++i) {
		if (obj[i] != s) {
			return false;
		}
	}

	return (obj.size() == 5 && obj.capacity() == 5);
}

bool testEmpty()
{
	PFAString obj(3, "PSY");
	obj.empty_array();

	return (obj.capacity() == 3 && obj.size() == 0);
}

bool testExpansion()
{
	PFAString obj(3, "GANGNAM");
	obj.push_back("STYLE");

	return (obj.capacity() == 6 && obj.size() == 4);
}

bool testSQBLV()
{
	PFAString obj(2, "LILY");
	obj[1] = "FLOWER";

	return (obj[0] == "LILY" && obj[1] == "FLOWER");
}

bool testSQAcc()
{
	PFAString obj(1, "LILY");

	return (obj[0] == "LILY");
}

bool testAssgn(bool empty) // ADD BOOL FOR EMPTY CHECK
{
	PFAString obj;
	PFAString test(10, "NOW");
	if (!empty) {
		obj.push_back("HOW");
		obj.push_back("HOW");
		obj.push_back("HOW");
	}
	
	test = obj;

	if (test.size() >= 1) {
		for (int i = 0; i < test.size(); ++i) {
			if (test[i] != "HOW") {
				return false;
			}
		}
	}

	return (test.capacity() == obj.size() && test.size() == obj.size());
}

bool testAssgnCpySize(bool smaller)
{
	PFAString target(5, "GOOD");
	PFAString from;

	int size;
	if (smaller)
		size = 3;
	else
		size = 8;

	for (int i = 0; i < size; ++i)
		from.push_back("PLACE");
	
	target = from;

	for (int i = 0; i < size; ++i)
		if (target[i] != "PLACE")
			return false;
	
	return ( target.size() == size &&  target.capacity() == size);
}

bool testAssgnMov(bool empty) // ADD BOOL FOR EMPTY CHECK
{
	PFAString one(5, "FLUFFY");
	PFAString two;
	
	if (!empty) {
		two = PFAString(3, "BUNNY");
		two.push_back("SUPER");
	}

	one = std::move(two);

	if (!empty) {
		return (one.size() == 4 
						&& one.capacity() == 6
						&& one[0] == "BUNNY"
						&& one[1] == "BUNNY"
						&& one[2] == "BUNNY"
						&& one[3] == "SUPER");
	} else {
		return (one.size() == 0 && one.capacity() == 0);
	}
}

bool testAssgnMovSize(bool smaller)
{
	PFAString target(5, "GOOD");
	PFAString from;

	int size;
	if (smaller)
		size = 3;
	else
		size = 8;

	for (int i = 0; i < size; ++i)
		from.push_back("PLACE");
	
	target = std::move(from);

	for (int i = 0; i < size; ++i)
		if (target[i] != "PLACE")
			return false;
	
	return ( target.size() == from.size() &&  target.capacity() == from.capacity());
}

bool testEQUIVT()
{
	PFAString obj;
	PFAString test(3, "HI");

	obj.push_back("HI");
	obj.push_back("HI");
	obj.push_back("HI");

	return (obj == test);
}

bool testEQUIVF()
{
	PFAString obj, test;
	obj.push_back("HI");
	test.push_back("HO");

	return !(obj == test);
}

bool testINEQUIVT()
{
	PFAString one(2, "HI");
	PFAString two(2, "HO");

	return (one != two);
}

bool testINEQUIVF()
{
	PFAString one(2, "HI");
	PFAString two(one);

	return !(one != two);
}

bool testLTT()
{
	PFAString obj(3, "A");
	PFAString test(2, "B");

	return (obj < test);
}

bool testLTF()
{
	PFAString obj(3, "A");
	PFAString test(4, "A");

	return !(test < obj);
}

bool testLTFE()
{
	PFAString obj(3, "A");
	PFAString test = obj;

	return !(obj < test);
}

bool testGTT()
{
	PFAString obj(3, "A");
	PFAString test(2, "B");

	return (test > obj);
}

bool testGTF()
{
	PFAString obj(3, "A");
	PFAString test(4, "A");

	return !(obj > test);
}

bool testGTFE()
{
	PFAString obj(3, "A");
	PFAString test = obj;

	return !(test > obj);
}

bool testLEQT()
{
	PFAString obj, test;

	obj.push_back("B");
	test.push_back("B");
	test.push_back("B");

	return (obj <= test);
}

bool testLEQTE()
{
	PFAString obj, test;

	obj.push_back("THIS");
	obj.push_back("IS");
	obj.push_back("SPARTA! *punt*");

	test = obj;

	return (obj <= test);
}

bool testLEQF()
{
	PFAString obj, test;
	
	obj.push_back("THIS");
	obj.push_back("IS");
	obj.push_back("SPARTA! *punt*");

	test = obj;
	test.push_back("AAaah");

	return !(test <= obj);
}

bool testGEQT()
{
	PFAString obj, test;

	obj.push_back("AIAIAI");
	test.push_back("AHAHAH");

	return (obj >= test);
}

bool testGEQTE()
{
	PFAString obj, test;
	
	obj.push_back("THIS");
	obj.push_back("IS");
	obj.push_back("SPARTA! *punt*");

	test = obj;

	return (test >= obj);
}

bool testGEQF()
{
	PFAString obj, test;
	
	obj.push_back("THIS");
	obj.push_back("IS");
	obj.push_back("SPARTA! *punt*");

	test = obj;
	test.push_back("AAaah");

	return !(obj >= test);
}

bool testAT(bool normal)
{
	PFAString obj(5, "DARUDE");

	if (normal) {
		try {
			obj.at(0);
			obj.at(4);
		} catch(const std::out_of_range &oor) {
			return false;
		}
		return true;
	} else {
		try {
			obj.at(-1);
		} catch(const std::out_of_range &oor) {
			return true;
		}
		return false;
	}
}

bool testExcEmpty()
{
	PFAString obj;

	try {
		obj.empty_array();
	} catch(...) {
		return true;
	}
	return false;
}

#endif