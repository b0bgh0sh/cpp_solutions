// n2w.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;
string helper(int h);
string ones(int o);
string tens(int t);
string ht(int k);
int pw(int k);
string trim(string t);


int main()
{
	int q = 0;
	cout << "Please Enter a Number < 2^32 - 1: ";
	cin >> q;
	cout << "\n*****ANSWER*****" << endl;
	string ans = "";
	int val = 0;
	// cout << (log10(q)) << endl;
	if (q != 0) {
		 val = floor(log10(q));
	}
	// cout << val << endl;
	if (val == 9) {
		int a1 = q % pw(9);
		int a2 = a1 % pw(6);
		int a3 = a2 % pw(3);
		// cout << a1 << " " << a2 << " " << a3 << endl;
		int hun = a3;
		int tho = (a2 - a3) / pw(3);
		int mil = (a1 - (a2 - a3)) / pw(6);
		int bil = (q - ((a1 - (a2 - a3)))) / pw(9);
		ans += ones(bil) + " Billion ";
		if (mil != 0) 
			ans += helper(mil) + " Million ";
		if (tho != 0)
			ans += helper(tho) + " Thousand ";
		if (hun != 0)
			ans += helper(hun);
	}
	if (val < 9 && val >= 6 ) {
		int a1 = q % pw(val + 1);
		int a2 = a1 % pw(6);
		int a3 = a2 % pw(3);
		// cout << a1 << " " << a2 << " " << a3 << endl;
		int hun = a3;
		int tho = (a2 - a3) / pw(3);
		int mil = (a1 - (a2 - a3)) / pw(6);
		// int bil = (q - ((a1 - (a2 - a3)))) / pw(9);
		// ans += ones(bil) + "Billion ";
		if (mil != 0)
			ans += helper(mil) + " Million ";
		if (tho != 0)
			ans += helper(tho) + " Thousand ";
		if (hun != 0)
			ans += helper(hun);
	}
	if (val < 6 && val >= 3) {
		int a1 = q % pw(val + 1);
		int a2 = a1 % pw(6);
		int a3 = a2 % pw(3);
		// cout << a1 << " " << a2 << " " << a3 << endl;
		int hun = a3;
		int tho = (a2 - a3) / pw(3);
		// int mil = (a1 - (a2 - a3)) / pw(6);
		// int bil = (q - ((a1 - (a2 - a3)))) / pw(9);
		// ans += ones(bil) + "Billion ";
		/*if (mil != 0)
			ans += helper(mil) + "Million ";*/
		if (tho != 0)
			ans += helper(tho) + " Thousand ";
		if (hun != 0)
			ans += helper(hun);
	}
	if (val < 3 && val >= 0) {
		int a1 = q % pw(val + 1);
		int a2 = a1 % pw(6);
		int a3 = a2 % pw(3);
		// cout << a1 << " " << a2 << " " << a3 << endl;
		int hun = a3;
		// int tho = (a2 - a3) / pw(3);
		// int mil = (a1 - (a2 - a3)) / pw(6);
		// int bil = (q - ((a1 - (a2 - a3)))) / pw(9);
		// ans += ones(bil) + "Billion ";
		/*if (mil != 0)
			ans += helper(mil) + "Million ";*/
		/*if (tho != 0)
			ans += helper(tho) + "Thousand ";*/
		if (hun != 0)
			ans += helper(hun);
	}
	if (val == 0 && q == 0) {
		ans = "Zero";
	}
	if (val == 0 && q == 1) {
		ans = "One";
	}
	cout << trim(ans);
	cin >> q;
	return 0;
}

string helper(int h) {
	int val = floor(log10(h));
	string ans = "";
	int z = 0;
	while (val >= 0) {
		if (val == 2) {
			ans += ones(h / 100) + " Hundred ";
		}
		else if (val == 1) {
			z = (h % 100) * 100;
		  //cout << z/100 <<" " << h << endl;
			if (z/100 < 20 && z/100 > 9) {
				ans += ht(z/100);
				break;
			}
			else {
				ans += tens(z/1000);
			}
		}
		else {
			ans += ones(h%10);
		}
		val--;
	}
	return trim(ans);
}

string ones(int o) {
	switch (o) {
	case 1:
		return "One";
	case 2:
		return "Two";
	case 3:
		return "Three";
	case 4:
		return "Four";
	case 5:
		return "Five";
	case 6:
		return "Six";
	case 7:
		return "Seven";
	case 8:
		return "Eight";
	case 9:
		return "Nine";
	default:
		return "";
	}
}

string tens(int t) {
	switch (t) {
	case 2:
		return "Twenty ";
	case 3:
		return "Thirty ";
	case 4:
		return "Forty ";
	case 5:
		return "Fifty ";
	case 6:
		return "Sixty ";
	case 7:
		return "Seventy ";
	case 8:
		return "Eighty ";
	case 9:
		return "Ninety ";
	default:
		return "";
	}
}

string ht(int k) {
	switch (k) {
	case 10:
		return "Ten";
	case 11:
		return "Eleven";
	case 12:
		return "Twelve";
	case 13:
		return "Thirteen";
	case 14:
		return "Fourteen";
	case 15:
		return "Fifteen";
	case 16:
		return "Sixteen";
	case 17:
		return "Seventeen";
	case 18:
		return "Eighteen";
	case 19:
		return "Nineteen";
	default:
		return "";
	}
}

int pw(int k) {
	return pow(10, k);
}

string trim(string t) {
	string res = t;
	if (t[t.length() - 1] == ' ')
		res = t.substr(0, t.length() - 1);
	return res;
}