#include"bits/stdc++.h"

using namespace std;

pair<char, pair<char, int> > z[26];

string z26loc = "/home/amb/code/nslab/a1/z26Char";

int main(int argc, char** argv)
{
	char delim = ' ';
	fstream z26load;

	z26load.open(z26loc);

	string line;

	int i, j, k, v = 0;
	
	while(getline(z26load, line))
	{
		string lowercase, uppercase, val;

		stringstream ss(line);

		getline(ss, lowercase, delim);
		getline(ss, uppercase, delim);	
		getline(ss, val);

		z[v].first = lowercase[0];
		z[v].second.first = uppercase[0];
		z[v].second.second = atoi(val.c_str());
		v++;		
	}

	string message;

	char key[][3] = { 1, 5, 1,
			  3, 2, 1,
			  1, 2, 4 };

	cout<<"Enter your message :"<<endl;
	getline(cin, message);

	int len = message.size();
	
	vector< vector<char> > mat(100);
	int c = 0, l = 0;

	for(i=0;i<len;i++)
	{
		if(message[i] != ' ')
		{
			mat[l].push_back(message[i]);
			c++;

			if(c==3)
			{
				l++;
				c = 0;
			}
		}
	}

	for(j=0;j<=l;j++)
	{
		int q = 3 - mat[j].size();
		while(q--)
		{
			mat[j].push_back('z');
		}
	}

/*	for(j=0;j<=l;j++)
	{		
		for(k=0;k<3;k++)
		{
			cout<<mat[j][k]<<" ";
		}
		cout<<endl;
	}
*/

	cout<<endl<<"Encrypting.."<<endl;

	int ciphertext[l+1][3];
	int g;

	for(i=0;i<=l;i++)
	{
		for(j=0;j<3;j++)
		{
			ciphertext[i][j] = 0;
			for(k=0;k<3;k++)
			{
				for(int h=0;h<26;h++)
				{
					if(mat[i][k] == z[h].first)
					{
						g = z[h].second.second;
						break;
					}
				}

				ciphertext[i][j] += (g * key[k][j]);		
			}
			ciphertext[i][j] %= 26;	
		}
	}

/*	for(i=0;i<=l;i++)
        {
                for(j=0;j<3;j++)
                {
                        cout<<ciphertext[i][j]<<" ";
                }
                cout<<endl;
        }
        cout<<endl;
*/
	cout<<endl<<"The encrypted message : "<<endl;
	for(i=0;i<=l;i++)
	{
		for(j=0;j<3;j++)
		{
			for(int h=0;h<26;h++)
                       	{
                        	if(ciphertext[i][j] == z[h].second.second)
                                {
                                	cout<<z[h].second.first;
                                }
                        }
		}
	}
	cout<<endl;

	return 0;
}
