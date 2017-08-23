#include"bits/stdc++.h"

using namespace std;

pair<char, pair<char, int> > z[26];

string z26loc = "/home/amb/code/nslab/a1/z26Char";
int z26star[] = { 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};

int gcdExtended(int a, int b, int *x, int *y)
{
	if(a == 0)
	{
		*x = 0;
		*y = 1;

		return b;
	}

	int gcd, x1, y1;

	gcd = gcdExtended(b%a, a, &x1, &y1);

	*x = y1 - (b/a)*x1;
	*y = x1;

	return gcd;
}

int multiplicativeInverse(int a)
{
	int g, x, y, res;

	g = gcdExtended(a, 26, &x, &y);

	if(g!=1)
	{
		return -1;
	}
	else
	{
		res = (x%26 + 26) % 26;
	}

	return res;
}

int main(int argc, char** argv)
{
	char delim = ' ';
	fstream z26load;

	z26load.open(z26loc);

	string line;
	int i = 0, j, p;

	string message;
	cout<<"Enter the ciphertext : "<<endl;
	getline(cin, message);

	while(getline(z26load, line))
	{
		string lowercase, uppercase, val;

		stringstream ss(line);

		getline(ss, lowercase, delim);
		getline(ss, uppercase, delim);	
		getline(ss, val);

		z[i].first = lowercase[0];
		z[i].second.first = uppercase[0];
		z[i].second.second = atoi(val.c_str());
		i++;		
	}

	cout<<endl<<"Decrypting.."<<endl;
	
	int len = message.size();

	list<char> plaintexts[26];
	int key, q;
	
	for(q=0;q<12;q++)
	{
		key = z26star[q];
		key = multiplicativeInverse(key);
		for(i=0;i<len;i++)
		{
			for(j=0;j<26;j++)
			{		
				if(message[i] == z[j].second.first)
				{
					int c = ((z[j].second.second * key) % 26);
					for(int p=0;p<26;p++)
					{
						if(c == z[p].second.second)
						{
							plaintexts[q].push_back(z[p].first);
						}
					}
				}
			}
		}
	}

	cout<<endl<<"Possible plaintexts : "<<endl;
	for(i=0;i<12;i++)
	{
		list<char>::iterator k;
		for(k=plaintexts[i].begin();k!=plaintexts[i].end();k++)
		{
			cout<<*k;
		}
		cout<<endl;
	}


	cout<<endl<<"Correct plaintext : "<<endl;
	list<char>::iterator k;
        for(k=plaintexts[5].begin();k!=plaintexts[5].end();k++)
        {
        	cout<<*k;
        }
        cout<<endl;

	return 0;
}	
